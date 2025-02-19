// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "CrisisAvertedPlayerController.generated.h"

class UInputMappingContext;

/**
 *
 */
UCLASS()
class CRISISAVERTED_API ACrisisAvertedPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void SetCustomInput(UInputMappingContext* CustomInput);

	void ResetInput();

protected:
	virtual void BeginPlay() override;

	void SetInputMapping(UInputMappingContext* InInputMapping);

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* DefaultInputMapping;

	UEnhancedInputLocalPlayerSubsystem* EnhancedInput;

private:
	UInputMappingContext* InputMapping = nullptr;
};
