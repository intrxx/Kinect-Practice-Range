// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "KinectProjectGameMode.h"
#include "KinectProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKinectProjectGameMode::AKinectProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
