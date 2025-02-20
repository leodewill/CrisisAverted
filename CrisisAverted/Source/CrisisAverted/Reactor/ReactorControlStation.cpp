// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorControlStation.h"
#include "CrisisAverted/Progression/ProgressionSubsystem.h"
#include "CrisisAverted/Minigame/ReactorMinigame.h"

// Sets default values
AReactorControlStation::AReactorControlStation()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	MinigameComponent = CreateDefaultSubobject<UMinigameComponent>(TEXT("MinigameComponent"));
	InteractionComponent = CreateDefaultSubobject<UInputInteractionComponent>(TEXT("Interaction"));
}

void AReactorControlStation::Interact(APawn* Pawn)
{
	InteractionComponent->Interact(Pawn);
}