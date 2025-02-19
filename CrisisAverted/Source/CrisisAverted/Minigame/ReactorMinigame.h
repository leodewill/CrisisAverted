// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Minigame.h"
#include "ReactorMinigame.generated.h"

/**
 * 
 */
UCLASS()
class CRISISAVERTED_API AReactorMinigame : public AMinigame
{
	GENERATED_BODY()
	
public:
	AReactorMinigame();

protected:
	virtual void Start() override;

	virtual void Update() override;

	UPROPERTY(EditDefaultsOnly)
	float Duration = 10.f;
};
