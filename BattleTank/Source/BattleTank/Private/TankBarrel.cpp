// Fill out your copyright notice in the Description page of Project Settings.


#include "TankBarrel.h"
#include "BattleTank.h"
#include "Math/UnrealMathUtility.h"

void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the right amoutn this frame 
	// Given a max elevation speed, and the frame time
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	auto Clamp = FMath::Clamp(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);
	SetRelativeRotation(
		FRotator(
			Clamp,
			0, 
			0
		)
	);

}