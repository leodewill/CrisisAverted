// Fill out your copyright notice in the Description page of Project Settings.


#include "UnstableOutputBlock.h"

UUnstableOutputBlock::UUnstableOutputBlock()
{
	PrimaryComponentTick.bCanEverTick = false;
	TargetPercent = 0.5;
	Tolerance = 0.1;
	RecoverySpeed = 1.f;
	FailThreshold = 10.f;

	Status = EUnstableMinigameStatus::Good;
	Percent = TargetPercent;
	UnstableTime = 0.f;
	bFailed = false;
}

void UUnstableOutputBlock::Setup(float InPercent, float InThreshold)
{
	TargetPercent = InPercent;
	FailThreshold = InThreshold;
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
	if (bFailed)
	{
		return;
	}

	if (Status != EUnstableMinigameStatus::Good)
	{
		UnstableTime += DeltaSeconds;
		if (UnstableTime >= FailThreshold)
		{
			UnstableTime = FailThreshold;
			OnTimeChanged.Broadcast(UnstableTime, FailThreshold);
			Fail();
		}
		else
		{
			OnTimeChanged.Broadcast(UnstableTime, FailThreshold);
		}
	}
	else if (UnstableTime > 0.f)
	{
		UnstableTime -= DeltaSeconds * RecoverySpeed;
		UnstableTime = FMath::Max(UnstableTime, 0.f);
		OnTimeChanged.Broadcast(UnstableTime, FailThreshold);
	}
}

void UUnstableOutputBlock::SetPercent(float NewPercent)
{
	Percent = FMath::Clamp(NewPercent, 0.f, 1.f);
	Process();
}

void UUnstableOutputBlock::SetTargetPercent(float NewPercent)
{
	TargetPercent = FMath::Clamp(NewPercent, 0.f, 1.f);
	Process();
}

void UUnstableOutputBlock::Process()
{
	EUnstableMinigameStatus OldStatus = Status;
	Status = (Percent < TargetPercent - Tolerance) ? EUnstableMinigameStatus::Low : ((Percent > TargetPercent + Tolerance) ? EUnstableMinigameStatus::High : EUnstableMinigameStatus::Good);
	OnChanged.Broadcast(Percent, Status, TargetPercent);
}

void UUnstableOutputBlock::Fail()
{
	bFailed = true;
	OnFailed.Broadcast(this);
}

