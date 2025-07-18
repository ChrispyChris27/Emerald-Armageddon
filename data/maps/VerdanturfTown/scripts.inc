VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_VERDANTURF_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_VERDANTURF_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_MintMan::
	lock
	faceplayer
	goto_if_set FLAG_MINTS_1, VerdanturfTown_GotMints
	msgbox VerdanturfTown_Text_GiveMints, MSGBOX_DEFAULT
	giveitem ITEM_SERIOUS_MINT, 5
	setflag FLAG_MINTS_1
	clearflag FLAG_MINTS_2
	goto VerdanturfTown_GotMints
	release
	end

VerdanturfTown_GotMints::
	msgbox VerdanturfTown_Text_ReceivedMints, MSGBOX_NPC
	release
	end

MetronomeGirl::
	lock
	faceplayer
	goto_if_set FLAG_METRONOME, MetronomeGirl2
	msgbox MetronomeText, MSGBOX_DEFAULT
	giveitem ITEM_METRONOME
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_METRONOME
	release
	end

MetronomeGirl2:
	msgbox MetronomeText2, MSGBOX_NPC
	release
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "My papa told me.\p"
	.string "He says this tunnel is full of\n"
	.string "timid POKéMON.\p"
	.string "They get all scared of loud noise and\n"
	.string "make a big uproar.\p"
	.string "So they had to stop the big tunnel\n"
	.string "project.\p"
	.string "But there's one man. He's trying to dig\n"
	.string "the tunnel by himself!$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "There was a man who dug a tunnel for\n"
	.string "a lady he loved.\p"
	.string "I don't really get it, but hey!$"

VerdanturfTown_Text_AirCleanHere:
	.string "The way the winds blow, volcanic ash\n"
	.string "is never blown in this direction.\p"
	.string "The air is clean and delicious here.\n"
	.string "Living here should do wonders for even\l"
	.string "frail and sickly people.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "My POKéMON and I, we've been riding\n"
	.string "a hot winning streak.\p"
	.string "So I decided to make my BATTLE TENT\n"
	.string "debut in this town.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Did you see the cave next to the\n"
	.string "POKéMON MART?\p"
	.string "There's a guy in there who's trying to\n"
	.string "bust up boulders so he can bust out\l"
	.string "through to the other side.\p"
	.string "It'd be great if we could go through…\n"
	.string "It'll make it easy to visit RUSTBORO.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "That cave next to the POKéMON MART\n"
	.string "is now a tunnel to the other side.\p"
	.string "It's great--it's easy to go shop for\n"
	.string "new DEVON products in RUSTBORO now.$"

VerdanturfTown_Text_TownSign:
	.string "VERDANTURF TOWN\p"
	.string "“The windswept highlands with the\n"
	.string "sweet fragrance of grass.”$"

VerdanturfTown_Text_WandasHouse:
	.string "WANDA'S HOUSE$"

VerdanturfTown_Text_BattleTentSign:
	.string "BATTLE TENT VERDANTURF SITE\n"
	.string "“Feast Your Eyes on Battles!”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "RUSTURF TUNNEL\n"
	.string "“Linking RUSTBORO and VERDANTURF\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"

VerdanturfTown_Text_GiveMints:
	.string "Well hello there young traveler!\p"
	.string "Have you ever caught the perfect\n"
	.string "POKéMON only to discover it has an\l"
	.string "imperfect nature?\p"
	.string "There used to be no hope for such a\n"
	.string "specimen, but after many years I have\l"
	.string "perfected the solution to this problem!\p"
	.string "I'd like to give you some free samples!\p"
	.string "All I ask is that you share the word with\n"
	.string "others you see while on your adventure!$"

VerdanturfTown_Text_ReceivedMints:
	.string "Simply use a mint on your POKéMON and\n"
	.string "it's nature will change to match that of\l"
	.string "the mint!\p"
	.string "I look forward to sharing more mints with\n"
	.string "you throughout your journey!$"

MetronomeText:
	.string "The grass here in VERDANTURF is filled\n"
	.string "with FAIRY type POKéMON.\p"
	.string "Many of these POKéMON are capable\n"
	.string "of wonderful music through their\l"
	.string "ALLURING VOICES.\p"
	.string "The sound of music is delightful, but\n"
	.string "sometimes the POKéMON get desynched\l"
	.string "in their songs.\p"
	.string "This item allows them to stay in sync\n"
	.string "with one another.\p"
	.string "Go ahead and take one, I have plenty.$"

MetronomeText2:
	.string "Please use that METRONOME to create\n"
	.string "beautiful music with your POKéMON.$"

