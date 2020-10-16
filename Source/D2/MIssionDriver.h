// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "StructandEnum.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "MIssionDriver.generated.h"

UCLASS()
class D2_API AMIssionDriver : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AMIssionDriver();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    UPROPERTY( EditAnywhere)
    UDataTable* MissionScriptTable;

    UPROPERTY( EditAnywhere)
    TArray<FMissionData> MissionData;

    UPROPERTY(EditAnywhere)
    int32 currentMissionEventIndex;

    UFUNCTION(BlueprintCallable,CallInEditor)
    void LoadMissionScript();

    UFUNCTION(BlueprintCallable)
    void ExecuteNextMissionEvent();
};
