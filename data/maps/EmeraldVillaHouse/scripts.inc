EmeraldVillaHouse_MapScripts::
	.byte 0

EmeraldVillaHouseLoreKeeper::
	lockall
	applymovement LOCALID_EMERALD_LK, Common_Movement_FacePlayer
	goto_if_eq VAR_EMERALD_LEGEND_STATE, 2, RetellEmeraldLegend
	goto_if_eq VAR_EMERALD_LEGEND_STATE, 1, EmeraldVillaShouldBattle
	msgbox EmeraldLorekeeperPreBattle, MSGBOX_DEFAULT
	setvar VAR_EMERALD_LEGEND_STATE, 1
	goto EmeraldVillaShouldBattle

EmeraldVillaShouldBattle::
	msgbox EmeraldLorekeeperPrepForBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, StartEmeraldVillaBattle
	msgbox EmeraldLorekeeperReturnLater, MSGBOX_DEFAULT
	releaseall
	end

StartEmeraldVillaBattle::
	setstartingstatus STARTING_STATUS_DELTA_STREAM
	msgbox EmeraldLorekeeperBattleStart, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LK_EMERALD, EmeraldLorekeeperDefeat
	msgbox EmeraldLorekeeperPostBattle, MSGBOX_DEFAULT
	setflag FLAG_EMERALD_LEGEND
	setvar VAR_EMERALD_LEGEND_STATE, 2
	goto TellEmeraldLegend

TellEmeraldLegend::
	msgbox EmeraldLorekeeperLegend, MSGBOX_DEFAULT
	releaseall
	end

RetellEmeraldLegend::
	msgbox TellEmeraldLegendAgainText, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, TellEmeraldLegend
	releaseall
	end

EmeraldLorekeeperPreBattle:
	.string "A visitor to the Emerald Villa is\n"
	.string "most unusual...\p"
	.string "Yet despite this, I have been\n"
	.string "expecting you...\p"
	.string "I understand that Groudon and\n"
	.string "Kyogre have been awakened and are\l"
	.string "currently causing chaos.\p"
	.string "The weather is in an erratic state\n"
	.string "although this villa is protected.\p"
	.string "If those two aren't calmed soon, all\n"
	.string "of Hoenn could be destroyed...\p"
	.string "But you already know all of this.\p"
	.string "If the entrance to this Villa was\n"
	.string "revealed to you, it means you have\l"
	.string "spoken to the Lorekeepers of the Ruby\l"
	.string "and Sapphire Legends already.\p"
	.string "You are here to learn of the\n"
	.string "Emerald Legend, correct?\p"
	.string "Long ago Rayquaza soared above\n"
	.string "Hoenn as the master of the skies.\p"
	.string "Where Rayquaza traveled, extreme\n"
	.string "gusts of wind would often pick up\l"
	.string "unsuspecting pokemon off the ground.\p"
	.string "This very villa was constructed on\n"
	.string "one such spot where the gusts of\l"
	.string "wind are exceptionally strong."

EmeraldLorekeeperPrepForBattle:
	.string "If you wish to hear the Emerald\n"
	.string "Legend, you must show me you too\l"
	.string "are a master of the skies.\p"
	.string "Are you prepared to do this?$"

EmeraldLorekeeperDefeat:
	.string "You are a true master of the sky.$"

EmeraldLorekeeperPostBattle:
	.string "Very well, you have deemed\n"
	.string "yourself worthy of hearing\l"
	.string "the legend of Rayquaza.\p"
	.string "Please follow me outside.$"

EmeraldLorekeeperReturnLater:
	.string "Please return when you are ready to\n"
	.string "prove you have mastered the skies.$"

EmeraldLorekeeperBattleStart:
	.string "Take to the skies and prove to me you\n"
	.string "are worthy of the Emerald Legend!$"

