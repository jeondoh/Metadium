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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	/** RootScene */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class USceneComponent* RootScene;
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
	/** 위젯 설명 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class UWidgetComponent* WidgetCaptionDetail;
	/** 파일저장 경로 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Player|Upload", meta=(AllowPrivateAccess=true))
	FString UploadPath;
	/** 파일명 */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Player|Upload", meta=(AllowPrivateAccess=true))
	FString UploadFileName;
	
	
};
