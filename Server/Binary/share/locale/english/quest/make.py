# -*- coding: utf-8 -*-
"""
Main script for preprocessing and compiling Quest files.
Handles preprocessing through `pre_qc.py` and compilation via a designated compiler.
"""

import os
import sys
import shutil
import pre_qc

# Constants
QC_BIN_NAME = "qc_Win32_Release"
PRE_QC_DIR = "pre_qc"
OBJ_DIR = "object"
LOCALE_LIST_FILE = "locale_list"
DEBUG_FLAG = "d"
EMPTY_NAME = ""


def is_windows_os():
	"""
	Checks if the operating system is Windows.

	Returns:
		bool: True if the operating system is Windows, False otherwise.
	"""
	return os.name == 'nt'


def compile_file(filename, use_debug):
	"""
	Compiles the specified file using the configured compiler.

	Args:
		filename (str): The file to compile.
		use_debug (bool): Whether to use the debug flag in the compilation.

	Raises:
		SystemExit: If the compilation fails.
	"""
	suffix = "_%s" % DEBUG_FLAG if use_debug else EMPTY_NAME
	if is_windows_os():
		compile_command = "%s%s.exe %s" % (QC_BIN_NAME, suffix, filename)
	else:
		compile_command = "./%s%s %s" % (QC_BIN_NAME, suffix, filename)

	if os.system(compile_command) != 0:
		print("Error occurred during compilation: %s" % filename)
		sys.exit(-1)


def setup_directories():
	"""
	Sets up the required directories for object files and preprocessing results.
	"""
	if os.path.exists(OBJ_DIR):
		shutil.rmtree(OBJ_DIR)
	os.mkdir(OBJ_DIR)

	if not os.path.exists(PRE_QC_DIR):
		os.mkdir(PRE_QC_DIR)


def process_locale_list(use_debug):
	"""
	Processes the `locale_list` file and compiles each file listed in it.

	Args:
		use_debug (bool): Whether to use the debug flag in the compilation.
	"""
	with open(LOCALE_LIST_FILE, "r") as locale_list:
		for line in locale_list:
			line = line.strip()
			if not line:
				continue

			preprocessed = pre_qc.run(line)
			filename = os.path.join(PRE_QC_DIR, line) if preprocessed else line

			compile_file(filename, use_debug)


def main():
	"""
	Main function to set up directories, process the locale list, and handle compilation.
	"""
	setup_directories()
	use_debug = DEBUG_FLAG in sys.argv
	process_locale_list(use_debug)

	if not is_windows_os():
		os.chmod(OBJ_DIR, 0o770)

if __name__ == "__main__":
	main()