DistortionWorldRoom1_MapScripts::
	.byte 0

Distortion_World_Teleport_2::
	addvar VAR_DISTORTION_WORLD_STATE, 1
	warpteleport MAP_DISTORTION_WORLD_ROOM2, 9, 0
	waitstate
	end
