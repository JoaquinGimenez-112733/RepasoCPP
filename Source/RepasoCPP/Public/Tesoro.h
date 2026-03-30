// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"

#include "Tesoro.generated.h"

class AItemBueno;

UCLASS()
class REPASOCPP_API ATesoro : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATesoro();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, Category="Tesoro")
	TSubclassOf<AActor> ItemASpawnear;
	
	UPROPERTY(EditAnywhere, Category="Tesoro")
	float TiempoDeEspera = 1.0;
	
	UPROPERTY(EditAnywhere, Category="Tesoro")
	FVector OffsetSpawn = FVector(100.f, 0.f, 0.f);
	
	UPROPERTY(BlueprintReadOnly, Category="Tesoro")
	int32 CantidadTotalItemBuenos = 0;
	
	UPROPERTY(BlueprintReadOnly, Category="Tesoro")
	int32 CantidadRecolectada = 0;
	
	UPROPERTY(BlueprintReadOnly, Category="Tesoro")
	bool bActivado = false;
	
	FTimerHandle TimerHandle_SpawnItem;
	
	UFUNCTION()
	void OnItemBuenoRecolectado(AItemBueno* ItemRecolectado);
	
	UFUNCTION()
	void SpawnNuevoItem();
	
	void ActivarTesoro();
	
	void DesactivarTesoro();
	
	virtual void Interact_Implementation(AActor* Interactor) override;
	

};
