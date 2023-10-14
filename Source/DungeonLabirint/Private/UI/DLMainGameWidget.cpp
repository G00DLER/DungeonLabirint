// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/DLMainGameWidget.h"
#include "Character/DLBaseCharacter.h"

int UDLMainGameWidget::GetAmountKeys()
{
	if (!GetWorld()) return 0;

	auto Player = Cast<ADLBaseCharacter>(GetOwningPlayerPawn());
	if (!Player) return 0;
	
	return Player->GetAmountKeys();
}
