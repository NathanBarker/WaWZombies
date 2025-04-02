// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "WawPickUp.generated.h"

class AWawCharacterBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUp, AWawCharacterBase*, PickUpCharacter);

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class WORLDATWAR_API UWawPickUp : public USphereComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UWawPickUp();

	/** Delegate to whom anyone can subscribe to receive this event */
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickUp OnPickUp;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	/** Code for when something overlaps this component */
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	                          UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                          const FHitResult& SweepResult);
};
