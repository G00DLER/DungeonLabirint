// Fill out your copyright notice in the Description page of Project Settings.


#include "DLGameMode.h"
#include "Character/DLBaseCharacter.h"

ADLGameMode::ADLGameMode()
{
	DefaultPawnClass = ADLBaseCharacter::StaticClass();
}
