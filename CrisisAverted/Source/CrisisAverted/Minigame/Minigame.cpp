// Fill out your copyright notice in the Description page of Project Settings.


#include "Minigame.h"

AMinigame::AMinigame()
{
	PrimaryActorTick.bCanEverTick = false;

	ElapsedTime = 0.f;
}

void AMinigame::RegisterBlock(UMinigameBlock* Block)
{
	if (IsValid(Block))
	{
		MinigameBlocks.Add(Block);
	}
}

void AMinigame::StartMinigame()
{
	for (UMinigameBlock* Block : MinigameBlocks)
	{
		Block->Start();
	}

	GetWorld()->GetTimerManager().SetTimer(MinigameTimer, this, &AMinigame::UpdateMinigame, MINIGAME_UPDATE_FREQ, true);
	ElapsedTime = 0.f;
	OnStart();
}

void AMinigame::UpdateMinigame()
{
	for (UMinigameBlock* Block : MinigameBlocks)
	{
		Block->Update(MINIGAME_UPDATE_FREQ);
	}

	ElapsedTime += MINIGAME_UPDATE_FREQ;
	OnUpdate();

	if (Duration > 0.f && ElapsedTime >= Duration)
	{
		GetWorld()->GetTimerManager().ClearTimer(MinigameTimer);
		OnExpired();
	}
}
