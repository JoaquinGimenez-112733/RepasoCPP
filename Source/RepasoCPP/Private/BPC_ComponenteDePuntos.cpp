// Fill out your copyright notice in the Description page of Project Settings.


#include "BPC_ComponenteDePuntos.h"

// Sets default values for this component's properties
UBPC_ComponenteDePuntos::UBPC_ComponenteDePuntos()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UBPC_ComponenteDePuntos::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UBPC_ComponenteDePuntos::SumarPuntos(int32 Cantidad)
{
	Puntos += Cantidad;
	UE_LOG(LogTemp, Warning, TEXT("Puntos Actuales: %d"), Puntos)
}

void UBPC_ComponenteDePuntos::RestarPuntos(int32 Cantidad)
{
	Puntos -= Cantidad;
	UE_LOG(LogTemp, Warning, TEXT("Puntos Actuales: %d"), Puntos)	
}