// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "InteractionVolume.generated.h"

/**
 * 
 */
UCLASS()
class CRISISAVERTED_API AInteractionVolume : public AVolume
{
	GENERATED_BODY()
	
public:
	virtual void PostInitializeComponents() override;

protected:
	UFUNCTION()
	void OnActorEnter(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnActorLeave(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditInstanceOnly)
	AActor* Target;
};
