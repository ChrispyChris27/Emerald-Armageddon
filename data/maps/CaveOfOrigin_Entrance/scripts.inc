CaveOfOrigin_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CaveOfOrigin_Entrance_OnResume
	.byte 0

CaveOfOrigin_Entrance_OnResume:
	setescapewarp MAP_SOOTOPOLIS_CITY, 31, 17
	end

CaveOfOriginEntrance_RoaringMoonBattle::
	setflag FLAG_SMART_WILD
	setflag FLAG_NO_RUN_WILD
	setflag FLAG_NO_CATCH_WILD
	settotemboost B_POSITION_OPPONENT_LEFT, 2, 1, 2, 2, 1
	setwildbattle SPECIES_ROARING_MOON, 44, ITEM_WEAKNESS_POLICY
	waitse
	playmoncry SPECIES_ROARING_MOON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartRogueWildBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, RoaringMoon_Defeated
	releaseall
	end

RoaringMoon_Defeated::
	clearflag FLAG_SMART_WILD
	clearflag FLAG_NO_RUN_WILD
	clearflag FLAG_NO_CATCH_WILD
	setflag FLAG_TOTEM_ROARING_MOON
	setvar VAR_ROGUE_STATE, 6 
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROGUE_MOON
	fadescreen FADE_FROM_BLACK
	pokenavcall RoaringMoonCalmedText
	waitmessage
	releaseall
	end

RoaringMoonCalmedText:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "Steven: {PLAYER}{KUN}!\n"
	.string "Are you okay!?!\p"
	.string "All of a sudden a surge of \n"
	.string "energy spikes popped up,\l"
	.string "including one right near you!\p"
	.string "I imagine that the erratic\n"
	.string "weather may have something to\l"
	.string "do with this.\p"
	.string "In addition to the Roaring\n"
	.string "Moon you just calmed, I'm\l"
	.string "picking up three more energy\l"
	.string "surges across Hoenn.\p"
	.string "The first surge showed up on\n"
	.string "the beaches near Lilycove City.\p"
	.string "The second surge is coming from\n"
	.string "Route 123 right below Mt. Pyre.\p"
	.string "Finally, the most powerful surge\n"
	.string "is coming from the waterfall that\l"
	.string "leads to Ever Grande City.\p"
	.string "Please {PLAYER}{KUN}.\p"
	.string "Find Wallace within the cave and\n"
	.string "then calm these rogue Pokémon!\p"
	.string "All of us are counting on you!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

RoaringMoon_Movement1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Sigilyph_Movement2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RoaringMoon_Enter1::
	lockall
	playmoncry SPECIES_SIGILYPH, CRY_MODE_ENCOUNTER
	applymovement LOCALID_ROGUE5, Sigilyph_Movement1
	goto CaveOfOriginEntrance_RoaringMoonBattle

