// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CustomActor.generated.h"

UCLASS()
class METADIUM_API ACustomActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACustomActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/** RootScene Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	USceneComponent* RootSceneComponent;
	/** SkeletalMesh Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	USkeletalMeshComponent* SkeletalMeshComponent;
	/** 캐릭터 사진 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Mat", meta=(AllowPrivateAccess=true))
	UMaterialInstanceDynamic* PlayerPhotoMatInstance;
	/** 캐릭터 색 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Mat", meta=(AllowPrivateAccess=true))
	UMaterialInstanceDynamic* PlayerColorMatInstance;
	/** 캐릭터 파티클 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Mat", meta=(AllowPrivateAccess=true))
	UParticleSystemComponent* PlayerParticle;

};
