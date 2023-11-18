// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_CharacterBase.h"
#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Input/TP_InputComponent.h"
#include "Settings/GameplayTagsSetup.h"


//////////////////////////////////////////////////////////////////////////
// ATP_CharacterBase

ATP_CharacterBase::ATP_CharacterBase()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;

	// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	Mesh1P->SetOnlyOwnerSee(true);
	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	Mesh1P->bCastDynamicShadow = false;
	Mesh1P->CastShadow = false;
	Mesh1P->SetRelativeRotation(FRotator(1.9f, -19.19f, 5.2f));
	Mesh1P->SetRelativeLocation(FVector(-0.5f, -4.4f, -155.7f));

}

void ATP_CharacterBase::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();
}

//////////////////////////////////////////////////////////////////////////// Input

void ATP_CharacterBase::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	UTP_InputComponent* TP_InputComponent = Cast<UTP_InputComponent>(PlayerInputComponent);
	TP_InputComponent->BindNativeAction(DefaultInputConfig, UGameplayTagsSetup::Get().InputTag_Move, ETriggerEvent::Triggered, this, &ThisClass::Input_Move);
	TP_InputComponent->BindNativeAction(DefaultInputConfig, UGameplayTagsSetup::Get().InputTag_Look_Mouse, ETriggerEvent::Triggered, this, &ThisClass::Input_LookMouse);
	TP_InputComponent->BindNativeAction(DefaultInputConfig, UGameplayTagsSetup::Get().InputTag_Crouch, ETriggerEvent::Triggered, this, &ThisClass::Input_Crouch);
	TP_InputComponent->BindNativeAction(DefaultInputConfig, UGameplayTagsSetup::Get().InputTag_Jump, ETriggerEvent::Triggered, this, &ThisClass::Input_Jump);
}

void ATP_CharacterBase::Input_Move(const FInputActionValue& InputActionValue)
{
	const FVector2D Value = InputActionValue.Get<FVector2D>();
	const FRotator MovementRotation(0.0f, Controller->GetControlRotation().Yaw, 0.0f);

	if (Value.X != 0.0f)
	{
		const FVector MovementDirection = MovementRotation.RotateVector(FVector::RightVector);
		AddMovementInput(MovementDirection, Value.X);
	}

	if (Value.Y != 0.0f)
	{
		const FVector MovementDirection = MovementRotation.RotateVector(FVector::ForwardVector);
		AddMovementInput(MovementDirection, Value.Y);
	}
}

void ATP_CharacterBase::Input_LookMouse(const FInputActionValue& InputActionValue)
{
	const FVector2D Value = InputActionValue.Get<FVector2D>();

	if (Value.X != 0.0f)
	{
		AddControllerYawInput(Value.X);
	}

	if (Value.Y != 0.0f)
	{
		AddControllerPitchInput(Value.Y);
	}
}

void ATP_CharacterBase::Input_Crouch(const FInputActionValue& InputActionValue)
{
	const UCharacterMovementComponent* MovementComponent = CastChecked<UCharacterMovementComponent>(GetCharacterMovement());

	if (bIsCrouched || MovementComponent->bWantsToCrouch)
	{
		UnCrouch();
	}
	else if (MovementComponent->IsMovingOnGround())
	{
		Crouch();
	}
}

void ATP_CharacterBase::Input_Jump(const FInputActionValue& InputActionValue)
{
	Jump();
}
