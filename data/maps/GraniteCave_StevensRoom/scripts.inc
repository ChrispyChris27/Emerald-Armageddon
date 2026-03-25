GraniteCave_StevensRoom_MapScripts::
	.byte 0

GraniteCave_StevensRoom_EventScript_Steven::
	lockall
	faceplayer
	msgbox GraniteCave_StevensRoom_Text_ImStevenLetterForMe, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_LETTER
	call Common_EventScript_PlayerHandedOverTheItem
	setflag FLAG_DELIVERED_STEVEN_LETTER
	setflag FLAG_HIDE_ROUTE_116_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDAS_BOYFRIEND
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_WANDA
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_ROCK_1
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_ROCK_2
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_PRESTATUS_TRAINER
	msgbox GraniteCave_StevensRoom_Text_ThankYouTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_STEEL_WING
	call_if_eq VAR_RESULT, FALSE, GraniteCave_StevensRoom_EventScript_BagFull
	msgbox GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox GraniteCave_StevensRoom_Text_RegisteredSteven, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_REGISTERED_STEVEN_POKENAV
	msgbox GraniteCave_StevensRoom_Text_IveGotToHurryAlong, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_SABLEYE, CRY_MODE_ENCOUNTER
	waitmoncry
	delay 16
	msgbox GraniteCave_Steven_Sableye1, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_TOTEM_SABLEYE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	addobject LOCALID_ROGUE_SABLEYE
	playse SE_DOOR
	waitse
	delay 16
	playmoncry SPECIES_SABLEYE, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE_SABLEYE, SableyeMovement
	goto GraniteCave_SableyeBattle
	end

GraniteCave_StevensRoom_EventScript_StevenExitNorth::
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement 0
	return

GraniteCave_StevensRoom_EventScript_BagFull::
	msgbox GraniteCave_StevensRoom_Text_OhBagIsFull, MSGBOX_DEFAULT
	return

GraniteCave_StevensRoom_Movement_StevenExit:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	step_end

GraniteCave_StevensRoom_Text_ImStevenLetterForMe:
	.string "My name is STEVEN.\p"
	.string "I'm interested in rare stones,\n"
	.string "so I travel here and there.\p"
	.string "Oh?\n"
	.string "A LETTER for me?$"

GraniteCave_StevensRoom_Text_ThankYouTakeThis:
	.string "STEVEN: Okay, thank you.\p"
	.string "You went through all this trouble to\n"
	.string "deliver that. I need to thank you.\p"
	.string "So your name is {PLAYER}?\p"
	.string "Let me see…\n"
	.string "I'll give you this TM.\p"
	.string "It contains my favorite move,\n"
	.string "STEEL WING.$"

GraniteCave_StevensRoom_Text_CouldBecomeChampionLetsRegister:
	.string "STEVEN: Hmmm...\p"
	.string "Your POKéMON appear quite\n"
	.string "capable.\p"
	.string "And if Mr. Devon trusted you to bring\n"
	.string "me that letter, perhaps you can help\l"
	.string "me out with something too.\p"
	.string "Listen {PLAYER},\n"
	.string "Something strange has been happening\l"
	.string "in Hoenn lately.\p"
	.string "Energy surges have been popping up\n"
	.string "throughout the region causing pokémon\l"
	.string "to go crazy!\p"
	.string "These rogue pokémon seem to absorb the\n"
	.string "energy from these surges becoming much\l"
	.string "more powerful than normal.\p"
	.string "What's more concerning is that some of\n"
	.string "these pokémon have been able to mega\l"
	.string "evolve, gigantamax, or terrastalize\l"
	.string "all on their own.\p"
	.string "Pokémon in Hoenn have been known to\n"
	.string "mega evolve when they have a strong\l"
	.string "bond with their trainer, but a pokémon\l"
	.string "mega evolving on its own is unusual...\p"
	.string "A pokémon in Hoenn gigantamaxing or\n"
	.string "terrastalizing is unheard of though!\p"
	.string "Those phenomena have only been seen\n"
	.string "in Galar and Paldea so far respectively.\p"
	.string "I'm concerned for what this might mean\n"
	.string "for us in the Hoenn region.\p"
	.string "Do you think you could help me figure\n"
	.string "out what's going on {PLAYER}?\p"
	.string "Let's register one another in\n"
	.string "our Pokénavs, that way we can stay\l"
	.string "in communication with each other.\p"
	.string "… … … … … …$"

