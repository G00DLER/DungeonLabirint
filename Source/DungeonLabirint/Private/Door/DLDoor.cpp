// Fill out your copyright notice in the Description page of Project Settings.


#include "Door/DLDoor.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

ADLDoor::ADLDoor()
{
	PrimaryActorTick.bCanEverTick = false;

	DoorFrameMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorFrameMesh");
	DoorFrameMesh->SetupAttachment(GetRootComponent());

	DoorMesh = CreateDefaultSubobject<UStaticMeshComponent>("DoorMesh");
	DoorMesh->SetupAttachment(DoorFrameMesh);

	BoxCollision = CreateDefaultSubobject<UBoxComponent>("BoxCollision");
	BoxCollision->SetupAttachment(DoorFrameMesh);
}

void ADLDoor::OpenDoor()
{
	if (!GetWorld() || IsOpen) return;

	UGameplayStatics::PlaySound2D(GetWorld(), OpenDoorSound);
	DoorMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	IsOpen = true;
}

void ADLDoor::DontOpenDoor()
{
	if (!GetWorld()) return;

	UGameplayStatics::PlaySound2D(GetWorld(), DontOpenDoorSound);
}

void ADLDoor::BeginPlay()
{
	Super::BeginPlay();
	
}
