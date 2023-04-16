// Fill out your copyright notice in the Description page of Project Settings.

#include "KPWeaponBase.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"


// Sets default values
AKPWeaponBase::AKPWeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(Root);

	WeaponMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	WeaponMesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AKPWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKPWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AKPWeaponBase::WeaponTrace(FHitResult& Hit, FVector& ThrowDirection)
{
	AController* PC = GetOwnerController();
	if(!PC)
	{
		return false;
	}

	FVector Location;
	FRotator Rotation;

	PC->GetPlayerViewPoint(Location, Rotation);
	ThrowDirection = -Rotation.Vector();

	FVector ThrowEnd = Location + Rotation.Vector() * WeaponRange;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	Params.AddIgnoredActor(GetOwner());

	return GetWorld()->LineTraceSingleByChannel(Hit, Location, ThrowEnd, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

void AKPWeaponBase::ThrowWeapon()
{
	FHitResult HitResult;
	FVector ShotDirection;
	bool bSuccess = WeaponTrace(HitResult, ShotDirection);

	if(bSuccess)
	{
		AActor* ShotActor = HitResult.GetActor();
		if(!ShotActor)
		{
			FPointDamageEvent DamageEvent(Damage, HitResult, ShotDirection, nullptr);
			AController* PC = GetOwnerController();
			ShotActor->TakeDamage(Damage, DamageEvent, PC, this);
		}
	}
}

AController* AKPWeaponBase::GetOwnerController() const
{
	APawn* Owner = Cast<APawn>(GetOwner());
	if(!Owner)
	{
		return nullptr;
	}
	
	return Owner->GetController();
}

