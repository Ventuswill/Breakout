// Fill out your copyright notice in the Description page of Project Settings.


#include "Paddle.h"
#include "PaperSpriteComponent.h"
#include "SimplePawnMovementComponent.h"

// Sets default values
APaddle::APaddle() : m_movement(0)
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerRoot = CreateDefaultSubobject<USceneComponent>("Player Root");
	SetRootComponent(PlayerRoot);

	PaddleSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Sprite");
	PaddleSpriteComponent->SetupAttachment(RootComponent);

	AutoPossessPlayer = EAutoReceiveInput::Player0;

	PaddleMovementComponent = CreateDefaultSubobject<USimplePawnMovementComponent>(TEXT("CustomMovementComponent"));
	//Set the SimplePawnMovementComponent's UpdateComponent to the RootComponent. This will apply the movement to the RootComponent
	PaddleMovementComponent->UpdatedComponent = RootComponent;

}

// Called when the game starts or when spawned
void APaddle::BeginPlay()
{
	Super::BeginPlay();
	
}

void APaddle::MoveHorizontal(float AxisValue)
{
	m_movement = AxisValue;
	if (PaddleMovementComponent && (PaddleMovementComponent->UpdatedComponent == RootComponent))
	{
		//Move the Pawn using the SimplePawnMovementComponent on the Forward Vector
		PaddleMovementComponent->AddInputVector(GetActorForwardVector() * - m_movement * 1000 * DeltaTime);

	}

}

// Called every frame
void APaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveHorizontal", this, &APaddle::MoveHorizontal);

}

