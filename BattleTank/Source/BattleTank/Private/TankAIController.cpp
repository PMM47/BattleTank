// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
//#include "Tank.h"

//ATank* ATankAIController::GetControlledTank() const
//{
//	return Cast<ATank> (GetPawn());
//
//}

void ATankAIController::BeginPlay() {

	Super::BeginPlay();

	//ATank* p_ControlledTank = GetControlledTank();

}

//void ATankAIController::Tick(float DeltaTime) {
//	Super::Tick(DeltaTime);
//	
//	if (GetPlayerTank())
//	{
//		// TODO Move towards the player
//
//
//		// Aim towards the player
//		GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
//
//		// Fire if ready
//		// Just fire for now
//		GetControlledTank()->Fire();
//	}
//
//	
//}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();

	if (GetWorld()->GetFirstPlayerController())
	{
		auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
		//ATank* ControlledTank = Cast<ATank>(GetPawn());
		auto ControlledTank = GetPawn();

		if (!ensure(PlayerTank && ControlledTank)) { return; }
		// Move towards the player
		MoveToActor(PlayerTank, AcceptanceRadius); // TODO check radius is in centimeters


		// Aim towards the player
		if (!ensure(AimingComponent)) return;

		//ControlledTank->AimAt(PlayerTank->GetActorLocation());
		AimingComponent->AimAt(PlayerTank->GetActorLocation());

		// Fire if ready
		// Just fire for now

		// TODO Fix Firing
		// ControlledTank->Fire();
		AimingComponent->Fire();
	}


}

//ATank * ATankAIController::GetPlayerTank() const
//{
//	ATank* p_PlayerTank = nullptr;
//
//	if (GetWorld()->GetFirstPlayerController())
//	{
//		p_PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
//		return p_PlayerTank;
//	}
//	else
//	{
//		// UE_LOG(LogTemp, Warning, TEXT("Nullptr, no PlayerController."));
//		return nullptr;
//	}
//	
//}

