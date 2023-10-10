// Fill out your copyright notice in the Description page of Project Settings.


#include "LapGateUser.h"
#include <Runtime/Engine/Public/Net/UnrealNetwork.h>

// Sets default values for this component's properties
ULapGateUser::ULapGateUser()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	SetIsReplicatedByDefault(true);
}


// Called when the game starts
void ULapGateUser::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULapGateUser::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (LapStarted)
		CurrentLapTime = FDateTime::Now() - LapGateStartTime;
	// ...
}

void ULapGateUser::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	DOREPLIFETIME(ULapGateUser, NextGate);
	DOREPLIFETIME(ULapGateUser, LapGateStartTime);
	DOREPLIFETIME(ULapGateUser, LapStartTime);
	DOREPLIFETIME(ULapGateUser, LapStarted);
	DOREPLIFETIME(ULapGateUser, CurrentLapTime);
	DOREPLIFETIME(ULapGateUser, LastLapTime);
	DOREPLIFETIME(ULapGateUser, BestLapTime);
}

bool ULapGateUser::EnterGate(int Index, bool LastGate)
{
	if (GetNetMode() == ENetMode::NM_Client)
		return false;

	if (Index == NextGate)
	{
		NextGate++;
		if (LastGate)
			NextGate = 0;

		// when we cross the first gate, start tracking and process
		// our latest laptime
		if (Index == 0)
		{
			LapStarted = true;
			LapGateStartTime = FDateTime::Now();
			LastLapTime = CurrentLapTime;
			if (BestLapTime == 0 || LastLapTime < BestLapTime)
				BestLapTime = LastLapTime;
		}

		return true;
	}
	return false;
}

