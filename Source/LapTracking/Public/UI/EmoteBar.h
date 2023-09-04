// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EmoteBar.generated.h"

/**
 * 
 */
UCLASS()
class LAPTRACKING_API UEmoteBar : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TArray<class UEmoteAction*> Emotes;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class AEmotingCharacter* Character;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UPanelWidget* Container;
	UPROPERTY(BluePrintReadOnly, meta = (BindWidget))
		class UEmoteButton* Prefab;

	void NativeConstruct() override;
};
