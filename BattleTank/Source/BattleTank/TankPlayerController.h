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
	
public: 
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void BeginPlay() override;

	// start the tank moving the barrel so that ta shot would hit where 
	// the crosshair intersects the world 
	void AimTowardsCrosshair();

	ATank* GetControlledTank() const; 

	ATank* ControlledTank = nullptr;

private: 
	bool GetSightRayHitLocation(FVector& HitLocation);

};
