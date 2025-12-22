NewMauville_Inside_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_Inside_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_Inside_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, NewMauville_Inside_OnLoad
	.byte 0

NewMauville_Inside_OnResume:
	call_if_eq VAR_TEMP_1, 1, NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	call_if_eq VAR_TEMP_2, 1, NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_Inside_EventScript_TryRemoveVoltorb
	end

NewMauville_Inside_EventScript_TryRemoveVoltorb::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

NewMauville_Inside_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	call_if_unset FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb1
	call_if_unset FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb2
	call_if_unset FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE, NewMauville_Inside_EventScript_ShowVoltorb3
	end

NewMauville_Inside_EventScript_ShowVoltorb1::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_1
	return

NewMauville_Inside_EventScript_ShowVoltorb2::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_2
	return

NewMauville_Inside_EventScript_ShowVoltorb3::
	clearflag FLAG_HIDE_NEW_MAUVILLE_VOLTORB_3
	return

NewMauville_Inside_OnLoad:
	call_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	end

NewMauville_Inside_EventScript_BlueButton::
	lockall
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_2, 0
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateBlueButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_GreenButton::
	lockall
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 1
	playse SE_PIN
	call NewMauville_Inside_EventScript_SetBarrierStateGreenButton
	special DrawWholeMapView
	releaseall
	end

NewMauville_Inside_EventScript_SetBarrierStateBlueButton::
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 23, 36, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 23, 37, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 10, 18, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 10, 19, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 10, 2, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 10, 3, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 37, 35, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 37, 36, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 28, 24, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 28, 25, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 10, 26, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 10, 27, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Green_Top, TRUE
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Green_TopMid, TRUE
	setmetatile 21, 4, METATILE_BikeShop_Barrier_Green_BottomMid, TRUE
	setmetatile 21, 5, METATILE_BikeShop_Barrier_Green_Bottom, TRUE
	setmetatile 6, 11, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 13, 10, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 16, 22, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 4, 26, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 30, 38, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 2, 11, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 17, 10, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 25, 18, METATILE_BikeShop_Button_Green, FALSE
	setmetatile 18, 36, METATILE_BikeShop_Button_Green, FALSE
	return

NewMauville_Inside_EventScript_SetBarrierStateGreenButton::
	setmetatile 23, 34, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 23, 35, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 23, 36, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 23, 37, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	setmetatile 10, 16, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 10, 17, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 10, 18, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 10, 19, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	setmetatile 10, 0, METATILE_BikeShop_Barrier_Blue_Top, TRUE
	setmetatile 10, 1, METATILE_BikeShop_Barrier_Blue_TopMid, TRUE
	setmetatile 10, 2, METATILE_BikeShop_Barrier_Blue_BottomMid, TRUE
	setmetatile 10, 3, METATILE_BikeShop_Barrier_Blue_Bottom, TRUE
	setmetatile 37, 33, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 37, 34, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 37, 35, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 37, 36, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 28, 22, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 28, 23, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 28, 24, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 28, 25, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 10, 24, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 10, 25, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 10, 26, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 10, 27, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 21, 2, METATILE_BikeShop_Barrier_Hidden_Top, TRUE
	setmetatile 21, 3, METATILE_BikeShop_Barrier_Hidden_Bottom, TRUE
	setmetatile 21, 4, METATILE_BikeShop_Floor_Shadow_Top, FALSE
	setmetatile 21, 5, METATILE_BikeShop_Wall_Edge_Top, FALSE
	setmetatile 2, 11, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 17, 10, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 25, 18, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 18, 36, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 6, 11, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 13, 10, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 16, 22, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 4, 26, METATILE_BikeShop_Button_Blue, FALSE
	setmetatile 30, 38, METATILE_BikeShop_Button_Blue, FALSE
	return

NewMauville_Inside_EventScript_RedButton::
	lockall
	msgbox NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped, MSGBOX_DEFAULT
	call NewMauville_Inside_EventScript_SetGeneratorOffMetatiles
	setvar VAR_NEW_MAUVILLE_STATE, 2
	releaseall
	end

