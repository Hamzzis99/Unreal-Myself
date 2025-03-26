// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "UE_MyGameCharacter.h"
#include "UE_MyGamePickUpComponent.generated.h"

// Declaration of the delegate that will be called when someone picks this up
// The character picking this up is the parameter sent with the notification
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUp, AUE_MyGameCharacter*, PickUpCharacter);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE_MYGAME_API UUE_MyGamePickUpComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	
	/** Delegate to whom anyone can subscribe to receive this event */
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickUp OnPickUp;

	UUE_MyGamePickUpComponent();
protected:

	/** Called when the game starts */
	virtual void BeginPlay() override;

	/** Code for when something overlaps this component */
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};