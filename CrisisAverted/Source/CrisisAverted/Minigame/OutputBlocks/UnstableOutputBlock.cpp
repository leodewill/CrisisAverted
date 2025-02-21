// Fill out your copyright notice in the Description page of Project Settings.


#include "UnstableOutputBlock.h"

UUnstableOutputBlock::UUnstableOutputBlock()
{
	PrimaryComponentTick.bCanEverTick = false;
	TargetPercent = 0.5;
	Tolerance = 0.1;
	GracePeriod = 10.f;

	Status = EUnstableMinigameStatus::Good;
	Percent = TargetPercent;
	UnstableTime = 0.f;
	bFailed = false;
}

void UUnstableOutputBlock::ResetPercent(float InValue)
{
	TargetPercent = InValue;
	Percent = TargetPercent;
	Status = EUnstableMinigameStatus::Good;
}

void UUnstableOutputBlock::Start()
{
	UnstableTime = 0.f;
	bFailed = false;
}

void UUnstableOutputBlock::Update(float DeltaSeconds)
{
	if (!bFailed && Status != EUnstableMinigameStatus::Good)
	{
		UnstableTime += DeltaSeconds;
		if (UnstableTime >= GracePeriod)
		{
			Fail();
		}
	}
}

void UUnstableOutputBlock::SetPercent(float NewPercent)
{
	Percent = FMath::Clamp(NewPercent, 0.f, 1.f);

	EUnstableMinigameStatus OldStatus = Status;
	Status = (Percent < TargetPercent - Tolerance) ? EUnstableMinigameStatus::Low : ((Percent > TargetPercent + Tolerance) ? EUnstableMinigameStatus::High : EUnstableMinigameStatus::Good);

	if (Status != EUnstableMinigameStatus::Good && Status != OldStatus)
	{
		UnstableTime = 0.f;
	}

	OnChanged.Broadcast(Percent, Status);
}

void UUnstableOutputBlock::Fail()
{
	bFailed = true;
	OnFailed.Broadcast(this);
}

