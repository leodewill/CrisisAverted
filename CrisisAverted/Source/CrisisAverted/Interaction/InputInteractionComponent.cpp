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
		PlayerController->SetCustomInput(InputMapping);
		if (!bIsBound)
		{
			BindActions(Cast<UEnhancedInputComponent>(PlayerController->InputComponent));
		}

		OnInteract.Broadcast(Pawn);
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
	}
}

