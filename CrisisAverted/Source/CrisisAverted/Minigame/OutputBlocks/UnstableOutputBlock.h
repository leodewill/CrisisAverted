// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../MinigameBlock.h"
#include "../MinigameImportantTypes.h"
#include "UnstableOutputBlock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUnstableFloatEvent, float, Value, float, TargetValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUnstableStatusEvent, EUnstableMinigameStatus, Status, EUnstableMinigameStatus, OldStatus);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRISISAVERTED_API UUnstableOutputBlock : public UMinigameBlock
{
	GENERATED_BODY()

public:	
	UUnstableOutputBlock();

	UFUNCTION(BlueprintCallable)
	void Setup(float InPercent, float InThreshold);

	UFUNCTION(BlueprintCallable)
	void SetPercent(float NewPercent);

	UFUNCTION(BlueprintCallable)
	void SetTargetPercent(float NewPercent);

	UFUNCTION(BlueprintPure)
	float GetPercent() const { return Percent; }

	UFUNCTION(BlueprintPure)
	float GetTargetPercent() const { return TargetPercent; }

	UPROPERTY(BlueprintAssignable)
	FUnstableFloatEvent OnValueChanged;

	UPROPERTY(BlueprintAssignable)
	FUnstableStatusEvent OnStatusChanged;

	UPROPERTY(BlueprintAssignable)
	FMinigameFloatEvent OnTargetChanged;

protected:
	void Process();

	UPROPERTY(EditDefaultsOnly)
	float TargetPercent;

	UPROPERTY(EditDefaultsOnly)
	float Tolerance;

private:
	float Percent;

	EUnstableMinigameStatus Status;
};
