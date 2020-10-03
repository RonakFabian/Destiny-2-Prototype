// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Item.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UItem : public UInterface
{
    GENERATED_BODY()
};

/**
 * 
 */
class D2_API IItem
{
    GENERATED_BODY()
    
public:
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interaction")
    void OnEquip();
    
    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Interaction")
    void OnUnequip();
};
