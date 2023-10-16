// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LapHUD.generated.h"

/**
 * 
 */
UCLASS()
class LAPTRACKING_API ULapHUD : public UUserWidget
{
	GENERATED_BODY()
public:

	UFUNCTION(BlueprintCallable)
	void SetLapGateUser(class ULapGateUser* user);


	UFUNCTION(BlueprintImplementableEvent)
	void OnLapCompleted(FTimespan time);
	
	UFUNCTION(BlueprintImplementableEvent)
	void OnBestLap(FTimespan time);
};
