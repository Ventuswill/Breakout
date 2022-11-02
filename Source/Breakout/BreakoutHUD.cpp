// Fill out your copyright notice in the Description page of Project Settings.


#include "BreakoutHUD.h"
#include "Blueprint/UserWidget.h"

ABreakoutHUD::ABreakoutHUD() : m_lives(3), m_score(0)
{
    static ConstructorHelpers::FClassFinder<UUserWidget> playerHud(TEXT("/Game/Blueprints/UI/PlayerUI"));
    if (playerHud.Succeeded())
        PlayerGuiClass = playerHud.Class;
}

void ABreakoutHUD::BeginPlay()
{
    Super::BeginPlay();

    PlayerGui = CreateWidget<UUserWidget>(GetGameInstance(), PlayerGuiClass);
    PlayerGui->AddToViewport();
}
