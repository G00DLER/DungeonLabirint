// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DLDoor.generated.h"

class UBoxComponent;
class USoundCue;

UCLASS()
class DUNGEONLABIRINT_API ADLDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	ADLDoor();

	void OpenDoor();
	void DontOpenDoor();
	bool DoorIsOpen() { return IsOpen; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DoorFrameMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UBoxComponent* BoxCollision;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundCue* OpenDoorSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundCue* DontOpenDoorSound;

private:
	bool IsOpen = false;

};
