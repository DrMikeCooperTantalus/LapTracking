// Fill out your copyright notice in the Description page of Project Settings.


#include "EmotingCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "EmoteAction.h"

void AEmotingCharacter::ServerDoEmote_Implementation(UEmoteAction* emote)
{
	MulticastDoEmote(emote);
}

void AEmotingCharacter::MulticastDoEmote_Implementation(UEmoteAction* emote)
{
	EmoteAction = emote;

	USkeletalMeshComponent* SkeletalMesh = FindComponentByClass<USkeletalMeshComponent>();
	SkeletalMesh->GetAnimInstance()->Montage_Play(emote->Animation);
}

void AEmotingCharacter::Plant()
{
	FVector position = GetActorLocation() + 100.0f * GetActorForwardVector();

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), EmoteAction->Particles, 
		position, GetActorRotation(), true);
}

// Sets default values
AEmotingCharacter::AEmotingCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEmotingCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEmotingCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AEmotingCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}



