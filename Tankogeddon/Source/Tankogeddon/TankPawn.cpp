// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPawn.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include <Camera/CameraComponent.h>

ATankPawn::ATankPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	BodyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body Mesh"));
	BodyMesh -> SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Turret mesh"));
	TurretMesh->SetupAttachment(BodyMesh);

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(BodyMesh);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);


}

void ATankPawn::MoveForward(float value)
{
	TargetForwardAxisValue = value;
}

void ATankPawn::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	FVector ActorLocation = GetActorLocation();
	FVector forwardVector = GetActorForwardVector();
	FVector moveposition = ActorLocation + forwardVector * MoveSpeed * TargetForwardAxisValue * DeltaSeconds;

	SetActorLocation(moveposition, true);
}
