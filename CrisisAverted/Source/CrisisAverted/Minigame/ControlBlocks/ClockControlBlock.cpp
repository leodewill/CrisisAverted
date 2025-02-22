// Fill out your copyright notice in the Description page of Project Settings.


#include "ClockControlBlock.h"

UClockControlBlock::UClockControlBlock()
{
	BaseDelay = 5.f;
	DelayVariation = 0.f;

	Delay = 5.f;
	ElapsedTime = 0.f;
	Speed = 1.f;
	bIsRunning = false;
	bIsReversed = false;
}

void UClockControlBlock::Setup(float InDelay, float InVariation, float InSpeed, float InRewindSpeed)
{
	BaseDelay = InDelay;
	DelayVariation = InVariation;
	Speed = InSpeed;
	ReverseSpeed = InRewindSpeed;
	CalculateDelay();
}

void UClockControlBlock::StartTimer()
{
	ElapsedTime = 0.f;
	CalculateDelay();
	bIsRunning = true;
	bIsReversed = false;
}

void UClockControlBlock::ResumeTimer()
{
	bIsReversed = false;
	bIsRunning = true;
}

void UClockControlBlock::ReverseTimer()
{
	bIsReversed = true;
	bIsRunning = true;
}

void UClockControlBlock::Update(float DeltaSeconds)
{
	if (bIsRunning)
	{
		if (!bIsReversed)
		{
			ElapsedTime += DeltaSeconds * Speed;
			ElapsedTime = FMath::Min(ElapsedTime, Delay);
			if (ElapsedTime >= Delay)
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
		else
		{
			ElapsedTime -= DeltaSeconds * ReverseSpeed;
			ElapsedTime = FMath::Max(ElapsedTime, 0.f);
			OnTimeChanged.Broadcast(ElapsedTime, Delay);
			if (FMath::IsNearlyZero(ElapsedTime))
			{
				PauseTimer();
			}
		}
	}
}

void UClockControlBlock::CalculateDelay()
{
	Delay = BaseDelay + DelayVariation * FMath::RandRange(-1.f, 1.f);
}
