// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "GameFramework/Controller.h"
#include "Components/SkeletalMeshComponent.h"
#include "D2Projectile.h"
#include "ProjectileWeapon.generated.h"

/**
 * 
 */
UCLASS()
class D2_API AProjectileWeapon : public AWeapon
{
	GENERATED_BODY()
public:
	
	void Shoot(AActor* ) override;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category=Projectile)
	TSubclassOf< AD2Projectile> ProjectileClass;
	
};
