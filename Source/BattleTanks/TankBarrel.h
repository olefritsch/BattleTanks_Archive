// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward, +1 max upward movement
	void ElevateBarrel(float RelativeSpeed);
	
private:
	UPROPERTY(EditAnywhere)
		float MaxElevationDegrees = 40;

	UPROPERTY(EditAnywhere)
		float MinElevationDegrees = 0;

	UPROPERTY(EditAnywhere)
		float MaxElevationSpeed = 20;
};
