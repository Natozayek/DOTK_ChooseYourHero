// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DOTK_ChooseYourHero : ModuleRules
{
	public DOTK_ChooseYourHero(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
