// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../MinigameBlock.h"
#include "../MinigameImportantTypes.h"
#include "UnstableOutputBlock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FUnstableFloatEvent, float, Value, EUnstableMinigameStatus, Status, float, TargetValue);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRISISAVERTED_API UUnstableOutputBlock : public UMinigameBlock
{
	GENERATED_BODY()

public:	
	UUnstableOutputBlock();

	UFUNCTION(BlueprintCallable)
	void Setup(float InPercent, float InThreshold);

	virtual void Start() override;

	virtual void Update(float DeltaSeconds) override;

	UFUNCTION(BlueprintCallable)
	void SetPercent(float NewPercent);

	UFUNCTION(BlueprintCallable)
	void SetTargetPercent(float NewPercent);

	UFUNCTION(BlueprintPure)
	float GetPercent() const { return Percent; }

	UFUNCTION(BlueprintPure)
	float GetTargetPercent() const { return TargetPercent; }

	UPROPERTY(BlueprintAssignable)
	FUnstableFloatEvent OnChanged;

	UPROPERTY(BlueprintAssignable)
	FUnstableFloatEvent OnTargetChanged;

	UPROPERTY(BlueprintAssignable)
	FMinigameBarEvent OnTimeChanged;

	UPROPERTY(BlueprintAssignable)
	FMinigameBlockEvent OnFailed;

protected:
	void Process();

	void Fail();

	UPROPERTY(EditDefaultsOnly)
	float TargetPercent;

	UPROPERTY(EditDefaultsOnly)
	float Tolerance;

	// The accumulated unstable time that the output takes to fail
	UPROPERTY(EditDefaultsOnly)
	float FailThreshold;

	// The proportional speed that the unstable time is reduced when the percent is within good range
	UPROPERTY(EditDefaultsOnly)
	float RecoverySpeed;

private:
	float Percent;

	EUnstableMinigameStatus Status;

	float UnstableTime;

	bool bFailed;
};
