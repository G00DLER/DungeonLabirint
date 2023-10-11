// Fill out your copyright notice in the Description page of Project Settings.


#include "Door/DLDoorKey.h"
#include "Components/SphereComponent.h"

ADLDoorKey::ADLDoorKey()
{
	PrimaryActorTick.bCanEverTick = true;

	KeyMesh = CreateDefaultSubobject<UStaticMeshComponent>("KeyMesh");
	KeyMesh->SetupAttachment(GetRootComponent());

	KeyCollision = CreateDefaultSubobject<USphereComponent>("KeyCollision");
	KeyCollision->SetupAttachment(KeyMesh);
}

void ADLDoorKey::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotationYaw, 0.0f));
}

void ADLDoorKey::BeginPlay()
{
	Super::BeginPlay();

	GenerateRotationYaw();
}

void ADLDoorKey::GenerateRotationYaw()
{
	if (!GetWorld()) return;

	const auto Direction = FMath::RandBool() ? 1.0f : -1.0f;
	RotationYaw = FMath::RandRange(1.0f, 2.0f) * Direction;
}

