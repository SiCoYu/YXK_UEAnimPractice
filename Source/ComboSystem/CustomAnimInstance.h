// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GameFramework/Character.h"
#include "CustomAnimInstance.generated.h"

class ACustomCharacter;

UCLASS()
class COMBOSYSTEM_API UCustomAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
public:
	UPROPERTY()
	ACustomCharacter* OwnCharacter;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	bool IsFullBody = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	bool IsInAir = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	bool IsAccelerating;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	bool IsAttacking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	float Speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	float YawDelta;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	float Roll;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	float Pitch;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	float Yaw;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	FRotator RotationLastTick;
};
