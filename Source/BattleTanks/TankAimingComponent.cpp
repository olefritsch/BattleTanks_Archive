// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankTurret.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UTankAimingComponent::SetTurretReference(UTankTurret * Turret)
{
	this->Turret = Turret;
}


void UTankAimingComponent::SetBarrelReference(UTankBarrel* Barrel)
{
	this->Barrel = Barrel;
}


void UTankAimingComponent::AimAt(FVector WorldSpaceLocation, float LaunchSpeed)
{
	if (!Barrel) return;

	FVector LaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("ProjectileStart"));

	if (UGameplayStatics::SuggestProjectileVelocity(this, LaunchVelocity, StartLocation, WorldSpaceLocation, LaunchSpeed, false, 1.0f, 0.0f, ESuggestProjVelocityTraceOption::DoNotTrace))
	{
		FVector LaunchDirection = LaunchVelocity.GetSafeNormal();
		RotateTurretToward(LaunchDirection);
		MoveBarrelToward(LaunchDirection);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%f: Could not find aim"), GetWorld()->GetRealTimeSeconds());
	}
}


void UTankAimingComponent::RotateTurretToward(FVector AimDirection)
{
	FRotator TurretRotator = Turret->GetForwardVector().Rotation();
	FRotator AimRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimRotator - TurretRotator;

	Turret->RotateTurret(DeltaRotator.Yaw);
}


void UTankAimingComponent::MoveBarrelToward(FVector AimDirection)
{
	FRotator BarrelRotator = Barrel->GetForwardVector().Rotation();
	FRotator AimAsRotator = AimDirection.Rotation();
	FRotator DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->ElevateBarrel(DeltaRotator.Pitch);
}

