DistortionWorldEntrance_MapScripts::
	.byte 0

Distortion_World_Teleport_1::
	addvar VAR_DISTORTION_WORLD_STATE, 1
	warpteleport MAP_DISTORTION_WORLD_ROOM1, 9, 19
	waitstate
	end
