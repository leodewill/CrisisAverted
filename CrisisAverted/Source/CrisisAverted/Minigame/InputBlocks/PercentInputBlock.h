// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "../MinigameBlock.h"
#include "PercentInputBlock.generated.h"

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRISISAVERTED_API UPercentInputBlock : public UMinigameBlock
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPercentInputBlock();

	virtual void Start() override;

	UFUNCTION(BlueprintCallable)
	virtual void SetPercent(float NewPercent);

	UFUNCTION(BlueprintPure)
	float GetPercent() const { return Percent; }

	UPROPERTY(BlueprintAssignable)
	FMinigameFloatEvent OnChanged;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0.0", ClampMax = "1.0", UIMin = "0.0", UIMax = "1.0"))
	float StartPercent;

	float Percent;
};
