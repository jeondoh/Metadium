// Fill out your copyright notice in the Description page of Project Settings.


#include "WebImageView.h"

#include "Interfaces/IHttpResponse.h"
#include "Kismet/KismetRenderingLibrary.h"

UWebImageView::UWebImageView()
{
	HttpModule = &FHttpModule::Get();
}

void UWebImageView::SetImageFromWeb()
{
	if(SourceImage==TEXT("") || SourceImage==TEXT("NONE")) return;

	const TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = HttpModule->CreateRequest();
	HttpRequest->SetVerb("GET");
	HttpRequest->SetURL(this->SourceImage);
	HttpRequest->OnProcessRequestComplete().BindUObject(this, &UWebImageView::OnHttpRequestFinishedCallback);
	HttpRequest->ProcessRequest();
}

void UWebImageView::OnHttpRequestFinishedCallback(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful)
{
	UTexture2D* OutputTexture = UKismetRenderingLibrary::ImportBufferAsTexture2D(GetWorld(), Response->GetContent());
	SetBrushFromTexture(OutputTexture);
}