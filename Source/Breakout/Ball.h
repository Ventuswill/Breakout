// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Ball.generated.h"

UCLASS()
class BREAKOUT_API ABall : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABall();

	UPROPERTY(VisibleAnywhere, Category = "Actor Visual")
		class UPaperSpriteComponent* Sprite;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Visual")
		class USphereComponent* BallCollision;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float elapsedTime;

	const int maxBrickScore = 1000;
	const int minBrickScore = 200;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int CalculateBrickScore();

};
