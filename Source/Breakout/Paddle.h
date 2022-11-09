// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Paddle.generated.h"

UCLASS()
class BREAKOUT_API APaddle : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APaddle();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Custom")
		class USceneComponent* PlayerRoot;

	UPROPERTY(EditAnywhere, Category = "Paddle Visual")
		class UPaperSpriteComponent* PaddleSpriteComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pawn Movement")
		class UPawnMovementComponent* PaddleMovementComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveHorizontal(float AxisValue);

	float m_movement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
