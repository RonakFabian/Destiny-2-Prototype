// Fill out your copyright notice in the Description page of Project Settings.
#include "ChooseNextWaypoint.h"
#include "PatrolComponent.h"
#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    // UE_LOG(LogTemp, Warning, TEXT("WayPointIndex is: %i"), Index);
    //Get the patrol points from ai controller
    auto myAiController = OwnerComp.GetAIOwner();
    auto ControlledPawn = myAiController->GetPawn();


    auto PatrollingComp = ControlledPawn->FindComponentByClass<UPatrolComponent>();
    if (!ensure(PatrollingComp)) { return EBTNodeResult::Failed; }


    TArray<AActor*> PatrolPoints = PatrollingComp->PartolPointCpp;
    if (PatrolPoints.Num() == 0)
    {
        UE_LOG(LogTemp, Warning, TEXT("No Waypoints Given!"));
        return EBTNodeResult::Failed; 
    }
    //Set Next Waypoint

    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
    BlackboardComp->SetValueAsObject(WayPointObject.SelectedKeyName, PatrolPoints[Index]);

    int32 NextIndex = (Index + 1) % PatrolPoints.Num();
    BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

    return EBTNodeResult::Succeeded;
}

void UChooseNextWaypoint::GetPatrolPoints(AAIController* controlledOwner)
{
}

void UChooseNextWaypoint::GetPatrolPoint()
{
}

void UChooseNextWaypoint::CycleIndex()
{
}
