// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjectileWeapon.h"


void AProjectileWeapon::Shoot(AActor* Player)
{
 if (canShoot)
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
    UWorld* const World = GetWorld();

   
        Super::Shoot(Player);


        if (World != NULL)
        {
            // spawn the projectile at the muzzle
            World->SpawnActor<AD2Projectile>(ProjectileClass, SpawnLocation, SpawnRotation, ActorSpawnParams);
        }
    }
}
