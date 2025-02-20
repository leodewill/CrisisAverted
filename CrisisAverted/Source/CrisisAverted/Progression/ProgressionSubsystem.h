// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "CrisisAverted/Minigame/Minigame.h"
#include "ProgressionSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinigameSyncEvent, AMinigame*, Minigame);

/**
 * 
 */
UCLASS()
class CRISISAVERTED_API UProgressionSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()
	
public:
	UProgressionSubsystem();

	UFUNCTION(BlueprintCallable)
	void StartMinigame(TSubclassOf<AMinigame> MinigameClass);

protected:
	AMinigame* ActiveMinigame;
};
