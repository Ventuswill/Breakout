// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BreakoutHUD.generated.h"

/**
 * 
 */
UCLASS()
class BREAKOUT_API ABreakoutHUD : public AHUD
{
	GENERATED_BODY()

public:

	ABreakoutHUD();


	UPROPERTY(EditAnywhere, Category = "Game Hud")
		TSubclassOf<class UUserWidget> PlayerGuiClass;

	UPROPERTY(EditAnywhere, Category = "Player GUI")
		class UUserWidget* PlayerGui;

	virtual void BeginPlay() override;

protected:

	int m_lives;
	int m_score;
	
};
