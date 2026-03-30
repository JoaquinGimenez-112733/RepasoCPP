#include "ItemMalo.h"
#include "BPC_ComponenteDePuntos.h"

AItemMalo::AItemMalo()
{
	ValorPuntos = 10;
}

void AItemMalo::AplicarEfecto_Implementation(AActor* Interactor)
{
	if (!Interactor) return;
	
	if (UBPC_ComponenteDePuntos* CompPuntos = Interactor->FindComponentByClass<UBPC_ComponenteDePuntos>())
	{
		CompPuntos->RestarPuntos(ValorPuntos);

	}
	
}

