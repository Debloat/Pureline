/*
 Navicat Premium Dump SQL

 Source Server         : Pureline
 Source Server Type    : MySQL
 Source Server Version : 50651 (5.6.51-log)
 Source Host           : localhost:3306
 Source Schema         : log

 Target Server Type    : MySQL
 Target Server Version : 50651 (5.6.51-log)
 File Encoding         : 65001

 Date: 17/09/2025 01:38:13
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for bootlog
-- ----------------------------
DROP TABLE IF EXISTS `bootlog`;
CREATE TABLE `bootlog`  (
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `hostname` char(128) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT 'UNKNOWN',
  `channel` tinyint(1) NOT NULL DEFAULT 0
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for change_name
-- ----------------------------
DROP TABLE IF EXISTS `change_name`;
CREATE TABLE `change_name`  (
  `pid` int(11) NULL DEFAULT NULL,
  `old_name` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `new_name` varchar(255) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `time` datetime NULL DEFAULT NULL,
  `ip` varchar(20) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for command_log
-- ----------------------------
DROP TABLE IF EXISTS `command_log`;
CREATE TABLE `command_log`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `userid` int(11) NOT NULL DEFAULT 0,
  `server` int(11) NOT NULL DEFAULT 0,
  `ip` varchar(15) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `port` int(6) NOT NULL DEFAULT 0,
  `username` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `command` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL,
  `date` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for cube
-- ----------------------------
DROP TABLE IF EXISTS `cube`;
CREATE TABLE `cube`  (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `pid` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `x` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `y` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `item_vnum` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `item_uid` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `item_count` int(5) UNSIGNED NOT NULL DEFAULT 0,
  `success` tinyint(1) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `pid`(`pid`) USING BTREE,
  INDEX `item_vnum`(`item_vnum`) USING BTREE,
  INDEX `item_uid`(`item_uid`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for dragon_slay_log
-- ----------------------------
DROP TABLE IF EXISTS `dragon_slay_log`;
CREATE TABLE `dragon_slay_log`  (
  `guild_id` int(11) UNSIGNED NOT NULL,
  `vnum` int(11) UNSIGNED NOT NULL,
  `start_time` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00',
  `end_time` timestamp NOT NULL DEFAULT '0000-00-00 00:00:00'
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for fish_log
-- ----------------------------
DROP TABLE IF EXISTS `fish_log`;
CREATE TABLE `fish_log`  (
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `player_id` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `map_index` tinyint(4) NOT NULL DEFAULT 0,
  `fish_id` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `fishing_level` int(11) NOT NULL DEFAULT 0,
  `waiting_time` int(11) NOT NULL DEFAULT 0,
  `success` tinyint(4) NOT NULL DEFAULT 0,
  `size` smallint(6) NOT NULL DEFAULT 0
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for goldlog
-- ----------------------------
DROP TABLE IF EXISTS `goldlog`;
CREATE TABLE `goldlog`  (
  `date` varchar(10) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '0000-00-00',
  `time` varchar(8) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '00:00:00',
  `pid` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `what` int(11) NOT NULL DEFAULT 0,
  `how` set('BUY','SELL','SHOP_SELL','SHOP_BUY','EXCHANGE_TAKE','EXCHANGE_GIVE','QUEST') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `hint` varchar(50) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  INDEX `date_idx`(`date`) USING BTREE,
  INDEX `pid_idx`(`pid`) USING BTREE,
  INDEX `what_idx`(`what`) USING BTREE,
  INDEX `how_idx`(`how`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for hack_crc_log
-- ----------------------------
DROP TABLE IF EXISTS `hack_crc_log`;
CREATE TABLE `hack_crc_log`  (
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `login` char(16) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `name` char(24) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `ip` char(15) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `server` char(100) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `why` char(255) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `crc` int(11) NOT NULL DEFAULT 0
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for hack_log
-- ----------------------------
DROP TABLE IF EXISTS `hack_log`;
CREATE TABLE `hack_log`  (
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `login` char(16) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `name` char(24) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `ip` char(15) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `server` char(100) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `why` char(255) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT ''
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for levellog
-- ----------------------------
DROP TABLE IF EXISTS `levellog`;
CREATE TABLE `levellog`  (
  `name` char(24) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `level` tinyint(4) NOT NULL DEFAULT 0,
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `playtime` int(11) NOT NULL DEFAULT 0,
  `account_id` int(11) NOT NULL,
  `pid` int(11) NOT NULL,
  PRIMARY KEY (`name`, `level`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for log
-- ----------------------------
DROP TABLE IF EXISTS `log`;
CREATE TABLE `log`  (
  `type` enum('ITEM','CHARACTER') CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT 'ITEM',
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `who` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `x` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `y` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `what` int(11) NOT NULL DEFAULT 0,
  `how` varchar(50) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `hint` varchar(70) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `ip` varchar(20) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `vnum` int(11) NULL DEFAULT NULL,
  INDEX `who_idx`(`who`) USING BTREE,
  INDEX `what_idx`(`what`) USING BTREE,
  INDEX `how_idx`(`how`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for loginlog
-- ----------------------------
DROP TABLE IF EXISTS `loginlog`;
CREATE TABLE `loginlog`  (
  `type` enum('LOGIN','LOGOUT') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `time` datetime NULL DEFAULT NULL,
  `channel` tinyint(4) NULL DEFAULT NULL,
  `account_id` int(10) UNSIGNED NULL DEFAULT NULL,
  `pid` int(10) UNSIGNED NULL DEFAULT NULL,
  `level` smallint(6) NULL DEFAULT NULL,
  `job` tinyint(4) NULL DEFAULT NULL,
  `playtime` int(10) UNSIGNED NULL DEFAULT NULL,
  INDEX `pid`(`pid`, `type`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for loginlog2
-- ----------------------------
DROP TABLE IF EXISTS `loginlog2`;
CREATE TABLE `loginlog2`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `type` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  `is_gm` int(11) NULL DEFAULT NULL,
  `login_time` datetime NULL DEFAULT NULL,
  `channel` int(11) NULL DEFAULT NULL,
  `account_id` int(11) NULL DEFAULT NULL,
  `pid` int(11) NULL DEFAULT NULL,
  `client_version` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  `ip` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  `logout_time` datetime NULL DEFAULT NULL,
  `playtime` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Table structure for money_log
-- ----------------------------
DROP TABLE IF EXISTS `money_log`;
CREATE TABLE `money_log`  (
  `time` datetime NULL DEFAULT NULL,
  `type` enum('MONSTER','SHOP','REFINE','QUEST','GUILD','MISC','KILL','DROP') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `vnum` int(11) NOT NULL DEFAULT 0,
  `gold` int(11) NOT NULL DEFAULT 0,
  INDEX `type`(`type`, `vnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for playercount
-- ----------------------------
DROP TABLE IF EXISTS `playercount`;
CREATE TABLE `playercount`  (
  `date` datetime NULL DEFAULT NULL,
  `count_red` int(11) NULL DEFAULT NULL,
  `count_yellow` int(11) NULL DEFAULT NULL,
  `count_blue` int(11) NULL DEFAULT NULL,
  `count_total` int(11) NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Table structure for quest_reward_log
-- ----------------------------
DROP TABLE IF EXISTS `quest_reward_log`;
CREATE TABLE `quest_reward_log`  (
  `quest_name` varchar(32) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `player_id` int(10) UNSIGNED NULL DEFAULT NULL,
  `player_level` tinyint(4) NULL DEFAULT NULL,
  `reward_type` enum('EXP','ITEM') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `reward_value1` int(10) UNSIGNED NULL DEFAULT NULL,
  `reward_value2` int(11) NULL DEFAULT NULL,
  `time` datetime NULL DEFAULT NULL,
  INDEX `player_id`(`player_id`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for refinelog
-- ----------------------------
DROP TABLE IF EXISTS `refinelog`;
CREATE TABLE `refinelog`  (
  `pid` int(10) UNSIGNED NULL DEFAULT NULL,
  `item_name` varchar(24) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `item_id` int(11) NOT NULL DEFAULT 0,
  `step` varchar(50) CHARACTER SET big5 COLLATE big5_chinese_ci NOT NULL DEFAULT '',
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `is_success` tinyint(1) NOT NULL DEFAULT 0,
  `setType` set('SOCKET','POWER','ROD','GUILD','SCROLL','HYUNIRON','GOD_SCROLL','MUSIN_SCROLL') CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for shout_log
-- ----------------------------
DROP TABLE IF EXISTS `shout_log`;
CREATE TABLE `shout_log`  (
  `time` datetime NULL DEFAULT '0000-00-00 00:00:00',
  `channel` tinyint(4) NULL DEFAULT NULL,
  `empire` tinyint(4) NULL DEFAULT NULL,
  `shout` varchar(350) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  INDEX `time_idx`(`time`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Table structure for speed_hack
-- ----------------------------
DROP TABLE IF EXISTS `speed_hack`;
CREATE TABLE `speed_hack`  (
  `pid` int(11) NULL DEFAULT NULL,
  `time` datetime NULL DEFAULT NULL,
  `x` int(11) NULL DEFAULT NULL,
  `y` int(11) NULL DEFAULT NULL,
  `hack_count` varchar(20) CHARACTER SET big5 COLLATE big5_bin NULL DEFAULT NULL
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

SET FOREIGN_KEY_CHECKS = 1;
