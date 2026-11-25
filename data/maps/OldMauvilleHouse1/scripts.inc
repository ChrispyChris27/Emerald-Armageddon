OldMauvilleHouse1_MapScripts::
	.byte 0

OldMauvilleOldMan::
	lock
	msgbox OldMauvilleManText, MSGBOX_NPC
	closemessage
	releaseall
	end

OldMauvilleManText:
	.string "Old Mauville was the very first\n"
	.string "settlement in Eastern Hoenn.\p"
	.string "Prior to its founding, there were\n"
	.string "no humans living east of the desert\l"
	.string "on Route 111.\p"
	.string "Just as quickly as they settled down,\n"
	.string "they moved north and east from here.\p"
	.string "According to legend, some settlements\n"
	.string "were even pulled across the ocean by\l"
	.string "a massive super ancient pokémon.$"
