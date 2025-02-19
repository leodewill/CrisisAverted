// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorMinigame.h"

AReactorMinigame::AReactorMinigame()
{
	PrimaryActorTick.bCanEverTick = false;
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
