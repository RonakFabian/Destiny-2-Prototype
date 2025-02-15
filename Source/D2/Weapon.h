// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UCLASS()
class D2_API AWeapon : public AActor
{
    GENERATED_BODY()


public:
    // Sets default values for this actor's properties
    AWeapon();

    void SetUpAttachment(USkeletalMeshComponent* Owner);

    /** Gun mesh: 1st person view (seen only by self) */
    UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
    class USkeletalMeshComponent* FP_Gun;


    /** Location on gun mesh where projectiles should spawn. */
    UPROPERTY(BlueprintReadWrite,EditDefaultsOnly, Category = Mesh)
    class USceneComponent* FP_MuzzleLocation;

    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = Mesh)
    class UParticleSystem* MuzzleParticle;

    UPROPERTY(EditAnywhere, BlueprintReadWrite,Category = Mesh)
    class UParticleSystem* ImpactParticle;


    /** Gun muzzle's offset from the characters location */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
    FVector GunOffset;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=WeaponData)
    float RateOfFire;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=WeaponData)
    int32 ammoPool;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=WeaponData)
    int32 loadedAmmo;

 UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=WeaponData)
    int32 MagazinePool;
   
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=WeaponData)
    int BaseDamage;
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=WeaponData)
    int ReloadTime;


    /** Sound to play each time we fire */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Gameplay)
    class USoundBase* FireSound;

    /** AnimMontage to play each time we fire */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
    class UAnimMontage* FireAnimation;

    void Equip();

    void Unequip();

   

    void Reload();
    
    UFUNCTION(BlueprintImplementableEvent)
    void ReloadUI();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    /** Fires a projectile. */
    UPROPERTY()
    bool canShoot=true;

    UPROPERTY()
    bool canReload=true;


    //Interface


public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    virtual void Shoot(AActor* Player);
    FORCEINLINE int GetCurrentWeaponBaseDamage() const { return BaseDamage; }
};
