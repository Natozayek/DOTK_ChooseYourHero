// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class DOTK_ChooseYourHeroEditorTarget : TargetRules
{
	public DOTK_ChooseYourHeroEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.Add("DOTK_ChooseYourHero");
	}
}
