// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


#include "StructandEnum.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "UObject/ObjectMacros.h"

#include "MIssionDriver.generated.h"

UCLASS()
class D2_API AMIssionDriver : public AActor
{
    GENERATED_BODY()

    
    UPROPERTY()
    FTimerHandle FTimerHandle;

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

    UPROPERTY( EditAnywhere, BlueprintReadWrite)
    TArray<FMissionData> MissionData;

    UPROPERTY(EditAnywhere,BlueprintReadWrite)
    int32 currentMissionEventIndex;

    UFUNCTION(BlueprintCallable,CallInEditor, Category= LoadScript)
    void LoadMissionScript();

    UFUNCTION(BlueprintCallable)
    void ExecuteNextMissionEvent();

    UFUNCTION(BlueprintImplementableEvent)
 void UpdateUI();


    void Delay();
    void GoTo();
    void Interact();
    void BeginMissionEvent();
};
