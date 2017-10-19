// Fill out your copyright notice in the Description page of Project Settings.

#include "ReadStuff.h"
#include "Engine/World.h"
#include "Engine/StaticMeshActor.h"
#include "GameFramework/Actor.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


// Sets default values for this component's properties
UReadStuff::UReadStuff()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UReadStuff::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		InputComponent->BindAction("DoStuff", IE_Pressed, this, &UReadStuff::DoStuff);
	}
}

void UReadStuff :: DoStuff() {
	
	string name, line;
	float x, y, z, r, p, y2;
	ifstream myfile("D:/Ciclo 7/DP2/Pruebas Unreal/TheStuff.txt");

	if (myfile) {
		while ( getline(myfile,line)) {

			name = line;
			getline(myfile, line);
			x = stof(line);
			getline(myfile, line);
			y = stof(line);
			getline(myfile, line);
			z = stof(line);
			getline(myfile, line);
			r = stof(line);
			getline(myfile, line);
			p = stof(line);
			getline(myfile, line);
			y2 = stof(line);
			FString ULine(name.c_str());
			UE_LOG(LogTemp, Warning, TEXT("%s"), *ULine);

			FVector Location(x, y, z);
			FRotator Rotation(r, p, y2);
			FActorSpawnParameters SpawnInfo;
			
			if (CubeBP) {
				GetWorld()->SpawnActor<AStaticMeshActor>(
					CubeBP,
					Location,
					Rotation,
					SpawnInfo
				);
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("BICA"));
			}
			

		}
		myfile.close();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("RIP"));
	}
}

// Called every frame
void UReadStuff::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

