// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MetaGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class METADIUM_API AMetaGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SavePlayerName(FString CustomPlayerName);

	UFUNCTION(BlueprintCallable)
	FString LoadPlayerName();

	UFUNCTION()
	void DeleteGame();
};
