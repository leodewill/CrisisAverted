// Fill out your copyright notice in the Description page of Project Settings.


#include "ClockControlBlock.h"

UClockControlBlock::UClockControlBlock()
{
	BaseDelay = 5.f;
	DelayVariation = 0.f;

	Delay = 5.f;
	ElapsedTime = 0.f;
	bIsRunning = false;
}

void UClockControlBlock::StartTimer()
{
	ElapsedTime = 0.f;
	Delay = BaseDelay + DelayVariation * FMath::RandRange(-1.f, 1.f);
	bIsRunning = true;
}

void UClockControlBlock::Update(float DeltaSeconds)
{
	if (bIsRunning)
	{
		ElapsedTime += DeltaSeconds;
		if (ElapsedTime > Delay)
		{
			bIsRunning = false;
			ElapsedTime = Delay;
			OnTimeChanged.Broadcast(ElapsedTime, Delay);
			OnExpired.Broadcast();
		}
		else
		{
			OnTimeChanged.Broadcast(ElapsedTime, Delay);
		}
	}
}
