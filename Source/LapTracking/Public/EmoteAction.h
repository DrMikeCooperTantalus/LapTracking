// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EmoteAction.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class LAPTRACKING_API UEmoteAction : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UAnimMontage* Animation;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UParticleSystem* Particles;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UTexture2D* Icon;
};
