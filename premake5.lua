workspace "hsfw"
	architecture "x64"
	configurations
	{
		"devel",
		"dist"
	}
	startproject "hsrt"

include "paths.lua"

include "hscore"
include "hsed"
include "hsrt"
