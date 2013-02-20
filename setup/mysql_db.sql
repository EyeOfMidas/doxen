-- phpMyAdmin SQL Dump
-- version 3.3.7deb7
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 15, 2013 at 05:13 PM
-- Server version: 5.1.63
-- PHP Version: 5.3.3-7+squeeze14

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- User: `doxen`
--
CREATE USER `doxen`@`localhost` IDENTIFIED BY 'doxenpassword';

-- --------------------------------------------------------

--
-- Database: `doxen`
--
CREATE DATABASE `doxen` DEFAULT CHARACTER SET utf8 COLLATE utf8_general_ci;
USE `doxen`;

-- --------------------------------------------------------

--
-- Table structure for table `comments`
--

CREATE TABLE IF NOT EXISTS `comments` (
  `comment_id` int(11) NOT NULL AUTO_INCREMENT,
  `content` text CHARACTER SET utf8 NOT NULL,
  `poster_user_id` int(11) NOT NULL,
  `parent_post_id` int(11) NOT NULL,
  `url_name` varchar(256) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`comment_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `posts`
--

CREATE TABLE IF NOT EXISTS `posts` (
  `post_id` int(11) NOT NULL AUTO_INCREMENT,
  `name` varchar(256) CHARACTER SET utf8 NOT NULL,
  `url_name` varchar(256) CHARACTER SET utf8 NOT NULL,
  `content` text CHARACTER SET utf8 NOT NULL,
  `link` text CHARACTER SET utf8 NOT NULL,
  `parent_topic_id` int(11) NOT NULL,
  PRIMARY KEY (`post_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `topics`
--

CREATE TABLE IF NOT EXISTS `topics` (
  `topic_id` int(11) NOT NULL AUTO_INCREMENT,
  `display_name` varchar(64) CHARACTER SET utf8 NOT NULL,
  `url_name` varchar(64) CHARACTER SET utf8 NOT NULL,
  PRIMARY KEY (`topic_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `users`
--

CREATE TABLE IF NOT EXISTS `users` (
  `user_id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(256) NOT NULL,
  `display_name` varchar(256) NOT NULL,
  `passwordhash` varchar(256) NOT NULL,
  PRIMARY KEY (`user_id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8 AUTO_INCREMENT=1 ;

-- --------------------------------------------------------

--
-- Table structure for table `topic_moderators`
--

CREATE TABLE IF NOT EXISTS `topic_moderators` (
	`topic_id` int(11) NOT NULL,
    `user_id` int(11) NOT NULL,
    `rank` varchar(64) NOT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- --------------------------------------------------------

--
-- User permissions: `doxen`
--
GRANT INSERT ON `doxen`.* TO `doxen`@`localhost`;
GRANT SELECT ON `doxen`.* TO `doxen`@`localhost`;
GRANT UPDATE ON `doxen`.* TO `doxen`@`localhost`;
FLUSH PRIVILEGES;

-- --------------------------------------------------------

