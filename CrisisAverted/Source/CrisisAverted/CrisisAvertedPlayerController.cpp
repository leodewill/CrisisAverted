// Copyright Epic Games, Inc. All Rights Reserved.


#include "CrisisAvertedPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"

void ACrisisAvertedPlayerController::SetCustomInput(UInputMappingContext* CustomInput)
{
	SetInputMapping(CustomInput);
}

void ACrisisAvertedPlayerController::ResetInput()
{
	SetInputMapping(DefaultInputMapping);
}

void ACrisisAvertedPlayerController::BeginPlay()
{
	Super::BeginPlay();

	EnhancedInput = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	ResetInput();
}

void ACrisisAvertedPlayerController::SetInputMapping(UInputMappingContext* InInputMapping)
{
	if (IsValid(EnhancedInput) && !EnhancedInput->HasMappingContext(InInputMapping))
	{
		EnhancedInput->RemoveMappingContext(InputMapping);
		EnhancedInput->AddMappingContext(InInputMapping, 0);
		InputMapping = InInputMapping;
	}
}