// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Engine/DataTable.h"
#include "Sound/SoundWave.h"
#include "UObject/NoExportTypes.h"
#include "StructandEnum.generated.h"

/**
 * 
 */
UCLASS()
class D2_API UStructandEnum : public UObject
{
    GENERATED_BODY()
};


UENUM(BlueprintType)
enum class FMissionEventType : uint8
{
    GoTo,
    Dialogue,
    Kill,
    Interact,
    End,
    Boss
};

UENUM(BlueprintType)
enum class FMissionReturnType: uint8
{
    Immediate,
    AfterEvent,
    AfterDialogue
};

USTRUCT(BlueprintType)
struct FMissionData:public FTableRowBase
{
    GENERATED_USTRUCT_BODY()
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Event")
    FMissionEventType MissionEventType;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Event")
    FMissionReturnType MissionReturnType;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mission Event")
    TSoftObjectPtr<AActor> MissionActor;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Dialouge")
    TSoftObjectPtr<USoundWave> AudioFileName;
    
};