NewMauville_Inside_EventScript_SetGeneratorOffMetatiles::
	setmetatile 33, 6, METATILE_BikeShop_Button_Pressed, FALSE
	setmetatile 32, 2, METATILE_BikeShop_Generator_Off_Tile0, TRUE
	setmetatile 33, 2, METATILE_BikeShop_Generator_Off_Tile1, TRUE
	setmetatile 34, 2, METATILE_BikeShop_Generator_Off_Tile2, TRUE
	setmetatile 35, 2, METATILE_BikeShop_Generator_Off_Tile3, TRUE
	setmetatile 32, 3, METATILE_BikeShop_Generator_Off_Tile4, TRUE
	setmetatile 33, 3, METATILE_BikeShop_Generator_Off_Tile5, TRUE
	setmetatile 34, 3, METATILE_BikeShop_Generator_Off_Tile6, TRUE
	setmetatile 35, 3, METATILE_BikeShop_Generator_Off_Tile7, TRUE
	special DrawWholeMapView
	return

NewMauville_Inside_EventScript_Generator::
	lockall
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, NewMauville_Inside_EventScript_GeneratorOff
	msgbox NewMauville_Inside_Text_GeneratorRadiatingHeat, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_GeneratorOff::
	msgbox NewMauville_Inside_Text_GeneratorQuietedDown, MSGBOX_DEFAULT
	releaseall
	end

NewMauville_Inside_EventScript_Voltorb1::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb1
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb1::
	setflag FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb2::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb2
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb2::
	setflag FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_EventScript_Voltorb3::
	lock
	faceplayer
	setwildbattle SPECIES_VOLTORB, 25
	waitse
	playmoncry SPECIES_VOLTORB, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_Inside_EventScript_DefeatedVoltorb3
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_Inside_EventScript_DefeatedVoltorb3
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_Inside_EventScript_DefeatedVoltorb3
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	release
	end

NewMauville_Inside_EventScript_DefeatedVoltorb3::
	setflag FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE
	goto Common_EventScript_RemoveStaticPokemon
	end

NewMauville_Inside_Text_GeneratorRadiatingHeat:
	.string "The generator is radiating heat that\n"
	.string "can be felt even at a distance.\p"
	.string "It looks like it should be turned off\n"
	.string "as soon as possible.$"

NewMauville_Inside_Text_GeneratorQuietedDown:
	.string "The generator quieted down.$"

NewMauville_Inside_Text_SteppedOnSwitchGeneratorStopped:
	.string "{PLAYER} stepped on the switch.\p"
	.string "Click…\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "The generator appears to have\n"
	.string "stopped…$"

NewMauville_Inside_Text_Grunt3Intro:
	.string "Impossible!\p"
	.string "How did you manage to get inside!?$"

NewMauville_Inside_Text_Grunt3Defeat:
	.string "Yikes!$"

NewMauville_Inside_Text_Grunt3Post:
	.string "How did you get your hands on a key?$"

NewMauville_Inside_Text_Grunt4Intro:
	.string "I thought we had the only copy of the\n"
	.string "Basement Key?$"

NewMauville_Inside_Text_Grunt4Defeat:
	.string "It was you who had the key to victory.$"

NewMauville_Inside_Text_Grunt4Post:
	.string "If you had a key to get in, I wonder\n"
	.string "who else might stumble into our plan.$"

NewMauville_Inside_Text_Grunt5Intro:
	.string "You'll have to figure out the secret\n"
	.string "of these switches to stop us!$"

NewMauville_Inside_Text_Grunt5Defeat:
	.string "My lips are still sealed!$"

NewMauville_Inside_Text_Grunt5Post:
	.string "There are green switches and blue\n"
	.string "switches.\p"
	.string "That's all you're getting from me!$"

NewMauville_Inside_Text_Grunt6Intro:
	.string "The boss intends to awaken an\n"
	.string "ancient Pokémon!\p"
	.string "I must help the boss achieve his\n"
	.string "dream!$"

NewMauville_Inside_Text_Grunt6Defeat:
	.string "I've failed you boss. Forgive me.$"

NewMauville_Inside_Text_Grunt6Post:
	.string "Maxie is an amazing boss.\p"
	.string "Us grunts are very well compensated.$"

NewMauville_Inside_Text_Grunt7Intro:
	.string "The New Mauville generator supplies\n"
	.string "power throughout all of Hoenn!\p"
	.string "We intend to take over that power!$"

