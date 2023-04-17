// Fill out your copyright notice in the Description page of Project Settings.

#include "KPHeroBase.h"

#include "KPHeroController.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"


AKPHeroBase::AKPHeroBase()
{
	GetCapsuleComponent()->InitCapsuleSize(55.0f, 96.0f);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->RelativeLocation = FVector(-39.5f, 1.75f, 64.0f);
	Camera->bUsePawnControlRotation = true;

	Mesh_1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh"));
	Mesh_1P->SetOnlyOwnerSee(true);
	Mesh_1P->SetupAttachment(Camera);
	Mesh_1P->bCastDynamicShadow = false;
	Mesh_1P->CastShadow = false;
	Mesh_1P->RelativeRotation = FRotator(0.f, -90.f, 0.f);
	Mesh_1P->RelativeLocation = FVector(-0.5f, -4.4f, -155.7f);
}

void AKPHeroBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("LookSide"), this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction(TEXT("Throw"), EInputEvent::IE_Pressed, this, &AKPHeroBase::Throw);
	PlayerInputComponent->BindAction(TEXT("Reload"), EInputEvent::IE_Pressed, this, &AKPHeroBase::Reload);
}

void AKPHeroBase::BeginPlay()
{
	Super::BeginPlay();
	
	Weapon = GetWorld()->SpawnActor<AKPWeaponBase>(WeaponClass);
	Weapon->AttachToComponent(Mesh_1P, FAttachmentTransformRules::KeepRelativeTransform, TEXT("GripPoint"));
	Weapon->SetOwner(this);
	
	AKPHeroController* PC = Cast<AKPHeroController>(GetController());
	if(PC)
	{
		PC->CreateHUD();
	}
}

void AKPHeroBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AKPHeroBase::Throw()
{
	UE_LOG(LogTemp, Warning, TEXT("Throwing..."));
	Weapon->ThrowWeapon();
}

void AKPHeroBase::Reload()
{
	UE_LOG(LogTemp, Warning, TEXT("Reloading..."));
	Weapon->CurrentMagazineCapacity = Weapon->MaxMagazineCapacity;
}

