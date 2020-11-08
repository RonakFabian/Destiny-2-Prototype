// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "IMissionEvent.h"
#include "TP_ThirdPerson/TP_ThirdPersonCharacter.h"
#include "PatrollingGuard.generated.h"

/**
 * 
 */
UCLASS()
class D2_API APatrollingGuard : public ATP_ThirdPersonCharacter
{
    GENERATED_BODY()
protected:
    
    virtual void BeginPlay() override;
    virtual void Tick(float delta) override;
  
};
