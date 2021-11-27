// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MetadiumSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class METADIUM_API UMetadiumSaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UMetadiumSaveGame();

	UPROPERTY(VisibleAnywhere, Category="SaveGame")
	FString SaveSlotName;
	
	UPROPERTY(VisibleAnywhere, Category="SaveGame")
	FString SavePlayerName;
	
	UPROPERTY(VisibleAnywhere, Category="SaveGame")
	uint32 UserIndex;
	
};
