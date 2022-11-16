// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

UCLASS()
class BREAKOUT_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sprite", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* BrickSprite;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sprite", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* BrickBlue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sprite", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* BrickBrown;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sprite", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* BrickGreen;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sprite", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* BrickPurple;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Sprite", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* BrickRed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = "true"))
		class UPaperSpriteComponent* BrickYellow;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Brick Collision")
		class UBoxComponent* BrickCollision;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetActive(bool active);

	

};
