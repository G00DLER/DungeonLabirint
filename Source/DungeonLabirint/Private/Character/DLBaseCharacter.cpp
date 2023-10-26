// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/DLBaseCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Door/DLDoor.h"
#include "Door/DLDoorKey.h"

ADLBaseCharacter::ADLBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->TargetArmLength = -10.0f;
	SpringArmComponent->SocketOffset = FVector(0.0f, 0.0f, 89.0f);
	SpringArmComponent->SetupAttachment(GetRootComponent());
	
	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetRelativeRotation(FRotator(0.0f, 0.0f, 0.0f));
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationPitch = true;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = true;
}

void ADLBaseCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	CheckOverlapKey();
}

void ADLBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ADLBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ADLBaseCharacter::MoveRight);
	PlayerInputComponent->BindAxis("LookUp", this, &ADLBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookRight", this, &ADLBaseCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &ADLBaseCharacter::Interact);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ADLBaseCharacter::IsJumping);
	PlayerInputComponent->BindAction("TestAmountKey", IE_Pressed, this, &ADLBaseCharacter::TestAmountKey);
}

void ADLBaseCharacter::MoveForward(float Amount)
{
	if (Amount == 0.0f) return;

	AddMovementInput(GetActorForwardVector(), Amount);
}

void ADLBaseCharacter::MoveRight(float Amount)
{
	if (Amount == 0.0f) return;

	AddMovementInput(GetActorRightVector(), Amount);
}

void ADLBaseCharacter::IsJumping()
{
	if (!GetWorld()) return;

	Jump();
}

void ADLBaseCharacter::Interact()
{
	if (!GetWorld() || AmountKeys <= 0) return;

	TArray<AActor*> OverlappedActors;
	GetOverlappingActors(OverlappedActors, ADLDoor::StaticClass());

	if (OverlappedActors.IsEmpty()) return;

	for (auto OverlappedActor : OverlappedActors)
	{
		ADLDoor* Door = Cast<ADLDoor>(OverlappedActor);
		Door->OpenDoor();
	}

	AmountKeys -= 1;
}

void ADLBaseCharacter::CheckOverlapKey()
{
	if (!GetWorld()) return;

	TArray<AActor*> OverlappedActors;
	GetOverlappingActors(OverlappedActors, ADLDoorKey::StaticClass());

	if (OverlappedActors.IsEmpty()) return;

	for (auto OverlappedActor : OverlappedActors)
	{
		ADLDoorKey* Key = Cast<ADLDoorKey>(OverlappedActor);
		Key->OnRaised();
	}

	AmountKeys += 1;
}

void ADLBaseCharacter::TestAmountKey()
{
	UE_LOG(LogTemp, Display, TEXT("Количество ключей - %i"), AmountKeys);
}
