// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	// start the tank moving the barrel so that ta shot would hit where 
	// the crosshair intersects the world 
	void AimTowardsCrosshair();

	ATank* GetControlledTank() const; 

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	ATank* ControlledTank = nullptr;

	bool GetSightRayHitLocation(FVector& HitLocation);

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

};
