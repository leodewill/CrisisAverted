// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "MinigameBlock.h"
#include "MinigameImportantTypes.h"
#include "Minigame.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinigameEndEvent, EMinigameEndReason, Reason);

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

	void RegisterBlock(UMinigameBlock* Block);

	void StartMinigame();

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	FGameplayTag MinigameTag;

	FMinigameEndEvent OnMinigameEnd;

protected:
	UFUNCTION()
	void UpdateMinigame();

	UFUNCTION(BlueprintCallable)
	void EndMinigame(EMinigameEndReason Reason);

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetup();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStart();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdate();

	UFUNCTION(BlueprintImplementableEvent)
	void OnEnd(EMinigameEndReason Reason);

	FTimerHandle MinigameTimer;

private:
	TArray<UMinigameBlock*> MinigameBlocks;
};
