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

	AMinigame* GetActiveMinigame() const { return ActiveMinigame; }

	AMinigame* GetActiveMinigameWithID(EMinigameType MinigameID) const { return (IsValid(ActiveMinigame) && ActiveMinigame->GetID() == MinigameID) ? ActiveMinigame : nullptr; }

	FMinigameSyncEvent OnStartMinigame;

protected:
	AMinigame* ActiveMinigame;
};
