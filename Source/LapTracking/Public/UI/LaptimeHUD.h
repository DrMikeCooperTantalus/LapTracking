// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LaptimeHUD.generated.h"

/**
 * 
 */
UCLASS()
class LAPTRACKING_API ULaptimeHUD : public UUserWidget
{
	GENERATED_BODY()
public:
	
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FTimespan LapTime;
};
