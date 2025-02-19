// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CrisisAverted/Interaction/InputInteractionComponent.h"
#include "ReactorControlComponent.generated.h"

constexpr float REACTOR_UPDATE_FREQ = 0.1f;

UCLASS( ClassGroup=(Reactor) )
class CRISISAVERTED_API UReactorControlComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UReactorControlComponent();

	virtual void InitializeComponent() override;

protected:
	virtual void Reset() {}

	UFUNCTION()
	virtual void BindActions(UEnhancedInputComponent* InputComponent) {}

	UFUNCTION()
	virtual void Update() {}

	void RequestUpdate();

	void StopUpdate();

	UInputInteractionComponent* InteractionComponent = nullptr;

private:
	FTimerHandle UpdateTimer;
};
