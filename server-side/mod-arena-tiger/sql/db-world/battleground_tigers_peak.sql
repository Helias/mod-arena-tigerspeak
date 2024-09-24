-- battleground_template
DELETE FROM `battleground_template` WHERE `ID` IN (871);
INSERT INTO `battleground_template` (`ID`,`MinPlayersPerTeam`,`MaxPlayersPerTeam`,`MinLvl`,`MaxLvl`,`AllianceStartLoc`,`AllianceStartO`,`HordeStartLoc`,`HordeStartO`,`StartMaxDist`,`Weight`,`ScriptName`,`Comment`) VALUES
(871,0,5,10,80,4535,0,4534,0,0,1,'',"The Tiger's Peak Arena");

-- game_graveyard
DELETE FROM `game_graveyard` WHERE `ID` IN (4534, 4535, 4536);
INSERT INTO `game_graveyard` VALUES
(4534,1134,491.476,633.332,380.707,'Arena - Shado-Pan - Teleport Target - Team 1'),
(4535,1134,642.367,633.406,380.705,'Arena - Shado-Pan - Teleport Target - Team 2'),
(4536,1134,565.578,631.54,380.704,'Arena - Shado-Pan - Teleport Target - Game On');

-- gameobject_template
DELETE FROM `gameobject_template` WHERE `entry` IN (212921, 184663, 184664);
INSERT INTO `gameobject_template` (`entry`,`type`,`displayId`,`name`,`IconName`,`castBarCaption`,`unk1`,`size`,`Data0`,`Data1`,`Data2`,`Data3`,`Data4`,`Data5`,`Data6`,`Data7`,`Data8`,`Data9`,`Data10`,`Data11`,`Data12`,`Data13`,`Data14`,`Data15`,`Data16`,`Data17`,`Data18`,`Data19`,`Data20`,`Data21`,`Data22`,`Data23`,`AIName`,`ScriptName`,`VerifiedBuild`) VALUES
(212921,0,11866,"unk name","","","",1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"","",12340),
(184663,6,5932,"Shadow Sight","","","",1,0,0,5,34709,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"","",12340),
(184664,6,5932,"Shadow Sight","","","",1,0,0,5,34709,1,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"","",12340);

-- gameobject_template_addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (212921, 184663, 184664);
INSERT INTO `gameobject_template_addon` (`entry`,`faction`,`flags`,`mingold`,`maxgold`) VALUES
(212921,0,0,0,0),
(184663,114,0,0,0),
(184664,114,0,0,0);
