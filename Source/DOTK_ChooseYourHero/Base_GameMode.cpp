// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_GameMode.h"
#include "DOTK_ChooseYourHeroCharacter.h"
#include "Child_PlayerController.h"

ABase_GameMode::ABase_GameMode() : Super()
{
	PlayerControllerClass = AChild_PlayerController::StaticClass();
	DefaultPawnClass = ADOTK_ChooseYourHeroCharacter::StaticClass();

}
