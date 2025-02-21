// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../MinigameBlock.h"
#include "../MinigameImportantTypes.h"
#include "UnstableOutputBlock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FUnstableFloatEvent, float, Value, EUnstableMinigameStatus, Status);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRISISAVERTED_API UUnstableOutputBlock : public UMinigameBlock
{
	GENERATED_BODY()

public:	
	UUnstableOutputBlock();

	UFUNCTION(BlueprintCallable)
	virtual void ResetPercent(float InValue);

	virtual void Start() override;

	virtual void Update(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	void SetPercent(float NewPercent);

	UFUNCTION(BlueprintPure)
	float GetPercent() const { return Percent; }

	UPROPERTY(BlueprintAssignable)
	FUnstableFloatEvent OnChanged;

	UPROPERTY(BlueprintAssignable)
	FMinigameBlockEvent OnFailed;

protected:
	void Fail();

	float Percent;

	UPROPERTY(EditDefaultsOnly)
	float TargetPercent;

	UPROPERTY(EditDefaultsOnly)
	float Tolerance;

	UPROPERTY(EditDefaultsOnly)
	float GracePeriod;

	EUnstableMinigameStatus Status;

	float UnstableTime;

	bool bFailed;
};
