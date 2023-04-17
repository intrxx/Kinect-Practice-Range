// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KPHeroHUD.h"
#include "GameFramework/PlayerController.h"
#include "KPHeroController.generated.h"

/**
 * 
 */
UCLASS()
class KINECTPROJECT_API AKPHeroController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AKPHeroController();
	
	void CreateHUD();
	UKPHeroHUD* GetHUDWidget() const;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI")
	TSubclassOf<class UKPHeroHUD> HeroHUD;

	UPROPERTY(BlueprintReadWrite, Category = "UI")
	class UKPHeroHUD* HeroHUDClass;
	
protected:
	
};
