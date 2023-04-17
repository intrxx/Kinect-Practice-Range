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

	UPROPERTY(EditAnywhere)
	int32 MaxMagazineCapacity = 5;
	UPROPERTY(VisibleAnywhere)
	int32 CurrentMagazineCapacity = 0;

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void ThrowWeapon();
	
private:
	AController* GetOwnerController() const;

	bool WeaponTrace(FHitResult& Hit, FVector& ThrowDirection);
	
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere)
	float Damage = 20.0f;

	UPROPERTY(EditAnywhere)
	float WeaponRange = 1500.0f;
	
};
