// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerImageChange.h"

#include "ImageViewActor.h"
#include "MetaPlayer.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

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
		if(GalaryPhoto && PlayerPhoto)
		{
			TArray<AActor*> arrOutActors; // 갤러리에 미리 세팅되어 있는 액자들
			TArray<AActor*> arrOutActors2; // Player가 찍은 사진들
			
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), GalaryPhoto, arrOutActors);
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), PlayerPhoto, arrOutActors2);
			const int PlayerPhotoSize = arrOutActors2.Num();

			if(arrOutActors.IsValidIndex(0))
			{
				for(int i=0; i<arrOutActors.Num(); i++)
				{
					AImageViewActor* GalaryActor = dynamic_cast<AImageViewActor*>(arrOutActors[i]);
					if(GalaryActor)
					{
						// 캐릭터가 찍은 사진이 없을 경우 전체 삭제
						if(!arrOutActors2.IsValidIndex(0) || i >= PlayerPhotoSize)
						{
							GalaryActor->Destroy();
							continue;
						}
						const FTransform ImgActorTransform = GalaryActor->GetActorTransform();
						// 캐릭터가 찍은 사진 > 미리 세팅되어 있는 액자에 배치
						AImageViewActor* PlayerActor = dynamic_cast<AImageViewActor*>(arrOutActors2[i]);
						if(PlayerActor)
						{
							PlayerActor->SetActorTransform(ImgActorTransform);
							GalaryActor->Destroy();
						}
					} // end if
				} // end for
			} // end if
		}
		// 마지막 장소 문 열리게
		MovingPhotoZoneBox();
	}
}