// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerImageChange.h"

#include "MetaPlayer.h"
#include "Components/BoxComponent.h"

// Sets default values
APlayerImageChange::APlayerImageChange()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
}

// Called when the game starts or when spawned
void APlayerImageChange::BeginPlay()
{
	Super::BeginPlay();

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &APlayerImageChange::BoxComponentBeginOverlap);
}

void APlayerImageChange::BoxComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AMetaPlayer* Player = Cast<AMetaPlayer>(OtherActor);
	if(Player)
	{
		
	}
}