// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AssetDefinitionDefault.h"
#include "Input/InputConfig.h"

#include "AssetDefinition_InputConfig.generated.h"

/**
 * 
 */
UCLASS()
class UAssetDefinition_InputConfig : public UAssetDefinitionDefault
{
	GENERATED_BODY()

public:
	/** Returns the name of this type */
	virtual FText GetAssetDisplayName() const override { return NSLOCTEXT("AssetDefinition", "InputConfig", "Input Config"); }

	/** Get the supported class of this type. */
	virtual TSoftClassPtr<UObject> GetAssetClass() const override { return UInputConfig::StaticClass(); }
	
	/** Returns the color associated with this type */
	virtual FLinearColor GetAssetColor() const override { return FLinearColor(FColor(201, 29, 85)); }
	
	/** Returns additional tooltip information for the specified asset, if it has any. */
	virtual FText GetAssetDescription(const FAssetData& AssetData) const override { return FText::FromString(TEXT("Hi there")); }
	
	/** Gets a list of categories this asset is in, these categories are used to help organize */
	virtual TConstArrayView<FAssetCategoryPath> GetAssetCategories() const override
	{
		static const auto Categories = { EAssetCategoryPaths::Input };
		return Categories;
	}
};