EmeraldLorekeeperLegend:
	.string "Thousands of years ago Groudon\n"
	.string "and Kyogre lived in harmony, with\l"
	.string "Kyogre having dominion over the sea\l"
	.string "and Groudon control of the land.\p"
	.string "Rayquaza, the third of the super\n"
	.string "ancient pokémon, watched over them\l"
	.string "both from the skies above.\p"
	.string "All three of these pokémon are very\n"
	.string "powerful, but by nature all are also\l"
	.string "peaceful and kind.\p"
	.string "Groudon created land that humans\n"
	.string "carved into homes and used to grow\l"
	.string "crops while Kyogre ensured there was\l"
	.string "enough water for people to drink and\l"
	.string "those crops to grow.\p"
	.string "Rayquaza patroled the skies, making\n"
	.string "sure that no natural disaster or\l"
	.string "aerial threat would harm people.\n"
	.string "Kyogre. Groudon. Humans. Rayquaza.\p"
	.string "For awhile, all four lived together\n"
	.string "in harmony.\p"
	.string "Then, everything changed when the\n"
	.string "pokémon from another dimension\l"
	.string "attacked.\p"
	.string "This pokémon sought to bring its own\n"
	.string "world into ours, leading to chaos,\l"
	.string "destruction, and the harmony between\l"
	.string "the humans and super ancient pokémon\l"
	.string "being destroyed.\p"
	.string "This pokémon was so dangerous and so\n"
	.string "powerful that it burned a hole through\l"
	.string "the skies of Hoenn using only light.\p"
	.string "Rayquaza abandoned the humans, Kyogre,\n"
	.string "and Groudon to protect the skies from\l"
	.string "this burning light.\p"
	.string "Both Kyogre and Groudon sought to help\n"
	.string "the humans, but they did so in ways\l"
	.string "that angered each other.\p"
	.string "While the humans were ultimately able\n"
	.string "to send the pokémon from another\l"
	.string "dimension back to its own realm,\l"
	.string "it required sealing their castle shut.\p"
	.string "Groudon and Kyogre both helped the\n"
	.string "humans to be able to move from their\l"
	.string "castle across the rest of Hoenn by\l"
	.string "making islands in the sea and rain\l"
	.string "in the deserts, but both also saw\l"
	.string "the actions of each other as a threat.\p"
	.string "The two goliaths primarily fought\n"
	.string "each other, while Regigigas, Wailord,\l"
	.string "and Relicanth helped the humans.\p"
	.string "Despite Groudon and Kyogre both\n"
	.string "having the same end goal, they were\l"
	.string "lost in the chaos caused by the\l"
	.string "pokémon from another dimension and\l"
	.string "couldn't perceive that their ideals\l"
	.string "were still aligned.\p"
	.string "Rayquaza witnessed this all from the\n"
	.string "skies, but was too busy repairing\l"
	.string "the ozone layer from the light that\l"
	.string "burned the sky to intervene.\p"
	.string "After many months, Rayquaza managed\n"
	.string "to repair the ozone layer and turned\l"
	.string "its attention towards stopping the\l"
	.string "conflict between Kyogre and Groudon.\p"
	.string "Rayquaza was able to stop Kyogre and\n"
	.string "Groudon from destroying Hoenn in their\l"
	.string "conflict by calming the two of them\l"
	.string "down and showing them that both of\l"
	.string "them were trying to help the humans.\p"
	.string "Rayquaza was able to convince Kyogre\n"
	.string "to preserve and area of heat and desert\l"
	.string "so that Groudon could call that home.\p"
	.string "This is why the desert on Route 111\n"
	.string "and the heat of Mt. Chimney and\l"
	.string "Lavaridge remain to this day.\p"
	.string "Groudon in return, would not create\n"
	.string "large islands in the southern parts\l"
	.string "of Hoenn, allowing Kyogre to roam\l"
	.string "freely through the ocean.\p"
	.string "This is why Pacifidlog Town was\n"
	.string "constructed on logs and not land.\p"
	.string "It ensured safe passage through the\n"
	.string "oceans for Kyogre.\p"
	.string "With a newfound understanding and\n"
	.string "their trust in each other restored,\l"
	.string "Kyogre and Groudon once again were\l"
	.string "able to work together in harmony\l"
	.string "to create the version of Hoenn you\l"
	.string "see today.\p"
	.string "Once they were satisfied that the\n"
	.string "humans could thrive in the world\l"
	.string "they had designed, Groudon, Kyogre,\l"
	.string "and Rayquaza went into hiding to\l"
	.string "rest and recover their strength.\p"
	.string "Groudon went to rest within the\n"
	.string "volcano of Mt. Chimney.\p"
	.string "Kyogre slept in the Seafloor Cavern.\p"
	.string "And Rayquaza watches over all from\n"
	.string "the highest point in all of Hoenn.\p"
	.string "This is the Emerald Legend.\p"
	.string "Rayquaza first saved Hoenn from the\n"
	.string "light that burned the sky, before\l"
	.string "restoring the peace between Kyogre\l"
	.string "and Groudon and allowing the three\l"
	.string "of them to shape a Hoenn that would\l"
	.string "allow civilization to thrive.$"

TellEmeraldLegendAgainText:
	.string "Would you like to hear the Emerald\n"
	.string "Legend once again?$"

