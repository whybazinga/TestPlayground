// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TP_GameMode.generated.h"

UCLASS()
class TESTPLAYGROUND_API ATP_GameMode : public AGameMode
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATP_GameMode();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
