/*This file contains the necessary script the generate the database that
the H5Tool need to use for spell casters information.
If you need to expand the program, don't forget to make use of this database
--Yours truly, Berein*/

--enable foreign key support
PRAGMA foreign_keys = ON;
--create basic entities
CREATE TABLE IF NOT EXISTS creatures(
	id INTEGER PRIMARY KEY,
	tier INTEGER NOT NULL CHECK(tier >= 1 AND tier <=7),
	growth INTEGER NOT NULL CHECK(growth >= 1) );
CREATE TABLE IF NOT EXISTS spells   (id INTEGER PRIMARY KEY);
CREATE TABLE IF NOT EXISTS mastery   (name TEXT PRIMARY KEY);
--create relations
CREATE TABLE IF NOT EXISTS spell_damage (
	id INTEGER,
	level TEXT,
	base INTEGER, 
	multiplier INTEGER,
	PRIMARY KEY (id, level),
	FOREIGN KEY (id)   REFERENCES spells (id),
	FOREIGN KEY (level) REFERENCES mastery(name));
CREATE TABLE IF NOT EXISTS caster_creatures (
	creature INTEGER,
	spell INTEGER,
	level TEXT,
	PRIMARY KEY(creature, spell)
	FOREIGN KEY(level) REFERENCES mastery(name));

--insert spell ids
CREATE TRIGGER insSpellIDs AFTER INSERT ON spells
WHEN NEW.id < 295 BEGIN
	INSERT INTO spells(id) VALUES(new.id + 1);
END;
PRAGMA recursive_triggers = 1;
INSERT INTO spells(id) VALUES(1);

