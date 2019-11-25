// Fill out your copyright notice in the Description page of Project Settings.

#include "vr02_lag_cpp.h"
#include "Cube.h"
#include "ConstructorHelpers.h"

// Sets default values
ACube::ACube()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	rangeMin = 0;
	rangeMax = 500;
	speed = 5;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>
		mesh(TEXT("/Game/Geometry/Meshes/1M_Cube_Chamfer"));
	if (mesh.Succeeded())
	{
		StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh1"));
		StaticMesh->SetStaticMesh(mesh.Object);
	}
	
}


// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float deltaSecond = GetWorld()->GetDeltaSeconds();
	FVector movement = FVector(0, 0, 1);
	FVector cubeLocation = GetActorLocation();
	if (cubeLocation.Z >= rangeMax)
	{
		direction = true;
	}
	else if (cubeLocation.Z <= rangeMin)
	{
		direction = false;
	}
	if (direction)
	{
		movement = movement * deltaSecond * speed * (-1);
	}
	else
	{
		movement = movement * deltaSecond * speed;
	}
	AddActorLocalOffset(movement);


}

