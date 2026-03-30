#pragma once

#include "CoreMinimal.h"
#include "ItemBase.h"
#include "ItemMalo.generated.h"

UCLASS(Blueprintable, BlueprintType)
class REPASOCPP_API AItemMalo : public AItemBase
{
	GENERATED_BODY()
	
public:
	AItemMalo();

	virtual void AplicarEfecto_Implementation(AActor* Interactor) override;
	
};
