// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "CustomCharacter.generated.h"

UCLASS()
class COMBOSYSTEM_API ACustomCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACustomCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	bool IsAttacking = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	bool IsSaveAttack = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	int32 AttackCount;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	float BaseLookUpRate = 45.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Character|Anim")
	float BaseTurnRate = 45.0f;
};
