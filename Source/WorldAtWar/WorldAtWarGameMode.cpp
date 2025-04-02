// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorldAtWarGameMode.h"
#include "WorldAtWarCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWorldAtWarGameMode::AWorldAtWarGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
