// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayTagContainer.h"
#include "MinigameBlock.h"
#include "MinigameImportantTypes.h"
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

	void RegisterBlock(UMinigameBlock* Block);

	void StartMinigame();

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	FGameplayTag MinigameTag;

protected:
	UFUNCTION()
	void UpdateMinigame();

	UFUNCTION(BlueprintCallable)
	void WinMinigame() {}

	UFUNCTION(BlueprintCallable)
	void LoseMinigame() {}

	UFUNCTION(BlueprintImplementableEvent)
	void OnSetup();

	UFUNCTION(BlueprintImplementableEvent)
	void OnStart();

	UFUNCTION(BlueprintImplementableEvent)
	void OnUpdate();

	UFUNCTION(BlueprintImplementableEvent)
	void OnExpired();
	
	//The minigame's duration. If this is greater than zero, the minigame calls OnExpired when the time is up.
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float Duration = 0.f;

	FTimerHandle MinigameTimer;

	UPROPERTY(BlueprintReadOnly)
	float ElapsedTime = 0.f;

private:
	TArray<UMinigameBlock*> MinigameBlocks;
};