NewMauville_Inside_Text_Grunt7Defeat:
	.string "I didn't have enough power.$"

NewMauville_Inside_Text_Grunt7Post:
	.string "I'm just one of many who stand in\n"
	.string "your way!\p"
	.string "The others are even more powerful!$"

NewMauville_Inside_Text_Grunt8Intro:
	.string "Well what have we here?\p"
	.string "You must be lost kid!\p"
	.string "Only Team Magma should be in here!$"

NewMauville_Inside_Text_Grunt8Defeat:
	.string "I lost to a kid!?!?$"

NewMauville_Inside_Text_Grunt8Post:
	.string "Get lost!\p"
	.string "I have nothing to say to you!$"

NewMauville_Inside_Text_Grunt9Intro:
	.string "How'd you get all the way back here?$"

NewMauville_Inside_Text_Grunt9Defeat:
	.string "This isn't good!$"

NewMauville_Inside_Text_Grunt9Post:
	.string "You may have made it this far, but\n"
	.string "you won't make it any further back!$"

NewMauville_Inside_Text_Grunt10Intro:
	.string "You must be strong to have made it\n"
	.string "this far, but you won't be getting\l"
	.string "any further!$"

NewMauville_Inside_Text_Grunt10Defeat:
	.string "You were stronger than I thought!$"

NewMauville_Inside_Text_Grunt10Post:
	.string "Your strength is impressive but not\n"
	.string "enough to stop us all!$"

NewMauville_Inside_Text_Grunt11Intro:
	.string "We aren't done with the generator yet!$"

NewMauville_Inside_Text_Grunt11Defeat:
	.string "You've generated a lot of trouble!$"

NewMauville_Inside_Text_Grunt11Post:
	.string "The generator produces a lot of power.\p"
	.string "Power which we intend to use!$"

NewMauville_Inside_Text_Grunt12Intro:
	.string "Even if we can't beat you, stalling\n"
	.string "you might be good enough!$"

NewMauville_Inside_Text_Grunt12Defeat:
	.string "We lasted as long as we could.$"

NewMauville_Inside_Text_Grunt12Post:
	.string "By now our plans here should be nearly\n"
	.string "complete!$"

NewMauville_Inside_Text_Grunt13Intro:
	.string "If you can't beat me, you'll never\n"
	.string "get through to the generator!$"

NewMauville_Inside_Text_Grunt13Defeat:
	.string "My mission!\n"
	.string "I messed it up!$"

NewMauville_Inside_Text_Grunt13Post:
	.string "I was supposed to stop anyone from\n"
	.string "reaching the switches below me.\p"
	.string "I failed in my mission!$"

NewMauville_Inside_Text_Grunt14Intro:
	.string "The ancient Pokémon we seek...\p"
	.string "We need the generator's power to\n"
	.string "awaken it...\p"
	.string "Which means I can't let you turn it off!$"

NewMauville_Inside_Text_Grunt14Defeat:
	.string "At least there's still one more line\n"
	.string "of defense...$"

NewMauville_Inside_Text_Grunt14Post:
	.string "If you want to put a stop to all of\n"
	.string "this, you'll have to take out someone\l"
	.string "with real authority here!$"

NewMauville_Inside_Text_Tabitha1:
	.string "Just a little bit more power and\n"
	.string "we'll be good to go.$"

NewMauville_Inside_Text_Tabitha2:
	.string "What are you doing here?\p"
	.string "You aren't part of Team Magma!\p"
	.string "You must be the meddlesome child\n"
	.string "Maxie warned me about.\p"
	.string "I suppose you are wondering what\n"
	.string "exactly it is we are doing here.\p"
	.string "We at Team Magma seek to awaken a\n"
	.string "powerful ancient Pokémon.\p"
	.string "After a long time searching, we have\n"
	.string "finally discovered its location.\p"
	.string "To reach the Pokémon we were in need\n"
	.string "of an immense amount of power.\p"
	.string "That level of power is not normally\n"
	.string "available thanks to limits placed on\l"
	.string "the generator for safety.\p"
	.string "This is why it was necessary for us\n"
	.string "to infiltrate New Mauville.\p"
	.string "By removing the safety limits set on\n"
	.string "the generator by Wattson, Maxie and \l"
	.string "Courtney will be able blow away the\l"
	.string "last obstacles in our way!\p"
	.string "Of course, removing these limits has\n"
	.string "led the generator to go haywire.\p"
	.string "An inconvenience, although more for\n"
	.string "the rest of Hoenn than for us.\p"
	.string "Now, like Courtney and Maxie, I too\n"
	.string "must remove an obstacle in our way.\p"
	.string "That obstacle being you!$"

