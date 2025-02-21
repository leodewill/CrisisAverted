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
	void StartTimer();

	UFUNCTION(BlueprintCallable)
	void PauseTimer() { bIsRunning = false; }

	UFUNCTION(BlueprintCallable)
	void ResumeTimer() { bIsRunning = true; }

	virtual void Update(float DeltaSeconds) override;

	UPROPERTY(BlueprintAssignable)
	FMinigameClockEvent OnExpired;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Settings")
	float BaseDelay;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float DelayVariation;

private:
	float Delay;

	float ElapsedTime;

	bool bIsRunning;
};
