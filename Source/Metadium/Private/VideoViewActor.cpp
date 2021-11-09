// Fill out your copyright notice in the Description page of Project Settings.


#include "VideoViewActor.h"

#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "MediaAssets/Public/MediaSoundComponent.h"

// Sets default values
AVideoViewActor::AVideoViewActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	MediaSound = CreateDefaultSubobject<UMediaSoundComponent>(TEXT("MediaSound"));
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetCaption = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetCaption"));
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));

	RootComponent = RootSceneComponent;
	StaticMeshComponent->SetupAttachment(RootSceneComponent);
	WidgetComponent->SetupAttachment(StaticMeshComponent);
	MediaSound->SetupAttachment(RootSceneComponent);
	WidgetCaption->SetupAttachment(RootSceneComponent);
	BoxComponent->SetupAttachment(RootSceneComponent);
}

// Called when the game starts or when spawned
void AVideoViewActor::BeginPlay()
{
	Super::BeginPlay();
}

void AVideoViewActor::SetVideoDataTable()
{
	const FString VideoTablePath{TEXT("DataTable'/Game/00_Metadium/video/VideoDataTable.VideoDataTable'")};
	UDataTable* VideoTableObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, *VideoTablePath));
	
	if (VideoTableObject)
	{
		FVideoDataTable* VideoDataRow = nullptr;
		// 초기화
		AVideoUrl = FText::FromString(TEXT(""));
		AVideoContext = FText::FromString(TEXT(""));
		// 데이터 불러오기
		VideoDataRow = VideoTableObject->FindRow<FVideoDataTable>(ATageName, TEXT(""));
		SetVideoDataRow(VideoDataRow);
	}
}

void AVideoViewActor::SetVideoDataRow(FVideoDataTable* VideoDataRow)
{
	if(VideoDataRow)
	{
		AVideoUrl = VideoDataRow->VideoUrl;
		AVideoContext = VideoDataRow->VideoContext;
	}
}
