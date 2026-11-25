OldMauvilleMuseum_MapScripts::
	.byte 0

OMPainting1Text:
	.string "This painting depicts a group of\n"
	.string "people and pokemon sealing a castle\l"
	.string "door closed.$"

OMPainting2Text:
	.string "This painting depicts a large white\n"
	.string "and yellow pokémon tugging a large\l"
	.string "landmass with ropes.$"

OMPainting3Text:
	.string "This painting depicts a brown fish\n"
	.string "pokémon swimming through a river\l"
	.string "in a desert wasteland.$"

OMPainting4Text:
	.string "This painting depicts a laser beam\n"
	.string "firing out of the mountains and\l"
	.string "into the sky.$"

OMPainting5Text:
	.string "This painting depicts what appears\n"
	.string "to be a black hole in the side of\l"
	.string "a rocky cliffside.$"

OMStatue1Text:
	.string "There's an inscription below the statue:\p"
	.string "Just as the Colossal Pokémon guided\n"
	.string "the ancient humans, this statue guides\l"
	.string "us in modern times.$"

OMStatue2Text:
	.string "There's an inscription below the statue:\p"
	.string "Just as the Longevity Pokémon guided\n"
	.string "rivers through the desert, this statue\l"
	.string "guides us in modern times.$"

OldMauvilleMuseumPainting1::
	msgbox OMPainting1Text, MSGBOX_SIGN
	end

OldMauvilleMuseumPainting2::
	msgbox OMPainting2Text, MSGBOX_SIGN
	end

OldMauvilleMuseumPainting3::
	msgbox OMPainting3Text, MSGBOX_SIGN
	end

OldMauvilleMuseumPainting4::
	msgbox OMPainting4Text, MSGBOX_SIGN
	end

OldMauvilleMuseumPainting5::
	msgbox OMPainting5Text, MSGBOX_SIGN
	end

OldMauvilleMuseumStatue1::
	msgbox OMStatue1Text, MSGBOX_SIGN
	end

OldMauvilleMuseumStatue2::
	msgbox OMStatue2Text, MSGBOX_SIGN
	end

OldMauvilleMuseumOldMan::
	lock
	msgbox OldMauvilleMuseumManText, MSGBOX_NPC
	closemessage
	releaseall
	end

OldMauvilleMuseumManText:
	.string "This museum was founded to \n"
	.string "remember parts of ancient Hoenn.\p"
	.string "The paintings you see here depict\n"
	.string "events that happened hundreds of\l"
	.string "years ago.$"

OldMauvilleMuseumOldWoman::
	lock
	msgbox OldMauvilleMuseumWomanText, MSGBOX_NPC
	closemessage
	releaseall
	end

OldMauvilleMuseumWomanText:
	.string "I don't know exactly what these\n"
	.string "paintings depict, but I can tell\l"
	.string "you this:\p"
	.string "There was an invader, a battle, and\n"
	.string "a victory for Hoenn.\p"
	.string "The victory came at a great cost,\n"
	.string "but the humans persisted with the\l"
	.string "help of the pokémon depicted here.$"
