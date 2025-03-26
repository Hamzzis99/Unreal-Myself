// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_MyGame : ModuleRules
{
	public UE_MyGame(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
