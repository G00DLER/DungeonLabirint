// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DLBaseCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

UCLASS()
class DUNGEONLABIRINT_API ADLBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ADLBaseCharacter();

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaSeconds) override;

	int GetAmountKeys() { return AmountKeys; }

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UCameraComponent* CameraComponent;

private:
	int AmountKeys = 0;
	
	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void IsJumping();
	void Interact();
	void CheckOverlapKey();

	void TestAmountKey();
};