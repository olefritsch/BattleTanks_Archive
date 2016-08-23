// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	///Check controlled Tank
	ATank* ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a Tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *(ControlledTank->GetName()));
	}
}

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
	if (!GetControlledTank()) return;
	
	FString ObjectHit = "";
	FVector HitLocation = FVector(0);

	GetCrosshairTraceHit(ObjectHit, HitLocation);

	UE_LOG(LogTemp, Warning, TEXT("ObjectHit: %s | HitLocation: %s"), *ObjectHit, *(HitLocation.ToString()));

}

bool ATankPlayerController::GetCrosshairTraceHit(FString& ObjectHit, FVector & HitLocation) const
{
	FVector2D CrosshairLocation = GetCrosshairLocation();
	FHitResult HitResult;
	
	bool bHit = GetHitResultAtScreenPosition(CrosshairLocation, ECollisionChannel::ECC_Visibility, false, HitResult);

	if (bHit)
	{
		ObjectHit = HitResult.GetActor()->GetName();
		HitLocation = HitResult.Location;
	}

	return bHit;
}


FVector2D ATankPlayerController::GetCrosshairLocation() const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	return FVector2D((ViewportSizeX / 2), (ViewportSizeY / 3));
}


