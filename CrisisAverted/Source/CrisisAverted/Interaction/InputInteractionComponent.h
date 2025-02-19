// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "CrisisAverted/CrisisAvertedPlayerController.h"
#include "InputInteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInputInteractionEvent, APawn*, Pawn);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRISISAVERTED_API UInputInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInputInteractionComponent();

	void Interact(APawn* Pawn);


	UPROPERTY(BlueprintAssignable)
	FInputInteractionEvent OnInteract;

protected:
	void BindActions(UEnhancedInputComponent* InputComponent);

	UFUNCTION()
	void Leave();

	ACrisisAvertedPlayerController* PlayerController;

	bool bIsBound = false;

	/** Input Mapping Context to be used for player input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* InputMapping;

	/** Leave Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LeaveAction;

};
