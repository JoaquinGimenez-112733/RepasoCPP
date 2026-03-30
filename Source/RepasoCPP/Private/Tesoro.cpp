// Fill out your copyright notice in the Description page of Project Settings.


#include "Tesoro.h"
#include "ItemBueno.h"
#include "EngineUtils.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ATesoro::ATesoro()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
	
}

// Called when the game starts or when spawned
void ATesoro::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	
	TArray<AActor*> ItemsBuenosEncontrados;
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(),AItemBueno::StaticClass(), ItemsBuenosEncontrados);
	CantidadTotalItemBuenos = ItemsBuenosEncontrados.Num();
	
	for (AActor* Actor : ItemsBuenosEncontrados)
	{
		AItemBueno* ItemBueno = Cast<AItemBueno>(Actor);
		if (ItemBueno)
		{
			ItemBueno->OnItemBuenoRecolectado.AddDynamic(this, &ATesoro::OnItemBuenoRecolectado);
		}
	}
	
	if (CantidadTotalItemBuenos == 0)
	{
		ActivarTesoro();
	}
		
}


void ATesoro::OnItemBuenoRecolectado(AItemBueno* ItemRecolectado)
{
	CantidadRecolectada++;
		
	if (CantidadRecolectada >= CantidadTotalItemBuenos)
	{
		ActivarTesoro();
	}
}
	
void ATesoro::ActivarTesoro()
{
	if (bActivado) return;
		
	bActivado = true;
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
		
	UE_LOG(LogTemp, Warning, TEXT("Tesoro Activado"));
}

void ATesoro::DesactivarTesoro()
{
	if (!bActivado) return;
		
	bActivado = false;
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
		
	UE_LOG(LogTemp, Warning, TEXT("Tesoro Desactivado"));
}
	
void ATesoro::Interact_Implementation(AActor* Interactor)
{
	if (!bActivado) return;
	DesactivarTesoro();
	GetWorldTimerManager().SetTimer(TimerHandle_SpawnItem, this, &ATesoro::SpawnNuevoItem, TiempoDeEspera, false);
		
}
	
void ATesoro::SpawnNuevoItem()
{
	if (!ItemASpawnear) return;
		
	FVector SpawnLocation = GetActorLocation() + OffsetSpawn;
		
	FRotator SpawnRotation = FRotator::ZeroRotator;
	GetWorld()->SpawnActor<AActor>(ItemASpawnear, GetActorLocation(), SpawnRotation);
		
	UE_LOG(LogTemp, Warning, TEXT("Nuevo Item Spawneado por Tesoro"));
}


