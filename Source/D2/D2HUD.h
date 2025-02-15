// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "D2HUD.generated.h"

UCLASS()
class AD2HUD : public AHUD
{
	GENERATED_BODY()

public:
	AD2HUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCanShowCrosshair;

private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

};

