// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "VideoViewActor.generated.h"

// 데이터 테이블 정의 / 비디오 설정
USTRUCT(BlueprintType)
struct FVideoDataTable : public FTableRowBase
{
	GENERATED_BODY()
	/** Blueprint 태그명 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TagName;
	/** 비디오 URL(NAS경로) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText VideoUrl;
	/** 비디오 설명 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText VideoContext;
};

UCLASS()
class METADIUM_API AVideoViewActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVideoViewActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/** Scene */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	USceneComponent* RootSceneComponent;
	/** Static Mesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* StaticMeshComponent;
	/** MediaSound */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	class UMediaSoundComponent* MediaSound;
	/** Widget Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	class UWidgetComponent* WidgetComponent;
	/** Widget Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	class UWidgetComponent* WidgetCaption;
	/** Box Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	class UBoxComponent* BoxComponent;
	/** 데이터 테이블 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Props|DataTable", meta=(AllowPrivateAccess=true))
	UDataTable* VideoDataTable;
	/** 태그명 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Props|DataTable", meta=(AllowPrivateAccess=true))
	FName ATageName;
	/** Video URL 주소(NAS) */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Props|DataTable", meta=(AllowPrivateAccess=true))
	FText AVideoUrl;
	/** Video 설명 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Props|DataTable", meta=(AllowPrivateAccess=true))
	FText AVideoContext;
	/** 미디어 플레이어 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Props", meta=(AllowPrivateAccess=true))
	class UMediaPlayer* MediaPlayer;
	/** 미디어 텍스쳐 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Props", meta=(AllowPrivateAccess=true))
	class UMediaTexture* MediaTexture;
	/** 데이터 테이블 활성화 */
	UFUNCTION(BlueprintCallable)
	void SetVideoDataTable();
	/** 데이터 테이블 데이터 SET */
	void SetVideoDataRow(FVideoDataTable* VideoDataRow);
};
