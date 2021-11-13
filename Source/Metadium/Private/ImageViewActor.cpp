// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageViewActor.h"
#include "Components/WidgetComponent.h"

// Sets default values
AImageViewActor::AImageViewActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	DefaultSceneRoot = CreateDefaultSubobject<UWidgetComponent>(TEXT("DefaultSceneRoot"));
	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetCaption = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetCaption"));

	RootComponent = DefaultSceneRoot;
	WidgetComponent->SetupAttachment(DefaultSceneRoot);
	WidgetCaption->SetupAttachment(DefaultSceneRoot);
}

// Called when the game starts or when spawned
void AImageViewActor::BeginPlay()
{
	Super::BeginPlay();
}

void AImageViewActor::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	if(ATageName == TEXT("PlayerPhoto")) return;
	SetImageDataTable();
}

void AImageViewActor::SetImageDataTable()
{
	const FString ImgTablePath{TEXT("DataTable'/Game/00_Metadium/image/ImageDataTable.ImageDataTable'")};
	UDataTable* ImgTableObject = Cast<UDataTable>(StaticLoadObject(UDataTable::StaticClass(), nullptr, *ImgTablePath));
	
	if (ImgTableObject)
	{
		FImageDataTable* ImgDataRow = nullptr;
		// 초기화
		AImageUrl = FText::FromString(TEXT(""));
		AImageContext = FText::FromString(TEXT(""));
		// 데이터 불러오기
		ImgDataRow = ImgTableObject->FindRow<FImageDataTable>(ATageName, TEXT(""));
		SetImageDataRow(ImgDataRow);
	}
}

void AImageViewActor::SetImageDataRow(FImageDataTable* ImgDataRow)
{
	if(ImgDataRow)
	{
		AImageUrl = ImgDataRow->ImageUrl;
		AImageContext = ImgDataRow->ImageContext;
	}
}
