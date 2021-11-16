// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerImageChange.generated.h"

UCLASS()
class METADIUM_API APlayerImageChange : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlayerImageChange();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere, Category="Component", meta=(AllowPrivateAccess=true))
	class UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	TSubclassOf<class AImageViewActor> GalaryPhoto;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Component", meta=(AllowPrivateAccess=true))
	TSubclassOf<class AImageViewActor> PlayerPhoto;
	
	UFUNCTION()
	void BoxComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
