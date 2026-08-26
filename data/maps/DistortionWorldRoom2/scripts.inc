DistortionWorldRoom2_MapScripts::
	.byte 0

Distortion_World_Teleport_3::
	addvar VAR_DISTORTION_WORLD_STATE, 1
	warpteleport MAP_DISTORTION_WORLD_ROOM3, 0, 0
	waitstate
	end
