#pragma once

#include "CoreMinimal.h"
#include "MinigameImportantTypes.generated.h"

UENUM(BlueprintType)
enum class EMinigameEndReason : uint8
{
    Cancel UMETA(DisplayName = "Cancel"),
    Win UMETA(DisplayName = "Win"),
    Lose UMETA(DisplayName = "Lose")
};

UENUM(BlueprintType)
enum class EUnstableMinigameStatus : uint8
{
    Low UMETA(DisplayName = "Low"),
    Good UMETA(DisplayName = "Good"),
    High UMETA(DisplayName = "High")
};