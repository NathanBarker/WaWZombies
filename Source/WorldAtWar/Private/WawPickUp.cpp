// Fill out your copyright notice in the Description page of Project Settings.


#include "WawPickUp.h"

#include "WawCharacterBase.h"


// Sets default values for this component's properties
UWawPickUp::UWawPickUp()
{
	PrimaryComponentTick.bCanEverTick = true;
	SphereRadius = 32.f;
}

void UWawPickUp::BeginPlay()
{
	Super::BeginPlay();
	OnComponentBeginOverlap.AddDynamic(this, &UWawPickUp::OnSphereBeginOverlap);
}

void UWawPickUp::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
                                      UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                      const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AWawCharacterBase* Character = Cast<AWawCharacterBase>(OtherActor);
	check(Character)
	
	if (IsValid(Character))
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);
	}
}
