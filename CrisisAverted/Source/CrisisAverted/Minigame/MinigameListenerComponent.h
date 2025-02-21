// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MinigameImportantTypes.h"
#include "GameplayTagContainer.h"
#include "MinigameListenerComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinigameListenerEvent, AMinigame*, Minigame);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinigameEndListenerEvent, EMinigameEndReason, Reason);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRISISAVERTED_API UMinigameListenerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMinigameListenerComponent();

	UPROPERTY(BlueprintAssignable)
	FMinigameListenerEvent OnEnterMinigame;

	UPROPERTY(BlueprintAssignable)
	FMinigameEndListenerEvent OnExitMinigame;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	FGameplayTag MinigameTag;

private:
	UFUNCTION()
	void OnAnyMinigameStarted(AMinigame* Minigame);
	
	UFUNCTION()
	void OnMinigameEnded(EMinigameEndReason Reason);
};
