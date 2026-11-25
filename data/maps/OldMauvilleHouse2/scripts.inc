OldMauvilleHouse2_MapScripts::
	.byte 0

OldMauvilleOldWoman::
	lock
	msgbox OldMauvilleWomanText, MSGBOX_NPC
	closemessage
	releaseall
	end

OldMauvilleWomanText:
	.string "According to legend, this area\n"
	.string "used to be desert like Route 111.\p"
	.string "When humans settled here hundreds\n"
	.string "of years ago, rivers to the north\l"
	.string "and west started flowing at the same\l"
	.string "bringing vegetation and fresh water\l"
	.string "to the area.\p"
	.string "Whether that was a conincidence or\n"
	.string "something bigger is up for debate.$"
