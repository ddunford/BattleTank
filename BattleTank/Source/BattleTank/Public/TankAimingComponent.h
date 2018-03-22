// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

//Enum for aiming state 
UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked
};

// Foward declaration
class UTankBarrel;
class UTankTurret;

// Holds barrels properties and elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UTankBarrel* BarrelToSet);
	void SetTurretReference(UTankTurret* TurretToSet);

	void AimAt(FVector HitLocation, float LaunchSpeed);

private: 
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;

	EFiringStatus FiringStatus = EFiringStatus::Reloading;

	void MoveBarrelTowards(FVector AimDirection);

};
