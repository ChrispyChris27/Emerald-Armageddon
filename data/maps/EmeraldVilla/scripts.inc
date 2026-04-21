EmeraldVilla_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EmeraldVilla_OnFrame
	.byte 0

EmeraldVilla_OnFrame::
	map_script_2 VAR_EMERALD_LEGEND_STATE, 2, TellEmeraldLegendOutside
	.2byte 0

TellEmeraldLegendOutside:
lockall
applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
waitmovement
msgbox EmeraldLegendPart1, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement1
applymovement LOCALID_PLAYER, SLegendMovement1
waitmovement
msgbox EmeraldLegendPart2, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement2
applymovement LOCALID_PLAYER, SLegendMovement2
waitmovement
msgbox EmeraldLegendPart3, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement3
applymovement LOCALID_PLAYER, SLegendMovement3
waitmovement
msgbox EmeraldLegendPart4, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement4
applymovement LOCALID_PLAYER, SLegendMovement4
waitmovement
msgbox EmeraldLegendPart5, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement5
applymovement LOCALID_PLAYER, SLegendMovement5
waitmovement
msgbox EmeraldLegendPart6, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement6
applymovement LOCALID_PLAYER, SLegendMovement6
waitmovement
msgbox EmeraldLegendPart7, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement7
applymovement LOCALID_PLAYER, SLegendMovement7
waitmovement
msgbox EmeraldLegendPart8, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement8
applymovement LOCALID_PLAYER, SLegendMovement8
waitmovement
msgbox EmeraldLegendPart9, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement9
applymovement LOCALID_PLAYER, SLegendMovement9
waitmovement
msgbox EmeraldLegendPart10, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement10
applymovement LOCALID_PLAYER, SLegendMovement10
waitmovement
msgbox EmeraldLegendPart11, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement11
applymovement LOCALID_PLAYER, SLegendMovement11
waitmovement
msgbox EmeraldLegendPart12, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement12
applymovement LOCALID_PLAYER, SLegendMovement12
waitmovement
msgbox EmeraldLegendPart13, MSGBOX_AUTOCLOSE
applymovement LOCALID_EMERALD_LK_OUTSIDE, SLKMovement13
waitmovement
removeobject LOCALID_EMERALD_LK_OUTSIDE
playse SE_DOOR
waitse
setvar VAR_EMERALD_LEGEND_STATE, 3
clearflag FLAG_LK_TEMP
releaseall
end

EmeraldLegendPart1:
	.string "Thousands of years ago Groudon\n"
	.string "and Kyogre lived in harmony, with\l"
	.string "Kyogre having dominion over the sea\l"
	.string "and Groudon control of the land.\p"
	.string "Rayquaza, the third of the super\n"
	.string "ancient pokémon, watched over them\l"
	.string "both from the skies above.\p"
	.string "All three of these pokémon are very\n"
	.string "powerful, but by nature all are also\l"
	.string "peaceful and kind.$"

EmeraldLegendPart2:
	.string "Groudon created land that humans\n"
	.string "carved into homes and used to grow\l"
	.string "crops while Kyogre ensured there was\l"
	.string "enough water for people to drink and\l"
	.string "those crops to grow.\p"
	.string "Rayquaza patroled the skies, making\n"
	.string "sure that no natural disaster or\l"
	.string "aerial threat would harm people.$"

EmeraldLegendPart3:
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
	.string "being destroyed.$"

EmeraldLegendPart4:
	.string "This pokémon was so dangerous and so\n"
	.string "powerful that it burned a hole through\l"
	.string "the skies of Hoenn using only light.\p"
	.string "Rayquaza abandoned the humans, Kyogre,\n"
	.string "and Groudon to protect the skies from\l"
	.string "this burning light.$"

EmeraldLegendPart5:
	.string "While the humans were ultimately able\n"
	.string "to send the pokémon from another\l"
	.string "dimension back to its own realm,\l"
	.string "it required sealing their castle shut.\p"
	.string "Groudon and Kyogre both helped the\n"
	.string "humans to be able to move from their\l"
	.string "castle across the rest of Hoenn by\l"
	.string "making islands in the sea and rain\l"
	.string "in the deserts, but both also saw\l"
	.string "the actions of each other as a threat.$"

EmeraldLegendPart6:
	.string "The two goliaths primarily fought\n"
	.string "each other, while Regigigas, Wailord,\l"
	.string "and Relicanth helped the humans.\p"
	.string "Despite Groudon and Kyogre both\n"
	.string "having the same end goal, they were\l"
	.string "lost in the chaos caused by the\l"
	.string "pokémon from another dimension and\l"
	.string "couldn't perceive that their ideals\l"
	.string "were still aligned.$"

EmeraldLegendPart7:
	.string "Rayquaza witnessed this all from the\n"
	.string "skies, but was too busy repairing\l"
	.string "the ozone layer from the light that\l"
	.string "burned the sky to intervene.\p"
	.string "After many months, Rayquaza managed\n"
	.string "to repair the ozone layer and turned\l"
	.string "its attention towards stopping the\l"
	.string "conflict between Kyogre and Groudon.$"

EmeraldLegendPart8:
	.string "Rayquaza was able to stop Kyogre and\n"
	.string "Groudon from destroying Hoenn in their\l"
	.string "conflict by calming the two of them\l"
	.string "down and showing them that both of\l"
	.string "them were trying to help the humans.$"

EmeraldLegendPart9:
	.string "Rayquaza was able to convince Kyogre\n"
	.string "to preserve an area of heat and desert\l"
	.string "so that Groudon could call that home.\p"
	.string "This is why the desert on Route 111\n"
	.string "and the heat of Mt. Chimney and\l"
	.string "Lavaridge remain to this day.$"

EmeraldLegendPart10:
	.string "Groudon in return, would not create\n"
	.string "large islands in the southern parts\l"
	.string "of Hoenn, allowing Kyogre to roam\l"
	.string "freely through the ocean.\p"
	.string "This is why Pacifidlog Town was\n"
	.string "constructed on logs and not land.\p"
	.string "It ensured safe passage through the\n"
	.string "oceans for Kyogre.$"

EmeraldLegendPart11:
	.string "With a newfound understanding and\n"
	.string "their trust in each other restored,\l"
	.string "Kyogre and Groudon once again were\l"
	.string "able to work together in harmony\l"
	.string "to create the version of Hoenn you\l"
	.string "see today.$"

EmeraldLegendPart12:
	.string "Once they were satisfied that the\n"
	.string "humans could thrive in the world\l"
	.string "they had designed, Groudon, Kyogre,\l"
	.string "and Rayquaza went into hiding to\l"
	.string "rest and recover their strength.\p"
	.string "Groudon went to rest within the\n"
	.string "volcano of Mt. Chimney.\p"
	.string "Kyogre slept in the Seafloor Cavern.\p"
	.string "And Rayquaza watches over all from\n"
	.string "the highest point in all of Hoenn.$"

EmeraldLegendPart13:
	.string "This is the Emerald Legend.\p"
	.string "Rayquaza first saved Hoenn from the\n"
	.string "light that burned the sky, before\l"
	.string "restoring the peace between Kyogre\l"
	.string "and Groudon and allowing the three\l"
	.string "of them to shape a Hoenn that would\l"
	.string "allow civilization to thrive.$"
