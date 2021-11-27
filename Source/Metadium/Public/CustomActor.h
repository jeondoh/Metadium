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
	/** 커스텀 함수 엑터 */
	UPROPERTY()
	class ACustomPlayerFnc* CustomActFnc;
	/** 캐릭터 몸 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* StaticMeshComponent;
	/** 캐릭터 머리장식 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* HeadAcc;
	/** 캐릭터 파티클 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	UParticleSystemComponent* PlayerParticle;
	/** 커스텀 캐릭터 */
	UPROPERTY(EditAnywhere, Category="Custom", meta=(AllowPrivateAccess=true))
	TSubclassOf<ACustomPlayerFnc> CustomPlayerFnc;
	/** 캐릭터 커스텀 머리 인덱스(서버저장) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Custom|DB", meta=(AllowPrivateAccess=true))
	FString UserAcc;
	/** 캐릭터 커스텀 얼굴 인덱스(서버저장) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Custom|DB", meta=(AllowPrivateAccess=true))
	FString UserPhoto;
	/** 캐릭터 커스텀 몸색 인덱스(서버저장) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Custom|DB", meta=(AllowPrivateAccess=true))
	FString UserColor;
	/** 캐릭터 커스텀 파티클 인덱스(서버저장) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Custom|DB", meta=(AllowPrivateAccess=true))
	FString UserParticle;

	UFUNCTION()
	class ACustomPlayerFnc* GetCustomPlayerFnc() const;
	UFUNCTION(BlueprintCallable)
	void CallPlayerHeadCustom(int Index);
	UFUNCTION(BlueprintCallable)
	void CallPlayerFaceCustom(int Index);
	UFUNCTION(BlueprintCallable)
	void CallPlayerColorCustom(int Index);
	UFUNCTION(BlueprintCallable)
	void CallPlayerParticleCustom(int Index);
	UFUNCTION()
	void CustomMaterial(int Index, int ElementIndex, UMaterialInstance* MatIns);

};
