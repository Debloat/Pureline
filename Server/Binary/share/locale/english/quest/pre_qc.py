# -*- coding: utf-8 -*-
"""
Literally, this is pre-QC.
In our Quest language, only local variables are allowed,
and global variables that span state, when, or function cannot be used.
Using global 'variables' is structurally impossible in the language and has no significant meaning.
However, using global 'constants' is essential for the Quest view.
To achieve this, functions like "function setting()" are used
to create tables every time, simulating the use of global constants.
This approach is highly inefficient,
so a pre-QC system, similar to C's preprocessor, was created to enable the use of global constants.
Before compiling a Quest file into QC, it passes through pre_qc.py,
where pre_qc.py processes the define statements and saves the results
into pre_qc/filename.
"""

import os

PRE_QC_DIR = "pre_qc"


def split_by_quat(buf):
	"""
	Splits a string by quotation marks while preserving their integrity.

	Args:
		buf (str): Input string to split.

	Returns:
		list: List of strings split by quotation marks.
	"""
	is_in_quotes = False
	buf_list = list(buf)
	buf_list.reverse()
	segment = ""
	result = []

	while buf_list:
		char = buf_list.pop()
		if char == '"':
			if is_in_quotes:
				segment += char
				result.append(segment)
				segment = ""
			else:
				if segment:
					result.append(segment)
				segment = '"'
			is_in_quotes = not is_in_quotes
		elif char == "\\" and buf_list and buf_list[0] == '"':
			segment += char + buf_list.pop()
		else:
			segment += char

	if segment:
		result.append(segment)

	return result


def add_sep_middle_of_element(elements, separator):
	"""
	Adds a separator between each element in a list.

	Args:
		elements (list): List of elements.
		separator (str): Separator to add.

	Returns:
		list: New list with separators added.
	"""
	elements.reverse()
	new_list = [elements.pop()]

	while elements:
		new_list.append(separator)
		new_list.append(elements.pop())

	return new_list


def my_split_with_seps(s, separators):
	"""
	Splits a string using multiple separators while retaining separators in the result.

	Args:
		s (str): Input string.
		separators (list): List of separators.

	Returns:
		list: List of split strings with separators included.
	"""
	result = [s]

	for sep in separators:
		new_result = []
		for segment in result:
			split_segments = segment.split(sep)
			split_segments = add_sep_middle_of_element(split_segments, sep)
			new_result.extend(split_segments)
		result = new_result

	return [r for r in result if r]


def my_split(s, separators):
	"""
	Splits a string using multiple separators.

	Args:
		s (str): Input string.
		separators (list): List of separators.

	Returns:
		list: List of split strings.
	"""
	result = [s]

	for sep in separators:
		new_result = []
		for segment in result:
			new_result.extend(segment.split(sep))
		result = new_result

	return [r for r in result if r]


def multi_index(lst, key):
	"""
	Finds all indices of a key in a list.

	Args:
		lst (list): List to search in.
		key (str): Key to search for.

	Returns:
		list: List of indices where the key occurs.
	"""
	return [i for i, value in enumerate(lst) if value == key]


def replace(lines, parameter_table, keys):
	"""
	Replaces occurrences of keys in the lines with their corresponding values from the parameter table.

	Args:
		lines (list): List of lines to process.
		parameter_table (dict): Dictionary of parameter substitutions.
		keys (list): List of keys to replace.

	Returns:
		list: Processed lines with replacements.
	"""
	result = []

	for string in lines:
		segments = split_by_quat(string)
		for segment in segments:
			if segment[0] == '"':
				result.append(segment)
			else:
				tokens = my_split_with_seps(
					segment, ["\t", ",", " ", "=", "[", "]", "-", "<", ">", "~", "!", ".", "(", ")"]
				)
				for key in keys:
					indices = multi_index(tokens, key)
					for i in indices:
						tokens[i] = parameter_table[key][0]
				result.extend(tokens)

	return result


def make_parameter_table(lines, parameter_table, keys):
	"""
	Parses lines to build a parameter table and extract global constants.

	Args:
		lines (list): List of lines from the input file.
		parameter_table (dict): Dictionary to store parameters.
		keys (list): List to store parameter keys.

	Returns:
		int: Index of the first non-parameter line.
	"""
	idx = 0

	for line in lines:
		idx += 1
		line = line.split("--")[0].strip()

		tokens = my_split(line, ["\t", ",", " ", "=", "[", "]", "\r", "\n"])
		if not tokens:
			continue

		if tokens[0] == "quest":
			return idx

		if tokens[0] == "define":
			if tokens[1] == "group":
				group_values = [
					parameter_table.get(value, value) for value in tokens[3:]
				]
				parameter_table[tokens[2]] = group_values
				keys.append(tokens[2])
			elif len(tokens) == 3:
				value = parameter_table.get(tokens[2], tokens[2])
				parameter_table[tokens[1]] = [value]
				keys.append(tokens[1])
			else:
				print("%d Invalid syntax: define [name] = [value]" % idx)
				print("define group [name] = \"[v0], [v1], ...\"")

	return idx


def run(filename):
	"""
	Main function to process a Quest file and generate a preprocessed output.

	Args:
		filename (str): Path to the input file.

	Returns:
		bool: True if processing was successful, False otherwise.
	"""
	parameter_table = {}
	keys = []

	filename = filename.strip()
	if not filename:
		return False

	with open(filename, "r", errors="ignore") as file:
		lines = file.readlines()

	start = make_parameter_table(lines, parameter_table, keys)
	if not keys:
		return False

	lines = lines[start - 1:]
	processed_lines = replace(lines, parameter_table, keys)

	output_path = os.path.join(PRE_QC_DIR, filename)
	
	with open(output_path, "w") as file:
		for line in processed_lines:
			file.write(line)

	return True