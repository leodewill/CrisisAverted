// Fill out your copyright notice in the Description page of Project Settings.


#include "PercentInputBlock.h"

UPercentInputBlock::UPercentInputBlock()
{
	PrimaryComponentTick.bCanEverTick = false;
	StartPercent = 0.f;
	Percent = 0.f;
}

void UPercentInputBlock::Start()
{
	Percent = StartPercent;
}

void UPercentInputBlock::SetPercent(float NewPercent)
{
	Percent = FMath::Clamp(NewPercent, 0.f, 1.f);
	OnChanged.Broadcast(Percent);
}

