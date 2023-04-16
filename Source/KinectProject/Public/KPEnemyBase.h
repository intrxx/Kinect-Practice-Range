// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KPCharacterBase.h"
#include "KPEnemyBase.generated.h"

/**
 * 
 */
UCLASS()
class KINECTPROJECT_API AKPEnemyBase : public AKPCharacterBase
{
	GENERATED_BODY()
	
public:
	AKPEnemyBase();

protected:
	void BeginPlay() override;

public:
	void Tick(float DeltaTime) override;
	
	
};
