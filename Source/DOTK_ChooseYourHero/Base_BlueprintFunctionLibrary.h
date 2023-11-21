// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Base_BlueprintFunctionLibrary.generated.h"


UENUM(BlueprintType)
enum class EStatusReturnType : uint8
{
	Success UMETA(DisplayName = "On Success"),
	Fail UMETA(DisplayName = "On Failure")


};
UCLASS()
class DOTK_CHOOSEYOURHERO_API UBase_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	public:
	UFUNCTION(BlueprintPure, Category = "BlueprintFunctionLibrary")
		static int32 GetLastMaxPlayerIndex();

	UFUNCTION(BlueprintCallable, Category = "BlueprintFunctionLibrary", meta = (WorldContext = "WorldContextObject"))
		static void SetActiveControllerID(const UObject* WorldContextObject, int32 ControllerID);

	UFUNCTION(BlueprintPure, Category = "BlueprintFunctionLibrary", meta = (WorldContext = "WorldContextObject"))
		static int32 GetActiveControllerID(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "BlueprintFunctionLibrary", meta = (WorldContext = "WorldContextObject"))
		static void RemoveAllPlayers(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "BlueprintFunctionLibrary", meta = (WorldContext = "WorldContextObject"))
		static class APlayerController* GetActivePlayerController(const UObject* WorldContextObject);

	UFUNCTION(BlueprintPure, Category = "BlueprintFunctionLibrary", meta = (WorldContext = "WorldContextObject"))
		static class ACharacter* GetActivePlayerCharacter(const UObject* WorldContextObject);

	UFUNCTION(BlueprintCallable, Category = "BlueprintFunctionLibrary", meta = (WorldContext = "WorldContextObject", ExpandEnumAsExecs = "Status"))
		static void SetupActiveControllerID(const UObject* WorldContextObject, FKey Key, EStatusReturnType& Status);

	/*UFUNCTION(BlueprintPure, Category = "BlueprintFunctionLibrary | Achievementes", meta = (WorldContext = "WorldContextObject"))
		static class UAchievementSubSystem* GetAchievementSystem(const UObject* WorldContextObject);*/ //-to be used later

};
