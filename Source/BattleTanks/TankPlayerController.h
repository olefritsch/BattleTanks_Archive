// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;

UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* ControlledTank;
	
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	void AimAtCrosshair();

	bool GetCrosshairTraceHit(FVector& HitLocation) const;

	FVector2D GetCrosshairLocation() const;

};
