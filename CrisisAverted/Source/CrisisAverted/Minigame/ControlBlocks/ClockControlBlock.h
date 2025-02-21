// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../MinigameBlock.h"
#include "ClockControlBlock.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FMinigameClockEvent);

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class CRISISAVERTED_API UClockControlBlock : public UMinigameBlock
{
	GENERATED_BODY()
	
public:
	UClockControlBlock();

	UFUNCTION(BlueprintCallable)
	void Setup(float InDelay, float InVariation, float InSpeed = 1.f, float InRewindSpeed = 1.f);

	UFUNCTION(BlueprintCallable)
	void StartTimer();

	UFUNCTION(BlueprintCallable)
	void PauseTimer() { bIsRunning = false; }

	UFUNCTION(BlueprintCallable)
	void ResumeTimer();

	UFUNCTION(BlueprintCallable)
	void ReverseTimer();

	virtual void Update(float DeltaSeconds) override;

	UPROPERTY(BlueprintAssignable)
	FMinigameBarEvent OnTimeChanged;

	UPROPERTY(BlueprintAssignable)
	FMinigameClockEvent OnExpired;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	float BaseDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float DelayVariation;

private:
	void CalculateDelay();

	float Delay;

	float ElapsedTime;

	float Speed;

	float ReverseSpeed;

	bool bIsRunning;

	bool bIsReversed;
};
