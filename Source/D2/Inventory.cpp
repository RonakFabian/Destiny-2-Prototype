// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory.h"

// Sets default values
AInventory::AInventory()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInventory::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInventory::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AInventory::AddWeaponToInventory(AWeapon* weapon)
{
	check(weapon);
	inventoryPool.Add(weapon);
	
}

void AInventory::SetWeaponActive(AWeapon* weapon, bool isActive)
{
	check(weapon);
	weapon->SetHidden(!isActive);
	weapon->SetActorTickEnabled(isActive);
	weapon->SetActorEnableCollision(isActive);
}

void AInventory::EquipPrimaryWeapon(AWeapon* Weapon, USkeletalMeshComponent* mesh)
{
	check(Weapon);
	check(mesh);
	SetWeaponActive(Weapon,true);
	Weapon->SetUpAttachment(mesh);
	
}


