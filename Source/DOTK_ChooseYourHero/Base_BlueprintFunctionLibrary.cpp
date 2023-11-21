// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_BlueprintFunctionLibrary.h"
#include "Base_GameInstance.h"
#include "Kismet/GameplayStatics.h"
//#include "AchievementSubSystem.h" -> to be used later


int32 UBase_BlueprintFunctionLibrary::GetLastMaxPlayerIndex()
{
	return UBase_GameInstance::MAX_CONTROLLERS - 1;
}

void UBase_BlueprintFunctionLibrary::SetActiveControllerID(const UObject* WorldContextObject, int32 ControllerID)
{
	UBase_GameInstance* GameInstanceRef = Cast<UBase_GameInstance>(UGameplayStatics::GetGameInstance(WorldContextObject));

	if (GameInstanceRef)
	{
		GameInstanceRef->SetActiveControllerID(ControllerID);
	}
}

int32 UBase_BlueprintFunctionLibrary::GetActiveControllerID(const UObject* WorldContextObject)
{
	UBase_GameInstance* GameInstanceRef = Cast<UBase_GameInstance>(UGameplayStatics::GetGameInstance(WorldContextObject));

	if (GameInstanceRef)
	{
		return GameInstanceRef->GetActiveControllerID();
	}
	return -1;
}

void UBase_BlueprintFunctionLibrary::RemoveAllPlayers(const UObject* WorldContextObject)
{
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(WorldContextObject, APlayerController::StaticClass(), FoundActors);

	for (AActor* Actor : FoundActors)
	{
		APlayerController* PC = Cast<APlayerController>(Actor);

		if (PC)
		{
			UGameplayStatics::RemovePlayer(PC, true);
		}
	}
}

APlayerController* UBase_BlueprintFunctionLibrary::GetActivePlayerController(const UObject* WorldContextObject)
{
	return UGameplayStatics::GetPlayerControllerFromID(WorldContextObject, GetActiveControllerID(WorldContextObject));

	//return UGameplayStatics::GetPlayerController(WorldContextObject, GetActiveControllerID(WorldContextObject));
}

ACharacter* UBase_BlueprintFunctionLibrary::GetActivePlayerCharacter(const UObject* WorldContextObject)
{
	return  GetActivePlayerController(WorldContextObject)->GetCharacter();

	//return UGameplayStatics::GetPlayerCharacter(WorldContextObject, GetActiveControllerID(WorldContextObject));

}

void UBase_BlueprintFunctionLibrary::SetupActiveControllerID(const UObject* WorldContextObject, FKey Key,
	EStatusReturnType& Status)
{
	if (Key.IsGamepadKey())
	{
		for (int32 ContollerIndex = 0; ContollerIndex < UBase_GameInstance::MAX_CONTROLLERS; ++ContollerIndex)
		{
			APlayerController* PC = UGameplayStatics::GetPlayerController(WorldContextObject, ContollerIndex);

			if (PC->WasInputKeyJustPressed(Key))
			{
				SetActiveControllerID(WorldContextObject, ContollerIndex);
				RemoveAllPlayers(WorldContextObject);
				Status = EStatusReturnType::Success;
				return;
			}
		}



	}

	Status = EStatusReturnType::Fail;
}

//UAchievementSubSystem* UBase_BlueprintFunctionLibrary::GetAchievementSystem(const UObject* WorldContextObject)
//{
//	UGameInstance* GameInstanceRef = UGameplayStatics::GetGameInstance(WorldContextObject);
//
//	if (GameInstanceRef)
//	{
//		return  GameInstanceRef->GetSubsystem<UAchievementSubSystem>();
//	}
//	return nullptr;
//}


