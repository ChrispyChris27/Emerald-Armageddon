RocketHideout3_MapScripts::
map_script MAP_SCRIPT_ON_LOAD, RocketHideout3_OnLoad
	.byte 0

RocketHideout3_OnLoad::
	setvar VAR_UNUSED_0x40F7, 1
	end

RocketHideout_Grunt7_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_7, RocketHideoutGrunt7Intro, RocketHideoutGrunt7Defeat
	msgbox RocketHideoutGrunt7PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt8_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_8, RocketHideoutGrunt8Intro, RocketHideoutGrunt8Defeat
	msgbox RocketHideoutGrunt8PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt9_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_9, RocketHideoutGrunt9Intro, RocketHideoutGrunt9Defeat
	msgbox RocketHideoutGrunt9PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt10_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_10, RocketHideoutGrunt10Intro, RocketHideoutGrunt10Defeat
	msgbox RocketHideoutGrunt10PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt11_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_11, RocketHideoutGrunt11Intro, RocketHideoutGrunt11Defeat
	msgbox RocketHideoutGrunt11PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt12_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_12, RocketHideoutGrunt12Intro, RocketHideoutGrunt12Defeat
	msgbox RocketHideoutGrunt12PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt13_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_13, RocketHideoutGrunt13Intro, RocketHideoutGrunt13Defeat
	msgbox RocketHideoutGrunt13PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt14_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_14, RocketHideoutGrunt14Intro, RocketHideoutGrunt14Defeat
	msgbox RocketHideoutGrunt14PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt15_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_15, RocketHideoutGrunt15Intro, RocketHideoutGrunt15Defeat
	msgbox RocketHideoutGrunt15PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Grunt16_Script::
	trainerbattle_single TRAINER_HIDEOUT_GRUNT_16, RocketHideoutGrunt16Intro, RocketHideoutGrunt16Defeat
	msgbox RocketHideoutGrunt16PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_Scientist1_Script::
	msgbox RocketHideoutScientist1Text, MSGBOX_NPC
	end

RocketHideout_Scientist2_Script::
	msgbox RocketHideoutScientist2Text, MSGBOX_NPC
	end

RocketHideout_Scientist3_Script::
	msgbox RocketHideoutScientist3Text, MSGBOX_NPC
	end

RocketHideout_Scientist4_Script::
	msgbox RocketHideoutScientist4Text, MSGBOX_NPC
	end

RocketHideout_Scientist5_Script::
	msgbox RocketHideoutScientist5Text, MSGBOX_NPC
	end

RocketHideout_Scientist6_Script::
	msgbox RocketHideoutScientist6Text, MSGBOX_NPC
	end

RocketHideoutScientist1Text:
	.string "I don't know what TEAM ROCKET\n"
	.string "is planning.\p"
	.string "I'm just a hired hand.$"

RocketHideoutScientist2Text:
	.string "I applied for a job at the SPACE\n"
	.string "CENTER but was turned down.\p"
	.string "TEAM ROCKET offered me the chance\n"
	.string "to make my dreams come true.$"

RocketHideoutScientist3Text:
	.string "Please leave me alone, I have to\n"
	.string "concentrate on this data.\p"
	.string "If something goes wrong there could\n"
	.string "be dire consequences.$"

RocketHideoutScientist4Text:
	.string "Any minute now we'll be ready for\n"
	.string "lift off.\p"
	.string "After that it's all hands on deck\n"
	.string "to make sure the launch is a success.$"

RocketHideoutScientist5Text:
	.string "I control the launch angle and\n"
	.string "trajectory from here.\p"
	.string "It's imperative that things are\n"
	.string "perfect if GIOVANNI is to acheive\l"
	.string "his goals.$"

RocketHideoutScientist6Text:
	.string "TEAM ROCKET offered me twice what\n"
	.string "they were paying me in MOSSDEEP.\p"
	.string "After helping them steal the rocket\n"
	.string "fuel, I started working in this lab.\p"
	.string "It makes no difference who I send to\n"
	.string "space as long as someone gets there!$"

RocketHideoutGrunt7Intro:
	.string "You aren't part of TEAM ROCKET!$"

RocketHideoutGrunt8Intro:
	.string "How did you find our hideout?$"

RocketHideoutGrunt9Intro:
	.string "Aren't these warp panels amazing?\p"
	.string "Once you step on one, you don't\n"
	.string "know if you'll be plunged into a\l"
	.string "battle or sent back to the start!$"

RocketHideoutGrunt10Intro:
	.string "I'm the next line of defense!\p"
	.string "Once I crush you I'll send you\n"
	.string "packing to the entrance!$"

RocketHideoutGrunt11Intro:
	.string "Now that we have the rocket fuel\n"
	.string "TEAM ROCKET is unstoppable!$"

RocketHideoutGrunt12Intro:
	.string "TEAM ROCKET will soon complete its\n"
	.string "master plan!$"

RocketHideoutGrunt13Intro:
	.string "You've gone through the control\n"
	.string "room so you know our plan now.\p"
	.string "For that reason I'll have to stop\n"
	.string "you!$"

RocketHideoutGrunt14Intro:
	.string "As awesome as it would be I have\n"
	.string "no intention of letting you see\l"
	.string "the rocket launch!\p"
	.string "Your reign of terror ends here!$"

RocketHideoutGrunt15Intro:
	.string "We've had scientists and engineers\n"
	.string "working here while we traversed\l"
	.string "HOENN doing research and collecting\l"
	.string "resources.\p"
	.string "Everything is coming together now and\n"
	.string "I won't let you get in the way!$"

RocketHideoutGrunt16Intro:
	.string "The warp panel ahead would take you\n"
	.string "to the end of our base.\p"
	.string "Unfortunately for you I'll be \n"
	.string "evicting you now!$"

RocketHideoutGrunt7Defeat:
	.string "Would you like to join TEAM ROCKET?$"

RocketHideoutGrunt8Defeat:
	.string "What do you mean no!?!?$"

RocketHideoutGrunt9Defeat:
	.string "That battle went at warp speed!$"

RocketHideoutGrunt10Defeat:
	.string "You sent me packing!$"

RocketHideoutGrunt11Defeat:
	.string "We on the other hand are not\n"
	.string "unstoppable.$"

RocketHideoutGrunt12Defeat:
	.string "I guess this is why we don't\n"
	.string "get to go on the rocket.$"

RocketHideoutGrunt13Defeat:
	.string "Don't go blabbing about the plan!$"

RocketHideoutGrunt14Defeat:
	.string "So your reign of terror continues...$"

RocketHideoutGrunt15Defeat:
	.string "My defeat won't stop anything!$"

RocketHideoutGrunt16Defeat:
	.string "I guess you'll be sticking around.$"

RocketHideoutGrunt7PostBattle:
	.string "You could be an asset for TEAM\n"
	.string "ROCKET, but instead you opt to\l"
	.string "just be an ass!$"

RocketHideoutGrunt8PostBattle:
	.string "Our hideout was so well hidden.\p"
	.string "How did you manage to find it!?!?$"

RocketHideoutGrunt9PostBattle:
	.string "If you step on the wrong panel you'll\n"
	.string "be sent back to the start of this room.\p"
	.string "Don't ask me what the right panel is!$"

RocketHideoutGrunt10PostBattle:
	.string ""
