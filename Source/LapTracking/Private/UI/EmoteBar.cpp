// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/EmoteBar.h"
#include "UI/EmoteButton.h"
#include "Components\PanelWidget.h"

void UEmoteBar::NativeConstruct()
{
	for (int i = 0; i < Emotes.Num(); i++)
	{
		// create new ones as we need them by using or cloning the first one
		UEmoteButton* button = i == 0 ? Prefab : DuplicateObject<UEmoteButton>(Prefab, Container);
		if (i > 0)
			Container->AddChild(button);
		button->SetEmote(Emotes[i]);
		button->Character = Character;
	}
}