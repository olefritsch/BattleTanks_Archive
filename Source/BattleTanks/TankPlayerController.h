// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5;
	
	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = (1 / 3);


	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	ATank* GetControlledTank() const;

	void AimAtCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;
	

};
