// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankPlayerController.h"


// Called when the game starts or when spawned
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	/// Check controlled Tank
	ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}


// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AimAtCrosshair();

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!ControlledTank) return;
	
	FVector HitLocation = FVector(0);
	GetCrosshairTraceHit(HitLocation);
	ControlledTank->AimAt(HitLocation);
}

bool ATankPlayerController::GetCrosshairTraceHit(FVector & HitLocation) const
{
	FVector2D CrosshairLocation = GetCrosshairLocation();
	FHitResult HitResult;
	
	bool bHit = GetHitResultAtScreenPosition(CrosshairLocation, ECollisionChannel::ECC_Visibility, false, HitResult);

	if (bHit) HitLocation = HitResult.Location;
		
	return bHit;
}


FVector2D ATankPlayerController::GetCrosshairLocation() const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	return FVector2D((ViewportSizeX / 2), (ViewportSizeY / 3));
}


