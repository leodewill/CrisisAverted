// Fill out your copyright notice in the Description page of Project Settings.


#include "InputInteractionComponent.h"
#include "CrisisAverted/CrisisAvertedPlayerController.h"
#include "EnhancedInputComponent.h"

UInputInteractionComponent::UInputInteractionComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bIsBound = false;
}

void UInputInteractionComponent::Interact(APawn* Pawn)
{
	if (!IsValid(Pawn))
	{
		return;
	}

	if (PlayerController = Cast<ACrisisAvertedPlayerController>(Pawn->GetController()); IsValid(PlayerController))
	{
		PlayerPawn = Pawn;
		PlayerController->SetCustomInput(InputMapping);
		if (!bIsBound)
		{
			BindActions(Cast<UEnhancedInputComponent>(PlayerController->InputComponent));
		}

		OnInteract.Broadcast(PlayerPawn, PlayerController);
	}
}

void UInputInteractionComponent::BindActions(UEnhancedInputComponent* InputComponent)
{
	if (IsValid(InputComponent))
	{
		InputComponent->BindAction(LeaveAction, ETriggerEvent::Triggered, this, &UInputInteractionComponent::Leave);
		bIsBound = true;
	}
}

void UInputInteractionComponent::Leave()
{
	if (IsValid(PlayerController))
	{
		PlayerController->ResetInput();
		OnLeave.Broadcast(PlayerPawn, PlayerController);
	}
}

