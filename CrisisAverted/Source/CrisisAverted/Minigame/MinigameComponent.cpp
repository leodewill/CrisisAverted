// Fill out your copyright notice in the Description page of Project Settings.


#include "MinigameComponent.h"
#include "CrisisAverted/Progression/ProgressionSubsystem.h"

// Sets default values for this component's properties
UMinigameComponent::UMinigameComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UMinigameComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UProgressionSubsystem>(); IsValid(ProgressionSubsystem))
	{
		if (AMinigame* ReactorMinigame = ProgressionSubsystem->GetActiveMinigameWithID(MinigameID); IsValid(ReactorMinigame))
		{
			OnEnterMinigame.Broadcast(ReactorMinigame);
		}
		else
		{
			ProgressionSubsystem->OnStartMinigame.AddUniqueDynamic(this, &UMinigameComponent::OnAnyMinigameStarted);
		}
	}
}

void UMinigameComponent::OnAnyMinigameStarted(AMinigame* Minigame)
{
	if (IsValid(Minigame) && Minigame->GetID() == MinigameID)
	{
		OnEnterMinigame.Broadcast(Minigame);
	}
}