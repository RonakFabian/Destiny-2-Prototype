// Fill out your copyright notice in the Description page of Project Settings.


#include "HitScanWeapon.h"

#include "DrawDebugHelpers.h"

//#include "Engine/Engine.h"

void AHitScanWeapon::Shoot(AActor* Player)
{
    Super::Shoot(Player);
    FHitResult HitResult;
    // GEngine->AddOnScreenDebugMessage(-1,2,FColor::Blue,TEXT("HitScan"));
    //ShootImplementation();
    const FName TraceTag("MyTraceTag");
 
    GetWorld()->DebugDrawTraceTag = TraceTag;
 
    FCollisionQueryParams CollisionParams;
    CollisionParams.TraceTag = TraceTag;

    GetWorld()->LineTraceSingleByChannel(HitResult, FP_MuzzleLocation->GetComponentLocation(),
                                         FP_MuzzleLocation->GetForwardVector() * 5000000.0f,
                                         ECollisionChannel::ECC_Visibility, CollisionParams);

     
    

   
}
