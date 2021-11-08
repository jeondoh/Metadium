// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "HttpModule.h"
#include "Components/Image.h"
#include "Interfaces/IHttpRequest.h"
#include "WebImageView.generated.h"

/**
 * 
 */
UCLASS()
class METADIUM_API UWebImageView : public UImage
{
	GENERATED_BODY()

public:
	UWebImageView();
	
	UFUNCTION(BlueprintCallable, Category = "WebImageView")
	void SetImageFromWeb();

	FHttpModule* HttpModule;

private:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WebImageView|Settings", meta=(AllowPrivateAccess=true))
	FString SourceImage;

	void OnHttpRequestFinishedCallback(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};
