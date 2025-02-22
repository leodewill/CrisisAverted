// Fill out your copyright notice in the Description page of Project Settings.


#include "UnstableOutputBlock.h"

UUnstableOutputBlock::UUnstableOutputBlock()
{
	PrimaryComponentTick.bCanEverTick = false;
	TargetPercent = 0.5;
	Tolerance = 0.1;

	Status = EUnstableMinigameStatus::Good;
	Percent = TargetPercent;
}

void UUnstableOutputBlock::Setup(float InPercent, float InThreshold)
{
	TargetPercent = InPercent;
	Percent = TargetPercent;
	Status = EUnstableMinigameStatus::Good;
}

void UUnstableOutputBlock::SetPercent(float NewPercent)
{
	Percent = FMath::Clamp(NewPercent, 0.f, 1.f);
	OnValueChanged.Broadcast(Percent, TargetPercent);
	Process();
}

void UUnstableOutputBlock::SetTargetPercent(float NewPercent)
{
	TargetPercent = FMath::Clamp(NewPercent, 0.f, 1.f);
	OnTargetChanged.Broadcast(TargetPercent);
	Process();
}

void UUnstableOutputBlock::Process()
{
	EUnstableMinigameStatus OldStatus = Status;
	Status = (Percent < TargetPercent - Tolerance) ? EUnstableMinigameStatus::Low : ((Percent > TargetPercent + Tolerance) ? EUnstableMinigameStatus::High : EUnstableMinigameStatus::Good);

	if (Status != OldStatus)
	{
		OnStatusChanged.Broadcast(Status, OldStatus);
	}
}

