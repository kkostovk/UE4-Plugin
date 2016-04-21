// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "TestingGame.h"
#include "TestingGameGameMode.h"
#include "TestingGameHUD.h"
#include "TestingGameCharacter.h"

ATestingGameGameMode::ATestingGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGameHUD::StaticClass();
}
