// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon.h"
#include "GameFramework/Controller.h"
#include "Components/SkeletalMeshComponent.h"

// Sets default values
AWeapon::AWeapon()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    FP_Gun = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FP_Gun"));
    FP_Gun->SetOnlyOwnerSee(true); // only the owning player will see this mesh
    FP_Gun->bCastDynamicShadow = false;
    FP_Gun->CastShadow = false;

    FP_Gun->SetupAttachment(RootComponent);

    FP_MuzzleLocation = CreateDefaultSubobject<USceneComponent>(TEXT("MuzzleLocation"));
    FP_MuzzleLocation->SetupAttachment(FP_Gun);
    FP_MuzzleLocation->SetRelativeLocation(FVector(0.2f, 48.4f, -10.6f));

    // Default offset from the character location for projectiles to spawn
    GunOffset = FVector(100.0f, 0.0f, 10.0f);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
    Super::BeginPlay();
}

void AWeapon::Shoot()
{
    UWorld* const World = GetWorld();
    if (World != NULL)
    {
        const FRotator SpawnRotation = FP_MuzzleLocation->GetRightVector().Rotation();

        // MuzzleOffset is in camera space, so transform it to world space before offsetting from the character location to find the final muzzle position
        const FVector SpawnLocation = ((FP_MuzzleLocation != nullptr)
                                           ? FP_MuzzleLocation->GetComponentLocation()
                                           : GetActorLocation());

        //Set Spawn Collision Handling Override
        FActorSpawnParameters ActorSpawnParams;
        ActorSpawnParams.SpawnCollisionHandlingOverride =
            ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButDontSpawnIfColliding;


        // spawn the projectile at the muzzle
        World->SpawnActor<AD2Projectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
    }
}

void AWeapon::SetUpAttachment(USkeletalMeshComponent* Mesh)
{
    FP_Gun->AttachToComponent(Mesh, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true), TEXT("GripPoint"));
}


void AWeapon::Equip()
{
}

void AWeapon::Unequip()
{
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}
