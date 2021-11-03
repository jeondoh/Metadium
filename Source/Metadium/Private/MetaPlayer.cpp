// Fill out your copyright notice in the Description page of Project Settings.


#include "MetaPlayer.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AMetaPlayer::AMetaPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("DefaultSceneRoot"));
	VROrigin = CreateDefaultSubobject<USceneComponent>(TEXT("VROrigin"));
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	RootComponent = RootScene;
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());
	VROrigin->SetupAttachment(GetRootComponent());
	SpringArmComponent->SetupAttachment(VROrigin);
	Camera->SetupAttachment(SpringArmComponent);
}

// Called when the game starts or when spawned
void AMetaPlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void AMetaPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}