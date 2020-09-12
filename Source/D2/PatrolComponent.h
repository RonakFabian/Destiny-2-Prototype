// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PatrolComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class D2_API UPatrolComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(EditInstanceOnly,Category="Patrol Points")
	TArray<AActor*> PartolPointCpp;
		
};
