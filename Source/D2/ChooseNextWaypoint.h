// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ChooseNextWaypoint.generated.h"

/**
 * 
 */
UCLASS()
class D2_API UChooseNextWaypoint : public UBTTaskNode
{
    GENERATED_BODY()
private:
    virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
    void GetPatrolPoints(AAIController* controlledOwner);
    void GetPatrolPoint();
    void CycleIndex();

protected:

    UPROPERTY(EditAnywhere,Category="Blackboard Data")
    struct FBlackboardKeySelector IndexKey;

    UPROPERTY(EditAnywhere,Category="Blackboard Data")
    struct FBlackboardKeySelector WayPointObject;

};
