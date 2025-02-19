// Copyright Epic Games, Inc. All Rights Reserved.

#include "CrisisAvertedGameMode.h"
#include "CrisisAvertedCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACrisisAvertedGameMode::ACrisisAvertedGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void ACrisisAvertedGameMode::StartMinigame(EMinigameType MinigameID)
{
	if (MinigameList.Contains(MinigameID))
	{
		ActiveMinigame = GetWorld()->SpawnActor<AMinigame>(MinigameList[MinigameID]);
		ActiveMinigame->StartMinigame();
	}
}
