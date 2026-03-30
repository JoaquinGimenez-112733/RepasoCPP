#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemBueno.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FonItemBuenoRecolectado, AItemBueno*, ItemRecolectado);

UCLASS(Blueprintable, BlueprintType)
class REPASOCPP_API AItemBueno : public AItemBase
{
GENERATED_BODY()
	
	public:
	AItemBueno();
	
	UPROPERTY(BlueprintAssignable, Category="Eventos")
	FonItemBuenoRecolectado OnItemBuenoRecolectado;
	
	virtual void AplicarEfecto_Implementation(AActor* Interactor) override;
	
};
