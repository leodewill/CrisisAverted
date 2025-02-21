// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReactorControlComponent.h"
#include "ReactorValveComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FValveEvent);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FValveUpdateEvent, float, Speed, float, DeltaSeconds);

/**
 * 
 */
UCLASS( ClassGroup = (Reactor), meta = (BlueprintSpawnableComponent) )
class CRISISAVERTED_API UReactorValveComponent : public UReactorControlComponent
{
	GENERATED_BODY()

public:
	UReactorValveComponent();

	UPROPERTY(BlueprintAssignable)
	FValveEvent OnOpen;

	UPROPERTY(BlueprintAssignable)
	FValveUpdateEvent OnGape;

	UPROPERTY(BlueprintAssignable)
	FValveEvent OnClose;
	
protected:
	virtual void BindActions(UEnhancedInputComponent* InputComponent) override;

	virtual void Update() override;

	/** Valve Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* ValveAction;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	float ValveSpeed;

private:
	/** Called for valve input */
	void OpenValve(const FInputActionValue& Value);

	/** Called for valve input */
	void CloseValve(const FInputActionValue& Value);
};
