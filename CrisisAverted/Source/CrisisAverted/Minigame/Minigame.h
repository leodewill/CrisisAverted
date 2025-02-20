// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CrisisAverted/Progression/ProgressionImportantTypes.h"
#include "Minigame.generated.h"

constexpr float MINIGAME_UPDATE_FREQ = 0.1f;

/**
 * 
 */
UCLASS()
class CRISISAVERTED_API AMinigame : public AActor
{
	GENERATED_BODY()

public:
	AMinigame();

	void StartMinigame();

	EMinigameType GetID() { return MinigameID; }

protected:
	UFUNCTION()
	void UpdateMinigame();

	void WinMinigame() {}

	void LoseMinigame() {}

	virtual void Start() {}

	virtual void Update() {}

	EMinigameType MinigameID;

	FTimerHandle MinigameTimer;

	float ElapsedTime = 0.f;

	bool bShouldUpdate;
};
