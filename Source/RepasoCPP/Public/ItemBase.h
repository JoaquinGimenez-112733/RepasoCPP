// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "ItemBase.generated.h"

class UStaticMeshComponent;

UCLASS(Blueprintable, BlueprintType)
class REPASOCPP_API AItemBase : public AActor, public IInteractInterface	
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item")
	UStaticMeshComponent* Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	int32 ValorPuntos = 10;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
	bool bDestruirAlInteractuar = true;
	
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Item")
	void AplicarEfecto(AActor* Interactor);

	virtual void AplicarEfecto_Implementation(AActor* Interactor);
	virtual void Interact_Implementation(AActor* Interactor) override;
};
