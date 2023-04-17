// Fill out your copyright notice in the Description page of Project Settings.

#include "KPCharacterBase.h"

#include "Components/CapsuleComponent.h"


// Sets default values
AKPCharacterBase::AKPCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AKPCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;
}

// Called every frame
void AKPCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

float AKPCharacterBase::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	DamageApplied = FMath::Min(CurrentHealth, DamageApplied);
	CurrentHealth -= DamageApplied;
	UE_LOG(LogTemp, Warning, TEXT("Taking damage, current health: %f"), CurrentHealth);

	if(IsDead())
	{
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Destroy();
	}
	
	return DamageApplied;
}

bool AKPCharacterBase::IsDead() const
{
	if(CurrentHealth <= 0)
	{
		return true;
	}
	return false;
}



