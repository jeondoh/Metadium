// Fill out your copyright notice in the Description page of Project Settings.


#include "MetaPlayer.h"

#include "CustomPlayerFnc.h"
#include "MetaGameModeBase.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMetaPlayer::AMetaPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<UBoxComponent>(TEXT("DefaultSceneRoot"));

	VROrigin = CreateDefaultSubobject<USceneComponent>(TEXT("VROrigin"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SelfCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("SelfCamera"));
	WidgetCaptionDetail = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetCaption"));
	PlayerParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PlayerParticle"));
	PlayerAcc = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlayerAcc"));

	RootComponent = RootScene;
	StaticMeshComponent->SetupAttachment(VROrigin);
	VROrigin->SetupAttachment(GetRootComponent());
	Camera->SetupAttachment(VROrigin);
	SpringArmComponent->SetupAttachment(VROrigin);
	SelfCamera->SetupAttachment(SpringArmComponent);
	WidgetCaptionDetail->SetupAttachment(RootScene);
	PlayerParticle->SetupAttachment(RootScene);
	PlayerAcc->SetupAttachment(RootScene);
}

// Called when the game starts or when spawned
void AMetaPlayer::BeginPlay()
{
	Super::BeginPlay();
	CustomActFnc = GetCustomPlayerFnc(); // 커스텀 Function Spawn
	GetPlayerInfo(); // 저장된 커스텀 정보 가져오기
}

ACustomPlayerFnc* AMetaPlayer::GetCustomPlayerFnc()
{
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	if(CustomPlayerFnc)
	{
		return GetWorld()->SpawnActor<ACustomPlayerFnc>(CustomPlayerFnc, FVector(0.f), FRotator(0.f), Params);		
	}
	return nullptr;
}

void AMetaPlayer::GetPlayerInfo()
{
	AMetaGameModeBase* GameMode = Cast<AMetaGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if(GameMode)
	{
		PlayerName = GameMode->LoadPlayerName();
		GetPlayerInfoToDB(); // DB에서 정보 가져와서 변수에 SET
	 	GameMode->DeleteGame(); // 저장 슬롯 제거
	}
}

void AMetaPlayer::CallPlayerHeadCustom(int Index)
{
	if(Index>4) return;
	if(CustomPlayerFnc && CustomActFnc)
	{
		PlayerAcc->SetStaticMesh(CustomActFnc->PlayerHeadCustom(Index));
	}
}

void AMetaPlayer::CallPlayerFaceCustom(int Index)
{
	UMaterialInstance* MaterialInstance = CustomActFnc->PlayerFaceCustom(Index);
	CustomMaterial(Index, 2, MaterialInstance);
}

void AMetaPlayer::CallPlayerColorCustom(int Index)
{
	UMaterialInstance* MaterialInstance = CustomActFnc->PlayerColorCustom(Index);
	CustomMaterial(Index, 0, MaterialInstance);
}

void AMetaPlayer::PlayerParticleCustom(int Index)
{
	if(Index>4) return;
	if(CustomPlayerFnc && CustomActFnc)
	{
		PlayerParticle->SetTemplate(CustomActFnc->PlayerParticleCustom(Index));
		PlayerParticle->SetRelativeScale3D(FVector(4.f));		
	}
}

void AMetaPlayer::CustomMaterial(int Index, int ElementIndex, UMaterialInstance* MatIns)
{
	if(Index>4) return;
	if(CustomPlayerFnc && CustomActFnc)
	{
		UMaterialInstanceDynamic* DynamicMaterialInstance = UMaterialInstanceDynamic::Create(MatIns, this);
		StaticMeshComponent->SetMaterial(ElementIndex, DynamicMaterialInstance);
	}
}