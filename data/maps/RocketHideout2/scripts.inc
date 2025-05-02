RocketHideout2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout2_OnLoad
	.byte 0

RocketHideout2_OnLoad::
	setvar VAR_UNUSED_0x40F7, 1
	end

RocketHideout_Grunt1_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_1, RocketHideoutGrunt1Intro, RocketHideoutGrunt1Defeat
	msgbox RocketHideoutGrunt1PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt2_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_2, RocketHideoutGrunt2Intro, RocketHideoutGrunt2Defeat
	msgbox RocketHideoutGrunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt3_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_3, RocketHideoutGrunt3Intro, RocketHideoutGrunt3Defeat
	msgbox RocketHideoutGrunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt4_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_4, RocketHideoutGrunt4Intro, RocketHideoutGrunt4Defeat
	msgbox RocketHideoutGrunt4PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt5_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_5, RocketHideoutGrunt5Intro, RocketHideoutGrunt5Defeat
	msgbox RocketHideoutGrunt5PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt6_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_6, RocketHideoutGrunt6Intro, RocketHideoutGrunt6Defeat
	msgbox RocketHideoutGrunt6PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideoutGrunt1Intro:
	.string "You must be the kid the boss\n"
	.string "warned us about!$"

RocketHideoutGrunt2Intro:
	.string "Prepare for a severe beatdown!$"

RocketHideoutGrunt3Intro:
	.string "Welcome to our base of operations!\p"
	.string "Now allow me to show you the exit!$"

RocketHideoutGrunt4Intro:
	.string "PACIFIDLOG TOWN is a prime location\n"
	.string "for conducting our operations!\p"
	.string "There's no space for you here!$"

RocketHideoutGrunt5Intro:
	.string "This is just my job five days a week.\p"
	.string "I'm not the man they think I am\n"
	.string "at home.\p"
	.string "I'm a rocket man!$"

RocketHideoutGrunt5Defeat:
	.string "You burned out my fuse up here alone!$"

RocketHideoutGrunt5PostBattle:
	.string "It's been a long, long time and all\n"
	.string "the science I don't understand, but\l"
	.string "our boss is almost finished with his\l"
	.string "master plan!$"

RocketHideoutGrunt6Intro:
	.string "Our base is filled with high tech\n"
	.string "gadgets and gizmos.\p"
	.string "I won't be giving you a tour though,\n"
	.string "I'll be giving you a lesson!$"

RocketHideoutGrunt1Defeat:
	.string "No wonder you're public enemy\n"
	.string "number one!$"

RocketHideoutGrunt2Defeat:
	.string "You beat me down!$"

RocketHideoutGrunt3Defeat:
	.string "I didn't operate my team well.$"

RocketHideoutGrunt4Defeat:
	.string "There's no space for a loser\n"
	.string "like me here!$"

RocketHideoutGrunt6Defeat:
	.string "Looks like you taught me\n"
	.string "a lesson.$"

RocketHideoutGrunt1PostBattle:
	.string "You think you're some big shot\n"
	.string "just because you beat me?$"

RocketHideoutGrunt2PostBattle:
	.string "I'm not worried!\p"
	.string "You've got a long way to go before\n"
	.string "you can do any real damage!$"

RocketHideoutGrunt3PostBattle:
	.string "This facility has state of the art\n"
	.string "technology developed by TEAM ROCKET!$"

RocketHideoutGrunt4PostBattle:
	.string "I wonder what it would be like to\n"
	.string "go into outer space?$"

RocketHideoutGrunt6PostBattle:
	.string "You're in for a surprise when you\n"
	.string "walk through that door!$"
