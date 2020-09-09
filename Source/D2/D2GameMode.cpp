// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "D2GameMode.h"
#include "D2HUD.h"
#include "D2Character.h"
#include "UObject/ConstructorHelpers.h"

AD2GameMode::AD2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AD2HUD::StaticClass();
}
