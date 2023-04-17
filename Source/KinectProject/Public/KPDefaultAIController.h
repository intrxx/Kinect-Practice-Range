// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "KPDefaultAIController.generated.h"

/**
 * 
 */
UCLASS()
class KINECTPROJECT_API AKPDefaultAIController : public AAIController
{
	GENERATED_BODY()

public:
	AKPDefaultAIController();
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* BehaviorTree;

public:
	UFUNCTION(BlueprintCallable)
	bool IsDead() const;
	
	
};