--insert creatures data
----heaven creatures
INSERT INTO creatures VALUES(1,1,22);
INSERT INTO creatures VALUES(2,1,22);
INSERT INTO creatures VALUES(3,2,12);
INSERT INTO creatures VALUES(4,2,12);
INSERT INTO creatures VALUES(5,3,10);
INSERT INTO creatures VALUES(6,3,10);
INSERT INTO creatures VALUES(7,4,5);
INSERT INTO creatures VALUES(8,4,5);
INSERT INTO creatures VALUES(9,5,3);
INSERT INTO creatures VALUES(10,5,3);
INSERT INTO creatures VALUES(11,6,2);
INSERT INTO creatures VALUES(12,6,2);
INSERT INTO creatures VALUES(13,7,1);
INSERT INTO creatures VALUES(14,7,1);
----inferno creatures
INSERT INTO creatures VALUES(15,1,16);
INSERT INTO creatures VALUES(16,1,16);
INSERT INTO creatures VALUES(17,2,15);
INSERT INTO creatures VALUES(18,2,15);
INSERT INTO creatures VALUES(19,3,8);
INSERT INTO creatures VALUES(20,3,8);
INSERT INTO creatures VALUES(21,4,5);
INSERT INTO creatures VALUES(22,4,5);
INSERT INTO creatures VALUES(23,5,3);
INSERT INTO creatures VALUES(24,5,3);
INSERT INTO creatures VALUES(25,6,2);
INSERT INTO creatures VALUES(26,6,2);
INSERT INTO creatures VALUES(27,7,1);
INSERT INTO creatures VALUES(28,7,1);
----necropolis creatures
INSERT INTO creatures VALUES(29,1,20);
INSERT INTO creatures VALUES(30,1,20);
INSERT INTO creatures VALUES(31,2,15);
INSERT INTO creatures VALUES(32,2,15);
INSERT INTO creatures VALUES(33,3,9);
INSERT INTO creatures VALUES(34,3,9);
INSERT INTO creatures VALUES(35,4,5);
INSERT INTO creatures VALUES(36,4,5);
INSERT INTO creatures VALUES(37,5,3);
INSERT INTO creatures VALUES(38,5,3);
INSERT INTO creatures VALUES(39,6,2);
INSERT INTO creatures VALUES(40,6,2);
INSERT INTO creatures VALUES(41,7,1);
INSERT INTO creatures VALUES(42,7,1);
----sylvan creatures
INSERT INTO creatures VALUES(43,1,10);
INSERT INTO creatures VALUES(44,1,10);
INSERT INTO creatures VALUES(45,2,9);
INSERT INTO creatures VALUES(46,2,9);
INSERT INTO creatures VALUES(47,3,7);
INSERT INTO creatures VALUES(48,3,7);
INSERT INTO creatures VALUES(49,4,4);
INSERT INTO creatures VALUES(50,4,4);
INSERT INTO creatures VALUES(51,5,3);
INSERT INTO creatures VALUES(52,5,3);
INSERT INTO creatures VALUES(53,6,2);
INSERT INTO creatures VALUES(54,6,2);
INSERT INTO creatures VALUES(55,7,1);
INSERT INTO creatures VALUES(56,7,1);
----academy creatures
INSERT INTO creatures VALUES(57,1,20);
INSERT INTO creatures VALUES(58,1,20);
INSERT INTO creatures VALUES(59,2,14);
INSERT INTO creatures VALUES(60,2,14);
INSERT INTO creatures VALUES(61,3,9);
INSERT INTO creatures VALUES(62,3,9);
INSERT INTO creatures VALUES(63,4,5);
INSERT INTO creatures VALUES(64,4,5);
INSERT INTO creatures VALUES(65,5,3);
INSERT INTO creatures VALUES(66,5,3);
INSERT INTO creatures VALUES(67,6,2);
INSERT INTO creatures VALUES(68,6,2);
INSERT INTO creatures VALUES(69,7,1);
INSERT INTO creatures VALUES(70,7,1);
----dungeon creatures
INSERT INTO creatures VALUES(71,1,7);
INSERT INTO creatures VALUES(72,1,7);
INSERT INTO creatures VALUES(73,2,5);
INSERT INTO creatures VALUES(74,2,5);
INSERT INTO creatures VALUES(75,3,6);
INSERT INTO creatures VALUES(76,3,6);
INSERT INTO creatures VALUES(77,4,4);
INSERT INTO creatures VALUES(78,4,4);
INSERT INTO creatures VALUES(79,5,3);
INSERT INTO creatures VALUES(80,5,3);
INSERT INTO creatures VALUES(81,6,2);
INSERT INTO creatures VALUES(82,6,2);
INSERT INTO creatures VALUES(83,7,1);
INSERT INTO creatures VALUES(84,7,1);
----neutral creatures
INSERT INTO creatures VALUES(85,4,4);
INSERT INTO creatures VALUES(86,4,4);
INSERT INTO creatures VALUES(87,4,4);
INSERT INTO creatures VALUES(88,4,4);
INSERT INTO creatures VALUES(89,6,2);
INSERT INTO creatures VALUES(90,6,2);
INSERT INTO creatures VALUES(91,7,1);
----fortress creatures
INSERT INTO creatures VALUES(92,1,18);
INSERT INTO creatures VALUES(93,1,18);
INSERT INTO creatures VALUES(94,2,14);
INSERT INTO creatures VALUES(95,2,14);
INSERT INTO creatures VALUES(96,3,7);
INSERT INTO creatures VALUES(97,3,7);
INSERT INTO creatures VALUES(98,4,6);
INSERT INTO creatures VALUES(99,4,6);
INSERT INTO creatures VALUES(100,5,3);
INSERT INTO creatures VALUES(101,5,3);
INSERT INTO creatures VALUES(102,6,2);
INSERT INTO creatures VALUES(103,6,2);
INSERT INTO creatures VALUES(104,7,1);
INSERT INTO creatures VALUES(105,7,1);
----heaven creatures
INSERT INTO creatures VALUES(106,1,22);
INSERT INTO creatures VALUES(107,2,12);
INSERT INTO creatures VALUES(108,3,10);
INSERT INTO creatures VALUES(109,4,5);
INSERT INTO creatures VALUES(110,5,3);
INSERT INTO creatures VALUES(111,6,2);
INSERT INTO creatures VALUES(112,7,1);
----neutral creatures
INSERT INTO creatures VALUES(113,3,8);
INSERT INTO creatures VALUES(114,4,4);
INSERT INTO creatures VALUES(115,6,2);
INSERT INTO creatures VALUES(116,5,3);
----stronghold creatures
INSERT INTO creatures VALUES(117,1,25);
INSERT INTO creatures VALUES(118,1,25);
INSERT INTO creatures VALUES(119,2,14);
INSERT INTO creatures VALUES(120,2,14);
INSERT INTO creatures VALUES(121,3,11);
INSERT INTO creatures VALUES(122,3,11);
INSERT INTO creatures VALUES(123,4,5);
INSERT INTO creatures VALUES(124,4,5);
INSERT INTO creatures VALUES(125,5,5);
INSERT INTO creatures VALUES(126,5,5);
INSERT INTO creatures VALUES(127,6,2);
INSERT INTO creatures VALUES(128,6,2);
INSERT INTO creatures VALUES(129,7,1);
INSERT INTO creatures VALUES(130,7,1);
----inferno creatures
INSERT INTO creatures VALUES(131,1,16);
INSERT INTO creatures VALUES(132,2,15);
INSERT INTO creatures VALUES(133,3,8);
INSERT INTO creatures VALUES(134,4,5);
INSERT INTO creatures VALUES(135,5,3);
INSERT INTO creatures VALUES(136,6,2);
INSERT INTO creatures VALUES(137,7,1);
----dungeon creatures
INSERT INTO creatures VALUES(138,1,7);
INSERT INTO creatures VALUES(139,2,5);
INSERT INTO creatures VALUES(140,3,6);
INSERT INTO creatures VALUES(141,4,4);
INSERT INTO creatures VALUES(142,5,3);
INSERT INTO creatures VALUES(143,6,2);
INSERT INTO creatures VALUES(144,7,1);
----sylvan creatures
INSERT INTO creatures VALUES(145,1,10);
INSERT INTO creatures VALUES(146,2,9);
INSERT INTO creatures VALUES(147,3,7);
INSERT INTO creatures VALUES(148,4,4);
INSERT INTO creatures VALUES(149,5,3);
INSERT INTO creatures VALUES(150,6,2);
INSERT INTO creatures VALUES(151,7,1);
----necropolis creatures
INSERT INTO creatures VALUES(152,1,20);
INSERT INTO creatures VALUES(153,2,15);
INSERT INTO creatures VALUES(154,3,9);
INSERT INTO creatures VALUES(155,4,5);
INSERT INTO creatures VALUES(156,5,3);
INSERT INTO creatures VALUES(157,6,2);
INSERT INTO creatures VALUES(158,7,1);
----academy creatures
INSERT INTO creatures VALUES(159,1,20);
INSERT INTO creatures VALUES(160,2,14);
INSERT INTO creatures VALUES(161,3,9);
INSERT INTO creatures VALUES(162,4,5);
INSERT INTO creatures VALUES(163,5,3);
INSERT INTO creatures VALUES(164,6,2);
INSERT INTO creatures VALUES(165,7,1);
----fortress creatures
INSERT INTO creatures VALUES(166,1,18);
INSERT INTO creatures VALUES(167,2,14);
INSERT INTO creatures VALUES(168,3,7);
INSERT INTO creatures VALUES(169,4,6);
INSERT INTO creatures VALUES(170,5,3);
INSERT INTO creatures VALUES(171,6,2);
INSERT INTO creatures VALUES(172,7,1);
----stronghold creatures
INSERT INTO creatures VALUES(173,1,25);
INSERT INTO creatures VALUES(174,2,14);
INSERT INTO creatures VALUES(175,3,11);
INSERT INTO creatures VALUES(176,4,5);
INSERT INTO creatures VALUES(177,5,5);
INSERT INTO creatures VALUES(178,6,2);
INSERT INTO creatures VALUES(179,7,1);