GraniteCave_StevensRoom_Text_RegisteredSteven:
	.string "Registered STEVEN\n"
	.string "in the POKéNAV.$"

GraniteCave_StevensRoom_Text_IveGotToHurryAlong:
	.string "I'd like you to calm down the rogue\n"
	.string "pokémon that show up throughout the\l"
	.string "Hoenn region.\p"
	.string "That way, I can focus on researching\n"
	.string "the source of the mysterious energy.\p"
	.string "I've been trying to do both but I've\n"
	.string "unfortunately not made much progress on\l"
	.string "the research aspect up to this point.\p"
	.string "In fact the reason I'm here in the\n"
	.string "first place is that I saw an energy\l"
	.string "surge in Granite Cave so I came to\l"
	.string "investigate.$"

GraniteCave_StevensRoom_Text_OhBagIsFull:
	.string "Oh, your BAG is full…\n"
	.string "That's too bad, then.$"

GraniteCave_Steven_Sableye1:
	.string "Did you hear that {PLAYER}?\p"
	.string "I think that's the rogue pokémon\n"
	.string "that I came here to investigate.\p"
	.string "I'd like to see how you and your\n"
	.string "pokémon work together in battle.\p"
	.string "Please calm the rogue pokémon and\n"
	.string "dispel the excess energy here.$"

SableyeMovement:
	walk_down
	walk_down
	walk_down
	step_end

GraniteCave_SableyeBattle::
	lockall
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	setflag FLAG_TOTEM_SABLEYE
	settotemboost B_POSITION_OPPONENT_LEFT, 1, 1, 1, 0, 0
	setwildbattle SPECIES_SABLEYE, 30, ITEM_ROSELI_BERRY
	playmoncry SPECIES_SABLEYE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartRogueWildBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Sableye_Defeated
	releaseall
	end

Sableye_Defeated::
	lockall
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setvar VAR_PETALBURG_GYM_STATE, 6
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROGUE_SABLEYE
	fadescreenswapbuffers FADE_FROM_BLACK
	applymovement LOCALID_GRANITE_CAVE_STEVEN, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement
	msgbox GraniteCave_Steven_Sableye2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, PlayerGCaveMoveLeft
	applymovement LOCALID_GRANITE_CAVE_STEVEN, GraniteCave_StevensRoom_Movement_StevenExit
	waitmovement LOCALID_GRANITE_CAVE_STEVEN
	removeobject LOCALID_GRANITE_CAVE_STEVEN
	playse SE_DOOR
	releaseall
	end

GraniteCave_Steven_Sableye2:
	.string "Great work {PLAYER}!\p"
	.string "I knew you would be up to the\n"
	.string "challenge when I saw your pokémon.\p"
	.string "Thanks to you, Sableye has calmed down\n"
	.string "and the energy surge has dissipated.\p"
	.string "When I find another energy surge I'll\n"
	.string "give you a call on your pokénav.\p"
	.string "While you handle the rogue pokémon I'll\n"
	.string "be able to focus on the energy surges.\p"
	.string "Together I'm sure we can get to the\n"
	.string "bottom of this.\p"
	.string "In the meantime, I bet you're ready\n"
	.string "to take on your father at the\l"
	.string "Petalburg City Gym.\p"
	.string "It was a pleasure meeting you {PLAYER},\n"
	.string "I look forward to working with you.$"

PlayerGCaveMoveLeft:
	walk_left
	face_right
	step_end


