-- phpMyAdmin SQL Dump
-- version 2.11.8.1deb1ubuntu0.2
-- http://www.phpmyadmin.net
--
-- Serveur: localhost
-- Généré le : Mar 13 Mai 2014 à 23:07
-- Version du serveur: 5.0.67
-- Version de PHP: 5.2.6-2ubuntu4.6

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";

--
-- Base de données: `avieira`
--

-- --------------------------------------------------------

--
-- Structure de la table `animal`
--

CREATE TABLE IF NOT EXISTS `animal` (
  `id` int(10) unsigned NOT NULL auto_increment,
  `nom` varchar(50) NOT NULL,
  `codeEspece` int(5) NOT NULL,
  `codeRegion` int(2) NOT NULL,
  PRIMARY KEY  (`id`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=117 ;

--
-- Contenu de la table `animal`
--

INSERT INTO `animal` (`id`, `nom`, `codeEspece`, `codeRegion`) VALUES
(111, 'porc', 2, 27),
(112, 'poule', 3, 63),
(113, 'chèvre', 4, 59),
(114, 'sanglier', 2, 63),
(115, 'coq', 3, 27),
(116, 'mouton', 4, 59);

-- --------------------------------------------------------

--
-- Structure de la table `EspeceAnimal`
--

CREATE TABLE IF NOT EXISTS `EspeceAnimal` (
  `code` int(10) unsigned NOT NULL,
  `nomScientifique` varchar(50) NOT NULL,
  `nomCourant` varchar(50) NOT NULL,
  `poidsMaturite` smallint(50) unsigned NOT NULL,
  `published` int(1) unsigned NOT NULL default '0',
  PRIMARY KEY  (`code`)
) ENGINE=MyISAM DEFAULT CHARSET=latin1;

--
-- Contenu de la table `EspeceAnimal`
--

INSERT INTO `EspeceAnimal` (`code`, `nomScientifique`, `nomCourant`, `poidsMaturite`, `published`) VALUES
(0, 'Bos Taurus Limousine', 'Vache Limousine', 600, 0),
(1, 'Bos Taurus Mirandaise', 'Vache Mirandaise', 650, 1),
(2, 'Sus scrofa domesticus', 'Porc Landrace Français', 300, 0),
(3, 'Aphanapteryx bonasia', 'Poule Rouge', 3, 0),
(4, 'Capra caucasica', ' chèvre du caucase ', 65, 0),
(5, 'Meles meles', 'Blaireau européen', 15, 0);

-- --------------------------------------------------------

--
-- Structure de la table `region`
--

CREATE TABLE IF NOT EXISTS `region` (
  `code` int(2) unsigned NOT NULL auto_increment,
  `nom` varchar(50) NOT NULL,
  PRIMARY KEY  (`code`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=64 ;

--
-- Contenu de la table `region`
--

INSERT INTO `region` (`code`, `nom`) VALUES
(27, 'Eure'),
(59, 'Nord'),
(63, 'Puy-de-Dôme');
