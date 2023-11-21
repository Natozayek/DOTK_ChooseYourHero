// Fill out your copyright notice in the Description page of Project Settings.


#include "Base_GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Base_BlueprintFunctionLibrary.h"


void UBase_GameInstance::HandleControllerConnectionChange(bool bConnected, FPlatformUserId userID, int32 ControllerID)
{

	FString UserId_Text;
	if (userID == PLATFORMUSERID_NONE)
	{
		UserId_Text = TEXT("None");
	}
	else
	{

		UserId_Text = FString::Printf(TEXT("%d"), userID.GetInternalId());

	}
	FString message = FString::Printf(TEXT("Controller connection changed - UserIdx:%d, UserID:%s, Connected: %d"),
	ControllerID, *UserId_Text, bConnected ? 1 : 0);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, message);


	if (GetActiveControllerID() == ControllerID)
	{
		if (APlayerController* ActivePC = UBase_BlueprintFunctionLibrary::GetActivePlayerController(this))
		{
			if (bConnected)
			{// Our active controller connected
				if (ControlDisconnectedPausesGame)
				{
					UGameplayStatics::SetGamePaused(this, false);
					ControlDisconnectedPausesGame = false;

				}
				//ControlDWidget->RemoveFromParent();
			}
			else // Our active controller disconnected
			{
				//if (ControlDWClass)
				
					if (!UGameplayStatics::IsGamePaused(this))
					{
						ControlDisconnectedPausesGame = true;
						UGameplayStatics::SetGamePaused(this, true);
					}
					//ControlDWidget = CreateWidget<UControllerDisconnectionWidget>(ActivePC, ControlDWClass);
					//ControlDWidget->AddToViewport();
				
				else
				{
					GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("ControlDWClass NOT SET!"));

				}
			}
		}
	}



}

void UBase_GameInstance::Init()
{
	Super::Init();

	FTickerDelegate delegate = FTickerDelegate::CreateUObject(this, &UBase_GameInstance::Tick);
	TickDelegateHandle = FTSTicker::GetCoreTicker().AddTicker(delegate);
	FCoreDelegates::OnControllerConnectionChange.AddUObject(this, &UBase_GameInstance::HandleControllerConnectionChange);


}

void UBase_GameInstance::Shutdown()
{
	Super::Shutdown();
	FTSTicker::GetCoreTicker().RemoveTicker(TickDelegateHandle);
}


bool UBase_GameInstance::Tick(float DeltaSeconds)
{
	if (GEngine)
	{
		FString message = FString::Printf(TEXT("Active controller ID: %d"), ActiveControllerID);
		GEngine->AddOnScreenDebugMessage(1, 0.2f, FColor::Blue, *message);
	}
	return true;
}


void UBase_GameInstance::SetActiveControllerID(int32 ControllerID)
{
	ActiveControllerID = ControllerID;
}

int32 UBase_GameInstance::GetActiveControllerID()
{
	return ActiveControllerID;
}

