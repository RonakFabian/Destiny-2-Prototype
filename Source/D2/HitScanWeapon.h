// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "HitScanWeapon.generated.h"

/**
 * 
 */
UCLASS()
class D2_API AHitScanWeapon : public AWeapon
{
    GENERATED_BODY()

    void Shoot(AActor*) override;

public:
    UFUNCTION(BlueprintImplementableEvent)
    void ShootImplementation();
};
