// Fill out your copyright notice in the Description page of Project Settings.

#include "KPWeaponBase.h"

#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/Engine.h"
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

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	WeaponMesh->SetupAttachment(Root);
}

// Called when the game starts or when spawned
void AKPWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	CurrentMagazineCapacity = MaxMagazineCapacity;
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

	DrawDebugLine(GetWorld(), Location, Hit.Location, FColor(255, 0, 0), false, 3, 0, 12);
	return GetWorld()->LineTraceSingleByChannel(Hit, Location, ThrowEnd, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

void AKPWeaponBase::ThrowWeapon()
{
	if(CurrentMagazineCapacity == 0)
	{
		return;
	}
	CurrentMagazineCapacity--;

	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("CurrentMagazineCapacity: %i"), CurrentMagazineCapacity));
	
	FHitResult HitResult;
	FVector ShotDirection;
	bool bSuccess = WeaponTrace(HitResult, ShotDirection);
	
	if(bSuccess)
	{
		UE_LOG(LogTemp, Warning, TEXT("Weapon Hit"));
		
		AActor* ShotActor = HitResult.GetActor();
		UE_LOG(LogTemp, Warning, TEXT("Shot actor: %s"), *HitResult.GetActor()->GetName());
		if(ShotActor)
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

