// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation();

	FString Name = GetName();

	UE_LOG(LogTemp, Display, TEXT("BeginPlay: %s"), *Name); //콘솔에 로그메시지를 남게 하는건가? *역참조를 사용해야함.
	

}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}




void AMovingPlatform::MovePlatform(float DeltaTime)
{
		// 위치까지 멀리 가게 됐다면 다시 되돌아오게 하자자
		// MovedDistance 100까지 이동을 하겠다고 얘기를 했는데?
	if (ShouldPlatformReturn())
		{
			FVector MoveDirection = PlatformVelocity.GetSafeNormal();
			StartLocation = StartLocation + MoveDirection * MoveDistance;
			SetActorLocation(StartLocation);
			PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();
		CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime); 
		SetActorLocation(CurrentLocation);
	
	}
}


void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}


float AMovingPlatform::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}