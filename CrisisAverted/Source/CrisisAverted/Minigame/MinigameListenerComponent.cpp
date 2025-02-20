// Fill out your copyright notice in the Description page of Project Settings.


#include "MinigameListenerComponent.h"
#include "CrisisAverted/Progression/ProgressionSubsystem.h"

// Sets default values for this component's properties
UMinigameListenerComponent::UMinigameListenerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


void UMinigameListenerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (UProgressionSubsystem* ProgressionSubsystem = GetWorld()->GetGameInstance()->GetSubsystem<UProgressionSubsystem>(); IsValid(ProgressionSubsystem))
	{
		if (AMinigame* ReactorMinigame = ProgressionSubsystem->GetActiveMinigameWithTag(MinigameTag); IsValid(ReactorMinigame))
		{
			OnEnterMinigame.Broadcast(ReactorMinigame);
		}
		else
		{
			ProgressionSubsystem->OnStartMinigame.AddUniqueDynamic(this, &UMinigameListenerComponent::OnAnyMinigameStarted);
		}
	}
}

void UMinigameListenerComponent::OnAnyMinigameStarted(AMinigame* Minigame)
{
	if (IsValid(Minigame) && Minigame->MinigameTag.MatchesTag(MinigameTag))
	{
		OnEnterMinigame.Broadcast(Minigame);
	}
}