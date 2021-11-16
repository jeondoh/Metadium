// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"
#include "ImageViewActor.generated.h"

// 데이터 테이블 정의 / 이미지 설정
USTRUCT(BlueprintType)
struct FImageDataTable : public FTableRowBase
{
	GENERATED_BODY()
	/** Blueprint 태그명 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName TagName;
	/** 이미지 URL(NAS경로) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ImageUrl;
	/** 이미지 설명 */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText ImageContext;
};

UCLASS()
class METADIUM_API AImageViewActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AImageViewActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void OnConstruction(const FTransform& Transform) override;

private:
	/** 루트 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	class UWidgetComponent* DefaultSceneRoot;
	/** 위젯 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	class UWidgetComponent* WidgetComponent;
	/** 위젯 설명 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	class UWidgetComponent* WidgetCaption;
	/** 태그명 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	FName ATageName;
	/** 이미지 URL 경로 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess=true))
	FText AImageUrl;
	/** 이미지 설명 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess=true))
	FText AImageContext;
	/** 데이터 테이블 */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="ImgActor|DataTable", meta=(AllowPrivateAccess=true))
	UDataTable* ImageDataTable;
	/** 데이터 테이블 활성화 */
	void SetImageDataTable();
	/** 데이터 테이블 데이터 SET */
	void SetImageDataRow(FImageDataTable* ImgDataRow);
};
