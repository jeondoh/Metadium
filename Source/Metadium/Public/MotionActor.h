// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MotionActor.generated.h"

UCLASS()
class METADIUM_API AMotionActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMotionActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Player", meta=(AllowPrivateAccess=true))
	AActor* AttachedActor;

public:
	FORCEINLINE AActor* GetAttachedActor() const {return AttachedActor;}

};
