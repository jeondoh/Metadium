// Fill out your copyright notice in the Description page of Project Settings.


#include "MetaPlayer.h"


#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/WidgetComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AMetaPlayer::AMetaPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
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
	SpringArmComponent->SetupAttachment(StaticMeshComponent);
	SelfCamera->SetupAttachment(SpringArmComponent);
	WidgetCaptionDetail->SetupAttachment(RootScene);
	PlayerParticle->SetupAttachment(RootScene);
	PlayerAcc->SetupAttachment(RootScene);
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
