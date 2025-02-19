// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ReactorControlComponent.h"
#include "ReactorSliderComponent.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSliderStateEvent, float, InputValue, float, OutputValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FSliderPercentChangedEvent, float, NewValue, float, OldValue);

UCLASS( ClassGroup = (Reactor), meta = (BlueprintSpawnableComponent) )
class CRISISAVERTED_API UReactorSliderComponent : public UReactorControlComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable)
	FSliderStateEvent OnReset;

	UPROPERTY(BlueprintAssignable)
	FSliderPercentChangedEvent OnInputChanged;

	UPROPERTY(BlueprintAssignable)
	FSliderPercentChangedEvent OnOutputChanged;
	
protected:
	virtual void Reset() override;

	virtual void BindActions(UEnhancedInputComponent* InputComponent) override;

	virtual void Update() override;

	/** Slider Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* SliderAction;

	UPROPERTY(EditDefaultsOnly)
	float InputSpeed;

	float InputPercent;

	UPROPERTY(EditDefaultsOnly)
	float OutputSpeed;

	float OutputPercent;

private:
	/** Called for slider input */
	void MoveSlider(const FInputActionValue& Value);

	/** Called for slider input */
	void StopSlider(const FInputActionValue& Value);

	float InputDirection;
};
