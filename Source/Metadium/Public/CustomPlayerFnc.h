// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CustomPlayerFnc.generated.h"

/**
 * 
 */
UCLASS()
class METADIUM_API ACustomPlayerFnc : public AActor
{
	GENERATED_BODY()

public:
	/** 캐릭터 머리 커스텀 */
	UFUNCTION(BlueprintCallable)
	UStaticMesh* PlayerHeadCustom(int Index);
	/** 캐릭터 얼굴 커스텀 */
	UFUNCTION(BlueprintCallable)
	UMaterialInstance* PlayerFaceCustom(int Index);
	/** 캐릭터 색 커스텀 */
	UFUNCTION(BlueprintCallable)
	UMaterialInstance* PlayerColorCustom(int Index);
	/** 캐릭터 파티클 커스텀 */
	UFUNCTION(BlueprintCallable)
	UParticleSystem* PlayerParticleCustom(int Index);
	
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomArr", meta=(AllowPrivateAccess=true))
	TArray<UMaterialInstance*> FaceArr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomArr", meta=(AllowPrivateAccess=true))
	TArray<UMaterialInstance*> BodyArr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomArr", meta=(AllowPrivateAccess=true))
	TArray<UParticleSystem*> ParticleArr;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="CustomArr", meta=(AllowPrivateAccess=true))
	TArray<UStaticMesh*> HeadAccArr;
};
