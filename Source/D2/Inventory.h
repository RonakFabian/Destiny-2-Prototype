// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapon.h"
#include "GameFramework/Actor.h"
#include "Inventory.generated.h"

UCLASS()
class D2_API AInventory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInventory();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category=Weapon)
	AWeapon* PrimaryWeapon;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category=Inventory)
	TArray<AWeapon*> inventoryPool;

	UFUNCTION(BlueprintCallable)
	void AddWeaponToInventory(AWeapon* weapon);

	UFUNCTION(BlueprintCallable)
    void SetWeaponActive(AWeapon* weapon,bool isActive);

	UFUNCTION(BlueprintCallable)
	void EquipPrimaryWeapon(AWeapon* Weapon,USkeletalMeshComponent* mesh);


};
