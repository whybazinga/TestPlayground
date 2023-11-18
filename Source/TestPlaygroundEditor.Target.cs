// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TestPlaygroundEditorTarget : TargetRules
{
	public TestPlaygroundEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange(
			new[]
			{
				"TestPlayground",
				"TestPlaygroundEditor"
			});
	}
}