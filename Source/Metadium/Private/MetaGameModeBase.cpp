// Fill out your copyright notice in the Description page of Project Settings.


#include "MetaGameModeBase.h"

#include "MetadiumSaveGame.h"
#include "Kismet/GameplayStatics.h"

void AMetaGameModeBase::SavePlayerName(FString CustomPlayerName)
{
	UMetadiumSaveGame* GameInstance = Cast<UMetadiumSaveGame>(UGameplayStatics::CreateSaveGameObject(UMetadiumSaveGame::StaticClass()));
	GameInstance->SavePlayerName = CustomPlayerName;
	UGameplayStatics::SaveGameToSlot(GameInstance, GameInstance->SaveSlotName, GameInstance->UserIndex);
}

FString AMetaGameModeBase::LoadPlayerName()
{
	UMetadiumSaveGame* LoadGameInstance = Cast<UMetadiumSaveGame>(UGameplayStatics::CreateSaveGameObject(UMetadiumSaveGame::StaticClass()));
	if(LoadGameInstance)
	{
		LoadGameInstance = Cast<UMetadiumSaveGame>(UGameplayStatics::LoadGameFromSlot(LoadGameInstance->SaveSlotName, LoadGameInstance->UserIndex));
		return LoadGameInstance->SavePlayerName;
	}
	return TEXT("");
}
