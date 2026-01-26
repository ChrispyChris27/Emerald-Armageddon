SeafloorCavern_Room8_MapScripts::
	.byte 0

SeafloorCavern_Room8_EventScript_Matt::
	trainerbattle_single TRAINER_MATT_DOUBLE, SeafloorCavern_Room8_Text_MattIntro, SeafloorCavern_Room8_Text_MattDefeat
	msgbox SeafloorCavern_Room8_Text_MattPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room8_Text_MattIntro:
	.string "It's time to avenge the defeat\n"
	.string "you handed me in our hideout!\p"
	.string "The Boss is on the verge of\n"
	.string "awakening Kyogre's true power.\p"
	.string "The two of us will put a stop to\n"
	.string "your meddling and save the boss\l"
	.string "some precious time!$"

SeafloorCavern_Room8_Text_MattDefeat:
	.string "Argh!\n"
	.string "Not again!$"

SeafloorCavern_Room8_Text_MattPostBattle:
	.string "As strong as you are, you're no\n"
	.string "match for the true power of Kyogre!\p"
	.string "Tread forward carefully or you'll\n"
	.string "be sucked into the depths of the sea!$"
