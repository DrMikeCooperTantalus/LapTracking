// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LapGateUser.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
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

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int NextGate;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FDateTime LapGateStartTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FDateTime LapStartTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		bool LapStarted;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FTimespan CurrentLapTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FTimespan LastLapTime;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		FTimespan BestLapTime;

	UFUNCTION(BlueprintCallable)
		bool EnterGate(int Index, bool LastGate);
};
