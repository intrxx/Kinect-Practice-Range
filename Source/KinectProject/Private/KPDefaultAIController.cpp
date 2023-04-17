// Fill out your copyright notice in the Description page of Project Settings.

#include "KPDefaultAIController.h"

#include "KPCharacterBase.h"
#include "KPEnemyBase.h"


AKPDefaultAIController::AKPDefaultAIController()
{
}

void AKPDefaultAIController::BeginPlay()
{
	Super::BeginPlay();

	if(BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);
	}
}

bool AKPDefaultAIController::IsDead() const
{
	AKPEnemyBase* Enemy = Cast<AKPEnemyBase>(GetPawn());
	if(Enemy)
	{
		return Enemy->IsDead();
	}
	return true;
}
