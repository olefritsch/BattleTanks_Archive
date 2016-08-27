// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankTurret;
class UTankBarrel;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetTurretReference(UTankTurret* Turret);

	void SetBarrelReference(UTankBarrel* Barrel);

	void AimAt(FVector WorldSpaceLocation, float LaunchSpeed);
	
private:
	UTankTurret* Turret;
	UTankBarrel* Barrel;

	void RotateTurretToward(FVector AimDirection);

	void MoveBarrelToward(FVector AimDirection);

};
