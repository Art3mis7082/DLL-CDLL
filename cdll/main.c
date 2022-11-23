
#include <stdio.h>
// para printf


#include <stdlib.h>
// para malloc and friends y size_t

#include <stdbool.h>
// para bool and friends

#include "CDLL.h"

#include "defs.h"


void Print( int item )
{
	printf( "%d\n", item );
}

// función predicado:
bool less_than( int list_val, int user_val ){ return list_val < user_val; }




//----------------------------------------------------------------------
//  Driver program
//----------------------------------------------------------------------
int main(void)
{
	CDLL* unaLista = CDLL_New();
	
	
	CDLL_Traverse( unaLista, Print );
	// el nombre de la función es su dirección
	



	CDLL_Delete( &unaLista );
	return 0;
}
