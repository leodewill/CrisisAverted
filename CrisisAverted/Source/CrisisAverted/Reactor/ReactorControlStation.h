// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "CrisisAverted/Interaction/Interactable.h"
#include "CrisisAverted/Minigame/MinigameComponent.h"
#include "CrisisAverted/Interaction/InputInteractionComponent.h"
#include "Camera/CameraComponent.h"
#include "ReactorControlStation.generated.h"

UCLASS()
class CRISISAVERTED_API AReactorControlStation : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReactorControlStation();

	virtual void Interact(APawn* Pawn) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UMinigameComponent* MinigameComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UInputInteractionComponent* InteractionComponent;
};
