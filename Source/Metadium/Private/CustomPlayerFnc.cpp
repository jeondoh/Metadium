// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomPlayerFnc.h"

UStaticMesh* ACustomPlayerFnc::PlayerHeadCustom(int Index)
{
	return HeadAccArr[Index];
}

UMaterialInstance* ACustomPlayerFnc::PlayerFaceCustom(int Index)
{
	return FaceArr[Index];
}

UMaterialInstance* ACustomPlayerFnc::PlayerColorCustom(int Index)
{
	return BodyArr[Index];
}

UParticleSystem* ACustomPlayerFnc::PlayerParticleCustom(int Index)
{
	return ParticleArr[Index];
}
