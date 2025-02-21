// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorValveComponent.h"

UReactorValveComponent::UReactorValveComponent()
{
	ValveSpeed = 0.1f;
}

void UReactorValveComponent::BindActions(UEnhancedInputComponent* InputComponent)
{
	InputComponent->BindAction(ValveAction, ETriggerEvent::Triggered, this, &UReactorValveComponent::OpenValve);
	InputComponent->BindAction(ValveAction, ETriggerEvent::Completed, this, &UReactorValveComponent::CloseValve);
}

void UReactorValveComponent::Update()
{
	OnGape.Broadcast(ValveSpeed, REACTOR_UPDATE_FREQ);
}

void UReactorValveComponent::OpenValve(const FInputActionValue& Value)
{
	RequestUpdate();
	OnOpen.Broadcast();
}

void UReactorValveComponent::CloseValve(const FInputActionValue& Value)
{
	StopUpdate();
	OnClose.Broadcast();
}
