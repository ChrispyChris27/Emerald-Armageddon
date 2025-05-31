.set LOCALID_ROOT_FOSSIL, 1
.set LOCALID_CLAW_FOSSIL, 2
.set LOCALID_DOME_FOSSIL, 4
.set LOCALID_HELIX_FOSSIL, 5
.set LOCALID_SKULL_FOSSIL, 6
.set LOCALID_ARMOR_FOSSIL, 7
.set LOCALID_COVER_FOSSIL, 8
.set LOCALID_PLUME_FOSSIL, 9
.set LOCALID_JAW_FOSSIL, 10
.set LOCALID_SAIL_FOSSIL, 11

MirageTower_4F_MapScripts::
	.byte 0

MirageTower_4F_EventScript_RootFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeRootFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveRootFossil
	giveitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	removeobject LOCALID_MIRAGE_ROOT_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveRootFossil::
	msgbox MirageTower_4F_Text_LeftRootFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_ClawFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeClawFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveClawFossil
	giveitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_MIRAGE_CLAW_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveClawFossil::
	msgbox MirageTower_4F_Text_LeaveClawFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_DomeFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeDomeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveDomeFossil
	giveitem ITEM_DOME_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_DOME_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveDomeFossil::
	msgbox MirageTower_4F_Text_LeaveDomeFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_HelixFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeHelixFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveHelixFossil
	giveitem ITEM_HELIX_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_HELIX_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveHelixFossil::
	msgbox MirageTower_4F_Text_LeaveHelixFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_SkullFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeSkullFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveSkullFossil
	giveitem ITEM_SKULL_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_SKULL_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveSkullFossil::
	msgbox MirageTower_4F_Text_LeaveSkullFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_ArmorFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeArmorFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveArmorFossil
	giveitem ITEM_ARMOR_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_ARMOR_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveArmorFossil::
	msgbox MirageTower_4F_Text_LeaveArmorFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_CoverFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeCoverFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveCoverFossil
	giveitem ITEM_COVER_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_COVER_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveCoverFossil::
	msgbox MirageTower_4F_Text_LeaveCoverFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_PlumeFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakePlumeFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeavePlumeFossil
	giveitem ITEM_PLUME_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_PLUME_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeavePlumeFossil::
	msgbox MirageTower_4F_Text_LeavePlumeFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_JawFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeJawFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveJawFossil
	giveitem ITEM_JAW_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_JAW_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveJawFossil::
	msgbox MirageTower_4F_Text_LeaveJawFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_SailFossil::
	lock
	faceplayer
	msgbox MirageTower_4F_Text_TakeSailFossil, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MirageTower_4F_EventScript_LeaveSailFossil
	giveitem ITEM_SAIL_FOSSIL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_HIDE_MIRAGE_TOWER_CLAW_FOSSIL
	setflag FLAG_HIDE_MIRAGE_TOWER_ROOT_FOSSIL
	removeobject LOCALID_SAIL_FOSSIL
	delay 30
	goto MirageTower_4F_EventScript_CollapseMirageTower
	end

MirageTower_4F_EventScript_LeaveSailFossil::
	msgbox MirageTower_4F_Text_LeaveSailFossilAlone, MSGBOX_DEFAULT
	release
	end

MirageTower_4F_EventScript_CollapseMirageTower::
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 32  @ num shakes
	setvar VAR_0x8007, 2   @ shake delay
	special ShakeCamera
	waitstate
	special DoMirageTowerCeilingCrumble
	waitstate
	setvar VAR_MIRAGE_TOWER_STATE, 1
	clearflag FLAG_LANDMARK_MIRAGE_TOWER
	warp MAP_ROUTE111, 19, 59
	waitstate
	release
	end

MirageTower_4F_Text_TakeRootFossil:
	.string "You found the ROOT FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the ROOT FOSSIL anyway?$"

MirageTower_4F_Text_LeftRootFossilAlone:
	.string "{PLAYER} left the ROOT FOSSIL alone.$"

MirageTower_4F_Text_TakeClawFossil:
	.string "You found the CLAW FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the CLAW FOSSIL anyway?$"

MirageTower_4F_Text_LeaveClawFossilAlone:
	.string "{PLAYER} left the CLAW FOSSIL alone.$"

	MirageTower_4F_Text_TakeDomeFossil:
	.string "You found the DOME FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the DOME FOSSIL anyway?$"

MirageTower_4F_Text_LeaveDomeFossilAlone:
	.string "{PLAYER} left the DOME FOSSIL alone.$"

MirageTower_4F_Text_TakeHelixFossil:
	.string "You found the HELIX FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the HELIX FOSSIL anyway?$"

MirageTower_4F_Text_LeaveHelixFossilAlone:
	.string "{PLAYER} left the HELIX FOSSIL alone.$"

MirageTower_4F_Text_TakeSkullFossil:
	.string "You found the SKULL FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the SKULL FOSSIL anyway?$"

MirageTower_4F_Text_LeaveSkullFossilAlone:
	.string "{PLAYER} left the SKULL FOSSIL alone.$"

MirageTower_4F_Text_TakeArmorFossil:
	.string "You found the ARMOR FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the ARMOR FOSSIL anyway?$"

MirageTower_4F_Text_LeaveArmorFossilAlone:
	.string "{PLAYER} left the ARMOR FOSSIL alone.$"

MirageTower_4F_Text_TakeCoverFossil:
	.string "You found the COVER FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the COVER FOSSIL anyway?$"

MirageTower_4F_Text_LeaveCoverFossilAlone:
	.string "{PLAYER} left the COVER FOSSIL alone.$"

MirageTower_4F_Text_TakePlumeFossil:
	.string "You found the PLUME FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the PLUME FOSSIL anyway?$"

MirageTower_4F_Text_LeavePlumeFossilAlone:
	.string "{PLAYER} left the PLUME FOSSIL alone.$"

MirageTower_4F_Text_TakeJawFossil:
	.string "You found the JAW FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the JAW FOSSIL anyway?$"

MirageTower_4F_Text_LeaveJawFossilAlone:
	.string "{PLAYER} left the JAW FOSSIL alone.$"

MirageTower_4F_Text_TakeSailFossil:
	.string "You found the SAIL FOSSIL.\p"
	.string "If this FOSSIL is taken, the ground\n"
	.string "around it will likely crumble away…\p"
	.string "Take the SAIL FOSSIL anyway?$"

MirageTower_4F_Text_LeaveSailFossilAlone:
	.string "{PLAYER} left the SAIL FOSSIL alone.$"
