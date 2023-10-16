// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/LapHUD.h"
#include "EmotingCharacter.h"
#include "LapGateUser.h"

void ULapHUD::SetLapGateUser(ULapGateUser* user)
{
	user->OnLapComplete.AddDynamic(this, &ULapHUD::OnLapCompleted);
	user->OnBestLap.AddDynamic(this, &ULapHUD::OnBestLap);
}

