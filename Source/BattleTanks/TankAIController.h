// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"

#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	ATank* ControlledTank;
	ATank* PlayerTank;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	void AimAtPlayer();

	ATank* GetControlledTank() const;

	ATank* GetPlayerTank() const;
	
	
};
