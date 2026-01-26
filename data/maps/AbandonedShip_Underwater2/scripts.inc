AbandonedShip_Underwater2_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Underwater2_OnResume
	.byte 0

AbandonedShip_Underwater2_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_ROOMS_B1F, 13, 7
	end

AbandonedShip_RogueBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 2, 0, 1
	settotemboost B_POSITION_OPPONENT_RIGHT, 1, 1, 2, 0, 1
	setwildbattle SPECIES_DHELMISE, 84, ITEM_LUM_BERRY, SPECIES_RELICANTH, 84, ITEM_RINDO_BERRY
	waitse
	playmoncry SPECIES_RELICANTH, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DHELMISE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Dhelmise_Relicanth_Defeated
	releaseall
	end

Dhelmise_Relicanth_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setflag FLAG_TOTEM_CRYOGONAL
	setvar VAR_ROGUE_STATE, 14
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ENTRANCE_AQUA_GRUNT
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROGUE_RELI
	removeobject LOCALID_ROGUE_DHEL
	fadescreen FADE_FROM_BLACK
	pokenavcall ShipCalmedText
	waitmessage
	releaseall
	end

Dhelmise_Relicanth_Enters1::
	lockall
	playmoncry SPECIES_RELICANTH, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DHELMISE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_RELI, Relicanth_Movement1
	applymovement LOCALID_ROGUE_DHEL, Dhelmise_Movement1
	goto AbandonedShip_RogueBattle

Relicanth_Movement1:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end 

Dhelmise_Movement1:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Dhelmise_Relicanth_Enters2::
	lockall
	playmoncry SPECIES_RELICANTH, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DHELMISE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_RELI, Relicanth_Movement2
	applymovement LOCALID_ROGUE_DHEL, Dhelmise_Movement2
	goto AbandonedShip_RogueBattle

Relicanth_Movement2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end 

Dhelmise_Movement2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end  

Dhelmise_Relicanth_Enters3::
	lockall
	playmoncry SPECIES_RELICANTH, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DHELMISE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_RELI, Relicanth_Movement3
	applymovement LOCALID_ROGUE_DHEL, Dhelmise_Movement3
	goto AbandonedShip_RogueBattle

Relicanth_Movement3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end 

Dhelmise_Movement3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end  

Dhelmise_Relicanth_Enters4::
	lockall
	playmoncry SPECIES_RELICANTH, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DHELMISE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_RELI, Relicanth_Movement4
	applymovement LOCALID_ROGUE_DHEL, Dhelmise_Movement4
	goto AbandonedShip_RogueBattle

Relicanth_Movement4:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end 

Dhelmise_Movement4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end  

Dhelmise_Relicanth_Enters5::
	lockall
	playmoncry SPECIES_RELICANTH, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_DHELMISE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_RELI, Relicanth_Movement5
	applymovement LOCALID_ROGUE_DHEL, Dhelmise_Movement5
	goto AbandonedShip_RogueBattle

Relicanth_Movement5:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_down
	step_end 

Dhelmise_Movement5:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end  

ShipCalmedText:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: Hey {PLAYER}{KUN}!\p"
	.string "I understand it wasn't just\n"
	.string "one rogue pokémon you had to\l"
	.string "deal with, but a pair of them.\p"
	.string "Relicanth and Dhelmise certainly\n"
	.string "are pokémon I would expect to\l"
	.string "find at the bottom of a ship.\p"
	.string "I'm glad you were able to calm\n"
	.string "them down.\p"
	.string "Anyways, do you about the under-\n"
	.string "water cavern on Route 128?\p"
	.string "Well, we recently spotted Team\n"
	.string "Aqua heading in and out of the\l"
	.string "cave with their stolen sub.\p"
	.string "I'll monitor the situation up\n"
	.string "here, but you should dive down\l"
	.string "and see what they are up to.\p"
	.string "I should have more information\n"
	.string "to share with you soon about\l"
	.string "the energy surges and mysterious\l"
	.string "castle within Meteor Falls.\p"
	.string "Good luck taking down Team Aqua!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
