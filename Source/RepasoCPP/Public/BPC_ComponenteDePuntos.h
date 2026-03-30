// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BPC_ComponenteDePuntos.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class REPASOCPP_API UBPC_ComponenteDePuntos : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UBPC_ComponenteDePuntos();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Puntos")	
	int32 Puntos = 0;
	
	UFUNCTION(BlueprintCallable, Category="Puntos")
	void SumarPuntos(int32 Cantidad);
	
	UFUNCTION(BlueprintCallable, Category="Puntos")
	void RestarPuntos(int32 Cantidad);
	
	UFUNCTION(BlueprintCallable, Category="Puntos")
	int32 GetPuntos() const { return Puntos; }
			
};
