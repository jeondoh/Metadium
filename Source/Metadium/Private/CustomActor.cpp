// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomActor.h"

#include "Particles/ParticleSystemComponent.h"

// Sets default values
ACustomActor::ACustomActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	RootSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootSceneComponent"));
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	PlayerParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PlayerParticle"));

	RootComponent = RootSceneComponent;
	SkeletalMeshComponent->SetupAttachment(GetRootComponent());
	PlayerParticle->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void ACustomActor::BeginPlay()
{
	Super::BeginPlay();
	
}


