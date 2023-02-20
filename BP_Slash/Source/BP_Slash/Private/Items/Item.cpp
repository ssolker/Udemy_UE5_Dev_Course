// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "BP_Slash/DebugMacros.h"

//Function Macro
#define THIRTY 30
//#define DRAW_SPHERE(Location) if (GetWorld()) DrawDebugSphere(GetWorld(), Location, 25.f, THIRTY, FColor::Red, false, 30.f)

// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlayVS")); //text unicode
	if (GEngine) {
		GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Blue, FString("Onscreen Message VS"));//10.f literal float value
	}

	//43
	UWorld* World = GetWorld();
	if (World) {

		//48 Actor Location, 49 Rotator, similar but use FRotator
		SetActorLocation(FVector(0.f, 0.f, 100.f));

		FVector Location = GetActorLocation();
		//DrawDebugSphere(World, Location, 25.f, THIRTY, FColor::Red, false, 30.f);
		DRAW_SPHERE(Location);
		FVector forward = GetActorForwardVector();
		//DRAW_FORWARD_LINE(Location, Location + forward * 100.f);
		// DrawDebugLine(World, Location, Location + forward * 100.f, FColor::Red, true, -1.f, 0, 1.f);
		//DRAW_POINT(Location + forward * 100.f);
		DRAW_VECTOR(Location, Location + forward * 100.f);
	}
	
}

// Called every frame
//Delta time per second
void AItem::Tick(float DeltaTime)
{
	//Learn about format specifiers in c
	//

	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("DeltaTime %f"), DeltaTime)
	//if (GEngine) {
	// FString message = FString::Printf(TEXT("%f"), DeltaTime);
	// FString Name = GetName();
	// FString message = FString::Printf(TEXT("Name: %s"), *Name); //Asterik provides with c string or array of characters
	//	GEngine->AddOnScreenDebugMessage(1, 10.f, FColor::Blue, FString(message));//10.f literal float value
	//}

	//Movement Rate in cm/s
	float movementRate = 50.f;

	//Movement * DeltaTime (cm/s) * (s/frame) = (cm/frame) so every frame is 1 cm
	//So this will go 50 cm per frame
	AddActorWorldOffset(FVector((movementRate * DeltaTime), 0.f, 0.f));
	DRAW_SPHERE_SingleFrame(GetActorLocation());

}

