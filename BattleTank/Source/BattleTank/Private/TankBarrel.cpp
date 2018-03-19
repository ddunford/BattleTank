// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float DegreesPerSecond)
{
	// Move the barrel the right amoutn this frame 
	// Given a max elevation speed, and the frame time

	UE_LOG(LogTemp, Warning, TEXT("ElevateBarrel at speed %f"), DegreesPerSecond);
}