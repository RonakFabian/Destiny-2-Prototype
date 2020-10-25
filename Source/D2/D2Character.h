// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Inventory.h"
#include "GameFramework/Character.h"
#include "D2Character.generated.h"

class UInputComponent;

UCLASS(config=Game)
class AD2Character : public ACharacter
{
    GENERATED_BODY()


    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
    class UCameraComponent* FirstPersonCameraComponent;


public:
    AD2Character();

    void PostInitializeComponents() override;

    UFUNCTION(BlueprintCallable,Category=Weapon)
    void SpawnPrimaryWeapon(AWeapon* Weapon);

    UFUNCTION(BlueprintCallable,Category=Weapon)
    void SpawnSecondaryWeapon(AWeapon* Weapon);


protected:
    virtual void BeginPlay();

public:

    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Weapon)
    TSubclassOf<class AWeapon> PrimaryWeaponRef;

    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Weapon)
    TSubclassOf<class AWeapon> SecondaryWeaponRef;

    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Weapon)
    AWeapon* PrimaryWeapon;

    AWeapon* currentWeapon;
    
    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Weapon)
    AWeapon* SecondaryWeapon;

    UPROPERTY(EditAnywhere,BlueprintReadWrite, Category=Mesh)
    class USkeletalMeshComponent* Mesh1P;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
    float BaseTurnRate;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
    float BaseLookUpRate;


    FTimerHandle TimerHandle;

    UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Inventory)
    AInventory* InventoryRef;

    UFUNCTION(BlueprintCallable)
    void OnFire();

    UFUNCTION(BlueprintCallable)
    void OnStartFire();

    UFUNCTION(BlueprintCallable)
    void OnStopFire();

    UFUNCTION(BlueprintCallable)
    void EquipWeaponPrimary();
    
    UFUNCTION(BlueprintCallable)
    void EquipWeaponSecondary();

protected:

    void OnResetVR();

    void MoveForward(float Val);

    void MoveRight(float Val);

    void TurnAtRate(float Rate);

    void LookUpAtRate(float Rate);


protected:
    // APawn interface
    virtual void SetupPlayerInputComponent(UInputComponent* InputComponent) override;

public:

    FORCEINLINE class USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
    FORCEINLINE class UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
};