--insert mastery data
INSERT INTO mastery VALUES('NOSKILL');
INSERT INTO mastery VALUES('BASIC');
INSERT INTO mastery VALUES('ADVANCED');
INSERT INTO mastery VALUES('EXPERT');

--insert spell_damage data
----light magic
INSERT INTO spell_damage VALUES(281,'NOSKILL',7,1);
INSERT INTO spell_damage VALUES(281,'BASIC',14,2);
INSERT INTO spell_damage VALUES(281,'ADVANCED',21,3);
INSERT INTO spell_damage VALUES(281,'EXPERT',28,4);
INSERT INTO spell_damage VALUES(35,'NOSKILL',8,2);
INSERT INTO spell_damage VALUES(35,'BASIC',12,3);
INSERT INTO spell_damage VALUES(35,'ADVANCED',30,6);
INSERT INTO spell_damage VALUES(35,'EXPERT',144,12);
INSERT INTO spell_damage VALUES(48,'NOSKILL',20,5);
INSERT INTO spell_damage VALUES(48,'BASIC',40,10);
INSERT INTO spell_damage VALUES(48,'ADVANCED',60,15);
INSERT INTO spell_damage VALUES(48,'EXPERT',240,30);
----destruction magic
INSERT INTO spell_damage VALUES(1,'NOSKILL',48,8);
INSERT INTO spell_damage VALUES(1,'BASIC',56,8);
INSERT INTO spell_damage VALUES(1,'ADVANCED',64,8);
INSERT INTO spell_damage VALUES(1,'EXPERT',72,8);
INSERT INTO spell_damage VALUES(237,'NOSKILL',24,8);
INSERT INTO spell_damage VALUES(237,'BASIC',32,8);
INSERT INTO spell_damage VALUES(237,'ADVANCED',40,8);
INSERT INTO spell_damage VALUES(237,'EXPERT',48,8);
INSERT INTO spell_damage VALUES(3,'NOSKILL',11,11);
INSERT INTO spell_damage VALUES(3,'BASIC',14,14);
INSERT INTO spell_damage VALUES(3,'ADVANCED',17,17);
INSERT INTO spell_damage VALUES(3,'EXPERT',20,20);
INSERT INTO spell_damage VALUES(4,'NOSKILL',60,12);
INSERT INTO spell_damage VALUES(4,'BASIC',72,12);
INSERT INTO spell_damage VALUES(4,'ADVANCED',84,12);
INSERT INTO spell_damage VALUES(4,'EXPERT',96,12);
INSERT INTO spell_damage VALUES(5,'NOSKILL',11,11);
INSERT INTO spell_damage VALUES(5,'BASIC',14,14);
INSERT INTO spell_damage VALUES(5,'ADVANCED',17,17);
INSERT INTO spell_damage VALUES(5,'EXPERT',20,20);
INSERT INTO spell_damage VALUES(6,'NOSKILL',60,12);
INSERT INTO spell_damage VALUES(6,'BASIC',72,12);
INSERT INTO spell_damage VALUES(6,'ADVANCED',84,12);
INSERT INTO spell_damage VALUES(6,'EXPERT',96,12);
INSERT INTO spell_damage VALUES(236,'NOSKILL',9,9);
INSERT INTO spell_damage VALUES(236,'BASIC',11,11);
INSERT INTO spell_damage VALUES(236,'ADVANCED',13,13);
INSERT INTO spell_damage VALUES(236,'EXPERT',15,15);
INSERT INTO spell_damage VALUES(8,'NOSKILL',9,9);
INSERT INTO spell_damage VALUES(8,'BASIC',12,12);
INSERT INTO spell_damage VALUES(8,'ADVANCED',15,15);
INSERT INTO spell_damage VALUES(8,'EXPERT',20,20);
INSERT INTO spell_damage VALUES(9,'NOSKILL',12,12);
INSERT INTO spell_damage VALUES(9,'BASIC',17,17);
INSERT INTO spell_damage VALUES(9,'ADVANCED',20,20);
INSERT INTO spell_damage VALUES(9,'EXPERT',40,40);
INSERT INTO spell_damage VALUES(10,'NOSKILL',9,9);
INSERT INTO spell_damage VALUES(10,'BASIC',12,12);
INSERT INTO spell_damage VALUES(10,'ADVANCED',15,15);
INSERT INTO spell_damage VALUES(10,'EXPERT',30,30);
INSERT INTO spell_damage VALUES(279,'NOSKILL',10,10);
INSERT INTO spell_damage VALUES(279,'BASIC',14,14);
INSERT INTO spell_damage VALUES(279,'ADVANCED',15,15);
INSERT INTO spell_damage VALUES(279,'EXPERT',30,30);
----dark magic
INSERT INTO spell_damage VALUES(14,'NOSKILL',32,8);
INSERT INTO spell_damage VALUES(14,'BASIC',32,8);
INSERT INTO spell_damage VALUES(14,'ADVANCED',32,8);
INSERT INTO spell_damage VALUES(14,'EXPERT',32,8);
INSERT INTO spell_damage VALUES(21,'NOSKILL',8,2);
INSERT INTO spell_damage VALUES(21,'BASIC',12,3);
INSERT INTO spell_damage VALUES(21,'ADVANCED',30,6);
INSERT INTO spell_damage VALUES(21,'EXPERT',144,12);
----summon magic
INSERT INTO spell_damage VALUES(2,'NOSKILL',20,4);
INSERT INTO spell_damage VALUES(2,'BASIC',30,6);
INSERT INTO spell_damage VALUES(2,'ADVANCED',40,8);
INSERT INTO spell_damage VALUES(2,'EXPERT',50,10);
INSERT INTO spell_damage VALUES(38,'NOSKILL',50,10);
INSERT INTO spell_damage VALUES(38,'BASIC',50,10);
INSERT INTO spell_damage VALUES(38,'ADVANCED',50,10);
INSERT INTO spell_damage VALUES(38,'EXPERT',50,10);
INSERT INTO spell_damage VALUES(42,'NOSKILL',120,15);
INSERT INTO spell_damage VALUES(42,'BASIC',160,20);
INSERT INTO spell_damage VALUES(42,'ADVANCED',200,25);
INSERT INTO spell_damage VALUES(42,'EXPERT',240,30);
INSERT INTO spell_damage VALUES(282,'NOSKILL',40,8);
INSERT INTO spell_damage VALUES(282,'BASIC',60,12);
INSERT INTO spell_damage VALUES(282,'ADVANCED',80,16);
INSERT INTO spell_damage VALUES(282,'EXPERT',100,20);
INSERT INTO spell_damage VALUES(39,'NOSKILL',10,2);
INSERT INTO spell_damage VALUES(39,'BASIC',20,4);
INSERT INTO spell_damage VALUES(39,'ADVANCED',30,6);
INSERT INTO spell_damage VALUES(39,'EXPERT',40,8);
INSERT INTO spell_damage VALUES(284,'NOSKILL',20,5);
INSERT INTO spell_damage VALUES(284,'BASIC',40,8);
INSERT INTO spell_damage VALUES(284,'ADVANCED',60,10);
INSERT INTO spell_damage VALUES(284,'EXPERT',96,12);
INSERT INTO spell_damage VALUES(34,'NOSKILL',250,50);
INSERT INTO spell_damage VALUES(34,'BASIC',550,50);
INSERT INTO spell_damage VALUES(34,'ADVANCED',600,60);
INSERT INTO spell_damage VALUES(34,'EXPERT',600,60);
--insert caster_creatures data
----heaven casters
INSERT INTO caster_creatures VALUES(10,23,"ADVANCED");
INSERT INTO caster_creatures VALUES(10,24,"ADVANCED");
INSERT INTO caster_creatures VALUES(10,25,"ADVANCED");
INSERT INTO caster_creatures VALUES(110,28,"EXPERT");
INSERT INTO caster_creatures VALUES(110,26,"ADVANCED");
INSERT INTO caster_creatures VALUES(112,28,"ADVANCED");
INSERT INTO caster_creatures VALUES(112,281,"BASIC");
----sylvan casters
INSERT INTO caster_creatures VALUES(44,39,"NOSKILL");
INSERT INTO caster_creatures VALUES(44,26,"ADVANCED");
INSERT INTO caster_creatures VALUES(49,3,"BASIC");
INSERT INTO caster_creatures VALUES(49,25,"ADVANCED");
INSERT INTO caster_creatures VALUES(50,237,"NOSKILL");
INSERT INTO caster_creatures VALUES(50,3,"ADVANCED");
INSERT INTO caster_creatures VALUES(50,25,"EXPERT");
INSERT INTO caster_creatures VALUES(148,25,"ADVANCED");
----academy casters
INSERT INTO caster_creatures VALUES(63,2,"BASIC");
INSERT INTO caster_creatures VALUES(63,26,"ADVANCED");
INSERT INTO caster_creatures VALUES(64,5,"BASIC");
INSERT INTO caster_creatures VALUES(64,2,"ADVANCED");
INSERT INTO caster_creatures VALUES(64,28,"ADVANCED");
INSERT INTO caster_creatures VALUES(64,26,"EXPERT");
INSERT INTO caster_creatures VALUES(162,2,"BASIC");
INSERT INTO caster_creatures VALUES(162,26,"ADVANCED");
INSERT INTO caster_creatures VALUES(65,23,"ADVANCED");
INSERT INTO caster_creatures VALUES(66,23,"ADVANCED");
INSERT INTO caster_creatures VALUES(163,23,"ADVANCED");
-----inferno casters
INSERT INTO caster_creatures VALUES(18,236,"NOSKILL");
INSERT INTO caster_creatures VALUES(25,5,"BASIC");
INSERT INTO caster_creatures VALUES(25,13,"ADVANCED");
INSERT INTO caster_creatures VALUES(26,5,"BASIC");
INSERT INTO caster_creatures VALUES(26,8,"BASIC");
INSERT INTO caster_creatures VALUES(26,13,"ADVANCED");
----necropolis casters
INSERT INTO caster_creatures VALUES(38,14,"ADVANCED");
INSERT INTO caster_creatures VALUES(38,15,"ADVANCED");
INSERT INTO caster_creatures VALUES(38,11,"EXPERT");
INSERT INTO caster_creatures VALUES(156,42,"BASIC");
INSERT INTO caster_creatures VALUES(156,11,"ADVANCED");
----dungeon casters
INSERT INTO caster_creatures VALUES(81,12,"ADVANCED");
INSERT INTO caster_creatures VALUES(81,13,"ADVANCED");
INSERT INTO caster_creatures VALUES(81,28,"ADVANCED");
INSERT INTO caster_creatures VALUES(82,17,"NOSKILL");
INSERT INTO caster_creatures VALUES(82,12,"ADVANCED");
INSERT INTO caster_creatures VALUES(82,13,"ADVANCED");
INSERT INTO caster_creatures VALUES(82,28,"ADVANCED");
INSERT INTO caster_creatures VALUES(143,17,"NOSKILL");
INSERT INTO caster_creatures VALUES(143,12,"ADVANCED");
INSERT INTO caster_creatures VALUES(143,13,"ADVANCED");
INSERT INTO caster_creatures VALUES(143,28,"ADVANCED");
----fortress casters
INSERT INTO caster_creatures VALUES(100,29,"BASIC");
INSERT INTO caster_creatures VALUES(101,29,"ADVANCED");
INSERT INTO caster_creatures VALUES(101,236,"ADVANCED");
INSERT INTO caster_creatures VALUES(170,29,"ADVANCED");
INSERT INTO caster_creatures VALUES(170,5,"ADVANCED");
----stronghold casters
INSERT INTO caster_creatures VALUES(123,24,"ADVANCED");
INSERT INTO caster_creatures VALUES(123,12,"ADVANCED");
INSERT INTO caster_creatures VALUES(124,7,"BASIC");
INSERT INTO caster_creatures VALUES(124,24,"ADVANCED");
INSERT INTO caster_creatures VALUES(124,12,"ADVANCED");
INSERT INTO caster_creatures VALUES(176,24,"ADVANCED");
INSERT INTO caster_creatures VALUES(176,12,"ADVANCED");
----neutral casters
INSERT INTO caster_creatures VALUES(86,4,"BASIC");
INSERT INTO caster_creatures VALUES(86,6,"BASIC");
INSERT INTO caster_creatures VALUES(116,17,"EXPERT");
INSERT INTO caster_creatures VALUES(116,42,"EXPERT");