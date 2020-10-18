// Fill out your copyright notice in the Description page of Project Settings.


#include "MIssionDriver.h"

#include "IMissionEvent.h"
#include "MissionActor.h"
#include "PatrollingGuard.h"
#include "TimerManager.h"


AMIssionDriver::AMIssionDriver()
{
    PrimaryActorTick.bCanEverTick = true;
    currentMissionEventIndex = -1;
}

// Called when the game starts or when spawned
void AMIssionDriver::BeginPlay()
{
    Super::BeginPlay();
    LoadMissionScript();
    ExecuteNextMissionEvent();
}

// Called every frame
void AMIssionDriver::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AMIssionDriver::LoadMissionScript()
{
    if (MissionScriptTable == nullptr) return;

    if (MissionData.IsValidIndex(0))
        MissionData.Empty();

    for (auto it : MissionScriptTable->GetRowMap())
    {
        FMissionData* missionData = (FMissionData*)(it.Value);
        MissionData.Add(*missionData);
    }
}

void AMIssionDriver::ExecuteNextMissionEvent()
{
    UE_LOG(LogTemp, Warning, TEXT("ExecuteNextMissionEvent"));
    currentMissionEventIndex++;
    if (MissionData.IsValidIndex(currentMissionEventIndex))
    {
        switch (MissionData[currentMissionEventIndex].MissionEventType)
        {
        case FMissionEventType::Boss:
            {
                BeginMissionEvent();
                break;
            }

        case FMissionEventType::Dialogue:
            {
                BeginMissionEvent();
                break;
            }

        case FMissionEventType::End:
            UE_LOG(LogTemp, Warning, TEXT("End Mission"));
            break;
        case FMissionEventType::Interact:
            {
                BeginMissionEvent();
                break;
            }

        case FMissionEventType::GoTo:
            {
                BeginMissionEvent();
                break;
            }
        case FMissionEventType::Kill:
            {
                BeginMissionEvent();
                break;
            }

        case FMissionEventType::Delay:
            {
                GetWorld()->GetTimerManager().SetTimer(FTimerHandle, [this]()
                {
                    Delay();
                }, MissionData[currentMissionEventIndex].DelayTime, false);
                break;
            }
        default: ;
        }

        if (MissionData[currentMissionEventIndex].MissionReturnType == FMissionReturnType::Immediate)
            ExecuteNextMissionEvent();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Reached EOS or Invalid Mission Event Index"));
    }
}

// GetWorldTimerManager().SetTimer(TimerHandle, this , &Method, DelayBetweenLoops , LoopTheTimer, FirstDelayInSeconds);
void AMIssionDriver::Delay()
{
    UE_LOG(LogTemp, Warning, TEXT("Delay End"));
    ExecuteNextMissionEvent();
}

void AMIssionDriver::GoTo()
{
    AMissionActor* Interactable = Cast<AMissionActor>(
        MissionData[currentMissionEventIndex].MissionActor.LoadSynchronous());
    UE_LOG(LogTemp, Warning, TEXT("%s"), *MissionData[currentMissionEventIndex].MissionActor->GetName());

    if (Interactable)
    {
        UE_LOG(LogTemp, Warning, TEXT("True"));
        Interactable->BeginExecuteMissionEvent();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Fail"));
    }
}

void AMIssionDriver::Interact()
{
    AMissionActor* Interactable = Cast<AMissionActor>(
        MissionData[currentMissionEventIndex].MissionActor.LoadSynchronous());
    UE_LOG(LogTemp, Warning, TEXT("%s"), *MissionData[currentMissionEventIndex].MissionActor->GetName());

    if (Interactable)
    {
        UE_LOG(LogTemp, Warning, TEXT("True"));
        Interactable->BeginExecuteMissionEvent();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Fail"));
    }
}

void AMIssionDriver::BeginMissionEvent()
{
    AMissionActor* Interactable = Cast<AMissionActor>(
        MissionData[currentMissionEventIndex].MissionActor.LoadSynchronous());
    UE_LOG(LogTemp, Warning, TEXT("%s"), *MissionData[currentMissionEventIndex].MissionActor->GetName());

    if (Interactable)
    {
        UE_LOG(LogTemp, Warning, TEXT("True"));
        Interactable->BeginExecuteMissionEvent();
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Fail"));
    }
}
