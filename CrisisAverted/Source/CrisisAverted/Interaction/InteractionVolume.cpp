// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionVolume.h"
#include "CrisisAverted/CrisisAvertedCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

void AInteractionVolume::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	OnActorBeginOverlap.AddUniqueDynamic(this, &AInteractionVolume::OnActorEnter);
	OnActorEndOverlap.AddUniqueDynamic(this, &AInteractionVolume::OnActorLeave);
}

void AInteractionVolume::OnActorEnter(AActor* OverlappedActor, AActor* OtherActor)
{
	if (ACrisisAvertedCharacter* PlayerCharacter = Cast<ACrisisAvertedCharacter>(OtherActor); IsValid(PlayerCharacter))
	{
		PlayerCharacter->InteractionTarget = Target;
	}
}

void AInteractionVolume::OnActorLeave(AActor* OverlappedActor, AActor* OtherActor)
{
	if (ACrisisAvertedCharacter* PlayerCharacter = Cast<ACrisisAvertedCharacter>(OtherActor); IsValid(PlayerCharacter) && PlayerCharacter->InteractionTarget != Target)
	{
		PlayerCharacter->InteractionTarget = nullptr;
	}
}
