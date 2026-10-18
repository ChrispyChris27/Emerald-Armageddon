EverGrandeCity_PokemonLeague_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CableClub_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, CableClub_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, CableClub_OnTransition
	.byte 0

@ The below 3 are unused and leftover from RS
EverGrandeCity_PokemonLeague_2F_EventScript_Colosseum::
	call CableClub_EventScript_Colosseum
	end

EverGrandeCity_PokemonLeague_2F_EventScript_TradeCenter::
	call CableClub_EventScript_TradeCenter
	end

EverGrandeCity_PokemonLeague_2F_EventScript_RecordCorner::
	call CableClub_EventScript_RecordCorner
	end

EverGrandeCity_PokemonLeague_2F_EventScript_Trader::
	lockall
	faceplayer
	goto_if_set FLAG_WEEZING_NPC_TRADE, Weezing_TradeCompleted
	ingame_trade INGAME_TRADE_GWEEZ, Weezing_Text_WillingToTradeIt, Weezing_DeclineTrade, PacifidlogTown_House3_EventScript_NotRequestedMon, Weezing_Text_ThankYou
	setflag FLAG_WEEZING_NPC_TRADE
	releaseall
	end

Weezing_DeclineTrade::
	msgbox Weezing_Decline_Text, MSGBOX_DEFAULT
	releaseall
	end

Weezing_TradeCompleted::
	msgbox Weezing_Trade_Done_Text, MSGBOX_DEFAULT
	releaseall
	end

Weezing_Text_WillingToTradeIt:
	.string "Pssst!\p"
	.string "I've got the opportunity of a\n"
	.string "lifetime for you my friend!\p"
	.string "I have this here Weezing of mine\n"
	.string "but it's ruining my ninja tactics!\p"
	.string "It keeps neutralizing my Shedinja's\n"
	.string "Wonder Guard which is no good at all!\p"
	.string "I'll let you take it off my hands\n"
	.string "for anything you've got!\p"
	.string "What do you say?$"

Weezing_Decline_Text:
	.string "You can't help a brother out?\p"
	.string "Well I hope you change your mind,\n"
	.string "I spent too long training this\l"
	.string "Weezing to just release it!$"

Weezing_Text_ThankYou:
	.string "Thanks my friend!\n"
	.string "Take good care of Plume Bob will ya?$"

Weezing_Trade_Done_Text:
	.string "Now that Pume Bob's Neutralizing Gas\n"
	.string "won't get in the way of my Shedinja\l"
	.string "my ninja tactics have greatly improved!\p"
	.string "I hope you can make use of that\n"
	.string "ability somehow!$"

