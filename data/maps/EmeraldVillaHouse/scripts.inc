EmeraldVillaHouse_MapScripts::
	.byte 0


EmeraldVillaHouseLoreKeeper::
	lockall
	msgbox EmeraldLorekeeperPreBattle, MSGBOX_NPC
	setflag FLAG_SKY_BATTLES
	special TrySkyBattle
    compare VAR_RESULT, TRUE
    goto_if_ne CannotSkyBattle
	trainerbattle_no_intro TRAINER_LK_EMERALD, EmeraldLorekeeperDefeat
	clearflag FLAG_SKY_BATTLES
	msgbox EmeraldLorekeeperPostBattle, MSGBOX_DEFAULT
	releaseall
	end

EmeraldLorekeeperPreBattle:
	.string "A visitor to the Emerald Villa is\n"
	.string "most unusual...\p"
	.string "Yet despite this, I have been\n"
	.string "expecting you...\p"
	.string "I understand that Groudon and\n"
	.string "Kyogre have been awakened and\l"
	.string "currently causing chaos.\p"
	.string "The weather is in an erratic state\n"
	.string "although this villa is protected.\p"
	.string "If those two aren't calmed soon, all\n"
	.string "of Hoenn could be destroyed...\p"
	.string "But you already know all of this.\n"
	.string "If the entrance to this Villa was\l"
	.string "revealed to you, it means you have\l"
	.string "spoken to the Lorekeepers of the Ruby\l"
	.string "and Sapphire Legends already.\p"
	.string "You are here to learn of the\n"
	.string "Emerald Legend, correct?\p"
	.string "Long ago Rayquaza soared above\n"
	.string "Hoenn as the master of the skies.\p"
	.string "If you wish to hear the Emerald\n"
	.string "Legend, you must show me you too\l"
	.string "are a master of the skies.$"

EmeraldLorekeeperDefeat:
	.string "You are a true master of the sky.$"

EmeraldLorekeeperPostBattle:
	.string "Very well, you have deemed\n"
	.string "yourself worthy of hearing\l"
	.string "the legend of Rayquaza.$"

CannotSkyBattle:
	.string "A true master of the skies would\n"
	.string "have a Pokemon that can fly!\p"
	.string "See me again when you have brought\n"
	.string "such a pokemon with you.$"
