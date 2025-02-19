// Fill out your copyright notice in the Description page of Project Settings.


#include "Minigame.h"

AMinigame::AMinigame()
{
	PrimaryActorTick.bCanEverTick = false;
	bShouldUpdate = true;

	ElapsedTime = 0.f;
}

void AMinigame::StartMinigame()
{
	if (bShouldUpdate)
	{
		GetWorld()->GetTimerManager().SetTimer(MinigameTimer, this, &AMinigame::UpdateMinigame, MINIGAME_UPDATE_FREQ, true);
	}

	ElapsedTime = 0.f;
	Start();
}

void AMinigame::UpdateMinigame()
{
	ElapsedTime += MINIGAME_UPDATE_FREQ;
	Update();
}
