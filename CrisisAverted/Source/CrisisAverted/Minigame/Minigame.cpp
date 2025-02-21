// Fill out your copyright notice in the Description page of Project Settings.


#include "Minigame.h"

AMinigame::AMinigame()
{
	PrimaryActorTick.bCanEverTick = false;
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
	OnSetup();
	for (UMinigameBlock* Block : MinigameBlocks)
	{
		Block->Start();
	}

	GetWorld()->GetTimerManager().SetTimer(MinigameTimer, this, &AMinigame::UpdateMinigame, MINIGAME_UPDATE_FREQ, true);
	OnStart();
}

void AMinigame::UpdateMinigame()
{
	for (UMinigameBlock* Block : MinigameBlocks)
	{
		Block->Update(MINIGAME_UPDATE_FREQ);
	}

	OnUpdate();
}

void AMinigame::EndMinigame(EMinigameEndReason Reason)
{
	GetWorld()->GetTimerManager().ClearTimer(MinigameTimer);
	OnEnd(Reason);
	OnMinigameEnd.Broadcast(Reason);
}
