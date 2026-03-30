#include "ItemBueno.h"
#include "BPC_ComponenteDePuntos.h"

AItemBueno::AItemBueno()
{
	ValorPuntos = 10;
}

void AItemBueno::AplicarEfecto_Implementation(AActor* Interactor)
{
	if (!Interactor) return;
	
	if (UBPC_ComponenteDePuntos* CompPuntos = Interactor->FindComponentByClass<UBPC_ComponenteDePuntos>())
	{
		CompPuntos->SumarPuntos(ValorPuntos);

	}
	
	OnItemBuenoRecolectado.Broadcast(this);
	
}

