// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE_MyGameGameMode.h"
#include "UE_MyGameCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE_MyGameGameMode::AUE_MyGameGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
