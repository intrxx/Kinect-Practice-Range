// Fill out your copyright notice in the Description page of Project Settings.

#include "KPHeroController.h"
#include "KPHeroHUD.h"
#include "UserWidget.h"


AKPHeroController::AKPHeroController()
{
	
}

void AKPHeroController::CreateHUD()
{
	if(!HeroHUD)
	{
		return;
	}

	HeroHUDClass = CreateWidget<UKPHeroHUD>(this, HeroHUD);
	HeroHUDClass->AddToViewport();
}

UKPHeroHUD* AKPHeroController::GetWidget() const
{
	return HeroHUDClass;
}



