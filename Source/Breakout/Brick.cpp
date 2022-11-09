// Fill out your copyright notice in the Description page of Project Settings.


#include "Brick.h"
#include "Components/BoxComponent.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BrickCollision = CreateDefaultSubobject<UBoxComponent>("Collision Box");
	BrickCollision->SetSimulatePhysics(false);
	BrickCollision->SetCollisionProfileName("OverlapAllDynamic");
	
	BrickCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	RootComponent = BrickCollision;

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::SetActive(bool active)
{

	if (active)
	{
		//CALL SetActorHiddenInGame() passing in false
		SetActorHiddenInGame(false);
		//CALL SetActive() on CollisionSphere passing in true
		BrickCollision->SetActive(true);
		//CALL SetCollisionEnabled() on CollisionSphere passing in ECollisionEnabled::QueryOnly
		BrickCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	}

	else
	{
		//CALL SetActorHiddenInGame() passing in true
		SetActorHiddenInGame(true);
		//CALL SetActive() on CollisionSphere passing in false
		BrickCollision->SetActive(false);
		//CALL  SetCollisionEnabled() on CollisionSphere passing in ECollisionEnabled::NoCollision
		BrickCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}

}