NewMauville_Inside_Text_Tabitha3:
	.string "No wonder Maxie warned me about you.$"

NewMauville_Inside_Text_Tabitha4:
	.string "Fwahaha!\p"
	.string "You may have defeated me, but you\n"
	.string "were too late to foil our plans!\p"
	.string "I've just gotten word that Maxie\n"
	.string "has found the POKéMON we seek!\p"
	.string "Go ahead and return the generator\n"
	.string "to normal.\p"
	.string "It is time for Team Magma to depart\n"
	.string "from here and continue the next stage\l"
	.string "of our operation!$"

NewMauville_Inside_EventScript_Grunt3::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_3, NewMauville_Inside_Text_Grunt3Intro, NewMauville_Inside_Text_Grunt3Defeat
	msgbox NewMauville_Inside_Text_Grunt3Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt4::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_4, NewMauville_Inside_Text_Grunt4Intro, NewMauville_Inside_Text_Grunt4Defeat
	msgbox NewMauville_Inside_Text_Grunt4Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt5::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_5, NewMauville_Inside_Text_Grunt5Intro, NewMauville_Inside_Text_Grunt5Defeat
	msgbox NewMauville_Inside_Text_Grunt5Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt6::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_6, NewMauville_Inside_Text_Grunt6Intro, NewMauville_Inside_Text_Grunt6Defeat
	msgbox NewMauville_Inside_Text_Grunt6Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt7::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_7, NewMauville_Inside_Text_Grunt7Intro, NewMauville_Inside_Text_Grunt7Defeat
	msgbox NewMauville_Inside_Text_Grunt7Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt8::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_8, NewMauville_Inside_Text_Grunt8Intro, NewMauville_Inside_Text_Grunt8Defeat
	msgbox NewMauville_Inside_Text_Grunt8Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt9::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_9, NewMauville_Inside_Text_Grunt9Intro, NewMauville_Inside_Text_Grunt9Defeat
	msgbox NewMauville_Inside_Text_Grunt9Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt10::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_10, NewMauville_Inside_Text_Grunt10Intro, NewMauville_Inside_Text_Grunt10Defeat
	msgbox NewMauville_Inside_Text_Grunt10Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt11::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_11, NewMauville_Inside_Text_Grunt11Intro, NewMauville_Inside_Text_Grunt11Defeat
	msgbox NewMauville_Inside_Text_Grunt11Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt12::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_12, NewMauville_Inside_Text_Grunt12Intro, NewMauville_Inside_Text_Grunt12Defeat
	msgbox NewMauville_Inside_Text_Grunt12Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt13::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_13, NewMauville_Inside_Text_Grunt13Intro, NewMauville_Inside_Text_Grunt13Defeat
	msgbox NewMauville_Inside_Text_Grunt13Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Grunt14::
	trainerbattle_single TRAINER_MAUVILLE_GRUNT_14, NewMauville_Inside_Text_Grunt14Intro, NewMauville_Inside_Text_Grunt14Defeat
	msgbox NewMauville_Inside_Text_Grunt14Post, MSGBOX_AUTOCLOSE
	end

NewMauville_Inside_EventScript_Tabitha::
	lockall
	msgbox NewMauville_Inside_Text_Tabitha1, MSGBOX_DEFAULT
	applymovement LOCALID_TABITHA_NM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_TABITHA_NM, Common_Movement_FacePlayer
	waitmovement 0
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox NewMauville_Inside_Text_Tabitha2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TABITHA_NM, NewMauville_Inside_Text_Tabitha3
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox NewMauville_Inside_Text_Tabitha4, MSGBOX_DEFAULT
	fadedefaultbgm
	fadescreen FADE_TO_BLACK 
	setflag FLAG_118_GRUNTS
	removeobject LOCALID_TABITHA_NM
	removeobject LOCALID_GRUNT_NM
	fadescreen FADE_FROM_BLACK 
	releaseall
	end
