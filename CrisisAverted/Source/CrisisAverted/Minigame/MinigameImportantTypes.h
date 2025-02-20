#pragma once

#include "CoreMinimal.h"
#include "MinigameImportantTypes.generated.h"

UENUM(BlueprintType)
enum class EUnstableMinigameStatus : uint8
{
    Low UMETA(DisplayName = "Low"),
    Good UMETA(DisplayName = "Good"),
    High UMETA(DisplayName = "High")
};