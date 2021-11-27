// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomActor.h"

#include "CustomPlayerFnc.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ACustomActor::ACustomActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	HeadAcc = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HeadAcc"));
	PlayerParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PlayerParticle"));

	RootComponent = RootSceneComponent;
	StaticMeshComponent->SetupAttachment(GetRootComponent());
	HeadAcc->SetupAttachment(GetRootComponent());
	PlayerParticle->SetupAttachment(GetRootComponent());
	// 캐릭터 커스텀 값 Index 기본지정
	UserAcc = TEXT("0");
	UserPhoto = TEXT("0");
	UserColor = TEXT("0");
	UserParticle = TEXT("0");
}

// Called when the game starts or when spawned
void ACustomActor::BeginPlay()
{
	Super::BeginPlay();
	// 커스텀 Function Spawn
	CustomActFnc = GetCustomPlayerFnc();
}

ACustomPlayerFnc* ACustomActor::GetCustomPlayerFnc() const
{
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	if(CustomPlayerFnc)
	{
		return GetWorld()->SpawnActor<ACustomPlayerFnc>(CustomPlayerFnc, FVector(0.f), FRotator(0.f), Params);		
	}
	return nullptr;
}

void ACustomActor::CallPlayerHeadCustom(int Index)
{
	if(Index>4) return;
	if(CustomPlayerFnc && CustomActFnc)
	{
		UserAcc = FString::FromInt(Index);
		HeadAcc->SetStaticMesh(CustomActFnc->PlayerHeadCustom(Index));
	}
}

void ACustomActor::CallPlayerFaceCustom(int Index)
{
	UserPhoto = FString::FromInt(Index);
	UMaterialInstance* MaterialInstance = CustomActFnc->PlayerFaceCustom(Index);
	CustomMaterial(Index, 2, MaterialInstance);
}

void ACustomActor::CallPlayerColorCustom(int Index)
{
	UserColor = FString::FromInt(Index);
	UMaterialInstance* MaterialInstance = CustomActFnc->PlayerColorCustom(Index);
	CustomMaterial(Index, 0, MaterialInstance);
}

void ACustomActor::CallPlayerParticleCustom(int Index)
{
	if(Index>4) return;
	if(CustomPlayerFnc && CustomActFnc)
	{
		UserParticle = FString::FromInt(Index);
		PlayerParticle->SetTemplate(CustomActFnc->PlayerParticleCustom(Index));
		PlayerParticle->SetRelativeScale3D(FVector(4.f));		
	}
}

void ACustomActor::CustomMaterial(int Index, int ElementIndex, UMaterialInstance* MatIns)
{
	if(Index>4) return;
	if(CustomPlayerFnc && CustomActFnc)
	{
		UMaterialInstanceDynamic* DynamicMaterialInstance = UMaterialInstanceDynamic::Create(MatIns, this);
		StaticMeshComponent->SetMaterial(ElementIndex, DynamicMaterialInstance);
	}
}
