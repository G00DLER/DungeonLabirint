// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DLBaseHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/DLMainGameWidget.h"

void ADLBaseHUD::BeginPlay()
{
	Super::BeginPlay();

	if (!MainWidget) return;

	UUserWidget* CurrentWidget = CreateWidget<UDLMainGameWidget>(GetWorld(), MainWidget);
	if (!CurrentWidget) return;

	CurrentWidget->AddToViewport();
}
