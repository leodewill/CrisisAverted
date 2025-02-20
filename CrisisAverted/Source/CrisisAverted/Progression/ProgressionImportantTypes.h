#pragma once

#include "CoreMinimal.h"
#include "ProgressionImportantTypes.generated.h"

UENUM(BlueprintType)
enum class EMinigameType : uint8
{
    None UMETA(DisplayName = "None"),
    ReactorBase UMETA(DisplayName = "Reactor")
};