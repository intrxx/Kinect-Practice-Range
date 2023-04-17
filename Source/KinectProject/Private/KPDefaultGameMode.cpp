// Fill out your copyright notice in the Description page of Project Settings.

#include "KPDefaultGameMode.h"

#include "EngineUtils.h"
#include "KPDefaultAIController.h"
#include "Kismet/GameplayStatics.h"


void AKPDefaultGameMode::PawnKilled(APawn* PawnKilled)
{
	APlayerController* PC = Cast<APlayerController>(PawnKilled->GetController());

	if(PC)
	{
		EndLevel(false);
	}

	for(AKPDefaultAIController* AIC : TActorRange<AKPDefaultAIController>(GetWorld()))
	{
		if(!AIC->IsDead())
		{
			return;
		}
	}
	EndLevel(true);
}

void AKPDefaultGameMode::EndLevel(bool bIsPlayerWinner)
{
	if(bIsPlayerWinner)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName("Test1"));
	}
	
}
