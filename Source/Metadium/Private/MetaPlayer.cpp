// Fill out your copyright notice in the Description page of Project Settings.


#include "MetaPlayer.h"

#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMetaPlayer::AMetaPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	VROrigin = CreateDefaultSubobject<USceneComponent>(TEXT("VROrigin"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SelfCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SelfCamera"));
	WidgetCaptionDetail = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetCaption"));

	RootComponent = RootScene;
	StaticMeshComponent->SetupAttachment(VROrigin);
	VROrigin->SetupAttachment(GetRootComponent());
	Camera->SetupAttachment(VROrigin);
	SpringArmComponent->SetupAttachment(StaticMeshComponent);
	SelfCamera->SetupAttachment(SpringArmComponent);
	WidgetCaptionDetail->SetupAttachment(RootScene);
}

// Called when the game starts or when spawned
void AMetaPlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AMetaPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AMetaPlayer::ReadFile()
{
	// We will use this FileManager to deal with the file.
	FString FilePath = UploadPath;
	FilePath.Append("/");
	FilePath.Append(*UploadFileName);

	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FString AbsoluteFilePath = FilePath;

	FString FileContent;
	if(FFileHelper::LoadFileToString(FileContent, *FilePath, FFileHelper::EHashOptions::None))
	{
		UE_LOG(LogTemp, Error, TEXT("File Read ::: %s"), *FileContent);
	}
	
	if (!PlatformFile.FileExists(*AbsoluteFilePath))
	{
		UE_LOG(LogTemp, Error, TEXT("Could Not Find File"));
		return;
	}
	// const int FileSize = FPlatformFileManager::Get().GetPlatformFile().FileSize(*AbsoluteFilePath);
	// UE_LOG(LogTemp, Error, TEXT("%d"), FileSize);
	
}