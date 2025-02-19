// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Progression/ProgressionImportantTypes.h"
#include "Minigame/Minigame.h"
#include "CrisisAvertedGameMode.generated.h"

UCLASS(minimalapi)
class ACrisisAvertedGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACrisisAvertedGameMode();

	UFUNCTION(BlueprintCallable)
	void StartMinigame(EMinigameType MinigameID);

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Minigames")
	TMap<EMinigameType, TSubclassOf<AMinigame>> MinigameList;

	AMinigame* ActiveMinigame;
};



