// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankTurret.h"


void UTankTurret::RotateTurret(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

	auto RotationChange = RelativeSpeed * MaxRotateSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewRotation = RelativeRotation.Yaw + RotationChange;

	SetRelativeRotation(FRotator(0, NewRotation, 0));
}

