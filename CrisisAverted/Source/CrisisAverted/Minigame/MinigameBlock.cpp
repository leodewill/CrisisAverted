// Fill out your copyright notice in the Description page of Project Settings.


#include "MinigameBlock.h"
#include "Minigame.h"

// Sets default values for this component's properties
UMinigameBlock::UMinigameBlock()
{
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;
}

void UMinigameBlock::InitializeComponent()
{
	Super::InitializeComponent();

	AMinigame* Minigame = Cast<AMinigame>(GetOwner());
	Minigame->RegisterBlock(this);
}

