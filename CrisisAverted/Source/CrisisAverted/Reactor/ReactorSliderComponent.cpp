// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorSliderComponent.h"

void UReactorSliderComponent::SetPercent(float InValue)
{
	InputDirection = InValue;
	InputPercent = InValue;
	OutputPercent = InValue;
	OnReset.Broadcast(InputPercent, OutputPercent);
}

void UReactorSliderComponent::BindActions(UEnhancedInputComponent* InputComponent)
{
	InputComponent->BindAction(SliderAction, ETriggerEvent::Triggered, this, &UReactorSliderComponent::MoveSlider);
	InputComponent->BindAction(SliderAction, ETriggerEvent::Completed, this, &UReactorSliderComponent::StopSlider);
}

void UReactorSliderComponent::Update()
{
	float OldPercent = InputPercent;
	if (!FMath::IsNearlyZero(InputDirection))
	{
		InputPercent += InputDirection * InputSpeed * REACTOR_UPDATE_FREQ;
		InputPercent = FMath::Clamp(InputPercent, 0.f, 1.f);
		OnInputChanged.Broadcast(InputPercent, OldPercent);
	}

	OldPercent = OutputPercent;
	if (InputPercent > OutputPercent)
	{
		OutputPercent += OutputSpeed * REACTOR_UPDATE_FREQ;
		OutputPercent = FMath::Clamp(OutputPercent, 0.f, InputPercent);
	}
	else
	{
		OutputPercent -= OutputSpeed * REACTOR_UPDATE_FREQ;
		OutputPercent = FMath::Clamp(OutputPercent, InputPercent, 1.f);
	}

	OnOutputChanged.Broadcast(OutputPercent, OldPercent);
	if (FMath::IsNearlyEqual(InputPercent, OutputPercent))
	{
		StopUpdate();
	}
}

void UReactorSliderComponent::MoveSlider(const FInputActionValue& Value)
{
	// input is a float
	InputDirection = Value.Get<float>();
	RequestUpdate();
}

void UReactorSliderComponent::StopSlider(const FInputActionValue& Value)
{
	InputDirection = 0.f;
}
