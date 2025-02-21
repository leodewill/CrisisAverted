// Fill out your copyright notice in the Description page of Project Settings.


#include "ReactorControlComponent.h"

// Sets default values for this component's properties
UReactorControlComponent::UReactorControlComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
}

void UReactorControlComponent::InitializeComponent()
{
	if (InteractionComponent = GetOwner()->GetComponentByClass<UInputInteractionComponent>(); IsValid(InteractionComponent))
	{
		InteractionComponent->OnBindActions.AddDynamic(this, &UReactorControlComponent::BindActions);
	}
}

void UReactorControlComponent::RequestUpdate()
{
	if (!UpdateTimer.IsValid())
	{
		GetWorld()->GetTimerManager().SetTimer(UpdateTimer, this, &UReactorControlComponent::Update, REACTOR_UPDATE_FREQ, true);
	}
}

void UReactorControlComponent::StopUpdate()
{
	if (UpdateTimer.IsValid())
	{
		GetWorld()->GetTimerManager().ClearTimer(UpdateTimer);
	}
}

