// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RepasoCPP : ModuleRules
{
	public RepasoCPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] {
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"AIModule",
			"StateTreeModule",
			"GameplayStateTreeModule",
			"UMG",
			"Slate"
		});

		PrivateDependencyModuleNames.AddRange(new string[] { });

		PublicIncludePaths.AddRange(new string[] {
			"RepasoCPP",
			"RepasoCPP/Variant_Platforming",
			"RepasoCPP/Variant_Platforming/Animation",
			"RepasoCPP/Variant_Combat",
			"RepasoCPP/Variant_Combat/AI",
			"RepasoCPP/Variant_Combat/Animation",
			"RepasoCPP/Variant_Combat/Gameplay",
			"RepasoCPP/Variant_Combat/Interfaces",
			"RepasoCPP/Variant_Combat/UI",
			"RepasoCPP/Variant_SideScrolling",
			"RepasoCPP/Variant_SideScrolling/AI",
			"RepasoCPP/Variant_SideScrolling/Gameplay",
			"RepasoCPP/Variant_SideScrolling/Interfaces",
			"RepasoCPP/Variant_SideScrolling/UI"
		});

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
