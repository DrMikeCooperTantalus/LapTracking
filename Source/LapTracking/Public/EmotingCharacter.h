// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EmotingCharacter.generated.h"

UCLASS()
class LAPTRACKING_API AEmotingCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEmotingCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		class UEmoteAction* EmoteAction;

	UFUNCTION(Server, Reliable)
		void ServerDoEmote(class UEmoteAction* emote);

	UFUNCTION(NetMulticast, Reliable)
		void MulticastDoEmote(class UEmoteAction* emote);

	UFUNCTION(BlueprintCallable)
		void Plant();
};
