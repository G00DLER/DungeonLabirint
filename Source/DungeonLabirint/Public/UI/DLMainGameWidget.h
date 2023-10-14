// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DLMainGameWidget.generated.h"


UCLASS()
class DUNGEONLABIRINT_API UDLMainGameWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable)
	int GetAmountKeys();
};
