/*
 Navicat Premium Dump SQL

 Source Server         : Pureline
 Source Server Type    : MySQL
 Source Server Version : 50651 (5.6.51-log)
 Source Host           : localhost:3306
 Source Schema         : player

 Target Server Type    : MySQL
 Target Server Version : 50651 (5.6.51-log)
 File Encoding         : 65001

 Date: 20/09/2025 16:48:02
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for affect
-- ----------------------------
DROP TABLE IF EXISTS `affect`;
CREATE TABLE `affect`  (
  `dwPID` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `bType` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `bApplyOn` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `lApplyValue` int(11) NOT NULL DEFAULT 0,
  `dwFlag` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `lDuration` int(11) NOT NULL DEFAULT 0,
  `lSPCost` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`dwPID`, `bType`, `bApplyOn`, `lApplyValue`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of affect
-- ----------------------------
INSERT INTO `affect` VALUES (1, 540, 0, 0, 0, 1892062636, 0);
INSERT INTO `affect` VALUES (1, 535, 120, 4, 40000097, 1892147915, 0);
INSERT INTO `affect` VALUES (1, 534, 119, 4, 40000098, 1892147915, 0);

-- ----------------------------
-- Table structure for banword
-- ----------------------------
DROP TABLE IF EXISTS `banword`;
CREATE TABLE `banword`  (
  `word` varbinary(24) NOT NULL DEFAULT '',
  PRIMARY KEY (`word`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of banword
-- ----------------------------
INSERT INTO `banword` VALUES (0x617279616E);
INSERT INTO `banword` VALUES (0x617373686F6C65);
INSERT INTO `banword` VALUES (0x62617374617264);
INSERT INTO `banword` VALUES (0x6261737461726473);
INSERT INTO `banword` VALUES (0x6269746368);
INSERT INTO `banword` VALUES (0x62697463686573);
INSERT INTO `banword` VALUES (0x6269746368696E67);
INSERT INTO `banword` VALUES (0x626974636879);
INSERT INTO `banword` VALUES (0x626F6F62);
INSERT INTO `banword` VALUES (0x626F6F626965);
INSERT INTO `banword` VALUES (0x626F6F62696573);
INSERT INTO `banword` VALUES (0x626F6F6273);
INSERT INTO `banword` VALUES (0x626F6F6279);
INSERT INTO `banword` VALUES (0x626F6F627973);
INSERT INTO `banword` VALUES (0x62756C6C73686974);
INSERT INTO `banword` VALUES (0x62756C6C73686974746572);
INSERT INTO `banword` VALUES (0x62756C6C7368697474657273);
INSERT INTO `banword` VALUES (0x62756C6C7368697474696E67);
INSERT INTO `banword` VALUES (0x636869636B656E73686974);
INSERT INTO `banword` VALUES (0x636869636B656E7368697473);
INSERT INTO `banword` VALUES (0x636C6974);
INSERT INTO `banword` VALUES (0x636F636B);
INSERT INTO `banword` VALUES (0x636F636B68656164);
INSERT INTO `banword` VALUES (0x636F636B73);
INSERT INTO `banword` VALUES (0x636F636B7375636B);
INSERT INTO `banword` VALUES (0x636F636B7375636B6572);
INSERT INTO `banword` VALUES (0x636F636B7375636B696E67);
INSERT INTO `banword` VALUES (0x63756D6D696E67);
INSERT INTO `banword` VALUES (0x63756E74);
INSERT INTO `banword` VALUES (0x63756E74726565);
INSERT INTO `banword` VALUES (0x63756E747279);
INSERT INTO `banword` VALUES (0x63756E7473);
INSERT INTO `banword` VALUES (0x64697073686974);
INSERT INTO `banword` VALUES (0x6469707368697473);
INSERT INTO `banword` VALUES (0x64756D626675636B);
INSERT INTO `banword` VALUES (0x64756D626675636B73);
INSERT INTO `banword` VALUES (0x64756D6273686974);
INSERT INTO `banword` VALUES (0x64756D627368697473);
INSERT INTO `banword` VALUES (0x666167);
INSERT INTO `banword` VALUES (0x666167676F74);
INSERT INTO `banword` VALUES (0x666167676F7473);
INSERT INTO `banword` VALUES (0x6661676779);
INSERT INTO `banword` VALUES (0x66616773);
INSERT INTO `banword` VALUES (0x6675636B);
INSERT INTO `banword` VALUES (0x6675636B61);
INSERT INTO `banword` VALUES (0x6675636B65);
INSERT INTO `banword` VALUES (0x6675636B6564);
INSERT INTO `banword` VALUES (0x6675636B656E);
INSERT INTO `banword` VALUES (0x6675636B6572);
INSERT INTO `banword` VALUES (0x6675636B657273);
INSERT INTO `banword` VALUES (0x6675636B66616365);
INSERT INTO `banword` VALUES (0x6675636B68656164);
INSERT INTO `banword` VALUES (0x6675636B6865616473);
INSERT INTO `banword` VALUES (0x6675636B686564);
INSERT INTO `banword` VALUES (0x6675636B696E);
INSERT INTO `banword` VALUES (0x6675636B696E67);
INSERT INTO `banword` VALUES (0x6675636B73);
INSERT INTO `banword` VALUES (0x6675636B7570);
INSERT INTO `banword` VALUES (0x6675636B757073);
INSERT INTO `banword` VALUES (0x66756B6B);
INSERT INTO `banword` VALUES (0x66756B6B61);
INSERT INTO `banword` VALUES (0x676F6E696666);
INSERT INTO `banword` VALUES (0x686562);
INSERT INTO `banword` VALUES (0x68656265);
INSERT INTO `banword` VALUES (0x6865626573);
INSERT INTO `banword` VALUES (0x6B696B65);
INSERT INTO `banword` VALUES (0x6B696B6573);
INSERT INTO `banword` VALUES (0x6B756E74);
INSERT INTO `banword` VALUES (0x6B756E74726565);
INSERT INTO `banword` VALUES (0x6B756E747279);
INSERT INTO `banword` VALUES (0x6B756E7473);
INSERT INTO `banword` VALUES (0x6D6F746865726675636B);
INSERT INTO `banword` VALUES (0x6D6F746865726675636B656E);
INSERT INTO `banword` VALUES (0x6D6F746865726675636B6572);
INSERT INTO `banword` VALUES (0x6D6F746865726675636B657273);
INSERT INTO `banword` VALUES (0x6D6F746865726675636B696E);
INSERT INTO `banword` VALUES (0x6D6F746865726675636B696E67);
INSERT INTO `banword` VALUES (0x6E617A69);
INSERT INTO `banword` VALUES (0x6E69676761);
INSERT INTO `banword` VALUES (0x6E6967676168);
INSERT INTO `banword` VALUES (0x6E696767616873);
INSERT INTO `banword` VALUES (0x6E696767617264);
INSERT INTO `banword` VALUES (0x6E6967676172646C79);
INSERT INTO `banword` VALUES (0x6E6967676173);
INSERT INTO `banword` VALUES (0x6E696767617A);
INSERT INTO `banword` VALUES (0x6E6967676572);
INSERT INTO `banword` VALUES (0x6E696767657273);
INSERT INTO `banword` VALUES (0x70656E6973);
INSERT INTO `banword` VALUES (0x70697373);
INSERT INTO `banword` VALUES (0x706F726E);
INSERT INTO `banword` VALUES (0x706F726E6F);
INSERT INTO `banword` VALUES (0x706F726E6F677261706879);
INSERT INTO `banword` VALUES (0x7075737379);
INSERT INTO `banword` VALUES (0x7363686C696D617A656C);
INSERT INTO `banword` VALUES (0x7363686C696D69656C);
INSERT INTO `banword` VALUES (0x73686974);
INSERT INTO `banword` VALUES (0x7368697466616365);
INSERT INTO `banword` VALUES (0x736869746661636564);
INSERT INTO `banword` VALUES (0x7368697468656164);
INSERT INTO `banword` VALUES (0x736869746865616473);
INSERT INTO `banword` VALUES (0x73686974686564);
INSERT INTO `banword` VALUES (0x7368697473);
INSERT INTO `banword` VALUES (0x7368697474696E67);
INSERT INTO `banword` VALUES (0x736869747479);
INSERT INTO `banword` VALUES (0x736C7574);
INSERT INTO `banword` VALUES (0x736C757473);
INSERT INTO `banword` VALUES (0x736C75747479);
INSERT INTO `banword` VALUES (0x74697474696573);
INSERT INTO `banword` VALUES (0x7469747479);
INSERT INTO `banword` VALUES (0x766167696E61);
INSERT INTO `banword` VALUES (0x766167696E616C);
INSERT INTO `banword` VALUES (0x77686F7265);
INSERT INTO `banword` VALUES (0x77686F726573);
INSERT INTO `banword` VALUES (0x77686F72696E67);

-- ----------------------------
-- Table structure for change_empire
-- ----------------------------
DROP TABLE IF EXISTS `change_empire`;
CREATE TABLE `change_empire`  (
  `account_id` int(11) NOT NULL DEFAULT 0,
  `change_count` tinyint(4) NULL DEFAULT NULL,
  `timestamp` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`account_id`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of change_empire
-- ----------------------------

-- ----------------------------
-- Table structure for guild
-- ----------------------------
DROP TABLE IF EXISTS `guild`;
CREATE TABLE `guild`  (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `name` varchar(12) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `sp` smallint(6) NOT NULL DEFAULT 1000,
  `master` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `level` tinyint(2) NULL DEFAULT NULL,
  `exp` int(11) NULL DEFAULT NULL,
  `skill_point` tinyint(2) NOT NULL DEFAULT 0,
  `skill` tinyblob NULL,
  `win` int(11) NOT NULL DEFAULT 0,
  `draw` int(11) NOT NULL DEFAULT 0,
  `loss` int(11) NOT NULL DEFAULT 0,
  `ladder_point` int(11) NOT NULL DEFAULT 0,
  `gold` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 2 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of guild
-- ----------------------------
INSERT INTO `guild` VALUES (1, '[GM-TEAM]', 0, 1, 20, 0, 19, 0x000000000000000000000000, 0, 0, 0, 19000, 0);

-- ----------------------------
-- Table structure for guild_comment
-- ----------------------------
DROP TABLE IF EXISTS `guild_comment`;
CREATE TABLE `guild_comment`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `guild_id` int(10) UNSIGNED NULL DEFAULT NULL,
  `name` varchar(8) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `notice` tinyint(4) NULL DEFAULT NULL,
  `content` varchar(50) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `time` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `aaa`(`notice`, `id`, `guild_id`) USING BTREE,
  INDEX `guild_id`(`guild_id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of guild_comment
-- ----------------------------

-- ----------------------------
-- Table structure for guild_grade
-- ----------------------------
DROP TABLE IF EXISTS `guild_grade`;
CREATE TABLE `guild_grade`  (
  `guild_id` int(11) NOT NULL DEFAULT 0,
  `grade` tinyint(4) NOT NULL DEFAULT 0,
  `name` varchar(8) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `auth` set('ADD_MEMBER','REMOVE_MEMEBER','NOTICE','USE_SKILL') CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  PRIMARY KEY (`guild_id`, `grade`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of guild_grade
-- ----------------------------
INSERT INTO `guild_grade` VALUES (1, 1, 'Leader ', 'ADD_MEMBER,REMOVE_MEMEBER,NOTICE,USE_SKILL');
INSERT INTO `guild_grade` VALUES (1, 2, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 3, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 4, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 5, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 6, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 7, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 8, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 9, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 10, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 11, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 12, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 13, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 14, 'Member ', '');
INSERT INTO `guild_grade` VALUES (1, 15, 'Member ', '');

-- ----------------------------
-- Table structure for guild_member
-- ----------------------------
DROP TABLE IF EXISTS `guild_member`;
CREATE TABLE `guild_member`  (
  `pid` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `guild_id` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `grade` tinyint(2) NULL DEFAULT NULL,
  `is_general` tinyint(1) NOT NULL DEFAULT 0,
  `offer` int(10) UNSIGNED NULL DEFAULT NULL,
  PRIMARY KEY (`guild_id`, `pid`) USING BTREE,
  UNIQUE INDEX `pid`(`pid`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of guild_member
-- ----------------------------
INSERT INTO `guild_member` VALUES (1, 1, 1, 0, 18000000);

-- ----------------------------
-- Table structure for guild_war
-- ----------------------------
DROP TABLE IF EXISTS `guild_war`;
CREATE TABLE `guild_war`  (
  `id_from` int(11) NOT NULL DEFAULT 0,
  `id_to` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id_from`, `id_to`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of guild_war
-- ----------------------------

-- ----------------------------
-- Table structure for guild_war_bet
-- ----------------------------
DROP TABLE IF EXISTS `guild_war_bet`;
CREATE TABLE `guild_war_bet`  (
  `login` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `gold` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `guild` int(11) NOT NULL DEFAULT 0,
  `war_id` int(10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`war_id`, `login`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of guild_war_bet
-- ----------------------------

-- ----------------------------
-- Table structure for guild_war_reservation
-- ----------------------------
DROP TABLE IF EXISTS `guild_war_reservation`;
CREATE TABLE `guild_war_reservation`  (
  `id` int(10) UNSIGNED NOT NULL AUTO_INCREMENT,
  `guild1` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `guild2` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `type` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `warprice` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `initscore` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `started` tinyint(1) NOT NULL DEFAULT 0,
  `bet_from` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `bet_to` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `winner` int(11) NOT NULL DEFAULT -1,
  `power1` int(11) NOT NULL DEFAULT 0,
  `power2` int(11) NOT NULL DEFAULT 0,
  `handicap` int(11) NOT NULL DEFAULT 0,
  `result1` int(11) NOT NULL DEFAULT 0,
  `result2` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of guild_war_reservation
-- ----------------------------

-- ----------------------------
-- Table structure for horse_name
-- ----------------------------
DROP TABLE IF EXISTS `horse_name`;
CREATE TABLE `horse_name`  (
  `id` int(11) NOT NULL DEFAULT 0,
  `name` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NONAME',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of horse_name
-- ----------------------------

-- ----------------------------
-- Table structure for item
-- ----------------------------
DROP TABLE IF EXISTS `item`;
CREATE TABLE `item`  (
  `id` int(11) UNSIGNED NOT NULL AUTO_INCREMENT,
  `owner_id` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `window` enum('INVENTORY','EQUIPMENT','SAFEBOX','MALL','DRAGON_SOUL_INVENTORY','BELT_INVENTORY') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'INVENTORY',
  `pos` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `count` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `vnum` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `socket0` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `socket1` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `socket2` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `socket3` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `socket4` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `socket5` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `attrtype0` tinyint(4) NOT NULL DEFAULT 0,
  `attrvalue0` smallint(6) NOT NULL DEFAULT 0,
  `attrtype1` tinyint(4) NOT NULL DEFAULT 0,
  `attrvalue1` smallint(6) NOT NULL DEFAULT 0,
  `attrtype2` tinyint(4) NOT NULL DEFAULT 0,
  `attrvalue2` smallint(6) NOT NULL DEFAULT 0,
  `attrtype3` tinyint(4) NOT NULL DEFAULT 0,
  `attrvalue3` smallint(6) NOT NULL DEFAULT 0,
  `attrtype4` tinyint(4) NOT NULL DEFAULT 0,
  `attrvalue4` smallint(6) NOT NULL DEFAULT 0,
  `attrtype5` tinyint(4) NOT NULL DEFAULT 0,
  `attrvalue5` smallint(6) NOT NULL DEFAULT 0,
  `attrtype6` tinyint(4) NOT NULL DEFAULT 0,
  `attrvalue6` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `owner_id_idx`(`owner_id`) USING BTREE,
  INDEX `item_vnum_index`(`vnum`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1610013545 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of item
-- ----------------------------
INSERT INTO `item` VALUES (40000007, 1, 'EQUIPMENT', 6, 1, 17109, 0, 0, 0, 0, 0, 0, 8, 20, 25, 10, 41, 5, 22, 20, 21, 20, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000100, 1, 'INVENTORY', 0, 1, 469, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000105, 1, 'INVENTORY', 158, 200, 27006, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (80000017, 1, 'INVENTORY', 154, 200, 27003, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000103, 1, 'INVENTORY', 153, 200, 27003, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000101, 1, 'INVENTORY', 152, 200, 27003, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000011, 1, 'EQUIPMENT', 4, 1, 3159, 1, 1, 1, 0, 0, 0, 9, 20, 15, 10, 16, 10, 22, 20, 5, 12, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000012, 1, 'EQUIPMENT', 1, 1, 12249, 0, 0, 0, 0, 0, 0, 7, 8, 10, 30, 11, 30, 28, 15, 24, 10, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000010, 1, 'EQUIPMENT', 2, 1, 15189, 0, 0, 0, 0, 0, 0, 1, 2000, 2, 80, 8, 8, 7, 8, 15, 10, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000013, 1, 'EQUIPMENT', 3, 1, 14109, 0, 0, 0, 0, 0, 0, 1, 2000, 2, 80, 16, 10, 23, 10, 25, 10, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000015, 1, 'EQUIPMENT', 5, 1, 16109, 0, 0, 0, 0, 0, 0, 1, 2000, 2, 80, 15, 10, 16, 10, 24, 10, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000009, 1, 'EQUIPMENT', 10, 1, 13049, 0, 0, 0, 0, 0, 0, 3, 12, 27, 15, 39, 10, 48, 1, 49, 1, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000008, 1, 'INVENTORY', 1, 1, 11299, 1, 1, 1, 0, 0, 0, 1, 2000, 9, 20, 23, 10, 39, 10, 53, 50, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000009, 1, 'EQUIPMENT', 7, 1, 72702, 0, 5, 1165, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000012, 1, 'INVENTORY', 14, 1, 71124, 0, 14, 1664, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000097, 1, 'INVENTORY', 10, 1, 72730, 1, 162614, 1000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000107, 1, 'INVENTORY', 89, 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000033, 1, 'INVENTORY', 41, 1, 70058, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000098, 1, 'INVENTORY', 11, 1, 72726, 1, 399232, 10000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000168, 1, 'INVENTORY', 46, 1, 11010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000169, 1, 'INVENTORY', 47, 1, 11020, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000170, 1, 'DRAGON_SOUL_INVENTORY', 0, 1, 110230, 86400, 0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000141, 1, 'EQUIPMENT', 0, 1, 20009, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000173, 1, 'INVENTORY', 12, 200, 71084, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000167, 1, 'INVENTORY', 45, 1, 11000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000171, 1, 'INVENTORY', 48, 1, 11030, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000106, 1, 'INVENTORY', 156, 200, 27006, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000017, 1, 'INVENTORY', 44, 165, 90012, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000018, 1, 'INVENTORY', 43, 170, 90011, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000019, 1, 'INVENTORY', 42, 175, 90010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000148, 1, 'INVENTORY', 2, 1, 11971, 28443, 1, 1, 0, 0, 0, 1, 1500, 53, 15, 24, 3, 36, 10, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000104, 1, 'INVENTORY', 157, 200, 27006, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (80000019, 1, 'INVENTORY', 16, 1, 149, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000087, 1, 'SAFEBOX', 0, 1, 18089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000020, 1, 'INVENTORY', 3, 1, 12019, 28443, 1, 1, 0, 0, 0, 1, 2000, 36, 10, 38, 15, 34, 15, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000022, 1, 'INVENTORY', 4, 1, 279, 1, 1, 1, 0, 0, 0, 15, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000075, 1, 'INVENTORY', 40, 1, 50053, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000132, 1, 'INVENTORY', 13, 180, 71085, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000084, 2, 'INVENTORY', 23, 5, 76000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000075, 2, 'INVENTORY', 16, 1, 71153, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000078, 2, 'INVENTORY', 15, 12, 76003, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000074, 2, 'INVENTORY', 11, 15, 76018, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000060, 2, 'INVENTORY', 6, 5, 27054, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000059, 2, 'INVENTORY', 5, 5, 27053, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000058, 2, 'INVENTORY', 4, 10, 27052, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000093, 2, 'INVENTORY', 27, 1, 76022, 0, 0, 1000000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000094, 2, 'INVENTORY', 30, 1, 76015, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000095, 2, 'INVENTORY', 31, 3, 76010, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000096, 2, 'INVENTORY', 32, 1, 76002, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000090, 2, 'INVENTORY', 24, 1, 76005, 0, 0, 100000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000086, 2, 'INVENTORY', 22, 3, 76013, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000088, 2, 'INVENTORY', 26, 1, 76001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000087, 2, 'INVENTORY', 25, 3, 76014, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000091, 2, 'INVENTORY', 28, 3, 76020, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000083, 2, 'INVENTORY', 18, 3, 76009, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000079, 2, 'INVENTORY', 19, 20, 76007, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000081, 2, 'INVENTORY', 21, 1, 70058, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000072, 2, 'INVENTORY', 14, 1, 76011, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000063, 2, 'INVENTORY', 7, 1, 76021, 0, 0, 100000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000070, 2, 'INVENTORY', 13, 3, 76024, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000066, 2, 'INVENTORY', 1, 1, 76004, 0, 0, 10000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000067, 2, 'INVENTORY', 10, 0, 76006, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000069, 2, 'INVENTORY', 12, 3, 76023, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000076, 2, 'INVENTORY', 17, 1, 76011, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000071, 2, 'INVENTORY', 9, 5, 76016, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000056, 2, 'EQUIPMENT', 4, 1, 7000, 1, 0, 0, 0, 0, 0, 19, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000064, 2, 'INVENTORY', 8, 3, 76008, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000062, 2, 'INVENTORY', 2, 9, 76017, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000057, 2, 'INVENTORY', 3, 20, 27051, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (40000061, 2, 'INVENTORY', 0, 12, 76012, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (20000085, 1, 'EQUIPMENT', 23, 1, 18089, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (50000002, 3, 'INVENTORY', 1, 1, 50188, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (50000003, 3, 'EQUIPMENT', 4, 1, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (50000023, 3, 'INVENTORY', 0, 8, 27001, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (50000004, 3, 'INVENTORY', 3, 18, 27051, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (50000005, 3, 'INVENTORY', 4, 10, 27052, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (50000006, 3, 'INVENTORY', 5, 5, 27053, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `item` VALUES (50000007, 3, 'INVENTORY', 6, 5, 27054, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- ----------------------------
-- Table structure for item_attr
-- ----------------------------
DROP TABLE IF EXISTS `item_attr`;
CREATE TABLE `item_attr`  (
  `apply` enum('MAX_HP','MAX_SP','CON','INT','STR','DEX','ATT_SPEED','MOV_SPEED','CAST_SPEED','HP_REGEN','SP_REGEN','POISON_PCT','STUN_PCT','SLOW_PCT','CRITICAL_PCT','PENETRATE_PCT','ATTBONUS_HUMAN','ATTBONUS_ANIMAL','ATTBONUS_ORC','ATTBONUS_MILGYO','ATTBONUS_UNDEAD','ATTBONUS_DEVIL','STEAL_HP','STEAL_SP','MANA_BURN_PCT','DAMAGE_SP_RECOVER','BLOCK','DODGE','RESIST_SWORD','RESIST_TWOHAND','RESIST_DAGGER','RESIST_BELL','RESIST_FAN','RESIST_BOW','RESIST_FIRE','RESIST_ELEC','RESIST_MAGIC','RESIST_WIND','REFLECT_MELEE','REFLECT_CURSE','POISON_REDUCE','KILL_SP_RECOVER','EXP_DOUBLE_BONUS','GOLD_DOUBLE_BONUS','ITEM_DROP_BONUS','POTION_BONUS','KILL_HP_RECOVER','IMMUNE_STUN','IMMUNE_SLOW','IMMUNE_FALL','SKILL','BOW_DISTANCE','ATT_GRADE_BONUS','DEF_GRADE_BONUS','MAGIC_ATT_GRADE','MAGIC_DEF_GRADE','CURSE_PCT','MAX_STAMINA','ATTBONUS_WARRIOR','ATTBONUS_ASSASSIN','ATTBONUS_SURA','ATTBONUS_SHAMAN','ATTBONUS_MONSTER','MALL_ATTBONUS','MALL_DEFBONUS','MALL_EXPBONUS','MALL_ITEMBONUS','MALL_GOLDBONUS','MAX_HP_PCT','MAX_SP_PCT','SKILL_DAMAGE_BONUS','NORMAL_HIT_DAMAGE_BONUS','SKILL_DEFEND_BONUS','NORMAL_HIT_DEFEND_BONUS','EXTRACT_HP_PCT','RESIST_WARRIOR','RESIST_ASSASSIN','RESIST_SURA','RESIST_SHAMAN','ENERGY','DEF_GRADE','COSTUME_ATTR_BONUS','MAGIC_ATTBONUS_PER','MELEE_MAGIC_ATTBONUS_PER','RESIST_ICE','RESIST_EARTH','RESIST_DARK','ANTI_CRITICAL_PCT','ANTI_PENETRATE_PCT') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'MAX_HP',
  `prob` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv1` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv2` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv3` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv4` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv5` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `weapon` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `body` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `wrist` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `foots` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `neck` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `head` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `shield` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `ear` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of item_attr
-- ----------------------------
INSERT INTO `item_attr` VALUES ('MAX_HP', '35', '500', '500', '1000', '1500', '2000', '0', '5', '5', '5', '5', '0', '0', '0');
INSERT INTO `item_attr` VALUES ('MAX_SP', '35', '10', '20', '30', '50', '80', '0', '0', '5', '5', '5', '0', '0', '0');
INSERT INTO `item_attr` VALUES ('CON', '11', '2', '4', '6', '8', '12', '5', '0', '0', '0', '0', '0', '5', '0');
INSERT INTO `item_attr` VALUES ('INT', '11', '2', '4', '6', '8', '12', '5', '0', '0', '0', '0', '0', '5', '0');
INSERT INTO `item_attr` VALUES ('STR', '11', '2', '4', '6', '8', '12', '5', '0', '0', '0', '0', '0', '5', '0');
INSERT INTO `item_attr` VALUES ('DEX', '11', '2', '4', '6', '8', '12', '5', '0', '0', '0', '0', '0', '5', '0');
INSERT INTO `item_attr` VALUES ('ATT_SPEED', '8', '1', '2', '3', '5', '8', '0', '0', '0', '5', '0', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('MOV_SPEED', '18', '2', '4', '6', '10', '20', '0', '0', '0', '5', '0', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('CAST_SPEED', '8', '2', '4', '6', '10', '20', '5', '5', '0', '0', '0', '0', '0', '0');
INSERT INTO `item_attr` VALUES ('HP_REGEN', '60', '4', '8', '12', '20', '30', '0', '0', '0', '0', '5', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('SP_REGEN', '60', '4', '8', '12', '20', '30', '0', '0', '0', '0', '5', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('POISON_PCT', '8', '1', '2', '3', '5', '8', '5', '0', '0', '0', '0', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('STUN_PCT', '18', '1', '2', '3', '5', '8', '5', '0', '0', '5', '5', '0', '0', '0');
INSERT INTO `item_attr` VALUES ('SLOW_PCT', '35', '1', '2', '3', '5', '8', '5', '0', '0', '5', '0', '0', '0', '0');
INSERT INTO `item_attr` VALUES ('CRITICAL_PCT', '18', '1', '2', '3', '5', '10', '5', '0', '0', '5', '5', '0', '0', '0');
INSERT INTO `item_attr` VALUES ('PENETRATE_PCT', '30', '1', '2', '3', '5', '10', '5', '0', '5', '0', '5', '0', '0', '0');
INSERT INTO `item_attr` VALUES ('ATTBONUS_HUMAN', '15', '1', '2', '3', '5', '10', '5', '0', '5', '0', '0', '5', '5', '5');
INSERT INTO `item_attr` VALUES ('ATTBONUS_ANIMAL', '35', '2', '4', '6', '10', '20', '5', '0', '5', '0', '0', '5', '5', '5');
INSERT INTO `item_attr` VALUES ('ATTBONUS_ORC', '35', '2', '4', '6', '10', '20', '5', '0', '5', '0', '0', '5', '5', '5');
INSERT INTO `item_attr` VALUES ('ATTBONUS_MILGYO', '35', '2', '4', '6', '10', '20', '5', '0', '5', '0', '0', '5', '5', '5');
INSERT INTO `item_attr` VALUES ('ATTBONUS_UNDEAD', '35', '2', '4', '6', '10', '20', '5', '0', '5', '0', '0', '5', '5', '5');
INSERT INTO `item_attr` VALUES ('ATTBONUS_DEVIL', '35', '2', '4', '6', '10', '20', '5', '0', '5', '0', '0', '5', '5', '5');
INSERT INTO `item_attr` VALUES ('STEAL_HP', '50', '1', '2', '3', '5', '10', '0', '5', '5', '0', '0', '0', '0', '0');
INSERT INTO `item_attr` VALUES ('STEAL_SP', '50', '1', '2', '3', '5', '10', '0', '5', '0', '0', '5', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('MANA_BURN_PCT', '18', '1', '2', '3', '5', '10', '0', '0', '5', '0', '0', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('BLOCK', '10', '2', '4', '6', '10', '15', '0', '0', '0', '0', '0', '0', '5', '0');
INSERT INTO `item_attr` VALUES ('DODGE', '10', '2', '4', '6', '10', '15', '0', '0', '0', '5', '0', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('RESIST_SWORD', '18', '2', '4', '6', '10', '15', '0', '5', '0', '5', '5', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('RESIST_TWOHAND', '18', '2', '4', '6', '10', '15', '0', '5', '0', '5', '5', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('RESIST_DAGGER', '18', '2', '4', '6', '10', '15', '0', '5', '0', '5', '5', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('RESIST_BELL', '18', '2', '4', '6', '10', '15', '0', '5', '0', '5', '5', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('RESIST_FAN', '18', '2', '4', '6', '10', '15', '0', '5', '0', '5', '5', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('RESIST_BOW', '18', '2', '4', '6', '10', '15', '0', '5', '0', '5', '5', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('RESIST_FIRE', '18', '2', '4', '6', '10', '15', '0', '5', '5', '0', '0', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('RESIST_ELEC', '18', '2', '4', '6', '10', '15', '0', '5', '5', '0', '0', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('RESIST_MAGIC', '25', '2', '4', '6', '10', '15', '0', '5', '5', '0', '0', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('RESIST_WIND', '18', '2', '4', '6', '10', '15', '0', '5', '5', '0', '0', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('REFLECT_MELEE', '18', '1', '2', '3', '6', '10', '0', '5', '0', '0', '0', '0', '5', '0');
INSERT INTO `item_attr` VALUES ('POISON_REDUCE', '18', '1', '2', '3', '4', '5', '0', '0', '0', '0', '0', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('EXP_DOUBLE_BONUS', '10', '2', '4', '6', '8', '20', '0', '0', '0', '5', '5', '0', '5', '0');
INSERT INTO `item_attr` VALUES ('GOLD_DOUBLE_BONUS', '10', '2', '4', '6', '8', '20', '0', '0', '0', '5', '5', '0', '5', '0');
INSERT INTO `item_attr` VALUES ('ITEM_DROP_BONUS', '7', '2', '4', '6', '8', '20', '0', '0', '5', '0', '0', '0', '0', '5');
INSERT INTO `item_attr` VALUES ('IMMUNE_STUN', '3', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0');
INSERT INTO `item_attr` VALUES ('IMMUNE_SLOW', '3', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '0');
INSERT INTO `item_attr` VALUES ('ATT_GRADE_BONUS', '9', '5', '10', '15', '30', '50', '0', '5', '0', '0', '0', '0', '0', '0');
INSERT INTO `item_attr` VALUES ('RESIST_ICE', '18', '6', '8', '10', '12', '15', '0', '5', '5', '0', '0', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('RESIST_EARTH', '18', '6', '8', '10', '12', '15', '0', '5', '5', '0', '0', '5', '0', '0');
INSERT INTO `item_attr` VALUES ('RESIST_DARK', '18', '6', '8', '10', '12', '15', '0', '5', '5', '0', '0', '5', '0', '0');

-- ----------------------------
-- Table structure for item_attr_rare
-- ----------------------------
DROP TABLE IF EXISTS `item_attr_rare`;
CREATE TABLE `item_attr_rare`  (
  `apply` enum('MAX_HP','MAX_SP','CON','INT','STR','DEX','ATT_SPEED','MOV_SPEED','CAST_SPEED','HP_REGEN','SP_REGEN','POISON_PCT','STUN_PCT','SLOW_PCT','CRITICAL_PCT','PENETRATE_PCT','ATTBONUS_HUMAN','ATTBONUS_ANIMAL','ATTBONUS_ORC','ATTBONUS_MILGYO','ATTBONUS_UNDEAD','ATTBONUS_DEVIL','STEAL_HP','STEAL_SP','MANA_BURN_PCT','DAMAGE_SP_RECOVER','BLOCK','DODGE','RESIST_SWORD','RESIST_TWOHAND','RESIST_DAGGER','RESIST_BELL','RESIST_FAN','RESIST_BOW','RESIST_FIRE','RESIST_ELEC','RESIST_MAGIC','RESIST_WIND','REFLECT_MELEE','REFLECT_CURSE','POISON_REDUCE','KILL_SP_RECOVER','EXP_DOUBLE_BONUS','GOLD_DOUBLE_BONUS','ITEM_DROP_BONUS','POTION_BONUS','KILL_HP_RECOVER','IMMUNE_STUN','IMMUNE_SLOW','IMMUNE_FALL','SKILL','BOW_DISTANCE','ATT_GRADE_BONUS','DEF_GRADE_BONUS','MAGIC_ATT_GRADE','MAGIC_DEF_GRADE','CURSE_PCT','MAX_STAMINA','ATT_BONUS_TO_WARRIOR','ATT_BONUS_TO_ASSASSIN','ATT_BONUS_TO_SURA','ATT_BONUS_TO_SHAMAN','ATT_BONUS_TO_MONSTER','NORMAL_HIT_DEFEND_BONUS','SKILL_DEFEND_BONUS','NOUSE2''NOUSE3','NOUSE4','NOUSE5','NOUSE6','NOUSE7','NOUSE8','NOUSE9','NOUSE10','NOUSE11','NOUSE12','NOUSE13','NOUSE14','RESIST_WARRIOR','RESIST_ASSASSIN','RESIST_SURA','RESIST_SHAMAN') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'MAX_HP',
  `prob` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv1` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv2` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv3` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv4` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lv5` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `weapon` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `body` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `wrist` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `foots` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `neck` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `head` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `shield` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `ear` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT ''
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of item_attr_rare
-- ----------------------------
INSERT INTO `item_attr_rare` VALUES ('MAX_HP', '1', '500', '500', '500', '500', '500', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('MAX_SP', '1', '50', '50', '50', '50', '50', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('CON', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('INT', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('STR', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('DEX', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('CRITICAL_PCT', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('PENETRATE_PCT', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('ATT_GRADE_BONUS', '1', '50', '50', '50', '50', '50', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_MONSTER', '1', '10', '10', '10', '10', '10', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_WARRIOR', '1', '10', '10', '10', '10', '10', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_ASSASSIN', '1', '10', '10', '10', '10', '10', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_SURA', '1', '10', '10', '10', '10', '10', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('ATT_BONUS_TO_SHAMAN', '1', '10', '10', '10', '10', '10', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('RESIST_WARRIOR', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('RESIST_ASSASSIN', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('RESIST_SURA', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('RESIST_SHAMAN', '1', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('ATT_SPEED', '1', '2', '2', '2', '2', '2', '5', '5', '5', '5', '5', '5', '5', '5');
INSERT INTO `item_attr_rare` VALUES ('MOV_SPEED', '1', '8', '8', '8', '8', '8', '5', '5', '5', '5', '5', '5', '5', '5');

-- ----------------------------
-- Table structure for item_award
-- ----------------------------
DROP TABLE IF EXISTS `item_award`;
CREATE TABLE `item_award`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `pid` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `login` varchar(30) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `vnum` int(6) UNSIGNED NOT NULL DEFAULT 0,
  `count` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `given_time` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `taken_time` datetime NULL DEFAULT NULL,
  `item_id` int(11) NULL DEFAULT NULL,
  `why` varchar(128) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `socket0` int(11) NOT NULL DEFAULT 0,
  `socket1` int(11) NOT NULL DEFAULT 0,
  `socket2` int(11) NOT NULL DEFAULT 0,
  `mall` tinyint(1) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `pid_idx`(`pid`) USING BTREE,
  INDEX `given_time_idx`(`given_time`) USING BTREE,
  INDEX `taken_time_idx`(`taken_time`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of item_award
-- ----------------------------

-- ----------------------------
-- Table structure for item_proto
-- ----------------------------
DROP TABLE IF EXISTS `item_proto`;
CREATE TABLE `item_proto`  (
  `vnum` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `name` varbinary(24) NOT NULL DEFAULT 'Noname',
  `type` tinyint(2) NOT NULL DEFAULT 0,
  `subtype` tinyint(2) NOT NULL DEFAULT 0,
  `weight` tinyint(3) NULL DEFAULT 0,
  `size` tinyint(3) NULL DEFAULT 0,
  `antiflag` int(11) NULL DEFAULT 0,
  `flag` int(11) NULL DEFAULT 0,
  `wearflag` int(11) NULL DEFAULT 0,
  `immuneflag` set('PARA','CURSE','STUN','SLEEP','SLOW','POISON','TERROR') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `gold` int(11) NULL DEFAULT 0,
  `shop_buy_price` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `refined_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `refine_set` smallint(11) UNSIGNED NOT NULL DEFAULT 0,
  `refine_set2` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `magic_pct` tinyint(4) NOT NULL DEFAULT 0,
  `limittype0` tinyint(4) NULL DEFAULT 0,
  `limitvalue0` int(11) NULL DEFAULT 0,
  `limittype1` tinyint(4) NULL DEFAULT 0,
  `limitvalue1` int(11) NULL DEFAULT 0,
  `applytype0` tinyint(4) NULL DEFAULT 0,
  `applyvalue0` int(11) NULL DEFAULT 0,
  `applytype1` tinyint(4) NULL DEFAULT 0,
  `applyvalue1` int(11) NULL DEFAULT 0,
  `applytype2` tinyint(4) NULL DEFAULT 0,
  `applyvalue2` int(11) NULL DEFAULT 0,
  `value0` int(11) NULL DEFAULT 0,
  `value1` int(11) NULL DEFAULT 0,
  `value2` int(11) NULL DEFAULT 0,
  `value3` int(11) NULL DEFAULT 0,
  `value4` int(11) NULL DEFAULT 0,
  `value5` int(11) NULL DEFAULT 0,
  `socket0` tinyint(4) NULL DEFAULT -1,
  `socket1` tinyint(4) NULL DEFAULT -1,
  `socket2` tinyint(4) NULL DEFAULT -1,
  `socket3` tinyint(4) NULL DEFAULT -1,
  `socket4` tinyint(4) NULL DEFAULT -1,
  `socket5` tinyint(4) NULL DEFAULT -1,
  `specular` tinyint(4) NOT NULL DEFAULT 0,
  `socket_pct` tinyint(4) NOT NULL DEFAULT 0,
  `addon_type` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`vnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of item_proto
-- ----------------------------

-- ----------------------------
-- Table structure for land
-- ----------------------------
DROP TABLE IF EXISTS `land`;
CREATE TABLE `land`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `map_index` int(11) NOT NULL DEFAULT 0,
  `x` int(11) NOT NULL DEFAULT 0,
  `y` int(11) NOT NULL DEFAULT 0,
  `width` int(11) NOT NULL DEFAULT 0,
  `height` int(11) NOT NULL DEFAULT 0,
  `guild_id` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `guild_level_limit` tinyint(4) NOT NULL DEFAULT 0,
  `price` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `enable` enum('YES','NO') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NO',
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 347 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of land
-- ----------------------------
INSERT INTO `land` VALUES (1, 1, 20200, 10000, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (2, 1, 23500, 13600, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (3, 1, 27600, 10900, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (4, 1, 55600, 9600, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (5, 1, 57100, 3800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (6, 1, 60900, 5200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (7, 1, 66100, 7900, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (8, 1, 81400, 16800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (9, 1, 90700, 20400, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (10, 1, 94300, 23700, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (11, 1, 10800, 108500, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (12, 1, 5900, 108500, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (13, 1, 7700, 104300, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (14, 1, 23400, 46200, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (15, 1, 17200, 44400, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (16, 1, 20000, 40100, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (17, 1, 25800, 36900, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (18, 1, 16900, 35800, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (101, 21, 29400, 11400, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (102, 21, 33600, 12700, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (103, 21, 36300, 16300, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (104, 21, 55900, 17200, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (105, 21, 72800, 8500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (106, 21, 76300, 5400, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (107, 21, 77600, 10200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (108, 21, 84200, 47200, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (109, 21, 87800, 61000, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (110, 21, 32100, 113800, 3000, 3000, 0, 10, 45000000, 'YES');
INSERT INTO `land` VALUES (111, 21, 28800, 117200, 3000, 3000, 0, 10, 45000000, 'YES');
INSERT INTO `land` VALUES (112, 21, 24400, 118700, 3000, 3000, 0, 10, 45000000, 'YES');
INSERT INTO `land` VALUES (113, 21, 22600, 114400, 3000, 3000, 0, 10, 45000000, 'YES');
INSERT INTO `land` VALUES (114, 21, 34800, 92300, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (115, 21, 37500, 89000, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (116, 21, 35100, 73600, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (117, 21, 35400, 69200, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (118, 21, 35400, 55600, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (201, 41, 66100, 9400, 3000, 3000, 0, 10, 45000000, 'YES');
INSERT INTO `land` VALUES (202, 41, 70300, 7900, 3000, 3000, 0, 10, 45000000, 'YES');
INSERT INTO `land` VALUES (203, 41, 73600, 11500, 3000, 3000, 0, 10, 45000000, 'YES');
INSERT INTO `land` VALUES (204, 41, 70900, 15100, 3000, 3000, 0, 10, 45000000, 'YES');
INSERT INTO `land` VALUES (205, 41, 71800, 61900, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (206, 41, 77000, 64100, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (207, 41, 60700, 66800, 3000, 3000, 1, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (208, 41, 74500, 68200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (209, 41, 67900, 110800, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (210, 41, 67900, 115700, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (211, 41, 62800, 114800, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (212, 41, 16600, 95300, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (213, 41, 5400, 94100, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (214, 41, 18600, 89300, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (215, 41, 4600, 89800, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (216, 41, 11200, 36000, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (217, 41, 8200, 31800, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (218, 41, 12000, 29200, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (75, 4, 9600, 13100, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (76, 4, 16100, 15600, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (77, 4, 9100, 19500, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (78, 4, 14900, 19500, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (79, 4, 27700, 19500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (80, 4, 23600, 23000, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (81, 4, 31800, 24200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (82, 4, 27900, 27300, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (83, 4, 35500, 35400, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (84, 4, 32800, 39300, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (85, 4, 39700, 39600, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (86, 4, 36100, 42700, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (87, 4, 24400, 39000, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (88, 4, 19900, 41600, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (89, 4, 14400, 41700, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (90, 4, 10200, 39100, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (91, 4, 7700, 34600, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (92, 4, 8400, 29500, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (175, 24, 7100, 5200, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (176, 24, 12800, 4800, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (177, 24, 9700, 9900, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (178, 24, 14500, 13300, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (179, 24, 36900, 26000, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (180, 24, 38600, 29800, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (181, 24, 36500, 33900, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (182, 24, 33600, 38600, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (183, 24, 30900, 33500, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (184, 24, 25700, 33500, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (185, 24, 25600, 37800, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (186, 24, 20900, 37800, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (187, 24, 20900, 33700, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (188, 24, 14200, 33700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (189, 24, 10000, 37100, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (190, 24, 5800, 34800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (191, 24, 8800, 29800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (192, 24, 10500, 26100, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (275, 44, 5400, 7700, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (276, 44, 9700, 7300, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (277, 44, 5500, 11500, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (278, 44, 5100, 15500, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (279, 44, 8900, 17900, 3000, 3000, 0, 10, 40000000, 'YES');
INSERT INTO `land` VALUES (280, 44, 22200, 15600, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (281, 44, 43000, 3700, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (282, 44, 38900, 27200, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (283, 44, 30200, 29900, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (284, 44, 40000, 34500, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (285, 44, 32800, 37000, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (286, 44, 40600, 39300, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (287, 44, 35600, 40600, 3000, 3000, 0, 10, 50000000, 'YES');
INSERT INTO `land` VALUES (288, 44, 18500, 33600, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (289, 44, 17300, 38500, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (290, 44, 13500, 39400, 3000, 3000, 0, 10, 70000000, 'YES');
INSERT INTO `land` VALUES (291, 44, 9100, 38700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (292, 44, 5000, 36300, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (293, 6, 25700, 9100, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (294, 6, 31000, 9400, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (295, 6, 36900, 9500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (296, 6, 35300, 14300, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (297, 6, 35700, 24600, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (298, 6, 38500, 31800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (299, 6, 32600, 31200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (300, 6, 28500, 36500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (301, 6, 15500, 38000, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (302, 6, 15000, 31800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (303, 6, 10200, 36700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (304, 6, 9200, 27500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (305, 6, 11200, 19200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (306, 6, 8500, 14700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (307, 6, 10700, 10000, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (308, 6, 15200, 10100, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (309, 6, 18300, 14700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (310, 26, 25700, 9100, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (311, 26, 31000, 9400, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (312, 26, 36900, 9500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (313, 26, 35300, 14300, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (314, 26, 35700, 24600, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (315, 26, 38500, 31800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (316, 26, 32600, 31200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (317, 26, 28500, 36500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (318, 26, 15500, 38000, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (319, 26, 15000, 31800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (320, 26, 10200, 36700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (321, 26, 9200, 27500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (322, 26, 11200, 19200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (323, 26, 8500, 14700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (324, 26, 10700, 10000, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (325, 26, 15200, 10100, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (326, 26, 18300, 14700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (327, 46, 25700, 9100, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (328, 46, 31000, 9400, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (329, 46, 36900, 9500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (330, 46, 35300, 14300, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (331, 46, 35700, 24600, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (332, 46, 38500, 31800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (333, 46, 32600, 31200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (334, 46, 28500, 36500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (335, 46, 15500, 38000, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (336, 46, 15000, 31800, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (337, 46, 10200, 36700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (338, 46, 9200, 27500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (339, 46, 11200, 19200, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (340, 46, 8500, 14700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (341, 46, 10700, 10000, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (342, 46, 15200, 10100, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (343, 46, 18300, 14700, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (344, 6, 35500, 38500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (345, 26, 35500, 38500, 3000, 3000, 0, 10, 65000000, 'YES');
INSERT INTO `land` VALUES (346, 46, 35500, 38500, 3000, 3000, 0, 10, 65000000, 'YES');

-- ----------------------------
-- Table structure for marriage
-- ----------------------------
DROP TABLE IF EXISTS `marriage`;
CREATE TABLE `marriage`  (
  `is_married` tinyint(4) NOT NULL DEFAULT 0,
  `pid1` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `pid2` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `love_point` int(11) UNSIGNED NULL DEFAULT NULL,
  `time` int(10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`pid1`, `pid2`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of marriage
-- ----------------------------

-- ----------------------------
-- Table structure for messenger_list
-- ----------------------------
DROP TABLE IF EXISTS `messenger_list`;
CREATE TABLE `messenger_list`  (
  `account` varchar(16) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `companion` varchar(16) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  PRIMARY KEY (`account`, `companion`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of messenger_list
-- ----------------------------
INSERT INTO `messenger_list` VALUES ('Test', '[SA]Admin');
INSERT INTO `messenger_list` VALUES ('[SA]Admin', 'Test');

-- ----------------------------
-- Table structure for mob_proto
-- ----------------------------
DROP TABLE IF EXISTS `mob_proto`;
CREATE TABLE `mob_proto`  (
  `vnum` int(11) NOT NULL DEFAULT 0,
  `name` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'Noname',
  `rank` tinyint(2) NOT NULL DEFAULT 0,
  `type` tinyint(2) NOT NULL DEFAULT 0,
  `battle_type` tinyint(1) NOT NULL DEFAULT 0,
  `level` smallint(3) NOT NULL DEFAULT 1,
  `size` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `ai_flag` set('AGGR','NOMOVE','COWARD','NOATTSHINSU','NOATTCHUNJO','NOATTJINNO','ATTMOB','BERSERK','STONESKIN','GODSPEED','DEATHBLOW','REVIVE') CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `mount_capacity` tinyint(2) NOT NULL DEFAULT 0,
  `setRaceFlag` set('ANIMAL','UNDEAD','DEVIL','HUMAN','ORC','MILGYO','INSECT','FIRE','ICE','DESERT','TREE','ATT_ELEC','ATT_FIRE','ATT_ICE','ATT_WIND','ATT_EARTH','ATT_DARK') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `setImmuneFlag` set('STUN','SLOW','FALL','CURSE','POISON','TERROR') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `empire` tinyint(4) NOT NULL DEFAULT 0,
  `folder` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `on_click` tinyint(4) NOT NULL DEFAULT 0,
  `st` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `dx` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `ht` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `iq` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `damage_min` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `damage_max` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `max_hp` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `regen_cycle` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `regen_percent` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `gold_min` int(11) NOT NULL DEFAULT 0,
  `gold_max` int(11) NOT NULL DEFAULT 0,
  `exp` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `def` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `attack_speed` smallint(6) UNSIGNED NOT NULL DEFAULT 100,
  `move_speed` smallint(6) UNSIGNED NOT NULL DEFAULT 100,
  `aggressive_hp_pct` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `aggressive_sight` smallint(10) UNSIGNED NOT NULL DEFAULT 0,
  `attack_range` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `drop_item` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `resurrection_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_curse` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_slow` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_poison` tinyint(4) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_stun` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_critical` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `enchant_penetrate` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `resist_sword` tinyint(4) NOT NULL DEFAULT 0,
  `resist_twohand` tinyint(4) NOT NULL DEFAULT 0,
  `resist_dagger` tinyint(4) NOT NULL DEFAULT 0,
  `resist_bell` tinyint(4) NOT NULL DEFAULT 0,
  `resist_fan` tinyint(4) NOT NULL DEFAULT 0,
  `resist_bow` tinyint(4) NOT NULL DEFAULT 0,
  `resist_fire` tinyint(4) NOT NULL DEFAULT 0,
  `resist_elect` tinyint(4) NOT NULL DEFAULT 0,
  `resist_magic` tinyint(4) NOT NULL DEFAULT 0,
  `resist_wind` tinyint(4) NOT NULL DEFAULT 0,
  `resist_poison` tinyint(4) NOT NULL DEFAULT 0,
  `dam_multiply` float NULL DEFAULT NULL,
  `summon` int(11) NULL DEFAULT NULL,
  `drain_sp` int(11) NULL DEFAULT NULL,
  `mob_color` int(10) UNSIGNED NULL DEFAULT NULL,
  `polymorph_item` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `skill_level0` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum0` int(10) UNSIGNED NULL DEFAULT NULL,
  `skill_level1` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum1` int(10) UNSIGNED NULL DEFAULT NULL,
  `skill_level2` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum2` int(10) UNSIGNED NULL DEFAULT NULL,
  `skill_level3` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum3` int(10) UNSIGNED NULL DEFAULT NULL,
  `skill_level4` tinyint(3) UNSIGNED NULL DEFAULT NULL,
  `skill_vnum4` int(10) UNSIGNED NULL DEFAULT NULL,
  `sp_berserk` tinyint(4) NOT NULL DEFAULT 0,
  `sp_stoneskin` tinyint(4) NOT NULL DEFAULT 0,
  `sp_godspeed` tinyint(4) NOT NULL DEFAULT 0,
  `sp_deathblow` tinyint(4) NOT NULL DEFAULT 0,
  `sp_revive` tinyint(4) NOT NULL DEFAULT 0,
  PRIMARY KEY (`vnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of mob_proto
-- ----------------------------

-- ----------------------------
-- Table structure for monarch
-- ----------------------------
DROP TABLE IF EXISTS `monarch`;
CREATE TABLE `monarch`  (
  `empire` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `pid` int(10) UNSIGNED NULL DEFAULT NULL,
  `windate` datetime NULL DEFAULT NULL,
  `money` bigint(20) UNSIGNED NULL DEFAULT NULL,
  PRIMARY KEY (`empire`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of monarch
-- ----------------------------

-- ----------------------------
-- Table structure for monarch_candidacy
-- ----------------------------
DROP TABLE IF EXISTS `monarch_candidacy`;
CREATE TABLE `monarch_candidacy`  (
  `pid` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `date` datetime NULL DEFAULT '0000-00-00 00:00:00',
  `name` varchar(16) CHARACTER SET big5 COLLATE big5_chinese_ci NULL DEFAULT NULL,
  `windate` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`pid`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = big5 COLLATE = big5_chinese_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of monarch_candidacy
-- ----------------------------

-- ----------------------------
-- Table structure for monarch_election
-- ----------------------------
DROP TABLE IF EXISTS `monarch_election`;
CREATE TABLE `monarch_election`  (
  `pid` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `selectedpid` int(10) UNSIGNED NULL DEFAULT 0,
  `electiondata` datetime NULL DEFAULT '0000-00-00 00:00:00',
  PRIMARY KEY (`pid`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of monarch_election
-- ----------------------------

-- ----------------------------
-- Table structure for myshop_pricelist
-- ----------------------------
DROP TABLE IF EXISTS `myshop_pricelist`;
CREATE TABLE `myshop_pricelist`  (
  `owner_id` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `item_vnum` int(11) UNSIGNED NOT NULL DEFAULT 0,
  `price` int(10) UNSIGNED NOT NULL DEFAULT 0,
  UNIQUE INDEX `list_id`(`owner_id`, `item_vnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of myshop_pricelist
-- ----------------------------

-- ----------------------------
-- Table structure for object
-- ----------------------------
DROP TABLE IF EXISTS `object`;
CREATE TABLE `object`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `land_id` int(11) NOT NULL DEFAULT 0,
  `vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `map_index` int(11) NOT NULL DEFAULT 0,
  `x` int(11) NOT NULL DEFAULT 0,
  `y` int(11) NOT NULL DEFAULT 0,
  `x_rot` float NOT NULL DEFAULT 0,
  `y_rot` float NOT NULL DEFAULT 0,
  `z_rot` float NOT NULL DEFAULT 0,
  `life` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 5 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of object
-- ----------------------------
INSERT INTO `object` VALUES (1, 207, 14100, 41, 984651, 272853, 0, 0, 268, 0);
INSERT INTO `object` VALUES (2, 207, 14013, 41, 984679, 272159, 0, 0, 265, 0);
INSERT INTO `object` VALUES (3, 207, 14063, 41, 984571, 273437, 0, 0, 268, 0);
INSERT INTO `object` VALUES (4, 207, 26992, 41, 984665, 274081, 0, 0, 268, 0);

-- ----------------------------
-- Table structure for object_proto
-- ----------------------------
DROP TABLE IF EXISTS `object_proto`;
CREATE TABLE `object_proto`  (
  `vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `price` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `materials` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `upgrade_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `upgrade_limit_time` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `life` int(11) NOT NULL DEFAULT 0,
  `reg_1` int(11) NOT NULL DEFAULT 0,
  `reg_2` int(11) NOT NULL DEFAULT 0,
  `reg_3` int(11) NOT NULL DEFAULT 0,
  `reg_4` int(11) NOT NULL DEFAULT 0,
  `npc` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `group_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `dependent_group` int(10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`vnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of object_proto
-- ----------------------------
INSERT INTO `object_proto` VALUES (14013, '?? ???', 20000000, '90010,20/90011,30/90012,20', 0, 0, 0, -213, -213, 213, 213, 20044, 2, 1);
INSERT INTO `object_proto` VALUES (14014, '??? ???', 20000000, '90010,20/90011,30/90012,20', 0, 0, 0, -213, -213, 213, 213, 20045, 2, 1);
INSERT INTO `object_proto` VALUES (14015, '???? ???', 20000000, '90010,20/90011,30/90012,20', 0, 0, 0, -213, -213, 213, 213, 20046, 2, 1);
INSERT INTO `object_proto` VALUES (14043, '????? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20060, 3, 1);
INSERT INTO `object_proto` VALUES (14045, '??? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20062, 3, 1);
INSERT INTO `object_proto` VALUES (14046, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20063, 3, 1);
INSERT INTO `object_proto` VALUES (14047, '? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20064, 3, 1);
INSERT INTO `object_proto` VALUES (14048, '? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20065, 3, 1);
INSERT INTO `object_proto` VALUES (14049, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20066, 3, 1);
INSERT INTO `object_proto` VALUES (14050, '??? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20067, 3, 1);
INSERT INTO `object_proto` VALUES (14051, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20068, 3, 1);
INSERT INTO `object_proto` VALUES (14052, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20069, 3, 1);
INSERT INTO `object_proto` VALUES (14053, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20070, 3, 1);
INSERT INTO `object_proto` VALUES (14054, '??? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20071, 3, 1);
INSERT INTO `object_proto` VALUES (14055, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 20072, 3, 1);
INSERT INTO `object_proto` VALUES (14061, '?? ??', 25000000, '90010,25/90011,25/90012,25', 0, 0, 0, -112, -298, 114, 225, 20077, 4, 1);
INSERT INTO `object_proto` VALUES (14062, '?? ??', 500000000, '90010,50/90011,50/90012,50', 0, 0, 0, -112, -298, 114, 225, 20078, 4, 4);
INSERT INTO `object_proto` VALUES (14063, '?? ??', 750000000, '90010,75/90011,75/90012,75', 0, 0, 0, -112, -298, 114, 225, 20079, 4, 4);
INSERT INTO `object_proto` VALUES (14100, '?(1)', 20000000, '90010,20/90011,30/90012,25', 0, 0, 0, -279, -347, 294, 325, 0, 1, 0);
INSERT INTO `object_proto` VALUES (14110, '?(2)', 20000000, '90010,20/90011,30/90012,25', 0, 0, 0, -279, -347, 294, 325, 0, 1, 0);
INSERT INTO `object_proto` VALUES (14120, '?(3)', 20000000, '90010,20/90011,30/90012,25', 0, 0, 0, -279, -347, 294, 325, 0, 1, 0);
INSERT INTO `object_proto` VALUES (14141, 'Wooden Wall 1', 800000, '90010,5/90011,15/90012,15', 0, 0, 0, -2, -40, 174, 40, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14142, 'Wooden Wall 2', 500000, '90010,5/90011,15/90012,15', 0, 0, 0, -36, -36, 36, 36, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14143, 'Wooden Wall 3', 800000, '90010,5/90011,15/90012,15', 0, 0, 0, -195, -52, 2, 52, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14144, 'Wooden Gate', 500000, '90010,5/90011,20/90012,20', 0, 0, 0, -1, -96, 348, 96, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14200, '?? ??', 3000000, '90011,5/90012,5', 0, 0, 0, -23, -5, 21, 20, 0, 0, 1);
INSERT INTO `object_proto` VALUES (14300, '?1', 300000, '90010,5', 0, 0, 0, -58, -59, 58, 59, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14301, '?2', 300000, '90010,5', 0, 0, 0, -59, -66, 59, 66, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14302, '?3', 300000, '90010,7', 0, 0, 0, -67, -51, 67, 51, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14303, '?4', 300000, '90010,7', 0, 0, 0, -52, -59, 52, 59, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14304, '?5', 300000, '90010,7', 0, 0, 0, -86, -73, 86, 73, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14305, '?6', 300000, '90010,8', 0, 0, 0, -96, -101, 96, 101, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14306, '?7', 300000, '90010,8', 0, 0, 0, -92, -92, 92, 92, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14307, '?8', 300000, '90010,8', 0, 0, 0, -33, -28, 33, 28, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14308, '?9', 300000, '90010,9', 0, 0, 0, -33, -27, 33, 27, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14309, '?10', 300000, '90010,9', 0, 0, 0, -91, -62, 91, 62, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14400, '??1', 2000000, '90011,5', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14401, '??2', 2000000, '90011,5', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14402, '??3', 2000000, '90011,7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14403, '??4', 2000000, '90011,7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14404, '??5', 2000000, '90011,7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14405, '??6', 2000000, '90011,9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14406, '??7', 2000000, '90011,9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14407, '??8', 2000000, '90011,9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto` VALUES (14408, '??9', 2000000, '90011,9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto` VALUES (26992, 'asd5', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 33009, 3, 1);
INSERT INTO `object_proto` VALUES (26993, 'asd4', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 33010, 3, 1);
INSERT INTO `object_proto` VALUES (26994, 'asd3', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 33011, 3, 1);
INSERT INTO `object_proto` VALUES (26995, 'asd2', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 33012, 3, 1);
INSERT INTO `object_proto` VALUES (26996, 'asd1', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -90, -100, 90, 100, 33013, 3, 1);

-- ----------------------------
-- Table structure for object_proto_original
-- ----------------------------
DROP TABLE IF EXISTS `object_proto_original`;
CREATE TABLE `object_proto_original`  (
  `vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `price` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `materials` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `upgrade_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `upgrade_limit_time` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `life` int(11) NOT NULL DEFAULT 0,
  `reg_1` int(11) NOT NULL DEFAULT 0,
  `reg_2` int(11) NOT NULL DEFAULT 0,
  `reg_3` int(11) NOT NULL DEFAULT 0,
  `reg_4` int(11) NOT NULL DEFAULT 0,
  `npc` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `group_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `dependent_group` int(10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`vnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of object_proto_original
-- ----------------------------
INSERT INTO `object_proto_original` VALUES (14013, '?? ???', 20000000, '90010,20/90011,30/90012,20', 0, 0, 0, -425, -425, 425, 425, 20044, 2, 1);
INSERT INTO `object_proto_original` VALUES (14014, '??? ???', 20000000, '90010,20/90011,30/90012,20', 0, 0, 0, -425, -425, 425, 425, 20045, 2, 1);
INSERT INTO `object_proto_original` VALUES (14015, '???? ???', 20000000, '90010,20/90011,30/90012,20', 0, 0, 0, -425, -425, 425, 425, 20046, 2, 1);
INSERT INTO `object_proto_original` VALUES (14043, '????? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20060, 3, 1);
INSERT INTO `object_proto_original` VALUES (14045, '??? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20062, 3, 1);
INSERT INTO `object_proto_original` VALUES (14046, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20063, 3, 1);
INSERT INTO `object_proto_original` VALUES (14047, '? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20064, 3, 1);
INSERT INTO `object_proto_original` VALUES (14048, '? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20065, 3, 1);
INSERT INTO `object_proto_original` VALUES (14049, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20066, 3, 1);
INSERT INTO `object_proto_original` VALUES (14050, '??? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20067, 3, 1);
INSERT INTO `object_proto_original` VALUES (14051, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20068, 3, 1);
INSERT INTO `object_proto_original` VALUES (14052, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20069, 3, 1);
INSERT INTO `object_proto_original` VALUES (14053, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20070, 3, 1);
INSERT INTO `object_proto_original` VALUES (14054, '??? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20071, 3, 1);
INSERT INTO `object_proto_original` VALUES (14055, '?? ???', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 20072, 3, 1);
INSERT INTO `object_proto_original` VALUES (14061, '?? ??', 25000000, '90010,25/90011,25/90012,25', 0, 0, 0, -223, -595, 227, 450, 20077, 4, 1);
INSERT INTO `object_proto_original` VALUES (14062, '?? ??', 500000000, '90010,50/90011,50/90012,50', 0, 0, 0, -223, -595, 227, 450, 20078, 4, 4);
INSERT INTO `object_proto_original` VALUES (14063, '?? ??', 750000000, '90010,75/90011,75/90012,75', 0, 0, 0, -223, -595, 227, 450, 20079, 4, 4);
INSERT INTO `object_proto_original` VALUES (14100, '?(1)', 20000000, '90010,20/90011,30/90012,25', 0, 0, 0, -558, -694, 587, 649, 0, 1, 0);
INSERT INTO `object_proto_original` VALUES (14110, '?(2)', 20000000, '90010,20/90011,30/90012,25', 0, 0, 0, -558, -694, 587, 649, 0, 1, 0);
INSERT INTO `object_proto_original` VALUES (14120, '?(3)', 20000000, '90010,20/90011,30/90012,25', 0, 0, 0, -558, -694, 587, 649, 0, 1, 0);
INSERT INTO `object_proto_original` VALUES (14141, 'Wooden Wall 1', 800000, '90010,5/90011,15/90012,15', 0, 0, 0, -3, -79, 348, 79, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14142, 'Wooden Wall 2', 500000, '90010,5/90011,15/90012,15', 0, 0, 0, -72, -71, 72, 71, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14143, 'Wooden Wall 3', 800000, '90010,5/90011,15/90012,15', 0, 0, 0, -390, -104, 4, 104, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14144, 'Wooden Gate', 500000, '90010,5/90011,20/90012,20', 0, 0, 0, -2, -192, 695, 192, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14200, '?? ??', 3000000, '90011,5/90012,5', 0, 0, 0, -45, -9, 42, 40, 0, 0, 1);
INSERT INTO `object_proto_original` VALUES (14300, '?1', 300000, '90010,5', 0, 0, 0, -116, -118, 116, 118, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14301, '?2', 300000, '90010,5', 0, 0, 0, -118, -132, 118, 132, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14302, '?3', 300000, '90010,7', 0, 0, 0, -133, -102, 133, 102, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14303, '?4', 300000, '90010,7', 0, 0, 0, -104, -117, 104, 117, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14304, '?5', 300000, '90010,7', 0, 0, 0, -171, -145, 171, 145, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14305, '?6', 300000, '90010,8', 0, 0, 0, -192, -201, 192, 201, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14306, '?7', 300000, '90010,8', 0, 0, 0, -183, -184, 183, 184, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14307, '?8', 300000, '90010,8', 0, 0, 0, -66, -56, 66, 56, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14308, '?9', 300000, '90010,9', 0, 0, 0, -65, -53, 65, 53, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14309, '?10', 300000, '90010,9', 0, 0, 0, -182, -123, 182, 123, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14400, '??1', 2000000, '90011,5', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14401, '??2', 2000000, '90011,5', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14402, '??3', 2000000, '90011,7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14403, '??4', 2000000, '90011,7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14404, '??5', 2000000, '90011,7', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14405, '??6', 2000000, '90011,9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14406, '??7', 2000000, '90011,9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14407, '??8', 2000000, '90011,9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (14408, '??9', 2000000, '90011,9', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `object_proto_original` VALUES (26992, 'asd5', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 33009, 3, 1);
INSERT INTO `object_proto_original` VALUES (26993, 'asd4', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 33010, 3, 1);
INSERT INTO `object_proto_original` VALUES (26994, 'asd3', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 33011, 3, 1);
INSERT INTO `object_proto_original` VALUES (26995, 'asd2', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 33012, 3, 1);
INSERT INTO `object_proto_original` VALUES (26996, 'asd1', 20000000, '90010,15/90011,20/90012,25', 0, 0, 0, -179, -199, 179, 199, 33013, 3, 1);

-- ----------------------------
-- Table structure for player
-- ----------------------------
DROP TABLE IF EXISTS `player`;
CREATE TABLE `player`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `account_id` int(11) NOT NULL DEFAULT 0,
  `name` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NONAME',
  `job` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `voice` tinyint(1) UNSIGNED NOT NULL DEFAULT 0,
  `dir` tinyint(2) NOT NULL DEFAULT 0,
  `x` int(11) NOT NULL DEFAULT 0,
  `y` int(11) NOT NULL DEFAULT 0,
  `z` int(11) NOT NULL DEFAULT 0,
  `map_index` int(11) NOT NULL DEFAULT 0,
  `exit_x` int(11) NOT NULL DEFAULT 0,
  `exit_y` int(11) NOT NULL DEFAULT 0,
  `exit_map_index` int(11) NOT NULL DEFAULT 0,
  `hp` smallint(4) NOT NULL DEFAULT 0,
  `mp` smallint(4) NOT NULL DEFAULT 0,
  `stamina` smallint(6) NOT NULL DEFAULT 0,
  `random_hp` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `random_sp` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `playtime` int(11) NOT NULL DEFAULT 0,
  `level` tinyint(2) UNSIGNED NOT NULL DEFAULT 1,
  `level_step` tinyint(1) NOT NULL DEFAULT 0,
  `st` smallint(3) NOT NULL DEFAULT 0,
  `ht` smallint(3) NOT NULL DEFAULT 0,
  `dx` smallint(3) NOT NULL DEFAULT 0,
  `iq` smallint(3) NOT NULL DEFAULT 0,
  `exp` int(11) NOT NULL DEFAULT 0,
  `gold` int(11) NOT NULL DEFAULT 0,
  `stat_point` smallint(3) NOT NULL DEFAULT 0,
  `skill_point` smallint(3) NOT NULL DEFAULT 0,
  `quickslot` tinyblob NULL,
  `ip` varchar(15) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '0.0.0.0',
  `part_main` int(11) NOT NULL DEFAULT 0,
  `part_base` int(11) NOT NULL DEFAULT 0,
  `part_hair` int(11) NOT NULL DEFAULT 0,
  `skill_group` tinyint(4) NOT NULL DEFAULT 0,
  `skill_level` blob NULL,
  `alignment` int(11) NOT NULL DEFAULT 0,
  `last_play` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `change_name` tinyint(1) NOT NULL DEFAULT 0,
  `sub_skill_point` smallint(3) NOT NULL DEFAULT 0,
  `stat_reset_count` tinyint(4) NOT NULL DEFAULT 0,
  `horse_hp` smallint(4) NOT NULL DEFAULT 0,
  `horse_stamina` smallint(4) NOT NULL DEFAULT 0,
  `horse_level` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `horse_hp_droptime` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `horse_riding` tinyint(1) NOT NULL DEFAULT 0,
  `horse_skill_point` smallint(3) NOT NULL DEFAULT 0,
  `bank_value` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `account_id_idx`(`account_id`) USING BTREE,
  INDEX `name_idx`(`name`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 4 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of player
-- ----------------------------
INSERT INTO `player` VALUES (1, 1, '[SA]Admin', 0, 0, 0, 960339, 266987, 0, 41, 960339, 266987, 41, 13648, 760, 1330, 500, 0, 2355, 105, 0, 90, 90, 90, 15, 0, 1352360737, 0, 104, 0x020202030205020402010000010A010B0209020B020D0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, '192.168.1.3', 20009, 0, 0, 2, 0x000000000000032800000000032800000000032800000000032800000000032800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000032847930D61032800000000032800000000032800000000032800000000032800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000032800000000000200000000000000000000032800000000000000000000032800000000032800000000032800000000032800000000011500000000032800000000000000000000000000000000000000000000000000000000000000000000011400000000011400000000011400000000011400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000032800000000032800000000032800000000032800000000032800000000032800000000032800000000032800000000032800000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 191668, '2025-09-18 20:04:24', 0, 46, 0, 0, 120, 21, 1635966330, 0, 0, 0);
INSERT INTO `player` VALUES (2, 2, 'Test', 7, 0, 0, 959425, 270013, 0, 41, 959425, 270013, 41, 5117, 2399, 820, 4257, 2079, 152, 100, 0, 3, 4, 3, 6, 0, 12099120, 267, 0, 0x010300000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, '192.168.1.3', 0, 0, 0, 0, 0x000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 610, '2025-09-18 16:00:27', 0, 91, 0, 0, 0, 0, 0, 0, 0, 0);
INSERT INTO `player` VALUES (3, 1, 'Sura', 2, 0, 0, 958052, 250798, 0, 41, 958052, 250798, 41, 811, 380, 815, 41, 20, 3, 2, 0, 5, 3, 3, 8, 18, 0, 0, 0, 0x010300000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, '192.168.1.3', 1, 1, 0, 0, 0x000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000, 57, '2025-09-18 20:01:12', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

-- ----------------------------
-- Table structure for player_deleted
-- ----------------------------
DROP TABLE IF EXISTS `player_deleted`;
CREATE TABLE `player_deleted`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `account_id` int(11) NOT NULL DEFAULT 0,
  `name` varchar(24) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NONAME',
  `job` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `voice` tinyint(1) UNSIGNED NOT NULL DEFAULT 0,
  `dir` tinyint(2) NOT NULL DEFAULT 0,
  `x` int(11) NOT NULL DEFAULT 0,
  `y` int(11) NOT NULL DEFAULT 0,
  `z` int(11) NOT NULL DEFAULT 0,
  `map_index` int(11) NOT NULL DEFAULT 0,
  `exit_x` int(11) NOT NULL DEFAULT 0,
  `exit_y` int(11) NOT NULL DEFAULT 0,
  `exit_map_index` int(11) NOT NULL DEFAULT 0,
  `hp` smallint(4) NOT NULL DEFAULT 0,
  `mp` smallint(4) NOT NULL DEFAULT 0,
  `stamina` smallint(6) NOT NULL DEFAULT 0,
  `random_hp` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `random_sp` smallint(5) UNSIGNED NOT NULL DEFAULT 0,
  `playtime` int(11) NOT NULL DEFAULT 0,
  `level` tinyint(2) UNSIGNED NOT NULL DEFAULT 1,
  `level_step` tinyint(1) NOT NULL DEFAULT 0,
  `st` smallint(3) NOT NULL DEFAULT 0,
  `ht` smallint(3) NOT NULL DEFAULT 0,
  `dx` smallint(3) NOT NULL DEFAULT 0,
  `iq` smallint(3) NOT NULL DEFAULT 0,
  `exp` int(11) NOT NULL DEFAULT 0,
  `gold` int(11) NOT NULL DEFAULT 0,
  `stat_point` smallint(3) NOT NULL DEFAULT 0,
  `skill_point` smallint(3) NOT NULL DEFAULT 0,
  `quickslot` tinyblob NULL,
  `ip` varchar(15) CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT '0.0.0.0',
  `part_main` mediumint(6) NOT NULL DEFAULT 0,
  `part_base` tinyint(4) NOT NULL DEFAULT 0,
  `part_hair` mediumint(4) NOT NULL DEFAULT 0,
  `skill_group` tinyint(4) NOT NULL DEFAULT 0,
  `skill_level` blob NULL,
  `alignment` int(11) NOT NULL DEFAULT 0,
  `last_play` datetime NOT NULL DEFAULT '0000-00-00 00:00:00',
  `change_name` tinyint(1) NOT NULL DEFAULT 0,
  `sub_skill_point` smallint(3) NOT NULL DEFAULT 0,
  `stat_reset_count` tinyint(4) NOT NULL DEFAULT 0,
  `horse_hp` smallint(4) NOT NULL DEFAULT 0,
  `horse_stamina` smallint(4) NOT NULL DEFAULT 0,
  `horse_level` tinyint(2) UNSIGNED NOT NULL DEFAULT 0,
  `horse_hp_droptime` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `horse_riding` tinyint(1) NOT NULL DEFAULT 0,
  `horse_skill_point` smallint(3) NOT NULL DEFAULT 0,
  `bank_value` int(11) NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `account_id_idx`(`account_id`) USING BTREE,
  INDEX `name_idx`(`name`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 1 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of player_deleted
-- ----------------------------

-- ----------------------------
-- Table structure for player_index
-- ----------------------------
DROP TABLE IF EXISTS `player_index`;
CREATE TABLE `player_index`  (
  `id` int(11) NOT NULL DEFAULT 0,
  `pid1` int(11) NOT NULL DEFAULT 0,
  `pid2` int(11) NOT NULL DEFAULT 0,
  `pid3` int(11) NOT NULL DEFAULT 0,
  `pid4` int(11) NOT NULL DEFAULT 0,
  `empire` tinyint(4) NOT NULL DEFAULT 0,
  PRIMARY KEY (`id`) USING BTREE,
  INDEX `pid1_key`(`pid1`) USING BTREE,
  INDEX `pid2_key`(`pid2`) USING BTREE,
  INDEX `pid3_key`(`pid3`) USING BTREE,
  INDEX `pid4_key`(`pid4`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of player_index
-- ----------------------------
INSERT INTO `player_index` VALUES (1, 1, 3, 0, 0, 3);
INSERT INTO `player_index` VALUES (2, 2, 0, 0, 0, 3);

-- ----------------------------
-- Table structure for quest
-- ----------------------------
DROP TABLE IF EXISTS `quest`;
CREATE TABLE `quest`  (
  `dwPID` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `szName` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szState` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `lValue` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`dwPID`, `szName`, `szState`) USING BTREE,
  INDEX `pid_idx`(`dwPID`) USING BTREE,
  INDEX `name_idx`(`szName`) USING BTREE,
  INDEX `state_idx`(`szState`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of quest
-- ----------------------------
INSERT INTO `quest` VALUES (0, 'oxevent_status', '', 0);
INSERT INTO `quest` VALUES (1, 'check_trans_ticket', '__status', 526282696);
INSERT INTO `quest` VALUES (1, 'event_mystery_box', '__status', -163855020);
INSERT INTO `quest` VALUES (1, 'find_senior_soldier', 'Ziel_Beding', 16);
INSERT INTO `quest` VALUES (1, 'find_senior_soldier', '__NEXT_TIME__', 1626464064);
INSERT INTO `quest` VALUES (1, 'give_basic_weapon', 'basic_weapon', 1);
INSERT INTO `quest` VALUES (1, 'harvest_festival', '__status', 695801987);
INSERT INTO `quest` VALUES (1, 'main_quest_lv1', '__status', -1147521841);
INSERT INTO `quest` VALUES (1, 'patrol_townaround', '__status', -906855452);
INSERT INTO `quest` VALUES (1, 'collect_quest_lv30', '__status', 695801987);
INSERT INTO `quest` VALUES (1, 'dragon_lair_weekly', '__status', 1929663828);
INSERT INTO `quest` VALUES (1, 'heavens_cave_escape', '__status', 295196323);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'heavens_cave_keyquest_CooldownTime', 86400);
INSERT INTO `quest` VALUES (1, 'main_quest_lv90', '__status', 1390588616);
INSERT INTO `quest` VALUES (1, 'new_quest_lv22', '__status', 695801987);
INSERT INTO `quest` VALUES (1, 'new_quest_lv26', '__status', -880201385);
INSERT INTO `quest` VALUES (1, 'new_quest_lv28', '__status', 695801987);
INSERT INTO `quest` VALUES (1, 'new_quest_lv29', '__status', -603704530);
INSERT INTO `quest` VALUES (1, 'new_quest_lv29', 'dropProb', 80);
INSERT INTO `quest` VALUES (1, 'new_quest_lv29', 'hayFromHarang', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv29', 'hayFromStablemaster', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv29', 'hayFromTaurean', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv29', 'hayIndex', 6);
INSERT INTO `quest` VALUES (1, 'new_quest_lv29', 'yonahspatience', 2);
INSERT INTO `quest` VALUES (1, 'new_quest_lv42', '__status', 695801987);
INSERT INTO `quest` VALUES (1, 'new_quest_lv43', '__status', 695801987);
INSERT INTO `quest` VALUES (1, 'new_quest_lv43', 'collect_count_1', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv52', '__status', 574123079);
INSERT INTO `quest` VALUES (1, 'new_quest_lv52', 'ghostsleft', 4);
INSERT INTO `quest` VALUES (1, 'new_quest_lv54', '__status', -2033559367);
INSERT INTO `quest` VALUES (1, 'new_quest_lv75', '__status', -1227866427);
INSERT INTO `quest` VALUES (1, 'new_quest_lv75', 'suraskel0', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv75', 'suraskel1', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv75', 'suraskel2', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv75', 'suraskel3', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv75', 'suraskel4', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv80', '__status', -1153682316);
INSERT INTO `quest` VALUES (1, 'new_quest_lv80', 'gotreward', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv80', 'notenchanted', 1);
INSERT INTO `quest` VALUES (1, 'new_quest_lv80', 'spawnsleft', 10);
INSERT INTO `quest` VALUES (1, 'new_quest_premium_lv4', '__status', -752091884);
INSERT INTO `quest` VALUES (1, 'new_quest_premium_lv4', 'amountXp', 1000);
INSERT INTO `quest` VALUES (1, 'new_quest_premium_lv4', 'amountYang', 500);
INSERT INTO `quest` VALUES (1, 'new_quest_premium_lv4', 'drop1', 50705);
INSERT INTO `quest` VALUES (1, 'new_quest_premium_lv4', 'drop2', 30177);
INSERT INTO `quest` VALUES (1, 'new_quest_premium_lv4', 'dropProb1', 40);
INSERT INTO `quest` VALUES (1, 'new_quest_premium_lv4', 'mob1', 104);
INSERT INTO `quest` VALUES (1, 'new_quest_premium_lv4', 'neededAmountDrop1', 2);
INSERT INTO `quest` VALUES (1, 'new_quest_premium_lv4', 'neededAmountDrop2', 1);
INSERT INTO `quest` VALUES (1, 'training_grandmaster_skill', 'skill16', 1);
INSERT INTO `quest` VALUES (1, 'alter_of_power', 'build_level', 20);
INSERT INTO `quest` VALUES (0, 'xmas_boom', '', 2);
INSERT INTO `quest` VALUES (0, 'ox_map_login_counter', '', 2);
INSERT INTO `quest` VALUES (1, 'oxevent_manager', 'ox_end_cooldown_time', 1636197933);
INSERT INTO `quest` VALUES (2, 'check_trans_ticket', '__status', 526282696);
INSERT INTO `quest` VALUES (1, 'fortune_telling', 'time', 1626493288);
INSERT INTO `quest` VALUES (1, 'fortune_telling', 'idx', 4);
INSERT INTO `quest` VALUES (1, 'training_grandmaster_skill', 'next_time', 1628289515);
INSERT INTO `quest` VALUES (1, 'dragon_soul', '__status', -252263835);
INSERT INTO `quest` VALUES (0, 'ds_drop', '', 10);
INSERT INTO `quest` VALUES (2, 'collect_quest_lv30', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'dragon_lair_weekly', '__status', 1929663828);
INSERT INTO `quest` VALUES (2, 'give_basic_weapon', 'basic_weapon', 1);
INSERT INTO `quest` VALUES (2, 'harvest_festival', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'heavens_cave_escape', '__status', 295196323);
INSERT INTO `quest` VALUES (2, 'heavens_cave_keyquest', 'heavens_cave_keyquest_CooldownTime', 3600);
INSERT INTO `quest` VALUES (2, 'main_quest_lv90', '__status', 1390588616);
INSERT INTO `quest` VALUES (2, 'new_quest_lv22', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'new_quest_lv26', '__status', -880201385);
INSERT INTO `quest` VALUES (2, 'new_quest_lv28', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'new_quest_lv29', '__status', -603704530);
INSERT INTO `quest` VALUES (2, 'new_quest_lv29', 'dropProb', 80);
INSERT INTO `quest` VALUES (2, 'new_quest_lv29', 'hayFromHarang', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv29', 'hayFromStablemaster', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv29', 'hayFromTaurean', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv29', 'hayIndex', 6);
INSERT INTO `quest` VALUES (2, 'new_quest_lv29', 'yonahspatience', 2);
INSERT INTO `quest` VALUES (2, 'new_quest_lv42', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'new_quest_lv43', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'new_quest_lv43', 'collect_count_1', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv52', '__status', 246050424);
INSERT INTO `quest` VALUES (2, 'new_quest_lv52', 'ghostsleft', 4);
INSERT INTO `quest` VALUES (2, 'new_quest_lv54', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'new_quest_lv75', '__status', -1227866427);
INSERT INTO `quest` VALUES (2, 'new_quest_lv75', 'suraskel0', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv75', 'suraskel1', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv75', 'suraskel2', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv75', 'suraskel3', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv75', 'suraskel4', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv80', '__status', -1227866427);
INSERT INTO `quest` VALUES (2, 'new_quest_lv80', 'gotreward', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv80', 'notenchanted', 1);
INSERT INTO `quest` VALUES (2, 'new_quest_lv80', 'spawnsleft', 10);
INSERT INTO `quest` VALUES (2, 'new_quest_premium_lv4', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'pre_event_heavens_cave', '__status', -2054313232);
INSERT INTO `quest` VALUES (2, 'skill_group', '__status', 1349952704);
INSERT INTO `quest` VALUES (2, 'spider_dungeon_2floor', '__status', 1290640410);
INSERT INTO `quest` VALUES (2, 'spider_dungeon_3floor_boss', '__status', -1393546546);
INSERT INTO `quest` VALUES (0, 'spider_lair_ongoing_1', '', 1);
INSERT INTO `quest` VALUES (0, 'spider_lair_start_time_1', '', 1626496540);
INSERT INTO `quest` VALUES (0, 'spider_lair_end_time_1', '', 1626497740);
INSERT INTO `quest` VALUES (0, 'spider_lair_leader_1', '', 1);
INSERT INTO `quest` VALUES (1, 'spider_dungeon_3floor_boss', 'retry_limit_time', 1626500320);
INSERT INTO `quest` VALUES (1, 'is_yang', 'next_time', 1626502355);
INSERT INTO `quest` VALUES (1, 'pre_event_heavens_cave', '__status', -2054313232);
INSERT INTO `quest` VALUES (1, 'new_christmas_2012_sock', 'open_item_storage_count', 1);
INSERT INTO `quest` VALUES (1, 'stash', '__status', -1800287157);
INSERT INTO `quest` VALUES (1, 'stash', 'open_count', 3);
INSERT INTO `quest` VALUES (1, 'stash', 'open_item_storage_count', 3);
INSERT INTO `quest` VALUES (0, 'event_map_choice', '', 0);
INSERT INTO `quest` VALUES (0, 'event_map_level_min', '', 0);
INSERT INTO `quest` VALUES (0, 'event_map_level_max', '', 0);
INSERT INTO `quest` VALUES (0, 'event_map_player_max', '', 0);
INSERT INTO `quest` VALUES (0, 'event_map_empire', '', 0);
INSERT INTO `quest` VALUES (0, 'event_map_login_counter', '', 0);
INSERT INTO `quest` VALUES (0, 'event_map_active', '', 0);
INSERT INTO `quest` VALUES (0, 'threeway_war_choice', '', 4);
INSERT INTO `quest` VALUES (0, 'threeway_war_level_min', '', 85);
INSERT INTO `quest` VALUES (0, 'threeway_war_level_max', '', 105);
INSERT INTO `quest` VALUES (0, 'threeway_war_sungzi_idx', '', 0);
INSERT INTO `quest` VALUES (0, 'threeway_war_pass_idx', '', 1);
INSERT INTO `quest` VALUES (0, 'threeway_war', '', 0);
INSERT INTO `quest` VALUES (0, 'threeway_war_dead_count', '', 25);
INSERT INTO `quest` VALUES (0, 'threeway_war_kill_count', '', 250);
INSERT INTO `quest` VALUES (0, 'threeway_war_boss_count', '', 5);
INSERT INTO `quest` VALUES (0, 'threeway_war_open_gate1', '', 1);
INSERT INTO `quest` VALUES (0, 'threeway_war_open_gate2', '', 1);
INSERT INTO `quest` VALUES (0, 'threeway_war_open_gate3', '', 1);
INSERT INTO `quest` VALUES (0, 'dragon_lair_time', '', 1626638337);
INSERT INTO `quest` VALUES (0, 'dragon_lair_password', '', 12345);
INSERT INTO `quest` VALUES (1, 'spider_dungeon_3floor_boss', '__status', -1393546546);
INSERT INTO `quest` VALUES (1, 'dragon_lair_access', 'time', 1626638337);
INSERT INTO `quest` VALUES (0, 'dragon_lair_alive', '', 0);
INSERT INTO `quest` VALUES (1, 'spider_dungeon_2floor', '__status', 1290640410);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'heavens_cave_keyquest_BloodStone', 30190);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'heavens_cave_keyquest_FrozenTear', 30186);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'heavens_cave_keyquest_NeededGlassAmount', 4);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'heavens_cave_keyquest_NeededTearsAmount', 7);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'heavens_cave_keyquest_RedForestRndNum', 1);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'heavens_cave_keyquest_TearBottle', 30189);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'heavens_cave_keyquest_VolcanicGlass', 30188);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'reachedspot', 1);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', '__status', -2138973444);
INSERT INTO `quest` VALUES (1, 'deviltower_zone', '9_done', 1);
INSERT INTO `quest` VALUES (1, 'flame_dungeon', 'exit_time', 1626680018);
INSERT INTO `quest` VALUES (1, 'questscroll5', '__status', -1212866787);
INSERT INTO `quest` VALUES (2, 'devilcatacomb_zone', 'level', 4);
INSERT INTO `quest` VALUES (1, 'charge_cash_by_voucher', 'total_cash', 1650);
INSERT INTO `quest` VALUES (2, 'flame_dungeon', 'exit_time', 1626680018);
INSERT INTO `quest` VALUES (1, 'devilcatacomb_zone', 'last_exit_time', 1626681625);
INSERT INTO `quest` VALUES (1, 'questscroll5', 'mission_index', 51);
INSERT INTO `quest` VALUES (2, 'devilcatacomb_zone', 'last_exit_time', 1626680943);
INSERT INTO `quest` VALUES (1, 'devilcatacomb_zone', 'done', 1);
INSERT INTO `quest` VALUES (1, 'event_halloween_hair', 'first_notice', 1);
INSERT INTO `quest` VALUES (2, 'heavens_cave_keyquest', '__status', 865973175);
INSERT INTO `quest` VALUES (2, 'oxevent_manager', 'ox_end_cooldown_time', 1627855853);
INSERT INTO `quest` VALUES (0, 'ox_map_level_min', '', 15);
INSERT INTO `quest` VALUES (0, 'ox_map_level_max', '', 39);
INSERT INTO `quest` VALUES (0, 'ox_map_player_max', '', 1);
INSERT INTO `quest` VALUES (2, 'levelup', 'buttonstate', 1);
INSERT INTO `quest` VALUES (2, 'levelup', 'current', 50);
INSERT INTO `quest` VALUES (2, 'levelup', 'remain', 40);
INSERT INTO `quest` VALUES (2, 'levelup', 'select', 1);
INSERT INTO `quest` VALUES (2, 'subquest_21', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'subquest_41', '__status', 695801987);
INSERT INTO `quest` VALUES (2, 'subquest_47', '__status', 695801987);
INSERT INTO `quest` VALUES (1, 'heavens_cave_keyquest', 'heavens_cave_keyquest_BloodDrop', 30187);
INSERT INTO `quest` VALUES (2, 'event_mystery_box', '__status', -163855020);
INSERT INTO `quest` VALUES (3, 'check_trans_ticket', '__status', 526282696);
INSERT INTO `quest` VALUES (3, 'event_mystery_box', '__status', -163855020);
INSERT INTO `quest` VALUES (3, 'give_basic_weapon', 'basic_weapon', 1);
INSERT INTO `quest` VALUES (3, 'harvest_festival', '__status', 695801987);
INSERT INTO `quest` VALUES (3, 'main_quest_lv1', '__status', -596781658);
INSERT INTO `quest` VALUES (3, 'spider_dungeon_2floor', '__status', 1290640410);
INSERT INTO `quest` VALUES (3, 'levelup', 'buttonstate', 1);
INSERT INTO `quest` VALUES (3, 'levelup', 'current', 2);
INSERT INTO `quest` VALUES (3, 'levelup', 'remain', 10);
INSERT INTO `quest` VALUES (3, 'levelup', 'select', 1);

-- ----------------------------
-- Table structure for refine_proto
-- ----------------------------
DROP TABLE IF EXISTS `refine_proto`;
CREATE TABLE `refine_proto`  (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `vnum0` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `count0` smallint(6) NOT NULL DEFAULT 0,
  `vnum1` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `count1` smallint(6) NOT NULL DEFAULT 0,
  `vnum2` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `count2` smallint(6) NOT NULL DEFAULT 0,
  `vnum3` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `count3` smallint(6) NOT NULL DEFAULT 0,
  `vnum4` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `count4` smallint(6) NOT NULL DEFAULT 0,
  `cost` int(11) NOT NULL DEFAULT 0,
  `src_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `result_vnum` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `prob` smallint(6) NOT NULL DEFAULT 100,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = MyISAM AUTO_INCREMENT = 760 CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of refine_proto
-- ----------------------------
INSERT INTO `refine_proto` VALUES (1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (7, 30053, 1, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (8, 30073, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (9, 30033, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (11, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (12, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (13, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (14, 30030, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (15, 30075, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (16, 30056, 2, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (17, 30022, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (18, 30067, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (19, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (22, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (23, 30079, 1, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (24, 30015, 1, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (25, 30016, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (26, 30089, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (27, 30091, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (28, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (29, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (30, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (31, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (32, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (33, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (34, 30034, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (35, 30011, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (36, 30035, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (37, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (38, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (39, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (41, 30052, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (42, 30046, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (43, 30045, 2, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (44, 30025, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (45, 30058, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (46, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (47, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (49, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (50, 30083, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (51, 30060, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (52, 30061, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (53, 30088, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (54, 30019, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (55, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (57, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (58, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (59, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (60, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (61, 30070, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (62, 30072, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (63, 30017, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (66, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (68, 30041, 1, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (69, 30008, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (70, 30057, 1, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (71, 30081, 1, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (72, 30077, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (73, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (74, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (77, 30009, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (78, 30039, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (79, 30040, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (80, 30048, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (81, 30090, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (85, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (86, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (88, 30031, 1, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (89, 30032, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (90, 30033, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (91, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (92, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (93, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (94, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (95, 30008, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (96, 30075, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (97, 30006, 2, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (98, 30022, 1, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (99, 30067, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (100, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (101, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (102, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (103, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (104, 30079, 1, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (105, 30015, 1, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (106, 30086, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (107, 30050, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (108, 30091, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (111, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (112, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (113, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (115, 30071, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (116, 30018, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (117, 30017, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (118, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (119, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (120, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (121, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (122, 30005, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (123, 30076, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (124, 30051, 1, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (125, 30081, 1, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (126, 30047, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (127, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (129, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (130, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (131, 30009, 1, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (132, 30080, 1, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (133, 30040, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (134, 30049, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (135, 30090, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (136, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (137, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (138, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (139, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (140, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (141, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (142, 30038, 1, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (143, 30023, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (144, 30074, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (145, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (146, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (147, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (149, 30007, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (150, 30078, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (151, 30045, 2, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (152, 30055, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (153, 30047, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (154, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (155, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (156, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (157, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (158, 30059, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (159, 30080, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (160, 30085, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (161, 30014, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (162, 30042, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (164, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (165, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (166, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (169, 30010, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (170, 30031, 1, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (171, 30032, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (172, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (173, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (174, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (175, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (176, 30021, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (177, 30008, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (178, 30057, 2, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (179, 30006, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (180, 30022, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (181, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (182, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (183, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (184, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (185, 30082, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (186, 30079, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (187, 30087, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (188, 30086, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (189, 30050, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (190, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (191, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (192, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (193, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (194, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (196, 30038, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (197, 30011, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (198, 30074, 1, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (199, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (200, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (201, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (202, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (203, 30007, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (204, 30046, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (205, 30045, 2, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (206, 30055, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (207, 30058, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (208, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (209, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (211, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (212, 30059, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (213, 30060, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (214, 30061, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (215, 30014, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (216, 30042, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (217, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (218, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (219, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (220, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (221, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (222, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (223, 30071, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (224, 30023, 1, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (225, 30074, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (226, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (227, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (228, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (229, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (230, 30005, 1, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (231, 30078, 1, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (232, 30051, 1, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (233, 30055, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (234, 30047, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (235, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (236, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (237, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (238, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (239, 30059, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (240, 30080, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (241, 30085, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (242, 30049, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (243, 30042, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (244, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (245, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (246, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (247, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (248, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (249, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (250, 30070, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (251, 30018, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (252, 30017, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (253, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (254, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (256, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (257, 30041, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (258, 30076, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (259, 30051, 2, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (260, 30081, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (261, 30077, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (262, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (263, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (264, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (265, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (266, 30009, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (267, 30039, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (268, 30040, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (269, 30048, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (270, 30090, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (271, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (272, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (273, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (274, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (275, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (276, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (277, 30010, 1, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (278, 30072, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (279, 30032, 1, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (280, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (281, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (282, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (283, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (284, 30021, 1, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (285, 30008, 1, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (286, 30057, 1, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (287, 30006, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (288, 30077, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (289, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (290, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (291, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (292, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (293, 30082, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (294, 30039, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (295, 30087, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (296, 30086, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (297, 30050, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (298, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (299, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (300, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (301, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (302, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (303, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (304, 30053, 1, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (305, 30073, 1, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (306, 30035, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (307, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (308, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (309, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (311, 30030, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (312, 30075, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (313, 30056, 2, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (314, 30025, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (315, 30067, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (317, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (320, 30083, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (321, 30015, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (322, 30016, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (323, 30089, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (324, 30019, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (325, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 600, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (326, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (327, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (328, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (329, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (330, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (331, 30034, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (332, 30073, 2, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (333, 30035, 2, 0, 0, 0, 0, 0, 0, 0, 0, 75000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (334, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (335, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (336, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (337, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (338, 30052, 2, 0, 0, 0, 0, 0, 0, 0, 0, 13000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (339, 30046, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (340, 30056, 2, 27799, 1, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (341, 30025, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 70000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (342, 30058, 2, 27987, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (343, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1200, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (344, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2500, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (345, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (346, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (347, 30083, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (348, 30060, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (349, 30061, 2, 30193, 2, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (350, 30088, 2, 30193, 4, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (351, 30019, 2, 30193, 6, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (352, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (353, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (354, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (355, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (356, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (357, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 60000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (358, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (359, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (360, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (400, 30192, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (401, 30194, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (402, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (403, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (404, 30083, 2, 0, 0, 0, 0, 0, 0, 0, 0, 20000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (405, 30060, 2, 0, 0, 0, 0, 0, 0, 0, 0, 30000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (406, 30061, 2, 30193, 2, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (407, 30088, 2, 30193, 4, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (408, 30019, 2, 30193, 6, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (501, 25040, 2, 70031, 1, 0, 0, 0, 0, 0, 0, 100000, 0, 0, 100);
INSERT INTO `refine_proto` VALUES (502, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (503, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 140000, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (504, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 170000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (505, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 200000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (506, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 240000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (507, 30050, 2, 0, 0, 0, 0, 0, 0, 0, 0, 290000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (508, 30083, 2, 27992, 1, 0, 0, 0, 0, 0, 0, 340000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (509, 30040, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 410000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (510, 30089, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 500000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (531, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7500, 0, 0, 90);
INSERT INTO `refine_proto` VALUES (532, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 15000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (533, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (534, 30196, 2, 0, 0, 0, 0, 0, 0, 0, 0, 40000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (535, 30090, 3, 0, 0, 0, 0, 0, 0, 0, 0, 65000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (536, 30195, 2, 0, 0, 0, 0, 0, 0, 0, 0, 90000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (537, 30197, 4, 27992, 1, 0, 0, 0, 0, 0, 0, 120000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (538, 30198, 2, 27993, 1, 0, 0, 0, 0, 0, 0, 150000, 0, 0, 20);
INSERT INTO `refine_proto` VALUES (539, 30199, 2, 27994, 1, 0, 0, 0, 0, 0, 0, 200000, 0, 0, 10);
INSERT INTO `refine_proto` VALUES (701, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 500000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (702, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000000, 0, 0, 25);
INSERT INTO `refine_proto` VALUES (703, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100);
INSERT INTO `refine_proto` VALUES (751, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100000, 0, 0, 40);
INSERT INTO `refine_proto` VALUES (752, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 500000, 0, 0, 50);
INSERT INTO `refine_proto` VALUES (753, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2000000, 0, 0, 30);
INSERT INTO `refine_proto` VALUES (758, 71123, 2, 71129, 3, 0, 0, 0, 0, 0, 0, 125000, 0, 0, 100);
INSERT INTO `refine_proto` VALUES (759, 71123, 3, 71129, 4, 0, 0, 0, 0, 0, 0, 200000, 0, 0, 100);
INSERT INTO `refine_proto` VALUES (530, 71129, 3, 71123, 3, 0, 0, 0, 0, 0, 0, 200000, 0, 0, 100);
INSERT INTO `refine_proto` VALUES (610, 25040, 2, 70031, 3, 51001, 200, 0, 0, 0, 0, 50000000, 0, 0, 100);
INSERT INTO `refine_proto` VALUES (601, 51001, 10, 70031, 3, 0, 0, 0, 0, 0, 0, 10000000, 0, 0, 80);
INSERT INTO `refine_proto` VALUES (602, 51001, 15, 70031, 3, 0, 0, 0, 0, 0, 0, 12000000, 0, 0, 75);
INSERT INTO `refine_proto` VALUES (603, 51001, 20, 70031, 3, 0, 0, 0, 0, 0, 0, 14000000, 0, 0, 75);
INSERT INTO `refine_proto` VALUES (604, 51001, 30, 70031, 3, 0, 0, 0, 0, 0, 0, 16000000, 0, 0, 75);
INSERT INTO `refine_proto` VALUES (605, 51001, 45, 70031, 3, 0, 0, 0, 0, 0, 0, 18000000, 0, 0, 70);
INSERT INTO `refine_proto` VALUES (606, 51001, 65, 70031, 3, 0, 0, 0, 0, 0, 0, 20000000, 0, 0, 65);
INSERT INTO `refine_proto` VALUES (607, 51001, 95, 70031, 3, 0, 0, 0, 0, 0, 0, 22000000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (608, 51001, 145, 70031, 3, 0, 0, 0, 0, 0, 0, 24000000, 0, 0, 60);
INSERT INTO `refine_proto` VALUES (609, 51001, 200, 70031, 3, 0, 0, 0, 0, 0, 0, 26000000, 0, 0, 60);

-- ----------------------------
-- Table structure for safebox
-- ----------------------------
DROP TABLE IF EXISTS `safebox`;
CREATE TABLE `safebox`  (
  `account_id` int(10) UNSIGNED NOT NULL DEFAULT 0,
  `size` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `password` varchar(6) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `gold` int(11) NOT NULL DEFAULT 0,
  PRIMARY KEY (`account_id`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of safebox
-- ----------------------------
INSERT INTO `safebox` VALUES (1, 1, '', 0);

-- ----------------------------
-- Table structure for shop
-- ----------------------------
DROP TABLE IF EXISTS `shop`;
CREATE TABLE `shop`  (
  `vnum` int(11) NOT NULL DEFAULT 0,
  `name` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'Noname',
  `npc_vnum` smallint(6) NOT NULL DEFAULT 0,
  PRIMARY KEY (`vnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of shop
-- ----------------------------
INSERT INTO `shop` VALUES (1, 'Weapon Shop Dealer', 9001);
INSERT INTO `shop` VALUES (2, 'Fisherman', 9009);
INSERT INTO `shop` VALUES (3, 'General Store Saleswoman', 9003);
INSERT INTO `shop` VALUES (4, 'Armour Shop Dealer', 9002);
INSERT INTO `shop` VALUES (5, 'Weapon Shop Dealer 2', 9007);
INSERT INTO `shop` VALUES (6, 'Armour Shop Dealer 2', 9008);
INSERT INTO `shop` VALUES (7, 'gold_bar_shop', 9005);
INSERT INTO `shop` VALUES (8, 'firework_shop', 9004);
INSERT INTO `shop` VALUES (9, 'Peddler', 20042);
INSERT INTO `shop` VALUES (10, 'pick_shop', 20015);
INSERT INTO `shop` VALUES (11, 'Stable Boy', 20349);
INSERT INTO `shop` VALUES (1001, 'all_sword', 0);
INSERT INTO `shop` VALUES (1002, 'all_dualhand_sword', 0);
INSERT INTO `shop` VALUES (1003, 'all_bow', 0);
INSERT INTO `shop` VALUES (1004, 'all_twohand_sword', 0);
INSERT INTO `shop` VALUES (1005, 'all_bell', 0);
INSERT INTO `shop` VALUES (1006, 'all_fan', 0);
INSERT INTO `shop` VALUES (1007, 'all_warrior_armour', 0);
INSERT INTO `shop` VALUES (1008, 'all_assassin_armour', 0);
INSERT INTO `shop` VALUES (1009, 'all_sura_armour', 0);
INSERT INTO `shop` VALUES (1010, 'all_shaman_armour', 0);
INSERT INTO `shop` VALUES (1011, 'all_warrior_helmet', 0);
INSERT INTO `shop` VALUES (1012, 'all_assassin_helmet', 0);
INSERT INTO `shop` VALUES (1013, 'all_sura_helmet', 0);
INSERT INTO `shop` VALUES (1014, 'all_shaman_helmet', 0);
INSERT INTO `shop` VALUES (1015, 'all_shield', 0);
INSERT INTO `shop` VALUES (1016, 'all_bracelet', 0);
INSERT INTO `shop` VALUES (1017, 'all_shoe', 0);
INSERT INTO `shop` VALUES (1018, 'all_necklace', 0);
INSERT INTO `shop` VALUES (1019, 'all_ring', 0);
INSERT INTO `shop` VALUES (13, 'Alchemist', 20001);

-- ----------------------------
-- Table structure for shop_item
-- ----------------------------
DROP TABLE IF EXISTS `shop_item`;
CREATE TABLE `shop_item`  (
  `shop_vnum` int(11) NOT NULL DEFAULT 0,
  `item_vnum` int(11) NOT NULL DEFAULT 0,
  `count` tinyint(4) UNSIGNED NOT NULL DEFAULT 1,
  UNIQUE INDEX `vnum_unique`(`shop_vnum`, `item_vnum`, `count`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = FIXED;

-- ----------------------------
-- Records of shop_item
-- ----------------------------
INSERT INTO `shop_item` VALUES (1, 20, 1);
INSERT INTO `shop_item` VALUES (1, 40, 1);
INSERT INTO `shop_item` VALUES (1, 60, 1);
INSERT INTO `shop_item` VALUES (1, 80, 1);
INSERT INTO `shop_item` VALUES (1, 1040, 1);
INSERT INTO `shop_item` VALUES (1, 2010, 1);
INSERT INTO `shop_item` VALUES (1, 2030, 1);
INSERT INTO `shop_item` VALUES (1, 2050, 1);
INSERT INTO `shop_item` VALUES (1, 2070, 1);
INSERT INTO `shop_item` VALUES (1, 3010, 1);
INSERT INTO `shop_item` VALUES (1, 3030, 1);
INSERT INTO `shop_item` VALUES (1, 3050, 1);
INSERT INTO `shop_item` VALUES (1, 3070, 1);
INSERT INTO `shop_item` VALUES (1, 4000, 1);
INSERT INTO `shop_item` VALUES (1, 4010, 1);
INSERT INTO `shop_item` VALUES (1, 4020, 1);
INSERT INTO `shop_item` VALUES (1, 5010, 1);
INSERT INTO `shop_item` VALUES (1, 5030, 1);
INSERT INTO `shop_item` VALUES (1, 7010, 1);
INSERT INTO `shop_item` VALUES (1, 7030, 1);
INSERT INTO `shop_item` VALUES (1, 7050, 1);
INSERT INTO `shop_item` VALUES (1, 8000, 100);
INSERT INTO `shop_item` VALUES (1, 8000, 200);
INSERT INTO `shop_item` VALUES (2, 27400, 1);
INSERT INTO `shop_item` VALUES (2, 27600, 1);
INSERT INTO `shop_item` VALUES (2, 27610, 1);
INSERT INTO `shop_item` VALUES (2, 27800, 5);
INSERT INTO `shop_item` VALUES (2, 27800, 50);
INSERT INTO `shop_item` VALUES (2, 27801, 5);
INSERT INTO `shop_item` VALUES (2, 27801, 50);
INSERT INTO `shop_item` VALUES (3, 14000, 1);
INSERT INTO `shop_item` VALUES (3, 15000, 1);
INSERT INTO `shop_item` VALUES (3, 16000, 1);
INSERT INTO `shop_item` VALUES (3, 17000, 1);
INSERT INTO `shop_item` VALUES (3, 27001, 5);
INSERT INTO `shop_item` VALUES (3, 27001, 20);
INSERT INTO `shop_item` VALUES (3, 27001, 200);
INSERT INTO `shop_item` VALUES (3, 27002, 5);
INSERT INTO `shop_item` VALUES (3, 27002, 20);
INSERT INTO `shop_item` VALUES (3, 27002, 200);
INSERT INTO `shop_item` VALUES (3, 27003, 5);
INSERT INTO `shop_item` VALUES (3, 27003, 20);
INSERT INTO `shop_item` VALUES (3, 27003, 200);
INSERT INTO `shop_item` VALUES (3, 27004, 5);
INSERT INTO `shop_item` VALUES (3, 27004, 20);
INSERT INTO `shop_item` VALUES (3, 27004, 200);
INSERT INTO `shop_item` VALUES (3, 27005, 5);
INSERT INTO `shop_item` VALUES (3, 27005, 20);
INSERT INTO `shop_item` VALUES (3, 27005, 200);
INSERT INTO `shop_item` VALUES (3, 27006, 5);
INSERT INTO `shop_item` VALUES (3, 27006, 20);
INSERT INTO `shop_item` VALUES (3, 27006, 200);
INSERT INTO `shop_item` VALUES (3, 50200, 1);
INSERT INTO `shop_item` VALUES (3, 50901, 10);
INSERT INTO `shop_item` VALUES (4, 11200, 1);
INSERT INTO `shop_item` VALUES (4, 11220, 1);
INSERT INTO `shop_item` VALUES (4, 11230, 1);
INSERT INTO `shop_item` VALUES (4, 11400, 1);
INSERT INTO `shop_item` VALUES (4, 11420, 1);
INSERT INTO `shop_item` VALUES (4, 11430, 1);
INSERT INTO `shop_item` VALUES (4, 11600, 1);
INSERT INTO `shop_item` VALUES (4, 11620, 1);
INSERT INTO `shop_item` VALUES (4, 11630, 1);
INSERT INTO `shop_item` VALUES (4, 11800, 1);
INSERT INTO `shop_item` VALUES (4, 11820, 1);
INSERT INTO `shop_item` VALUES (4, 11830, 1);
INSERT INTO `shop_item` VALUES (4, 12200, 1);
INSERT INTO `shop_item` VALUES (4, 12340, 1);
INSERT INTO `shop_item` VALUES (4, 12480, 1);
INSERT INTO `shop_item` VALUES (4, 12620, 1);
INSERT INTO `shop_item` VALUES (4, 13000, 1);
INSERT INTO `shop_item` VALUES (5, 3100, 1);
INSERT INTO `shop_item` VALUES (5, 5020, 1);
INSERT INTO `shop_item` VALUES (5, 5030, 1);
INSERT INTO `shop_item` VALUES (5, 5040, 1);
INSERT INTO `shop_item` VALUES (5, 5050, 1);
INSERT INTO `shop_item` VALUES (5, 5070, 1);
INSERT INTO `shop_item` VALUES (5, 5080, 1);
INSERT INTO `shop_item` VALUES (5, 7020, 1);
INSERT INTO `shop_item` VALUES (5, 7050, 1);
INSERT INTO `shop_item` VALUES (5, 7060, 1);
INSERT INTO `shop_item` VALUES (5, 7090, 1);
INSERT INTO `shop_item` VALUES (5, 7100, 1);
INSERT INTO `shop_item` VALUES (6, 14000, 1);
INSERT INTO `shop_item` VALUES (6, 14020, 1);
INSERT INTO `shop_item` VALUES (6, 14040, 1);
INSERT INTO `shop_item` VALUES (6, 14060, 1);
INSERT INTO `shop_item` VALUES (6, 14080, 1);
INSERT INTO `shop_item` VALUES (6, 14140, 1);
INSERT INTO `shop_item` VALUES (6, 15000, 1);
INSERT INTO `shop_item` VALUES (6, 15020, 1);
INSERT INTO `shop_item` VALUES (6, 15040, 1);
INSERT INTO `shop_item` VALUES (6, 15060, 1);
INSERT INTO `shop_item` VALUES (6, 15080, 1);
INSERT INTO `shop_item` VALUES (6, 15160, 1);
INSERT INTO `shop_item` VALUES (6, 16000, 1);
INSERT INTO `shop_item` VALUES (6, 16020, 1);
INSERT INTO `shop_item` VALUES (6, 16040, 1);
INSERT INTO `shop_item` VALUES (6, 16060, 1);
INSERT INTO `shop_item` VALUES (6, 16080, 1);
INSERT INTO `shop_item` VALUES (6, 16180, 1);
INSERT INTO `shop_item` VALUES (6, 17000, 1);
INSERT INTO `shop_item` VALUES (6, 17020, 1);
INSERT INTO `shop_item` VALUES (6, 17040, 1);
INSERT INTO `shop_item` VALUES (6, 17060, 1);
INSERT INTO `shop_item` VALUES (6, 17080, 1);
INSERT INTO `shop_item` VALUES (6, 17180, 1);
INSERT INTO `shop_item` VALUES (7, 80003, 1);
INSERT INTO `shop_item` VALUES (7, 80004, 1);
INSERT INTO `shop_item` VALUES (7, 80005, 1);
INSERT INTO `shop_item` VALUES (7, 80006, 1);
INSERT INTO `shop_item` VALUES (7, 80007, 1);
INSERT INTO `shop_item` VALUES (8, 50100, 100);
INSERT INTO `shop_item` VALUES (8, 50101, 100);
INSERT INTO `shop_item` VALUES (8, 50102, 100);
INSERT INTO `shop_item` VALUES (8, 50103, 100);
INSERT INTO `shop_item` VALUES (8, 50104, 100);
INSERT INTO `shop_item` VALUES (8, 50105, 100);
INSERT INTO `shop_item` VALUES (9, 11901, 1);
INSERT INTO `shop_item` VALUES (9, 11903, 1);
INSERT INTO `shop_item` VALUES (9, 50201, 1);
INSERT INTO `shop_item` VALUES (10, 29101, 1);
INSERT INTO `shop_item` VALUES (11, 50054, 1);
INSERT INTO `shop_item` VALUES (11, 50055, 1);
INSERT INTO `shop_item` VALUES (11, 50056, 1);
INSERT INTO `shop_item` VALUES (13, 100100, 1);
INSERT INTO `shop_item` VALUES (13, 100200, 1);
INSERT INTO `shop_item` VALUES (1001, 10, 1);
INSERT INTO `shop_item` VALUES (1001, 20, 1);
INSERT INTO `shop_item` VALUES (1001, 30, 1);
INSERT INTO `shop_item` VALUES (1001, 40, 1);
INSERT INTO `shop_item` VALUES (1001, 50, 1);
INSERT INTO `shop_item` VALUES (1001, 60, 1);
INSERT INTO `shop_item` VALUES (1001, 70, 1);
INSERT INTO `shop_item` VALUES (1001, 80, 1);
INSERT INTO `shop_item` VALUES (1001, 90, 1);
INSERT INTO `shop_item` VALUES (1001, 100, 1);
INSERT INTO `shop_item` VALUES (1001, 110, 1);
INSERT INTO `shop_item` VALUES (1001, 120, 1);
INSERT INTO `shop_item` VALUES (1001, 130, 1);
INSERT INTO `shop_item` VALUES (1002, 1000, 1);
INSERT INTO `shop_item` VALUES (1002, 1010, 1);
INSERT INTO `shop_item` VALUES (1002, 1020, 1);
INSERT INTO `shop_item` VALUES (1002, 1030, 1);
INSERT INTO `shop_item` VALUES (1002, 1040, 1);
INSERT INTO `shop_item` VALUES (1002, 1050, 1);
INSERT INTO `shop_item` VALUES (1002, 1060, 1);
INSERT INTO `shop_item` VALUES (1002, 1070, 1);
INSERT INTO `shop_item` VALUES (1002, 1080, 1);
INSERT INTO `shop_item` VALUES (1002, 1090, 1);
INSERT INTO `shop_item` VALUES (1002, 4000, 1);
INSERT INTO `shop_item` VALUES (1002, 4010, 1);
INSERT INTO `shop_item` VALUES (1002, 4020, 1);
INSERT INTO `shop_item` VALUES (1003, 2000, 1);
INSERT INTO `shop_item` VALUES (1003, 2010, 1);
INSERT INTO `shop_item` VALUES (1003, 2020, 1);
INSERT INTO `shop_item` VALUES (1003, 2030, 1);
INSERT INTO `shop_item` VALUES (1003, 2040, 1);
INSERT INTO `shop_item` VALUES (1003, 2050, 1);
INSERT INTO `shop_item` VALUES (1003, 2060, 1);
INSERT INTO `shop_item` VALUES (1003, 2070, 1);
INSERT INTO `shop_item` VALUES (1003, 2080, 1);
INSERT INTO `shop_item` VALUES (1003, 2090, 1);
INSERT INTO `shop_item` VALUES (1003, 2100, 1);
INSERT INTO `shop_item` VALUES (1003, 2110, 1);
INSERT INTO `shop_item` VALUES (1003, 2120, 1);
INSERT INTO `shop_item` VALUES (1003, 8000, 50);
INSERT INTO `shop_item` VALUES (1003, 8000, 200);
INSERT INTO `shop_item` VALUES (1004, 3000, 1);
INSERT INTO `shop_item` VALUES (1004, 3010, 1);
INSERT INTO `shop_item` VALUES (1004, 3020, 1);
INSERT INTO `shop_item` VALUES (1004, 3030, 1);
INSERT INTO `shop_item` VALUES (1004, 3040, 1);
INSERT INTO `shop_item` VALUES (1004, 3050, 1);
INSERT INTO `shop_item` VALUES (1004, 3060, 1);
INSERT INTO `shop_item` VALUES (1004, 3070, 1);
INSERT INTO `shop_item` VALUES (1004, 3080, 1);
INSERT INTO `shop_item` VALUES (1004, 3090, 1);
INSERT INTO `shop_item` VALUES (1004, 3100, 1);
INSERT INTO `shop_item` VALUES (1004, 3110, 1);
INSERT INTO `shop_item` VALUES (1004, 3120, 1);
INSERT INTO `shop_item` VALUES (1005, 5000, 1);
INSERT INTO `shop_item` VALUES (1005, 5010, 1);
INSERT INTO `shop_item` VALUES (1005, 5020, 1);
INSERT INTO `shop_item` VALUES (1005, 5030, 1);
INSERT INTO `shop_item` VALUES (1005, 5040, 1);
INSERT INTO `shop_item` VALUES (1005, 5050, 1);
INSERT INTO `shop_item` VALUES (1005, 5060, 1);
INSERT INTO `shop_item` VALUES (1005, 5070, 1);
INSERT INTO `shop_item` VALUES (1005, 5080, 1);
INSERT INTO `shop_item` VALUES (1006, 7000, 1);
INSERT INTO `shop_item` VALUES (1006, 7010, 1);
INSERT INTO `shop_item` VALUES (1006, 7020, 1);
INSERT INTO `shop_item` VALUES (1006, 7030, 1);
INSERT INTO `shop_item` VALUES (1006, 7040, 1);
INSERT INTO `shop_item` VALUES (1006, 7050, 1);
INSERT INTO `shop_item` VALUES (1006, 7060, 1);
INSERT INTO `shop_item` VALUES (1006, 7070, 1);
INSERT INTO `shop_item` VALUES (1006, 7080, 1);
INSERT INTO `shop_item` VALUES (1006, 7090, 1);
INSERT INTO `shop_item` VALUES (1006, 7100, 1);
INSERT INTO `shop_item` VALUES (1006, 7110, 1);
INSERT INTO `shop_item` VALUES (1006, 7120, 1);
INSERT INTO `shop_item` VALUES (1007, 11200, 1);
INSERT INTO `shop_item` VALUES (1007, 11210, 1);
INSERT INTO `shop_item` VALUES (1007, 11220, 1);
INSERT INTO `shop_item` VALUES (1007, 11230, 1);
INSERT INTO `shop_item` VALUES (1007, 11240, 1);
INSERT INTO `shop_item` VALUES (1007, 11250, 1);
INSERT INTO `shop_item` VALUES (1007, 11260, 1);
INSERT INTO `shop_item` VALUES (1008, 11400, 1);
INSERT INTO `shop_item` VALUES (1008, 11410, 1);
INSERT INTO `shop_item` VALUES (1008, 11420, 1);
INSERT INTO `shop_item` VALUES (1008, 11430, 1);
INSERT INTO `shop_item` VALUES (1008, 11440, 1);
INSERT INTO `shop_item` VALUES (1008, 11450, 1);
INSERT INTO `shop_item` VALUES (1008, 11460, 1);
INSERT INTO `shop_item` VALUES (1009, 11600, 1);
INSERT INTO `shop_item` VALUES (1009, 11610, 1);
INSERT INTO `shop_item` VALUES (1009, 11620, 1);
INSERT INTO `shop_item` VALUES (1009, 11630, 1);
INSERT INTO `shop_item` VALUES (1009, 11640, 1);
INSERT INTO `shop_item` VALUES (1009, 11650, 1);
INSERT INTO `shop_item` VALUES (1009, 11660, 1);
INSERT INTO `shop_item` VALUES (1010, 11800, 1);
INSERT INTO `shop_item` VALUES (1010, 11810, 1);
INSERT INTO `shop_item` VALUES (1010, 11820, 1);
INSERT INTO `shop_item` VALUES (1010, 11830, 1);
INSERT INTO `shop_item` VALUES (1010, 11840, 1);
INSERT INTO `shop_item` VALUES (1010, 11850, 1);
INSERT INTO `shop_item` VALUES (1010, 11860, 1);
INSERT INTO `shop_item` VALUES (1011, 12200, 1);
INSERT INTO `shop_item` VALUES (1011, 12220, 1);
INSERT INTO `shop_item` VALUES (1011, 12240, 1);
INSERT INTO `shop_item` VALUES (1012, 12340, 1);
INSERT INTO `shop_item` VALUES (1012, 12360, 1);
INSERT INTO `shop_item` VALUES (1012, 12380, 1);
INSERT INTO `shop_item` VALUES (1013, 12480, 1);
INSERT INTO `shop_item` VALUES (1013, 12500, 1);
INSERT INTO `shop_item` VALUES (1013, 12520, 1);
INSERT INTO `shop_item` VALUES (1014, 12620, 1);
INSERT INTO `shop_item` VALUES (1014, 12640, 1);
INSERT INTO `shop_item` VALUES (1014, 12660, 1);
INSERT INTO `shop_item` VALUES (1015, 13000, 1);
INSERT INTO `shop_item` VALUES (1015, 13040, 1);
INSERT INTO `shop_item` VALUES (1016, 14000, 1);
INSERT INTO `shop_item` VALUES (1016, 14020, 1);
INSERT INTO `shop_item` VALUES (1016, 14040, 1);
INSERT INTO `shop_item` VALUES (1016, 14060, 1);
INSERT INTO `shop_item` VALUES (1016, 14080, 1);
INSERT INTO `shop_item` VALUES (1016, 14100, 1);
INSERT INTO `shop_item` VALUES (1016, 14120, 1);
INSERT INTO `shop_item` VALUES (1016, 14140, 1);
INSERT INTO `shop_item` VALUES (1016, 14160, 1);
INSERT INTO `shop_item` VALUES (1016, 14180, 1);
INSERT INTO `shop_item` VALUES (1016, 14200, 1);
INSERT INTO `shop_item` VALUES (1017, 15000, 1);
INSERT INTO `shop_item` VALUES (1017, 15020, 1);
INSERT INTO `shop_item` VALUES (1017, 15040, 1);
INSERT INTO `shop_item` VALUES (1017, 15060, 1);
INSERT INTO `shop_item` VALUES (1017, 15080, 1);
INSERT INTO `shop_item` VALUES (1017, 15100, 1);
INSERT INTO `shop_item` VALUES (1017, 15120, 1);
INSERT INTO `shop_item` VALUES (1017, 15140, 1);
INSERT INTO `shop_item` VALUES (1017, 15160, 1);
INSERT INTO `shop_item` VALUES (1017, 15180, 1);
INSERT INTO `shop_item` VALUES (1017, 15200, 1);
INSERT INTO `shop_item` VALUES (1017, 15220, 1);
INSERT INTO `shop_item` VALUES (1018, 16000, 1);
INSERT INTO `shop_item` VALUES (1018, 16020, 1);
INSERT INTO `shop_item` VALUES (1018, 16040, 1);
INSERT INTO `shop_item` VALUES (1018, 16060, 1);
INSERT INTO `shop_item` VALUES (1018, 16080, 1);
INSERT INTO `shop_item` VALUES (1018, 16100, 1);
INSERT INTO `shop_item` VALUES (1018, 16120, 1);
INSERT INTO `shop_item` VALUES (1018, 16140, 1);
INSERT INTO `shop_item` VALUES (1018, 16160, 1);
INSERT INTO `shop_item` VALUES (1018, 16180, 1);
INSERT INTO `shop_item` VALUES (1018, 16200, 1);
INSERT INTO `shop_item` VALUES (1019, 17000, 1);
INSERT INTO `shop_item` VALUES (1019, 17020, 1);
INSERT INTO `shop_item` VALUES (1019, 17040, 1);
INSERT INTO `shop_item` VALUES (1019, 17060, 1);
INSERT INTO `shop_item` VALUES (1019, 17080, 1);
INSERT INTO `shop_item` VALUES (1019, 17100, 1);
INSERT INTO `shop_item` VALUES (1019, 17120, 1);
INSERT INTO `shop_item` VALUES (1019, 17140, 1);
INSERT INTO `shop_item` VALUES (1019, 17160, 1);
INSERT INTO `shop_item` VALUES (1019, 17180, 1);
INSERT INTO `shop_item` VALUES (1019, 17200, 1);

-- ----------------------------
-- Table structure for skill_proto
-- ----------------------------
DROP TABLE IF EXISTS `skill_proto`;
CREATE TABLE `skill_proto`  (
  `dwVnum` int(11) NOT NULL DEFAULT 0,
  `szName` varchar(32) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `bType` tinyint(4) NOT NULL DEFAULT 0,
  `bLevelStep` tinyint(4) NOT NULL DEFAULT 0,
  `bMaxLevel` tinyint(4) NOT NULL DEFAULT 0,
  `bLevelLimit` tinyint(3) UNSIGNED NOT NULL DEFAULT 0,
  `szPointOn` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '0',
  `szPointPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szSPCostPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szDurationPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szDurationSPCostPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szCooldownPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szMasterBonusPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szAttackGradePoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `setFlag` set('ATTACK','USE_MELEE_DAMAGE','COMPUTE_ATTGRADE','SELFONLY','USE_MAGIC_DAMAGE','USE_HP_AS_COST','COMPUTE_MAGIC_DAMAGE','SPLASH','GIVE_PENALTY','USE_ARROW_DAMAGE','PENETRATE','IGNORE_TARGET_RATING','ATTACK_SLOW','ATTACK_STUN','HP_ABSORB','SP_ABSORB','ATTACK_FIRE_CONT','REMOVE_BAD_AFFECT','REMOVE_GOOD_AFFECT','CRUSH','ATTACK_POISON','TOGGLE','DISABLE_BY_POINT_UP','CRUSH_LONG') CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL DEFAULT NULL,
  `setAffectFlag` set('YMIR','INVISIBILITY','SPAWN','POISON','SLOW','STUN','DUNGEON_READY','FORCE_VISIBLE','BUILDING_CONSTRUCTION_SMALL','BUILDING_CONSTRUCTION_LARGE','BUILDING_UPGRADE','MOV_SPEED_POTION','ATT_SPEED_POTION','FISH_MIDE','JEONGWIHON','GEOMGYEONG','CHEONGEUN','GYEONGGONG','EUNHYUNG','GWIGUM','TERROR','JUMAGAP','HOSIN','BOHO','KWAESOK','MANASHIELD','MUYEONG','REVIVE_INVISIBLE','FIRE','GICHEON','JEUNGRYEOK') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'YMIR',
  `szPointOn2` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NONE',
  `szPointPoly2` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szDurationPoly2` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `setAffectFlag2` set('YMIR','INVISIBILITY','SPAWN','POISON','SLOW','STUN','DUNGEON_READY','FORCE_VISIBLE','BUILDING_CONSTRUCTION_SMALL','BUILDING_CONSTRUCTION_LARGE','BUILDING_UPGRADE','MOV_SPEED_POTION','ATT_SPEED_POTION','FISH_MIDE','JEONGWIHON','GEOMGYEONG','CHEONGEUN','GYEONGGONG','EUNHYUNG','GWIGUM','TERROR','JUMAGAP','HOSIN','BOHO','KWAESOK','MANASHIELD') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'YMIR',
  `szPointOn3` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NONE',
  `szPointPoly3` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szDurationPoly3` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `szGrandMasterAddSPCostPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `prerequisiteSkillVnum` int(11) NOT NULL DEFAULT 0,
  `prerequisiteSkillLevel` int(11) NOT NULL DEFAULT 0,
  `eSkillType` set('NORMAL','MELEE','RANGE','MAGIC') CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT 'NORMAL',
  `iMaxHit` tinyint(4) NOT NULL DEFAULT 0,
  `szSplashAroundDamageAdjustPoly` varchar(100) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '1',
  `dwTargetRange` int(11) NOT NULL DEFAULT 1000,
  `dwSplashRange` int(10) UNSIGNED NOT NULL DEFAULT 0,
  PRIMARY KEY (`dwVnum`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of skill_proto
-- ----------------------------
INSERT INTO `skill_proto` VALUES (1, '»ï¿¬?ü', 1, 1, 1, 0, 'HP', '-( 1.1*atk + (0.5*atk +  1.5 * str)*k)', '40+100*k', '', '', '12', '-( 1.1*atk + (0.5*atk +  1.5 * str)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '40+100*k', 0, 0, 'MELEE', 5, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (2, '??¹æ?³¿ì', 1, 1, 1, 0, 'HP', '-(3*atk + (0.8*atk + str*5 + dex*3 +con)*k)', '50+130*k', '', '', '15', '-(3*atk + (0.8*atk + str*5 + dex*3 +con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '50+130*k', 0, 0, 'MELEE', 12, '1', 0, 200);
INSERT INTO `skill_proto` VALUES (3, '?ü±??¥', 1, 1, 1, 0, 'ATT_SPEED', '50*k', '50+140*k', '60+90*k', '', '63+10*k', '50*k', '', 'SELFONLY', 'JEONGWIHON', 'MOV_SPEED', '20*k', '60+90*k', '', '', '', '', '50+140*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (4, '°?°æ', 1, 1, 1, 0, 'ATT_GRADE', '(100 + str + lv * 3)*k', '100+200*k', '30+50*k', '', '30+10*k', '(100 + str + lv * 3)*k', '', 'SELFONLY', 'GEOMGYEONG', 'NONE', '', '', '', '', '', '', '100+200*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (5, '?º?¯°?', 1, 1, 1, 0, 'HP', '-(2*atk + (atk + dex*3 + str*7 + con)*k)', '60+120*k', '', '', '12', '-(2*atk + (atk + dex*3 + str*7 + con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'MOV_SPEED', '150', '3', '', '', '', '', '60+120*k', 0, 0, 'MELEE', 4, '1', 0, 200);
INSERT INTO `skill_proto` VALUES (16, '±â°ø?ü', 1, 1, 1, 0, 'HP', '-(2.3*atk + (4*atk  + str*4 + con)*k)', '60+120*k', '', '', '15', '-(2.3*atk + (4*atk  + str*4 + con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '60+120*k', 0, 0, 'MELEE', 4, '1', 0, 100);
INSERT INTO `skill_proto` VALUES (17, '°?»ê?¸¿ì', 1, 1, 1, 0, 'HP', '-(2.3*atk + (3*atk + str*4 + con*3)*k)', '60+150*k', '', '', '15', '-(2.3*atk + (3*atk + str*4 + con*3)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '60+150*k', 0, 0, 'MELEE', 8, '1', 0, 200);
INSERT INTO `skill_proto` VALUES (18, '´ë?ø°¢', 1, 1, 1, 0, 'HP', '-(2*atk + (2*atk + 2*dex + 2*con + str*4)*k)', '50+140*k', '', '', '25', '-(2*atk + (2*atk + 2*dex + 2*con + str*4)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SELFONLY,SPLASH,ATTACK_STUN', '', 'NONE', '100+k*1000/6', '2', '', '', '', '', '50+140*k', 0, 0, 'MELEE', 10, '1', 0, 400);
INSERT INTO `skill_proto` VALUES (19, '?µ±???', 1, 1, 1, 0, 'DEF_GRADE', '(200 + str*0.2 + con*0.5 ) *k', '80+220*k', '60+90*k', '', '63+10*k', '(200 + str*0.2 + con*0.5 ) *k', '', 'SELFONLY', 'CHEONGEUN', 'MOV_SPEED', '-(1+9*k)', '60+90*k', '', '', '', '', '80+220*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (20, '°??³', 1, 1, 1, 0, 'HP', '-(2*atk + (atk + dex*3 + str*5 + con)*k)', '40+120*k', '', '', '20', '-(2*atk + (atk + dex*3 + str*5 + con)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '40+120*k', 0, 0, 'MELEE', 10, '0.5', 1200, 200);
INSERT INTO `skill_proto` VALUES (31, '¾?½?', 2, 1, 1, 0, 'HP', '-(atk + (1.2 * atk + number(500, 700) + dex*4+ str*4 )*k)', '40+160*k', '', '', '15', '-(atk + (1.2 * atk + number(500, 700) + dex*4+ str*4 )*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'MELEE', 6, '0.8', 0, 0);
INSERT INTO `skill_proto` VALUES (32, '±?½??º¿µ', 2, 1, 1, 0, 'HP', '-(atk + (1.6* atk + number(200,300) + dex*7 + str*7)*k)', '40+160*k', '', '', '20', '-(atk + (1.6* atk + number(200,300) + dex*7 + str*7)*k)', '', 'ATTACK,USE_MELEE_DAMAGE', '', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'MELEE', 6, '0.8', 800, 0);
INSERT INTO `skill_proto` VALUES (33, '?÷·û»ì', 2, 1, 1, 0, 'HP', '-(2*atk + (0.5*atk + dex*9 + str*7)*k)', '50+140*k', '', '', '25', '-(2*atk + (0.5*atk + dex*9 + str*7)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,ATTACK_POISON', '', 'NONE', '40*k', '', '', '', '', '', '50+140*k', 0, 0, 'MELEE', 12, '0.8', 0, 0);
INSERT INTO `skill_proto` VALUES (34, '?º?ü¹ý', 2, 1, 1, 0, 'NONE', '', '30+60*k', '15+30*k', '', '60', '', '', 'SELFONLY', 'EUNHYUNG', 'NONE', '', '', '', '', '', '', '30+60*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (35, '»ê°øº?', 2, 1, 1, 0, 'HP', '-(lv*2+(atk + str*3 + dex*18)*k)', '40+130*k', '', '', '25', '-(lv*2+(atk + str*3 + dex*18)*k)', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,ATTACK_POISON', '', 'NONE', '60*k', '5+25*k', '', '', '', '', '40+130*k', 0, 0, 'MAGIC', 0, '0.5', 800, 200);
INSERT INTO `skill_proto` VALUES (46, '¿¬»ç', 2, 1, 1, 0, 'HP', '-(atk + 0.3*atk*floor(2+k*6)+ (0.8*atk+dex*8*ar) *k)', '40+130*k', '', '', '15', '-(atk + 0.2*atk*floor(2+k*6)+ (0.8*atk+dex*8*ar) *k)', '', 'ATTACK,USE_ARROW_DAMAGE', '', 'NONE', '', '', '', '', '', '', '40+130*k', 0, 0, 'RANGE', 1, '1', 2500, 0);
INSERT INTO `skill_proto` VALUES (47, '°ü°?¼ú', 2, 1, 1, 0, 'HP', '-(atk + (1.9*atk + dex*2+ str*2)*k)', '30+130*k', '', '', '12', '-(atk + (1.7*atk + dex*2+ str*2)*k)', '', 'ATTACK,USE_ARROW_DAMAGE', '', 'NONE', '', '', '', '', '', '', '30+130*k', 0, 0, 'RANGE', 8, '1', 2500, 0);
INSERT INTO `skill_proto` VALUES (48, '?­?¶??', 2, 1, 1, 0, 'HP', '-(1.5*atk + (2.8*atk + number(100, 300))*k)', '50+130*k', '', '', '25', '-(1.5*atk + (2.6*atk + number(100, 300))*k)', '', 'ATTACK,SPLASH,USE_ARROW_DAMAGE', '', 'NONE', '', '', '', '', '', '', '50+130*k', 0, 0, 'RANGE', 12, '0.6', 2500, 300);
INSERT INTO `skill_proto` VALUES (49, '°æ°ø¼ú', 2, 1, 1, 0, 'MOV_SPEED', '60*k', '30+40*k', '15+30*k', '', '30+30*k', '60*k', '', 'SELFONLY', 'GYEONGGONG', 'NONE', '', '', '', '', '', '', '30+40*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (50, 'µ¶±â±?', 2, 1, 1, 0, 'HP', '-(atk + (1.5*atk + number(100, 200)+dex*6+str*2)*k)', '40+160*k', '', '', '25', '-(atk + (1.2*atk + number(100, 200)+dex*6+str*2)*k)', '', 'ATTACK,SPLASH,USE_ARROW_DAMAGE,CRUSH,ATTACK_POISON', '', 'NONE', '80*k', '15+30*k', '', '', '', '', '40+160*k', 0, 0, 'RANGE', 12, '0.5', 2500, 300);
INSERT INTO `skill_proto` VALUES (61, '¼â·??ö', 3, 1, 1, 0, 'HP', '-(atk + 2*lv + iq*2 + ( 2*atk + str*4 + iq*14) * k)', '30+140*k', '', '', '10', '-(atk + 2*lv + iq*2 + ( 2*atk + str*4 + iq*14) * k)', '', 'ATTACK,USE_MELEE_DAMAGE,PENETRATE', '', 'NONE', '1+k*9', '', '', '', '', '', '30+140*k', 0, 0, 'MELEE', 4, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (62, '¿ë±???', 3, 1, 1, 0, 'HP', '-(1.1 * atk + 2*lv + iq*2+(1.5*atk + str + iq*12) * k)', '50+150*k', '', '', '15', '-(1.1 * atk + 2*lv + iq*2+(1.5*atk + str + iq*12) * k)', '', 'ATTACK,USE_MELEE_DAMAGE,SELFONLY,SPLASH,IGNORE_TARGET_RATING', '', 'NONE', '1+k*9', '', '', '', '', '', '50+150*k', 0, 0, 'MELEE', 12, '1', 0, 500);
INSERT INTO `skill_proto` VALUES (63, '±?°?', 3, 1, 1, 0, 'ATT_GRADE', '(3 * iq + 2 * lv)*k', '20+240*k', '50+100*k', '2+23*k', '0', '(3 * iq + 2 * lv)*k', '', 'SELFONLY,TOGGLE', 'GWIGUM', 'HIT_HP_RECOVER', '10*k', '50+80*k', '', '', '', '', '20+240*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (64, '°ø?÷', 3, 1, 1, 0, 'DODGE', '1 + 29 * k', '60+120*k', '60+100*k', '', '100', '1 + 29 * k', '', 'SELFONLY', 'TERROR', 'NONE', '', '', '', '', '', '', '60+120*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (65, '??¸¶°©', 3, 1, 1, 0, 'DEF_GRADE', '(iq+30)*k', '70+170*k', '30+120*k', '', '33+140*k', '(iq+30)*k', '', 'SELFONLY', 'JUMAGAP', 'REFLECT_MELEE', '(iq/4+10)*k', '30+120*k', '', '', '', '', '70+170*k', 0, 0, 'NORMAL', 1, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (66, '??¹ý¼ú', 3, 1, 1, 0, 'HP', '-(40 +5*lv + 2*iq+(10*iq + 7*mwep + number(50,100) )*ar*k)', '30+120*k', '', '', '12', '-(40 +5*lv + 2*iq+(10*iq + 7*mwep + number(50,100) )*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH,REMOVE_GOOD_AFFECT', '', 'NONE', '10+40*k', '7+23*k', '', '', '', '', '30+120*k', 0, 0, 'NORMAL', 5, '0.6', 1800, 200);
INSERT INTO `skill_proto` VALUES (76, '¸¶·?', 3, 1, 1, 0, 'HP', '-(40 +5*lv + 2*iq +(13*iq + 6*mwep + number(50,100) )*ar*k)', '30+140*k', '', '', '7', '-(40 +5*lv + 2*iq +(13*iq + 6*mwep + number(50,100) )*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '30+140*k', 0, 0, 'MAGIC', 5, '0.6', 1500, 200);
INSERT INTO `skill_proto` VALUES (77, '?­¿°?ø', 3, 1, 1, 0, 'HP', '-(5*lv + 2*iq+(10*iq + 6*mwep + str*4 + con*2 + number(180,200) )*k)', '60+140*k', '', '', '12', '-(5*lv + 2*iq+(10*iq + 6*mwep + str*4 + con*2 + number(180,200) )*k)', '', 'ATTACK,SELFONLY,COMPUTE_MAGIC_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '60+140*k', 0, 0, 'MAGIC', 15, '0.8', 0, 500);
INSERT INTO `skill_proto` VALUES (78, '¹«¿µ?ø', 3, 1, 1, 0, 'HP', '-(30+ 2*lv + 2*iq+(7*iq + 6*mwep + number(200,500))*ar*k)', '20+30*k', '40+30*k', '5+40*k', '43+30*k', '-(30+ 2*lv + 2*iq+(7*iq + 6*mwep + number(200,500))*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH,TOGGLE', '', 'NONE', '', '', '', '', '', '', '20+30*k', 0, 0, 'MAGIC', 1, '1', 800, 0);
INSERT INTO `skill_proto` VALUES (79, '?æ½?¼ö?£', 3, 1, 1, 0, 'DEF_GRADE', '(0.5*iq+15)*k', '20+30*k', '60+120*k', '5+10*k', '63+10*k', '(0.5*iq+15)*k', '', 'SELFONLY,TOGGLE', 'MANASHIELD', 'MANASHIELD', '100-((iq*0.84)*k)', '60+10*k', '', '', '', '', '20+30*k', 0, 0, 'MAGIC', 1, '0.8', 0, 0);
INSERT INTO `skill_proto` VALUES (80, '?õ¼?¸¶·?', 3, 1, 1, 0, 'HP', '-(40 + 2* lv + 2*iq +(2 * con + 2 * dex + 13*iq + 6*mwep + number(180, 200))*ar*k)', '40+120*k', '', '', '12', '-(40 + 2* lv + 2*iq +(2 * con + 2 * dex + 13*iq + 6*mwep + number(180, 200))*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH,ATTACK_SLOW', '', 'NONE', '333+300*k', '10+10*k', '', '', '', '', '40+120*k', 0, 0, 'MAGIC', 9, '0.8', 1200, 400);
INSERT INTO `skill_proto` VALUES (81, '¸¶?¯°?', 3, 1, 1, 0, 'HP', '-(120 + 6*lv + (5 * con + 5 * dex + 29*iq + 9*mwep)*ar*k)', '80+220*k', '', '', '24', '-(120 + 6*lv + (5 * con + 5 * dex + 29*iq + 9*mwep)*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '80+220*k', 0, 0, 'MAGIC', 9, '0.4', 1500, 200);
INSERT INTO `skill_proto` VALUES (91, 'ºñ??º?', 4, 1, 1, 0, 'HP', '-(70 + 4*lv + (20*iq+5*mwep+50)*ar*k)', '30+160*k', '', '', '7', '-(70 + 4*lv + (20*iq+5*mwep+50)*ar*k)', '', 'ATTACK,COMPUTE_MAGIC_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '30+160*k', 0, 0, 'MAGIC', 5, '0.5', 1800, 201);
INSERT INTO `skill_proto` VALUES (92, '¿ë??»ê', 4, 1, 1, 0, 'HP', '-(60 + 5*lv + (18*iq + 6*mwep + 120)*ar*k)', '50+160*k', '', '', '8', '-(60 + 5*lv + (18*iq + 6*mwep + 120)*ar*k)', '', 'ATTACK,ATTACK_FIRE_CONT', '', 'NONE', 'lv+5*iq *k', 'iq*0.2*k', '', '', '', '', '50+160*k', 0, 0, 'MAGIC', 10, '0.8', 0, 0);
INSERT INTO `skill_proto` VALUES (93, '??·æ?ø', 4, 1, 1, 0, 'HP', '-(80 + 6*lv + (20*iq+14*mwep+120)*ar*k)', '50+160*k', '', '', '20', '-(80 + 6*lv + (20*iq+14*mwep+120)*ar*k)', '', 'ATTACK,SELFONLY,SPLASH,ATTACK_FIRE_CONT', '', 'NONE', 'lv+5*iq *k', 'iq*0.2*k', '', '', '', '', '50+160*k', 0, 0, 'MAGIC', 15, '0.8', 0, 500);
INSERT INTO `skill_proto` VALUES (94, '?£½?', 4, 1, 1, 0, 'RESIST_NORMAL', '(iq*0.3+5)*(2*k+0.5)/(k+1.5)', '40+160*k', '60+200*k', '', '10', '(iq*0.3+5)*(2*k+0.5)/(k+1.5)', '', '', 'HOSIN', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'NORMAL', 1, '1', 800, 0);
INSERT INTO `skill_proto` VALUES (95, '¹?»ç', 4, 1, 1, 0, 'REFLECT_MELEE', '5+(iq*0.3 + 5)*k', '40+160*k', '60+200*k', '', '10', '5+(iq*0.3 + 5)*k', '', '', 'BOHO', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (96, '±â?µ´ë°ø', 4, 1, 1, 0, 'CRITICAL', '(iq*0.3+5)*(2*k+0.5)/(k+1.5)', '40+160*k', '60+100*k', '', '10', '(iq*0.3+5)*(2*k+0.5)/(k+1.5)', '', '', 'GICHEON', 'NONE', '', '', '', '', '', '', '40+160*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (106, '³ú?ü·?', 4, 1, 1, 0, 'HP', '-(60 + 4*lv + (7*iq+8*mwep+number(iq*5,iq*15))*ar*k)', '30+150*k', '', '', '7', '-(60 + 4*lv + (7*iq+8*mwep+number(iq*5,iq*15))*ar*k)', '', 'ATTACK,SPLASH', '', 'NONE', '', '', '', '', '', '', '30+150*k', 0, 0, 'MAGIC', 5, '0.6', 1800, 200);
INSERT INTO `skill_proto` VALUES (107, 'º­¶ô', 4, 1, 1, 0, 'HP', '-(40 + 4*lv + (13*iq+7*mwep+number(iq*5,iq*16))*ar*k)', '50+150*k', '', '', '15', '-(40 + 4*lv + (13*iq+7*mwep+number(iq*5,iq*16))*ar*k)', '', 'ATTACK,SPLASH,ATTACK_STUN', '', 'NONE', '50+1000*k/6', '5', '', '', '', '', '50+150*k', 0, 0, 'MAGIC', 15, '0.8', 1500, 400);
INSERT INTO `skill_proto` VALUES (108, '?ø·?°?', 4, 1, 1, 0, 'HP', '-(50 + 5*lv + (6*iq+6*mwep+number(1,800))*ar*k) * (1-chain*0.13)', '40+180*k', '', '', '10', '-(50 + 5*lv + (6*iq+6*mwep+number(1,800))*ar*k) * (1-chain*0.13)', '', 'ATTACK', '', 'NONE', '', '', '', '', '', '', '40+180*k', 0, 0, 'MAGIC', 7, '0.8', 2500, 0);
INSERT INTO `skill_proto` VALUES (109, '?¤¾÷??', 4, 1, 1, 0, 'HP', '200+7*lv+(30*iq+6*mwep+600)*k', '40+200*k', '', '', '10', '200+7*lv+(30*iq+6*mwep+600)*k', '', 'REMOVE_BAD_AFFECT', '', 'NONE', '20+80*k', '0', '', '', '', '', '40+200*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (110, '?è¼?', 4, 1, 1, 0, 'MOV_SPEED', '5 + 35*k', '60+120*k', '60+100*k', '', '10', '5 + 35*k', '', '', 'KWAESOK', 'CASTING_SPEED', '3+33*k', '60+100*k', '', '', '', '', '60+120*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (111, '?õ·?¼ú', 4, 1, 1, 0, 'ATT_GRADE', '10+(iq*0.4 +20)*k', '60+120*k', '60+100*k', '', '10', '10+(iq*0.4 +30)*k', '', '', 'JEUNGRYEOK', 'NONE', '', '', '', '', '', '', '60+120*k', 0, 0, 'NORMAL', 1, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (121, '?ë¼?·?', 0, 1, 40, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (122, '¿¬°è±â', 0, 1, 2, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (124, '?¤±¤¼ú', 0, 1, 40, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (125, 'º¯½?', 0, 1, 40, 0, 'NONE', '', '', '10+1000*k', '', '', '', '', 'DISABLE_BY_POINT_UP', 'YMIR', 'NONE', '', '', 'YMIR', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 1000, 0);
INSERT INTO `skill_proto` VALUES (126, '½?¼ö¾î', 0, 1, 20, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (127, '?µ?¶¾î', 0, 1, 20, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (128, '?ø³ë¾î', 0, 1, 20, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (129, 'µ?°©¼ú', 0, 1, 40, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', 'NONE', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (130, '½?¸¶', 0, 1, 1, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (131, '¸»¼??¯', 0, 1, 10, 0, 'NONE', '', '', '', '', '', '', '', 'DISABLE_BY_POINT_UP', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (137, '³­¹«', 5, 1, 1, 50, 'HP', '-(atk+(2*atk*k))', '60+80*k', '', '', '5-(4*k)', '', '', 'ATTACK,USE_MELEE_DAMAGE,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 10, '1', 300, 0);
INSERT INTO `skill_proto` VALUES (138, 'µ¹°?', 5, 1, 1, 52, 'HP', '-(2.4*(200+1.5*lv)+(3*200*k))', '60+120*k', '', '', '15', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH_LONG', '', 'MOV_SPEED', '50', '5', '', '', '', '', '', 0, 0, 'MELEE', 6, '1', 400, 100);
INSERT INTO `skill_proto` VALUES (139, '?»?â', 5, 1, 1, 55, 'HP', '-(2*(200+1.5*lv)+(3*200*k))', '60+160*k', '', '', '20', '', '', 'ATTACK,USE_MELEE_DAMAGE,SELFONLY,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 12, '1', 400, 250);
INSERT INTO `skill_proto` VALUES (140, '³­¹«(?°)', 5, 1, 1, 50, 'HP', '-(atk+(2*atk*k))', '60+80*k', '', '', '10', '', '', 'ATTACK,USE_ARROW_DAMAGE,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, '', 5, '1', 2500, 0);
INSERT INTO `skill_proto` VALUES (151, '¿ë¾?', 0, 1, 7, 0, 'NONE', '', '', '', '', '', '', '', '', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (152, '¿ë½?????', 0, 1, 7, 0, 'MAX_HP', 'maxhp*0.2*k', '150+150*k', '300', '', '600', '', '', '', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (153, '¿ë½?????º¹', 0, 1, 7, 0, 'MAX_SP', 'maxsp*0.2*k', '150+150*k', '300', '', '600', '', '', '', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (154, '¼º??°©', 0, 1, 7, 0, 'DEF_GRADE', 'odef*0.1*k', '150+150*k', '180', '', '480', '', '', '', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (155, '°¡¼??­', 0, 1, 7, 0, 'MOV_SPEED', '15*k', '150+150*k', '180', '', '480', '', '', '', '', 'ATT_SPEED', '15*k', '180', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (156, '¿ë½???º?³ë', 0, 1, 7, 0, 'CRITICAL', '50*k', '150+150*k', '180', '', '480', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (157, '??¹®¼ú', 0, 1, 7, 0, 'CASTING_SPEED', '50*k', '150+150*k', '180', '', '480', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (158, '±æµå??µ¿', 0, 1, 3, 0, 'NONE', '', '', '', '', '', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (159, '°ø°£??¹®', 0, 1, 5, 0, 'NONE', '', '', '', '', '', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (160, '°¡¼??­', 0, 1, 5, 0, 'NONE', '3*k', '80-12*k', '300', '', '', '', '', 'SELFONLY', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (161, '°ø°£??¹®', 0, 1, 2, 0, 'NONE', '', '50', '', '', '', '', '', '', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (162, '°ø°£??µ¿', 0, 1, 2, 0, 'NONE', '', '20', '', '', '', '', '', '', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'NORMAL', 0, '1', 0, 0);
INSERT INTO `skill_proto` VALUES (256, 'CRUSH200½º?³', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '4', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 300);
INSERT INTO `skill_proto` VALUES (257, '??¹?¹ü?§350½º?³', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '6', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 525);
INSERT INTO `skill_proto` VALUES (258, 'CRUSH300½º?³', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '8', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 450);
INSERT INTO `skill_proto` VALUES (259, '??¹?¹ü?§200½º?³', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '10', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 300);
INSERT INTO `skill_proto` VALUES (260, 'CURSH400½º?³', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '12', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,CRUSH', '', 'NONE', '', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 600);
INSERT INTO `skill_proto` VALUES (261, 'µ¶250½º?³', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '10', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH,ATTACK_POISON', '', 'NONE', '80', '', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 375);
INSERT INTO `skill_proto` VALUES (262, 'SLOW300½º?³', 0, 1, 1, 0, 'HP', '-5*k*atk', '', '', '', '14', '', '', 'ATTACK,USE_MELEE_DAMAGE,SPLASH', '', 'MOV_SPEED', '-20', '10', '', '', '', '', '', 0, 0, 'MELEE', 0, '1', 0, 450);

-- ----------------------------
-- Table structure for string
-- ----------------------------
DROP TABLE IF EXISTS `string`;
CREATE TABLE `string`  (
  `name` varchar(64) CHARACTER SET latin1 COLLATE latin1_swedish_ci NOT NULL DEFAULT '',
  `text` text CHARACTER SET latin1 COLLATE latin1_swedish_ci NULL,
  PRIMARY KEY (`name`) USING BTREE
) ENGINE = MyISAM CHARACTER SET = latin1 COLLATE = latin1_swedish_ci ROW_FORMAT = DYNAMIC;

-- ----------------------------
-- Records of string
-- ----------------------------

SET FOREIGN_KEY_CHECKS = 1;
