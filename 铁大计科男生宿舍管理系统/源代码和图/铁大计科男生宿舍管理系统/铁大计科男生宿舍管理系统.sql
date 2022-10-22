/*
 Navicat Premium Data Transfer

 Source Server         : MySQL1
 Source Server Type    : MySQL
 Source Server Version : 50562
 Source Host           : localhost:3306
 Source Schema         : dormitory

 Target Server Type    : MySQL
 Target Server Version : 50562
 File Encoding         : 65001

 Date: 07/07/2021 18:11:10
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for d_admin
-- ----------------------------
DROP TABLE IF EXISTS `d_admin`;
CREATE TABLE `d_admin`  (
  `a_id` int(11) NOT NULL AUTO_INCREMENT,
  `a_username` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `a_password` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `a_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `a_phone` bigint(20) NULL DEFAULT NULL,
  `a_power` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `a_describe` varchar(40) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`a_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of d_admin
-- ----------------------------
INSERT INTO `d_admin` VALUES (1, 'dyh', '943E1A667C406771A65BF22A3306E566', '董亚恒', 1374657, '1', '低');
INSERT INTO `d_admin` VALUES (2, 'csp', 'F60DB57E1F60C5950586AB73E192B2B3', '陈顺鹏', 1232244, '1', '高');
INSERT INTO `d_admin` VALUES (3, 'hyj', 'b9b1d96b82fb0fa8075c6bee27329040', '韩英杰', 1231233, '1', '高');
INSERT INTO `d_admin` VALUES (4, 'cjz', '7dadc3fd09f9ffbfe116f928ef4966a0', '崔金泽', 1233423, '1', '高');

-- ----------------------------
-- Table structure for d_class
-- ----------------------------
DROP TABLE IF EXISTS `d_class`;
CREATE TABLE `d_class`  (
  `c_id` int(11) NOT NULL AUTO_INCREMENT,
  `c_classid` int(11) NOT NULL,
  `c_classname` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `c_counsellor` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`c_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 7 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of d_class
-- ----------------------------
INSERT INTO `d_class` VALUES (1, 1, '信1901-1', '董亚恒');
INSERT INTO `d_class` VALUES (2, 2, '信1901-2', '董亚恒');
INSERT INTO `d_class` VALUES (3, 3, '信1901-3', '董亚恒');
INSERT INTO `d_class` VALUES (4, 4, '信1901-4', '董亚恒');
INSERT INTO `d_class` VALUES (5, 5, '信1901-5', '董亚恒');
INSERT INTO `d_class` VALUES (6, 6, '信1901-6', '董亚恒');

-- ----------------------------
-- Table structure for d_dormgrade
-- ----------------------------
DROP TABLE IF EXISTS `d_dormgrade`;
CREATE TABLE `d_dormgrade`  (
  `g_id` int(11) NOT NULL AUTO_INCREMENT,
  `d_id` int(11) NOT NULL,
  `d_dormbuilding` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `d_grade` int(11) NULL DEFAULT NULL,
  `create_time` datetime NULL DEFAULT NULL,
  `update_time` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`g_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 7 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of d_dormgrade
-- ----------------------------
INSERT INTO `d_dormgrade` VALUES (1, 211, '9号楼', 6, '2021-07-02 10:51:17', '2021-07-02 17:28:38');
INSERT INTO `d_dormgrade` VALUES (2, 649, '9号楼', 7, '2021-07-02 16:36:47', '2021-07-02 16:36:55');
INSERT INTO `d_dormgrade` VALUES (3, 651, '9号楼', 8, '2021-07-02 16:37:42', '2021-07-02 16:37:47');
INSERT INTO `d_dormgrade` VALUES (5, 123, '9号楼', 6, '2021-07-05 23:33:06', '2021-07-05 23:33:06');

-- ----------------------------
-- Table structure for d_dormitoryinfo
-- ----------------------------
DROP TABLE IF EXISTS `d_dormitoryinfo`;
CREATE TABLE `d_dormitoryinfo`  (
  `d_id` int(11) NOT NULL AUTO_INCREMENT,
  `s_dormitoryid` int(11) NOT NULL,
  `d_dormbuilding` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `d_bedtotal` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `d_bed` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `a_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`d_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 5 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of d_dormitoryinfo
-- ----------------------------
INSERT INTO `d_dormitoryinfo` VALUES (1, 211, '9号楼', '4', '4', '董亚恒');
INSERT INTO `d_dormitoryinfo` VALUES (2, 649, '9号楼', '4', '4', '董亚恒');
INSERT INTO `d_dormitoryinfo` VALUES (3, 651, '9号楼', '4', '4', '董亚恒');
INSERT INTO `d_dormitoryinfo` VALUES (4, 234, '9号楼', '6', '5', '董亚恒');

-- ----------------------------
-- Table structure for d_dormrepair
-- ----------------------------
DROP TABLE IF EXISTS `d_dormrepair`;
CREATE TABLE `d_dormrepair`  (
  `r_id` int(11) NOT NULL AUTO_INCREMENT,
  `d_id` int(11) NOT NULL,
  `d_dormbuilding` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `r_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `reason` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `create_time` datetime NULL DEFAULT NULL,
  `update_time` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`r_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 6 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of d_dormrepair
-- ----------------------------
INSERT INTO `d_dormrepair` VALUES (1, 211, '9号楼', '张三', '水池', '2021-06-30 22:39:58', '2021-07-01 22:39:58');
INSERT INTO `d_dormrepair` VALUES (2, 649, '9号楼', '李四', '灯管', '2021-06-30 16:29:20', '2021-07-01 16:29:35');
INSERT INTO `d_dormrepair` VALUES (3, 651, '9号楼', '王麻子', '水龙头', '2021-06-30 16:31:14', '2021-07-01 16:31:20');
INSERT INTO `d_dormrepair` VALUES (5, 234, '9', '王五', '灯泡', '2021-07-05 23:13:07', '2021-07-05 23:14:09');

-- ----------------------------
-- Table structure for d_stgrade
-- ----------------------------
DROP TABLE IF EXISTS `d_stgrade`;
CREATE TABLE `d_stgrade`  (
  `g_id` int(11) NOT NULL AUTO_INCREMENT,
  `s_studentid` int(11) NOT NULL,
  `s_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `s_grade` int(11) NULL DEFAULT NULL,
  `s_classid` int(11) NULL DEFAULT NULL,
  `s_dormitoryid` int(11) NULL DEFAULT NULL,
  `create_time` datetime NULL DEFAULT NULL,
  `update_time` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`g_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 12 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of d_stgrade
-- ----------------------------
INSERT INTO `d_stgrade` VALUES (2, 20190002, '陈顺鹏', 7, 3, 211, '2021-07-01 17:00:05', '2021-07-01 17:00:13');
INSERT INTO `d_stgrade` VALUES (3, 20190003, '杨子腾', 6, 2, 211, '2021-07-01 17:00:54', '2021-07-06 19:50:07');
INSERT INTO `d_stgrade` VALUES (4, 20190004, '干冲', 7, 5, 649, '2021-07-01 17:01:33', '2021-07-01 17:02:15');
INSERT INTO `d_stgrade` VALUES (5, 20190005, '崔金泽', 7, 3, 211, '2021-07-02 17:03:03', '2021-07-02 17:03:09');
INSERT INTO `d_stgrade` VALUES (6, 20190006, '李易唐', 8, 4, 649, '2021-07-02 17:03:53', '2021-07-02 17:01:01');
INSERT INTO `d_stgrade` VALUES (7, 20190007, '王都和', 9, 4, 649, '2021-07-02 17:05:04', '2021-07-02 17:05:07');
INSERT INTO `d_stgrade` VALUES (8, 20190008, '李晓洋', 9, 2, 211, '2021-07-02 17:05:34', '2021-07-02 17:05:39');
INSERT INTO `d_stgrade` VALUES (9, 20190009, '贺运佳', 8, 1, 651, '2021-07-02 17:06:28', '2021-07-02 17:06:35');
INSERT INTO `d_stgrade` VALUES (10, 20190010, '秦剑', 8, 5, 651, '2021-07-02 17:07:09', '2021-07-05 23:40:58');
INSERT INTO `d_stgrade` VALUES (11, 20194123, '张三', 3, 2, 321, '2021-07-05 23:39:26', '2021-07-05 23:39:26');

-- ----------------------------
-- Table structure for d_student
-- ----------------------------
DROP TABLE IF EXISTS `d_student`;
CREATE TABLE `d_student`  (
  `s_id` int(11) NOT NULL AUTO_INCREMENT,
  `s_studentid` int(11) NOT NULL,
  `s_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `s_sex` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `s_age` int(11) NULL DEFAULT NULL,
  `s_phone` bigint(20) NULL DEFAULT NULL,
  `s_classid` int(11) NOT NULL,
  `s_classname` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `s_dormitoryid` int(11) NOT NULL,
  PRIMARY KEY (`s_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 15 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of d_student
-- ----------------------------
INSERT INTO `d_student` VALUES (1, 20190001, '韩英杰', '男', 20, 1374657, 1, '信1901-1', 649);
INSERT INTO `d_student` VALUES (2, 20190002, '陈顺鹏', '男', 20, 1374657, 3, '信1901-3', 211);
INSERT INTO `d_student` VALUES (3, 20190003, '杨子腾', '男', 20, 1374657, 2, '信1901-2', 211);
INSERT INTO `d_student` VALUES (4, 20190004, '干冲', '男', 20, 1374657, 5, '信1901-5', 649);
INSERT INTO `d_student` VALUES (5, 20190005, '崔金泽', '男', 20, 1374657, 3, '信1901-3', 211);
INSERT INTO `d_student` VALUES (6, 20190006, '李易唐', '男', 20, 1374657, 4, '信1901-4', 649);
INSERT INTO `d_student` VALUES (7, 20190007, '王都和', '男', 20, 12312312312, 4, '信1901-4', 649);
INSERT INTO `d_student` VALUES (8, 20190008, '李晓洋', '男', 20, 1374657, 2, '信1901-2', 211);
INSERT INTO `d_student` VALUES (9, 20190009, '贺运佳', '男', 20, 1374657, 1, '信1901-1', 651);
INSERT INTO `d_student` VALUES (10, 20190010, '秦剑', '男', 20, 1374657, 5, '信1901-5', 651);
INSERT INTO `d_student` VALUES (11, 20190011, '唐子豪', '男', 20, 1374657, 4, '信1901-4', 651);
INSERT INTO `d_student` VALUES (12, 20190012, '王凯迪', '男', 20, 1374657, 3, '信1901-3', 651);
INSERT INTO `d_student` VALUES (14, 2012133, '奥术师', '男', 19, 1233333, 3, '信1901-3', 211);

-- ----------------------------
-- Table structure for d_visitor
-- ----------------------------
DROP TABLE IF EXISTS `d_visitor`;
CREATE TABLE `d_visitor`  (
  `v_id` int(11) NOT NULL AUTO_INCREMENT,
  `v_name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `v_phone` bigint(20) NULL DEFAULT NULL,
  `v_dormitoryid` int(11) NULL DEFAULT NULL,
  `v_dormbuilding` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NULL DEFAULT NULL,
  `create_time` datetime NULL DEFAULT NULL,
  PRIMARY KEY (`v_id`) USING BTREE
) ENGINE = InnoDB AUTO_INCREMENT = 14 CHARACTER SET = utf8mb4 COLLATE = utf8mb4_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of d_visitor
-- ----------------------------
INSERT INTO `d_visitor` VALUES (10, '张老师', 134244, 211, '9', '2021-07-02 20:30:16');
INSERT INTO `d_visitor` VALUES (11, '李老师', 134244, 611, '16', '2021-07-02 20:30:41');
INSERT INTO `d_visitor` VALUES (12, '刘老师', 142453, 314, '9', '2021-07-02 20:31:05');
INSERT INTO `d_visitor` VALUES (13, '马老师', 131231, 611, '16', '2021-07-05 23:45:14');

SET FOREIGN_KEY_CHECKS = 1;
