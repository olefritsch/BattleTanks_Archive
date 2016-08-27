// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrel.h"


void UTankBarrel::ElevateBarrel(float RelativeSpeed)
{
	float ElevationSpeed = FMath::Clamp(RelativeSpeed, -1.0f, 1.0f);

	auto ElevationChange = ElevationSpeed * MaxElevationSpeed * GetWorld()->DeltaTimeSeconds;
	auto NewElevation = RelativeRotation.Pitch + ElevationChange;

	float ClampedElevation = FMath::Clamp(NewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(ClampedElevation, 0, 0));
}

