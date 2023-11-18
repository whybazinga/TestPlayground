#pragma once

#include "GameplayTagContainer.h"
#include "Engine/DeveloperSettings.h"

#include "GameplayTagsSetup.generated.h"


UCLASS(Config = "GameplayTags", DefaultConfig, DisplayName = "Gameplay Tags Mapping")
class UGameplayTagsSetup : public UDeveloperSettings
{
	GENERATED_BODY()

	// Create custom handles for tags that we require in code.
	// We will always be expecting that these tags are set and valid

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Config, meta=(Categories="InputTag"))
	FGameplayTag InputTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Config, meta=(Categories="InputTag"))
	FGameplayTag InputTag_Move;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Config, meta=(Categories="InputTag"))
	FGameplayTag InputTag_Look_Mouse;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Config, meta=(Categories="InputTag"))
	FGameplayTag InputTag_Crouch;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input", Config, meta=(Categories="InputTag"))
	FGameplayTag InputTag_Jump;

public:
	virtual FName GetCategoryName() const override;

public:
	FORCEINLINE static const UGameplayTagsSetup& Get()
	{
		return *GetDefault<UGameplayTagsSetup>();
	}
};
