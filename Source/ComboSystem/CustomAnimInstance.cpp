// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomAnimInstance.h"
#include "GameFramework/Pawn.h"
#include "CustomCharacter.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

void UCustomAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	APawn* Owner = TryGetPawnOwner();
	OwnCharacter = Cast<ACustomCharacter>(Owner);
	if (IsValid(OwnCharacter))
	{

	}
}

void UCustomAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (IsValid(OwnCharacter))
	{
		bool is_in_air = OwnCharacter->GetMovementComponent()->IsFalling();
		IsInAir = is_in_air;

		FRotator Delta = OwnCharacter->GetBaseAimRotation() - OwnCharacter->GetActorRotation();
		Roll = Delta.Roll;
		Pitch = Delta.Pitch;
		Yaw = Delta.Yaw;

		FRotator TempDelta = RotationLastTick - OwnCharacter->GetActorRotation();
		YawDelta = UKismetMathLibrary::FInterpTo(YawDelta, TempDelta.Yaw / 7, 0.0f, 6.0f);
		RotationLastTick = OwnCharacter->GetActorRotation();
		
		float acceleration = OwnCharacter->GetCharacterMovement()->GetCurrentAcceleration().Size();
		IsAccelerating = acceleration > 0.0f;

		IsFullBody = GetCurveValue("FullBody") > 0.0f;

		FRotator Rotation{ OwnCharacter->GetActorRotation() };
		FVector Velocity{ OwnCharacter->GetVelocity() };
		Speed = Velocity.Size();
		Velocity.Z = 0.0f;
		bool is_fly = OwnCharacter->GetCharacterMovement()->MovementMode == EMovementMode::MOVE_Flying;
		if (!is_fly)
		{
			Direction = CalculateDirection(Velocity, Rotation);
		}
	}
}
