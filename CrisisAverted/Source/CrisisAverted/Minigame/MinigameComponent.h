// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CrisisAverted/Progression/ProgressionImportantTypes.h"
#include "MinigameComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMinigameListenerEvent, AMinigame*, Minigame);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRISISAVERTED_API UMinigameComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UMinigameComponent();

	UPROPERTY(BlueprintAssignable)
	FMinigameListenerEvent OnEnterMinigame;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	EMinigameType MinigameID;

private:
	UFUNCTION()
	void OnAnyMinigameStarted(AMinigame* Minigame);
		
};
