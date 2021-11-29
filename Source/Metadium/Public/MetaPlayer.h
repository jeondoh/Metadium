// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MetaPlayer.generated.h"

UCLASS()
class METADIUM_API AMetaPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMetaPlayer();

	/** DB에서 커스텀 정보 가져와서 캐릭터 커스텀 */
	UFUNCTION(BlueprintImplementableEvent)
	void GetPlayerInfoToDB();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	/** RootScene */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta = (AllowPrivateAccess = true))
	class UBoxComponent* RootScene;
	/** VROrigin */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class USceneComponent* VROrigin;
	/** StaticMesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta = (AllowPrivateAccess = true))
	class UStaticMeshComponent* StaticMeshComponent;
	/** VR 왼손 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Player|Components", meta=(AllowPrivateAccess=true))
	class AMotionActor* LeftController;
	/** VR 오른손 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Player|Components", meta=(AllowPrivateAccess=true))
	class AMotionActor* RightController;
	/** VR Widget Interaction 왼손 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player|Components", meta = (AllowPrivateAccess = true))
	class UWidgetInteractionComponent* WidgetCompLeft;
	/** VR Widget Interaction 오른손 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player|Components", meta = (AllowPrivateAccess = true))
	class UWidgetInteractionComponent* WidgetCompRight;
	/** Spring Arm */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class USpringArmComponent* SpringArmComponent;
	/** SelfieCamera */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Player|Components", meta = (AllowPrivateAccess = true))
	class UCameraComponent* SelfCamera;
	/** Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class UCameraComponent* Camera;
	/** 캐릭터 파티클 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	UParticleSystemComponent* PlayerParticle;
	/** 캐릭터 머리띠 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	UStaticMeshComponent* PlayerAcc;
	/** 위젯 설명 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class UWidgetComponent* WidgetCaptionDetail;
	/** 파일저장 경로 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Player|Upload", meta=(AllowPrivateAccess=true))
	FString UploadPath;
	/** 파일명 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Player|Upload", meta=(AllowPrivateAccess=true))
	FString UploadFileName;

	// *********************************************************************************************************** //

	/** 캐릭터명 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Player|Info", meta=(AllowPrivateAccess=true))
	FString PlayerName;
	/** 캐릭터 이메일 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Player|Info", meta=(AllowPrivateAccess=true))
	FString PlayerEmail;

	// *********************************************************************************************************** //

	/** 커스텀 캐릭터 */
	UPROPERTY(EditAnywhere, Category="Custom", meta=(AllowPrivateAccess=true))
	TSubclassOf<class ACustomPlayerFnc> CustomPlayerFnc;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Custom", meta=(AllowPrivateAccess=true))
	class ACustomPlayerFnc* CustomActFnc;
	/** 커스텀 인덱스 저장 Array */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Custom", meta=(AllowPrivateAccess=true))
	TArray<int> CustomIndex;
	/** GamePlay에 저장되어있는 캐릭터명 가져오기 */
	UFUNCTION(BlueprintCallable)
	void GetPlayerInfo();
	UFUNCTION()
	ACustomPlayerFnc* GetCustomPlayerFnc();
	/** 커스텀 */
	UFUNCTION(BlueprintCallable)
	void CallPlayerHeadCustom(int Index);
	UFUNCTION(BlueprintCallable)
	void CallPlayerFaceCustom(int Index);
	UFUNCTION(BlueprintCallable)
	void CallPlayerColorCustom(int Index);
	UFUNCTION(BlueprintCallable)
	void PlayerParticleCustom(int Index);
	UFUNCTION()
	void CustomMaterial(int Index, int ElementIndex, UMaterialInstance* MatIns);
};
