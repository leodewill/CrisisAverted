// Fill out your copyright notice in the Description page of Project Settings.


#include "PercentInputBlock.h"

UPercentInputBlock::UPercentInputBlock()
{
	PrimaryComponentTick.bCanEverTick = false;
	Percent = 0.f;
}

void UPercentInputBlock::Setup(float InValue)
{
	Percent = InValue;
}

void UPercentInputBlock::SetPercent(float NewPercent)
{
	Percent = FMath::Clamp(NewPercent, 0.f, 1.f);
	OnChanged.Broadcast(Percent);
}

