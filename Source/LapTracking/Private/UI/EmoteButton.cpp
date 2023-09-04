// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/EmoteButton.h"
#include "EmoteAction.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "EmotingCharacter.h"

void UEmoteButton::SetEmote(class UEmoteAction* Emote)
{
	EmoteAction = Emote;
	EmoteName->SetText(FText::FromString(Emote->GetName()));
	SetButtonIcon(EmoteButton, Emote->Icon);
}

void UEmoteButton::NativeConstruct()
{
	EmoteButton->OnClicked.AddDynamic(this, &UEmoteButton::DoEmote);
}

void UEmoteButton::DoEmote()
{
	Character->DoEmote(EmoteAction);
}

void UEmoteButton::SetButtonIcon(UButton* button, UTexture2D* icon)
{
	if (icon == nullptr)
		return;
	FVector2D size(icon->GetSizeX(), icon->GetSizeY());
	button->WidgetStyle.Normal.SetResourceObject(icon);
	button->WidgetStyle.Normal.ImageSize = size;
	button->WidgetStyle.Hovered.SetResourceObject(icon);
	button->WidgetStyle.Hovered.ImageSize = size;
	button->WidgetStyle.Pressed.SetResourceObject(icon);
	button->WidgetStyle.Pressed.ImageSize = size;
	button->WidgetStyle.Disabled.SetResourceObject(icon);
	button->WidgetStyle.Disabled.ImageSize = size;
}