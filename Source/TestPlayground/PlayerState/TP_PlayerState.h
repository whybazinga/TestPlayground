// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "TP_PlayerState.generated.h"

UCLASS()
class TESTPLAYGROUND_API ATP_PlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATP_PlayerState();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
