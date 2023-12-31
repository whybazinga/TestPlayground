// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"

#include "InputConfigAssetFactory.generated.h"

/**
 * 
 */
UCLASS(MinimalAPI)
class UInputConfigAssetFactory : public UFactory
{
	GENERATED_BODY()

public:
	UInputConfigAssetFactory();

	// UFactory Interface
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
	virtual bool ShouldShowInNewMenu() const override;
};
