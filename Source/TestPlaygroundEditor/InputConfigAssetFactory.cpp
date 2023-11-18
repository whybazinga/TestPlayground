// Fill out your copyright notice in the Description page of Project Settings.


#include "InputConfigAssetFactory.h"

#include "Input/InputConfig.h"


UInputConfigAssetFactory::UInputConfigAssetFactory()
	: Super()
{
	// Tell the editor which type of assets this factor can
	// create.
	SupportedClass = UInputConfig::StaticClass();

	// This factory creates new instances from scratch
	// rather than importing using drag-and-drop. This is
	// what decide which of the three factory types this
	// factory is. How we can get three types from a bool is
	// beyond me.
	bCreateNew = true;

	// Enter name-edit-mode after the asset has been created.
	bEditAfterNew = true;
}

UObject* UInputConfigAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UInputConfig>(InParent, InClass, InName, Flags);
}

bool UInputConfigAssetFactory::ShouldShowInNewMenu() const
{
	return true;
}
