// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestPlayground : ModuleRules
{
	public TestPlayground(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
				"TestPlayground"
			}
		);
		
		PrivateIncludePaths.AddRange(
			new string[] {
			}
		);

		OptimizeCode = CodeOptimization.Never;

		PublicDependencyModuleNames.AddRange(new string[]
		{
			"Core",
			"CoreUObject",
			"DeveloperSettings",
			"Engine",
			"EnhancedInput",
			"GameplayAbilities",
			"GameplayTags",
			"GameplayTasks",
			"HeadMountedDisplay",
			"NetCore"
		});

		// Generate compile errors if using DrawDebug functions in test/shipping builds.
		PublicDefinitions.Add("SHIPPING_DRAW_DEBUG_ERROR=1");
	}
}
