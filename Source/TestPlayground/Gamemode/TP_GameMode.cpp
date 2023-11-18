// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_GameMode.h"

#include "TestPlayground/PlayerState/TP_PlayerState.h"


// Sets default values
ATP_GameMode::ATP_GameMode()
	: Super()
{
	PrimaryActorTick.bCanEverTick = false;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;
	PlayerStateClass = ATP_PlayerState::StaticClass();
}

// Called when the game starts or when spawned
void ATP_GameMode::BeginPlay()
{
	Super::BeginPlay();

}

