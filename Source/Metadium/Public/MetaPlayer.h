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
	/*******************************************************************************************************/
	// 컴포넌트
	
	/** RootScene */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class USceneComponent* RootScene;
	/** VROrigin */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class USceneComponent* VROrigin;
	/** SkeletalMesh */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	USkeletalMeshComponent* SkeletalMeshComponent;
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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class USpringArmComponent* SpringArmComponent;
	/** Camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Player|Components", meta=(AllowPrivateAccess=true))
	class UCameraComponent* Camera;
	
	/*******************************************************************************************************/
	
};
