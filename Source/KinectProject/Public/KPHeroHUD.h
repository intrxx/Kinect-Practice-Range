// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "KPHeroHUD.generated.h"

/**
 * 
 */
UCLASS()
class KINECTPROJECT_API UKPHeroHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetMaxMagazineCapacity(int32 MaxMagazineCapacity);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentMagazineCapacity(int32 CurrentMagazineCapacity);
	
};
