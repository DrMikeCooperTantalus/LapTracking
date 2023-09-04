// Fill out your copyright notice in the Description page of Project Settings.


#include "EmoteAnimNotify.h"
#include "EmotingCharacter.h"

void UEmoteAnimNotify::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	AEmotingCharacter* ch = dynamic_cast<AEmotingCharacter*>(MeshComp->GetOwner());
	if (ch)
		ch->Plant();
}