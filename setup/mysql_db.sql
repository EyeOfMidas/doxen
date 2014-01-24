-- phpMyAdmin SQL Dump
-- version 3.4.10.1deb1
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Jan 18, 2014 at 05:17 PM
-- Server version: 5.5.34
-- PHP Version: 5.3.10-1ubuntu3.9

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- User: `doxen`
--

CREATE USER `doxen`@`localhost` IDENTIFIED BY 'doxenpassword';

-- --------------------------------------------------------

--
-- Database: `doxen`
--

DROP DATABASE IF EXISTS `doxen`;
CREATE DATABASE `doxen` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `doxen`;

-- --------------------------------------------------------

--
-- Table structure for table `comments`
--

CREATE TABLE IF NOT EXISTS `comments` (
  `comment_id` int(11) NOT NULL AUTO_INCREMENT,
  `content` text NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `url_name` varchar(256) NOT NULL,
  `is_edited` tinyint(1) NOT NULL DEFAULT '0',
  PRIMARY KEY (`comment_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `comment_comment_associations`
--

CREATE TABLE IF NOT EXISTS `comment_comment_associations` (
  `comment_id` int(11) NOT NULL,
  `parent_comment_id` int(11) NOT NULL,
  UNIQUE KEY `comment_id` (`comment_id`,`parent_comment_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `comment_file_associations`
--

CREATE TABLE IF NOT EXISTS `comment_file_associations` (
  `comment_id` int(11) NOT NULL,
  `file_id` int(11) NOT NULL,
  UNIQUE KEY `comment_id` (`comment_id`,`file_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `comment_post_associations`
--

CREATE TABLE IF NOT EXISTS `comment_post_associations` (
  `comment_id` int(11) NOT NULL,
  `post_id` int(11) NOT NULL,
  UNIQUE KEY `comment_id` (`comment_id`,`post_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `comment_user_associations`
--

CREATE TABLE IF NOT EXISTS `comment_user_associations` (
  `comment_id` int(11) NOT NULL,
  `user_id` int(11) NOT NULL,
  UNIQUE KEY `comment_id` (`comment_id`,`user_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `default_topics`
--

CREATE TABLE IF NOT EXISTS `default_topics` (
  `topic_id` int(11) NOT NULL,
  `sort_order` int(3) NOT NULL,
  UNIQUE KEY `UNIQUE` (`topic_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `files`
--

CREATE TABLE IF NOT EXISTS `files` (
  `file_id` int(11) NOT NULL AUTO_INCREMENT,
  `file_hash` varchar(255) NOT NULL,
  `name` varchar(255) NOT NULL,
  `size` int(11) NOT NULL,
  `type` varchar(255) NOT NULL,
  PRIMARY KEY (`file_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `posts`
--

CREATE TABLE IF NOT EXISTS `posts` (
  `post_id` int(11) NOT NULL AUTO_INCREMENT,
  `poster_user_id` int(11) NOT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `name` varchar(256) NOT NULL,
  `url_name` varchar(256) NOT NULL,
  `content` text NOT NULL,
  PRIMARY KEY (`post_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `post_file_associations`
--

CREATE TABLE IF NOT EXISTS `post_file_associations` (
  `post_id` int(11) NOT NULL,
  `file_id` int(11) NOT NULL,
  UNIQUE KEY `post_id` (`post_id`,`file_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `post_last_updated`
--

CREATE TABLE IF NOT EXISTS `post_last_updated` (
  `post_id` int(11) NOT NULL,
  `last_updated` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  UNIQUE KEY `post_id` (`post_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `post_tags`
--

CREATE TABLE IF NOT EXISTS `post_tags` (
  `post_id` int(11) NOT NULL,
  `tag_id` int(11) NOT NULL,
  UNIQUE KEY `post_id` (`post_id`,`tag_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `post_topic_associations`
--

CREATE TABLE IF NOT EXISTS `post_topic_associations` (
  `post_id` int(11) NOT NULL,
  `topic_id` int(11) NOT NULL,
  UNIQUE KEY `post_id` (`post_id`,`topic_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `ranks`
--

CREATE TABLE IF NOT EXISTS `ranks` (
  `rank_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`rank_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8;

--
-- Dumping data for table `ranks`
--

INSERT INTO `ranks` (`rank_id`, `name`) VALUES
(1, 'Administrator'),
(2, 'Owner'),
(3, 'Moderator');

-- --------------------------------------------------------

--
-- Table structure for table `topics`
--

CREATE TABLE IF NOT EXISTS `topics` (
  `topic_id` int(11) NOT NULL AUTO_INCREMENT,
  `display_name` varchar(64) NOT NULL,
  `url_name` varchar(64) NOT NULL,
  `description` text NOT NULL,
  `sidebar` text NOT NULL,
  PRIMARY KEY (`topic_id`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `topic_topic_associations`
--

CREATE TABLE IF NOT EXISTS `topic_topic_associations` (
  `topic_id` int(11) NOT NULL,
  `subtopic_id` int(11) NOT NULL,
  UNIQUE KEY `topic_id` (`topic_id`,`subtopic_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `email` varchar(255) NOT NULL,
  `username` varchar(256) NOT NULL,
  `display_name` varchar(256) NOT NULL,
  PRIMARY KEY (`user_id`),
  UNIQUE KEY `email` (`email`),
  UNIQUE KEY `username` (`username`)
) ENGINE=MyISAM  DEFAULT CHARSET=utf8;

--
-- Dumping data for table `users`
--

INSERT INTO `users` (`user_id`, `email`, `username`, `display_name`) VALUES
(1, 'admin@localhost', 'admin', 'Administrator');

-- --------------------------------------------------------

--
-- Table structure for table `users_auth`
--

CREATE TABLE IF NOT EXISTS `users_auth` (
  `user_id` int(11) NOT NULL,
  `passwordhash` varchar(255) NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Dumping data for table `users_auth`
--

INSERT INTO `users_auth` (`user_id`, `passwordhash`) VALUES
(1, 'd033e22ae348aeb5660fc2140aec35850c4da997');

-- --------------------------------------------------------

--
-- Table structure for table `user_file_associations`
--

CREATE TABLE IF NOT EXISTS `user_file_associations` (
  `user_id` int(11) NOT NULL,
  `file_id` int(11) NOT NULL,
  UNIQUE KEY `user_id` (`user_id`,`file_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `user_post_viewed`
--

CREATE TABLE IF NOT EXISTS `user_post_viewed` (
  `user_id` int(11) NOT NULL,
  `post_id` int(11) NOT NULL,
  `last_viewed` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  UNIQUE KEY `user_id` (`user_id`,`post_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `user_tags`
--

CREATE TABLE IF NOT EXISTS `user_tags` (
  `tag_id` int(11) NOT NULL AUTO_INCREMENT,
  `user_id` int(11) NOT NULL,
  `is_seen` tinyint(1) NOT NULL,
  `tagged_on` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`tag_id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `user_topic_acl`
--

CREATE TABLE IF NOT EXISTS `user_topic_acl` (
  `user_id` int(11) NOT NULL,
  `topic_id` int(11) NOT NULL,
  `rank_id` int(11) NOT NULL,
  UNIQUE KEY `user_id` (`user_id`,`topic_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- Table structure for table `user_topic_subscription`
--

CREATE TABLE IF NOT EXISTS `user_topic_subscription` (
  `user_id` int(11) NOT NULL,
  `topic_id` int(11) NOT NULL,
  UNIQUE KEY `user_id` (`user_id`,`topic_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- User permissions: `doxen`
--

GRANT INSERT ON `doxen`.* TO `doxen`@`localhost`;
GRANT SELECT ON `doxen`.* TO `doxen`@`localhost`;
GRANT UPDATE ON `doxen`.* TO `doxen`@`localhost`;
GRANT DELETE ON  `doxen`.`user_topic_subscription` TO  'doxen'@'localhost';
FLUSH PRIVILEGES;


/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;

