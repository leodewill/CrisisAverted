// Fill out your copyright notice in the Description page of Project Settings.


#include "ProgressionSubsystem.h"

UProgressionSubsystem::UProgressionSubsystem()
{
}

void UProgressionSubsystem::StartMinigame(TSubclassOf<AMinigame> MinigameClass)
{
	ActiveMinigame = GetWorld()->SpawnActor<AMinigame>(MinigameClass);
}
