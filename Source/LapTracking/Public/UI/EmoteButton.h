// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EmoteButton.generated.h"

/**
 * 
 */
UCLASS()
class LAPTRACKING_API UEmoteButton : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UTextBlock* EmoteName;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
		class UButton* EmoteButton;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class AEmotingCharacter* Character;

	UFUNCTION(BlueprintCallable)
		void SetEmote(class UEmoteAction* Emote);

	void NativeConstruct() override;

protected:
	class UEmoteAction* EmoteAction;

	UFUNCTION()
		void DoEmote();

	void SetButtonIcon(UButton* button, UTexture2D* icon);
};
