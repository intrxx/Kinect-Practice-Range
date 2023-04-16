// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KPCharacterBase.h"
#include "KPWeaponBase.h"
#include "KPHeroBase.generated.h"

/**
 * 
 */
UCLASS()
class KINECTPROJECT_API AKPHeroBase : public AKPCharacterBase
{
	GENERATED_BODY()

public:
	AKPHeroBase();

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Throw();

private:
	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
	class USkeletalMeshComponent* Mesh_1P;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AKPWeaponBase> WeaponClass;
	
	UPROPERTY()
	AKPWeaponBase* Weapon;
};
