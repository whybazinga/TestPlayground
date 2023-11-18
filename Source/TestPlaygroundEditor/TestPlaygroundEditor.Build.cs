// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestPlaygroundEditor : ModuleRules
{
	public TestPlaygroundEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PublicIncludePaths.AddRange(
			new[]
			{
				"TestPlaygroundEditor"
			});

		PrivateIncludePaths.AddRange(
			new string[]
			{
			});

		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"TestPlayground"
			});

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"CoreUObject",
				"AssetDefinition",
				"Engine",
				"UnrealEd",
			});

		PrivateIncludePathModuleNames.AddRange(
			new string[]
			{
			});

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
			});
	}
}