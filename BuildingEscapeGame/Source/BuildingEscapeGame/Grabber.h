// Copyright Haydn Murray 2017

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPEGAME_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    // How far ahead of the player can we reach in CM
    float Reach = 100.f;
    
    UPhysicsHandleComponent* PhysicsHandle = nullptr;
    
    UInputComponent* InputComponent = nullptr;
    
    // Ray-cast and grab what's in reach
    void Grab();
    
    // called when grab is released
    void Release();
    
    // Find attached Physics handle
    void FindPhysicsHandleComponent();
    
    // Setup input component
    void SetupInputComponent();
    
    // Return hit for first physics body in reach
    const FHitResult GetFirstPhysicsBodyInReach();
};
