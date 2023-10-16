// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LapGateUser.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable )
class LAPTRACKING_API ULapGateUser : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULapGateUser();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
		int NextGate;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
		FDateTime LapGateStartTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
		FDateTime LapStartTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
		bool LapStarted;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
		FTimespan CurrentLapTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
		FTimespan LastLapTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated)
		FTimespan BestLapTime;

	UFUNCTION(BlueprintCallable)
		bool EnterGate(int Index, bool LastGate);

	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLapDelegate, FTimespan, Time);

	UPROPERTY(BlueprintAssignable)
		FLapDelegate OnLapComplete;
	UPROPERTY(BlueprintAssignable)
		FLapDelegate OnBestLap;

	// UFUNCTION(BlueprintImplementableEvent)
	// void OnLapComplete(FTimespan time);
	//
	// UFUNCTION(BlueprintImplementableEvent)
	// void OnBestLap(FTimespan time);
};
