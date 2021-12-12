-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: localhost    Database: shop
-- ------------------------------------------------------
-- Server version	5.6.51-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `shop`
--

DROP TABLE IF EXISTS `shop`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `shop` (
  `Item_ID` int(11) NOT NULL,
  `Item_Name` varchar(45) COLLATE utf8_bin NOT NULL,
  `Item_HP` bigint(20) DEFAULT NULL,
  `Item_MP` bigint(20) DEFAULT NULL,
  `Item_AP` bigint(20) DEFAULT NULL,
  `Item_DP` bigint(20) DEFAULT NULL,
  `Item_Cost` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`Item_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `shop`
--

LOCK TABLES `shop` WRITE;
/*!40000 ALTER TABLE `shop` DISABLE KEYS */;
INSERT INTO `shop` VALUES (3001,'Divine Sunderer',400,0,35,0,3300),(3002,'Muramana',0,860,35,0,2900),(3003,'Essence Reaver',0,0,45,0,2800),(3004,'Guardian Angel',0,0,40,40,2800),(3005,'Wit\'s End',0,0,40,50,3100),(3006,'Frozen Heart',0,400,0,80,2500);
/*!40000 ALTER TABLE `shop` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-13  4:29:25
-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: localhost    Database: enemy
-- ------------------------------------------------------
-- Server version	5.6.51-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `enemystatus`
--

DROP TABLE IF EXISTS `enemystatus`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `enemystatus` (
  `Enemy_ID` int(11) NOT NULL,
  `Enemy_Name` varchar(45) COLLATE utf8_bin NOT NULL,
  `Enemy_HP` int(11) DEFAULT NULL,
  `Enemy_MP` int(11) DEFAULT NULL,
  `Enemy_AP` int(11) DEFAULT NULL,
  `Enemy_DP` int(11) DEFAULT NULL,
  `Enemy_Cost` int(11) DEFAULT NULL,
  PRIMARY KEY (`Enemy_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `enemystatus`
--

LOCK TABLES `enemystatus` WRITE;
/*!40000 ALTER TABLE `enemystatus` DISABLE KEYS */;
INSERT INTO `enemystatus` VALUES (1,'Teemo',514,334,54,24,0),(2,'Graves',555,325,68,33,0),(3,'Ryze',575,300,58,22,0),(4,'Vayne',515,232,60,23,0),(5,'Galio',562,500,59,24,0);
/*!40000 ALTER TABLE `enemystatus` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `item`
--

DROP TABLE IF EXISTS `item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item` (
  `Enemy_ID_item` int(11) NOT NULL,
  `Item_ID` int(11) NOT NULL,
  `Item_name` text COLLATE utf8_bin NOT NULL,
  `Item_HP` int(11) DEFAULT NULL,
  `Item_MP` int(11) DEFAULT NULL,
  `Item_AP` int(11) DEFAULT NULL,
  `Item_DP` int(11) DEFAULT NULL,
  `Item_Cost` int(11) DEFAULT NULL,
  PRIMARY KEY (`Enemy_ID_item`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item`
--

LOCK TABLES `item` WRITE;
/*!40000 ALTER TABLE `item` DISABLE KEYS */;
/*!40000 ALTER TABLE `item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skill`
--

DROP TABLE IF EXISTS `skill`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `skill` (
  `Enemy_ID` int(11) NOT NULL,
  `Enemy_name` varchar(45) COLLATE utf8_bin NOT NULL,
  `Name_Q` varchar(45) COLLATE utf8_bin NOT NULL,
  `Damage_Q` int(11) DEFAULT NULL,
  `Name_W` varchar(45) COLLATE utf8_bin NOT NULL,
  `Damage_W` int(11) DEFAULT NULL,
  `Name_E` varchar(45) COLLATE utf8_bin NOT NULL,
  `Damage_E` int(11) DEFAULT NULL,
  `Name_R` varchar(45) COLLATE utf8_bin NOT NULL,
  `Damage_R` int(11) DEFAULT NULL,
  PRIMARY KEY (`Enemy_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `skill`
--

LOCK TABLES `skill` WRITE;
/*!40000 ALTER TABLE `skill` DISABLE KEYS */;
INSERT INTO `skill` VALUES (1,'Teemo','Blinding Dart',80,'Move Quick',0,'Toxic Shot',24,'Noxious Trap',200),(2,'Graves','End of the Line',130,'Smoke Screen',60,'Quickdraw',0,'Collateral Damage',450),(3,'Ryze','Overload',75,'Rune Prison',80,'Spell Flux',60,'Realm Warp',0),(4,'Vayne','Tumble',96,'Silver Bolts',50,'Condemn',50,'Final Hour',0),(5,'Galio','Winds of War',70,'Shield of Durand',60,'Justice Punch',90,'Hero\'s Entrance',150);
/*!40000 ALTER TABLE `skill` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-13  4:29:25
-- MySQL dump 10.13  Distrib 8.0.26, for Win64 (x86_64)
--
-- Host: localhost    Database: player
-- ------------------------------------------------------
-- Server version	5.6.51-log

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `item`
--

DROP TABLE IF EXISTS `item`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item` (
  `Player_ID_item` bigint(20) NOT NULL,
  `Item_ID` bigint(20) NOT NULL,
  `Item_name` varchar(45) COLLATE utf8_bin NOT NULL,
  `Item_HP` bigint(20) DEFAULT NULL,
  `Item_MP` bigint(20) DEFAULT NULL,
  `Item_AP` bigint(20) DEFAULT NULL,
  `Item_Cost` bigint(20) DEFAULT NULL,
  PRIMARY KEY (`Player_ID_item`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item`
--

LOCK TABLES `item` WRITE;
/*!40000 ALTER TABLE `item` DISABLE KEYS */;
INSERT INTO `item` VALUES (1,3002,'Muramana',0,860,35,0);
/*!40000 ALTER TABLE `item` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `playerstatus`
--

DROP TABLE IF EXISTS `playerstatus`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `playerstatus` (
  `Player_ID` int(11) NOT NULL,
  `Player_Name` varchar(45) COLLATE utf8_bin NOT NULL,
  `Player_HP` int(11) DEFAULT NULL,
  `Player_MP` int(11) DEFAULT NULL,
  `Player_AP` int(11) DEFAULT NULL,
  `Player_DP` int(11) DEFAULT NULL,
  `Player_Cost` int(11) DEFAULT NULL,
  PRIMARY KEY (`Player_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `playerstatus`
--

LOCK TABLES `playerstatus` WRITE;
/*!40000 ALTER TABLE `playerstatus` DISABLE KEYS */;
INSERT INTO `playerstatus` VALUES (1,'Ezreal',530,1235,95,24,4700);
/*!40000 ALTER TABLE `playerstatus` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `skill`
--

DROP TABLE IF EXISTS `skill`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `skill` (
  `Player_ID` int(11) NOT NULL,
  `Player_Name` varchar(45) COLLATE utf8_bin NOT NULL,
  `Name_Q` varchar(45) COLLATE utf8_bin NOT NULL,
  `Damage_Q` int(11) DEFAULT NULL,
  `Name_W` varchar(45) COLLATE utf8_bin NOT NULL,
  `Damage_W` int(11) DEFAULT NULL,
  `Name_E` varchar(45) COLLATE utf8_bin NOT NULL,
  `Damage_E` int(11) DEFAULT NULL,
  `Name_R` varchar(45) COLLATE utf8_bin NOT NULL,
  `Damage_R` int(11) DEFAULT NULL,
  PRIMARY KEY (`Player_ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `skill`
--

LOCK TABLES `skill` WRITE;
/*!40000 ALTER TABLE `skill` DISABLE KEYS */;
INSERT INTO `skill` VALUES (1,'Ezreal','Mystic Shot',20,'Essence Flux',80,'Arcane Shift',80,'Trueshot Barrage',350);
/*!40000 ALTER TABLE `skill` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2021-12-13  4:29:25
