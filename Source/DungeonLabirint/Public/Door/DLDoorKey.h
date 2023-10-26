// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DLDoorKey.generated.h"

class USphereComponent;
class USoundCue;

UCLASS()
class DUNGEONLABIRINT_API ADLDoorKey : public AActor
{
	GENERATED_BODY()
	
public:	
	ADLDoorKey();
	
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	void OnRaised();
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* KeyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USphereComponent* KeyCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundCue* KeySound;

private:
	float RotationYaw;
	
	void GenerateRotationYaw();
};
