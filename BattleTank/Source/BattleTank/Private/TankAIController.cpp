// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"
#include "Engine/World.h"
#include "TankPlayerController.h"

// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (!ControlledTank) { return; }
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return; }
	auto PlayerTank = Cast<ATank>(PlayerPawn);
	if (!PlayerTank) { return; }

	//TODO move towards the player 

	//Aim towards the player 
	ControlledTank->AimAt(PlayerTank->GetActorLocation());

	//Fire if ready 
	ControlledTank->Fire();

}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

