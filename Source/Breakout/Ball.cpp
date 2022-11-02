// Fill out your copyright notice in the Description page of Project Settings.


#include "Ball.h"
#include "PaperSpriteComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
ABall::ABall() : elapsedTime(0.0f)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>("Sprite");
	Sprite->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ABall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//if (ball is moving)
	{
		elapsedTime += DeltaTime;
	}

}

int ABall::CalculateBrickScore()
{
	int calculatedScore = maxBrickScore - ((int)elapsedTime * 10);

	if (calculatedScore > minBrickScore)
	{
		return calculatedScore;
	}

	return minBrickScore;
}

