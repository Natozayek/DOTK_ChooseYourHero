// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Base_GameInstance.generated.h"

/**
 * 
 */
UCLASS()
class DOTK_CHOOSEYOURHERO_API UBase_GameInstance : public UGameInstance
{
	GENERATED_BODY()



	int32 ActiveControllerID = -1;
	//FTickerDelegate TickDelegate;
	FTSTicker::FDelegateHandle TickDelegateHandle;

	void HandleControllerConnectionChange(bool bConnected, FPlatformUserId userID, int32 ControllerID);
	bool ControlDisconnectedPausesGame = false;


public:
	static const int32 MAX_CONTROLLERS = 4;
	virtual void Init() override;
	virtual void Shutdown() override;

	bool Tick(float DeltaSeconds);


	void SetActiveControllerID(int32 ControllerID);
	int32 GetActiveControllerID();

	//UPROPERTY()
		//UControllerDisconnectionWidget* ControlDWidget;

	//UPROPERTY(EditAnywhere, Category = "Widget")
		//TSubclassOf<UControllerDisconnectionWidget> ControlDWClass;
	
};
