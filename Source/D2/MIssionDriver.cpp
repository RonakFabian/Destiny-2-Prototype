// Fill out your copyright notice in the Description page of Project Settings.


#include "MIssionDriver.h"

// Sets default values
AMIssionDriver::AMIssionDriver()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMIssionDriver::BeginPlay()
{
	Super::BeginPlay();
	LoadMissionScript();
}

// Called every frame
void AMIssionDriver::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMIssionDriver::LoadMissionScript()
{
	if(MissionScriptTable==nullptr) return;
	
	if (MissionData.IsValidIndex(0))
		MissionData.Empty();

	for (auto it : MissionScriptTable->GetRowMap())
	{
		FMissionData* missionData = (FMissionData*)(it.Value);
		MissionData.Add(*missionData);
	}
}

void AMIssionDriver::ExecuteNextMissionEvent()
{
	UE_LOG(LogTemp,Warning,TEXT("ExecuteNextMissionEvent"));
}



