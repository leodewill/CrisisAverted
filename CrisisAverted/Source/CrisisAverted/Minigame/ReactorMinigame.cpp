// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorMinigame.h"

AReactorMinigame::AReactorMinigame()
{
	PrimaryActorTick.bCanEverTick = false;

	MinigameID = EMinigameType::ReactorBase;
}

void AReactorMinigame::Start()
{
	
}

void AReactorMinigame::Update()
{
	if (ElapsedTime >= Duration)
	{
		WinMinigame();
	}
}
