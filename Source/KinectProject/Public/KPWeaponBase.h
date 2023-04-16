// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "KPWeaponBase.generated.h"

UCLASS()
class KINECTPROJECT_API AKPWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKPWeaponBase();

	void ThrowWeapon();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	AController* GetOwnerController() const;

	bool WeaponTrace(FHitResult& Hit, FVector& ThrowDirection);
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere)
	float Damage = 20.0f;

	UPROPERTY(EditAnywhere)
	float WeaponRange = 1500.0f;
	UPROPERTY(EditAnywhere)
	float MaxMagazineCapacity = 5.0f;
	
	
};
