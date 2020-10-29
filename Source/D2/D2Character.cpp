// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "D2Character.h"
#include "D2Projectile.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "MotionControllerComponent.h"
#include "TimerManager.h"


DEFINE_LOG_CATEGORY_STATIC(LogFPChar, Warning, All);

//////////////////////////////////////////////////////////////////////////
// AD2Character

AD2Character::AD2Character()
{
    GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

    BaseTurnRate = 45.f;
    BaseLookUpRate = 45.f;

    FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
    FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
    FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
    FirstPersonCameraComponent->bUsePawnControlRotation = true;

    Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
    Mesh1P->SetOnlyOwnerSee(true);
    Mesh1P->SetupAttachment(FirstPersonCameraComponent);
    Mesh1P->bCastDynamicShadow = false;
    Mesh1P->CastShadow = false;
    Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
    Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));
}

void AD2Character::PostInitializeComponents()
{
    Super::PostInitializeComponents();
    FVector Location(0.0f, 0.0f, 0.0f);
    FRotator Rotation(0.0f, 0.0f, 0.0f);
    FActorSpawnParameters SpawnInfo;
    PrimaryWeapon = GetWorld()->SpawnActor<AWeapon>(PrimaryWeaponRef, Location, Rotation, SpawnInfo);
    SecondaryWeapon = GetWorld()->SpawnActor<AWeapon>(SecondaryWeaponRef, Location, Rotation, SpawnInfo);
}


void AD2Character::BeginPlay()
{
    Super::BeginPlay();


    if (PrimaryWeapon)
        SpawnPrimaryWeapon(PrimaryWeapon);

    if (SecondaryWeapon)
        SpawnSecondaryWeapon(SecondaryWeapon);


    EquipWeaponPrimary();
}

//////////////////////////////////////////////////////////////////////////
// Input

void AD2Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
    // set up gameplay key bindings
    check(PlayerInputComponent);

    // Bind jump events
    PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
    PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

    // Bind fire event
    PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &AD2Character::OnStartFire);
    PlayerInputComponent->BindAction("Fire", IE_Released, this, &AD2Character::OnStopFire);
    PlayerInputComponent->BindAction("EquipPrimary", IE_Pressed, this, &AD2Character::EquipWeaponPrimary);
    PlayerInputComponent->BindAction("EquipSecondary", IE_Pressed, this, &AD2Character::EquipWeaponSecondary);
    PlayerInputComponent->BindAction("Reload", IE_Pressed, this, &AD2Character::OnReload);
    

    

    PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AD2Character::OnResetVR);

    // Bind movement events
    PlayerInputComponent->BindAxis("MoveForward", this, &AD2Character::MoveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &AD2Character::MoveRight);


    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
    PlayerInputComponent->BindAxis("TurnRate", this, &AD2Character::TurnAtRate);
    PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
    PlayerInputComponent->BindAxis("LookUpRate", this, &AD2Character::LookUpAtRate);
}

void AD2Character::SpawnPrimaryWeapon(AWeapon* Weapon)
{
    Weapon->AttachToComponent(
        Mesh1P,
        FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true),
        TEXT("GripPoint")
    );

    Weapon->SetOwner(this);
}

void AD2Character::SpawnSecondaryWeapon(AWeapon* Weapon)
{
    Weapon->AttachToComponent(
        Mesh1P,
        FAttachmentTransformRules(EAttachmentRule::SnapToTarget, true),
        TEXT("GripPoint")
    );

    Weapon->SetOwner(this);
}

void AD2Character::OnFire()
{
    if (currentWeapon != NULL)
    {
        currentWeapon->Shoot(this);
    }

 }

void AD2Character::OnReload()
{
    if (currentWeapon != NULL)
    {
        currentWeapon->Reload();
    }
}

void AD2Character::OnStartFire()
{
    OnFire();
    
    if (currentWeapon != NULL)
    {
        GetWorldTimerManager().SetTimer(TimerHandle, this, &AD2Character::OnFire, currentWeapon->RateOfFire,
                                        true);
    }
  
}

void AD2Character::OnStopFire()
{
    
    
    GetWorldTimerManager().ClearTimer(TimerHandle);
}


void AD2Character::EquipWeaponPrimary()
{
    if(SecondaryWeapon)
    {
        SecondaryWeapon->Unequip();
    }
    if(PrimaryWeapon)
    {
        PrimaryWeapon->Equip();
    }

    currentWeapon=PrimaryWeapon;
}

void AD2Character::EquipWeaponSecondary()
{
    if(SecondaryWeapon)
    {
        SecondaryWeapon->Equip();
    }
    if(PrimaryWeapon)
    {
        PrimaryWeapon->Unequip();
    }
    currentWeapon=SecondaryWeapon;
}



void AD2Character::OnResetVR()
{
    UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AD2Character::MoveForward(float Value)
{
    if (Value != 0.0f)
    {
        // add movement in that direction
        AddMovementInput(GetActorForwardVector(), Value);
    }
}

void AD2Character::MoveRight(float Value)
{
    if (Value != 0.0f)
    {
        // add movement in that direction
        AddMovementInput(GetActorRightVector(), Value);
    }
}

void AD2Character::TurnAtRate(float Rate)
{
    // calculate delta for this frame from the rate information
    AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AD2Character::LookUpAtRate(float Rate)
{
    // calculate delta for this frame from the rate information
    AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}
