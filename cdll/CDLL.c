/*Copyright (C) 
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 * 2022 - francisco dot rodriguez at ingenieria dot unam dot edu
 */


#include "CDLL.h"

static Node* new_node( int x )
{
   Node* n = (Node*) malloc( sizeof( Node ) );
   if( n != NULL ){
      n->datos = x;
      n->next = NULL;
      n->prev = NULL;
   }

   return n;
}

// Función auxiliar.
//
// Elimina el nodo apuntado por |pos|. Esta función es utilizada
// por CDLL_Find_if()
//
// Devuelve el nodo a la derecha del nodo recién eliminado.
static Node* erase( CDLL* list, Node* pos )
{

}

/**
 * @brief Crea una lista doblemente enlazada
 *
 * @return Una referencia a la nueva lista
 * @post Una lista existente en el heap
 */
CDLL* CDLL_New()
{
}

/**
 * @brief Destruye una lista.
 *
 * @param this Una lista.
 */
void CDLL_Delete( CDLL** this )
{
}

/**
 * @brief Inserta un elemento a la derecha del cursor
 *
 * @param lista Una referencia a la lista de trabajo
 * @param item El elemento a insertar
 *
 * @post Coloca al cursor en el nuevo nodo
 *
 */
void CDLL_Insert( CDLL* this, int item )
{
}

/**
 * @brief Inserta un elemento en el frente de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void CDLL_Push_front( CDLL* this, int item )
{
}

/**
 * @brief Inserta un elemento en el fondo de la lista.
 *
 * @param this Una lista.
 * @param item El elemento a insertar
 */
void CDLL_Push_back( CDLL* this, int item )
{
   Node* n = new_node( item );
   assert( n );

   if( this->first != NULL ){

      this->last->next = n;
      n->prev = this->last;
      this->last = n;
   } else{
      this->first = this->last = this->cursor = n;
   }
   ++this->len;
}

/**
 * @brief Elimina el elemento al frente de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void CDLL_Pop_front( CDLL* this )
{
}

/**
 * @brief Elimina el elemento al fondo de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void CDLL_Pop_back( CDLL* this )
{
   assert( this->len );
   // ERR: no se puede borrar nada de una lista vacía

   if( this->last != this->first ) // también funciona: if( this->len > 1 ){...}
   { 
      Node* x = this->last->prev;
      free( this->last );
      x->next = NULL;
      this->last = x;
      --this->len;
   } else{
      free( this->last );
      this->first = this->last = this->cursor = NULL;
   }
}

/**
 * @brief Devuelve una copia del valor apuntado por el cursor
 *
 * @param this Una lista
 *
 * @return El valor apuntado por el cursor
 */
int CDLL_Cursor_Get( CDLL* this )
{
}

/**
 * @brief Coloca al cursor al inicio de la lista.
 *
 * @param this Una referencia a la lista de trabajo
 */
void CDLL_Cursor_front( CDLL* this )
{
   this->cursor = this->first;
}

/**
 * @brief Coloca al cursor al final de la lista.
 *
 * @param this Una referencia a la lista de trabajo
 */
void CDLL_Cursor_back( CDLL* this )
{
}

/**
 * @brief Mueve al cursor al siguiente elemento a la derecha.
 *
 * @param this Una lista.
 */
void CDLL_Cursor_next( CDLL* this )
{
}

/**
 * @brief Mueve al cursor al siguiente elemento a la izquierda.
 *
 * @param this Una lista.
 */
void CDLL_Cursor_prev( CDLL* this )
{
   assert( this->cursor != NULL );

   Node* left = this->cursor->prev;
   this->cursor = left;
}

/**
 * @brief Indica si la lista está vacía.
 *
 * @param this Referencia a una lista.
 *
 * @return true si la lista está vacía; false en caso contrario.
 */
bool CDLL_IsEmpty( CDLL* this )
{
   return this->first == NULL;
}

/**
 * @brief Devuelve el número actual de elementos en la lista.
 *
 * @param this Una lista.
 *
 * @return Devuelve el número actual de elementos en la lista.
 */
size_t CDLL_Len( CDLL* this )
{
}

/**
 * @brief Elimina todos los elementos de la lista sin eliminar la lista.
 *
 * @param this Una lista
 */
void CDLL_MakeEmpty( CDLL* this )
{
}

/**
 * @brief Devuelve una copia del elemento en el frente de la lista
 *
 * @param this Una lista
 *
 * @return La copia del elemento en el frente de la lista
 *
 * @pre La lista NO debe estar vacía
 */
int CDLL_Front( CDLL* this )
{
   assert( this->first != NULL );
   // ERR: no se puede leer de una lista vacía

   return this->first->datos;
}

/**
 * @brief Devuelve una copia del elemento en la parte trasera de la lista.
 *
 * @param this Una lista.
 *
 * @return La copia del elemento en la parte trasera de la lista.
 *
 * @pre La lista NO debe estar vacía
 */
int CDLL_Back( CDLL* this )
{
}

/**
 * @brief Elimina el elemento apuntado por el cursor.
 *
 * @param this Una lista.
 *
 */
void CDLL_Erase( CDLL* this )
{
}

/**
 * @brief Elimina el primer nodo que coincida con la llave.
 *
 * @param this Una lista
 * @param key  Valor buscado
 *
 */
void CDLL_Remove( CDLL* this, int key )
{
}

/**
 * @brief Busca un valor en la lista. Si lo encuentra coloca ahí al cursor.
 *
 * @param this Una lista.
 * @param key El valor que se está buscando.
 *
 * @post Si se encontró una coincidencia coloca al cursor en ese nodo; en caso contrario el cursor es NULL.
 *
 * @code
 * if( CDLL_Find( list, x ) )
 * {
 *    y = CDLL_Cursor_Get( list );
 *
 *    // ...
 * }
 * @endcode
 */
bool CDLL_Find( CDLL* this, int key )
{
   for( this->cursor = this->first; 
        this->cursor != NULL; 
        this->cursor = this->cursor->next )
   {
      if( this->cursor->datos == key )
      {
         return true;
      }
   }
   return false;
}

/**
 * @brief Imprime la estructura de la lista. Es para uso de depuración, no es de uso general.
 *
 * @param this Una lista.
 */
void CDLL_PrintStructure( CDLL* this )
{
   if( CDLL_IsEmpty( this ) )
   {
      fprintf( stderr, "Empty list. Nothing to show.\n" );
   } 
   else
   {
      fprintf( stderr, "\nNil->" );

      // usando un for en lugar de while (mi preferido):
      for( Node* it = this->first; it != NULL; it = it->next )
      {
         fprintf( stderr, "(%d)->", it->datos );
      } 
      fprintf( stderr, "Nil\n" );
   }
}


//----------------------------------------------------------------------
//                       Avanzadas: 
//----------------------------------------------------------------------

/**
 * @brief Recorre la lista y hace algo con cada uno de sus elementos
 *
 * @param lista Una lista
 * @param p_fn Función que procesa cada elemento de la lista
 */
void CDLL_For_each( CDLL* this, void (*p_fn)( int item ) )
{
   for( Node* it = this->first; it != NULL; it = it->next )
   {
      p_fn( it->datos );
   }
}

/**
 * @brief Busca si algún valor en la lista cumple con la función predicado
 *
 * @param this Una lista
 * @param p_fn Función predicado. El elemento |y| es proporcionado por el argumento |key|, mientras que el valor |x| se obtiene de la lista. Por ejemplo, si la función quiere saber si el valor de la lista es menor que el valor del usuario (list_val < user_val), entonces la función podría ser: less_than( list_val, user_val), la cual se lee en conjunto: "Si el valor de la lista |list_val| es menor que el valor del usuario |user_val|, entonces devuelve verdadero; en caso contrario devuelve falso"
 * @param key El valor contra el que se está realizando la comparación.
 *
 * @return Un apuntador al nodo donde se haya encontrado la primer coincidencia. Devuelve NULL en caso de no haber encontrado ninguna
 */
Node* CDLL_Find_if( CDLL* this, bool (*cmp)( int, int ), int key )
{
   assert( CDLL_IsEmpty( this ) == false );
   // ERR: no se puede buscar nada en una lista vacía

   Node* it = this->first;
   // |it| es la abreviación de "iterator", o  en español, "iterador"

   while( it != NULL ){

      if( cmp( it->datos, key ) == true ) break;

      it = it->next;
   }

   return it;
}


/**
 * @brief Elimina todos los elementos que den positivo a la función predicado.
 *
 * @param this Una lista.
 * @param cmp Función predicado. El elemento |y| es proporcionado por el argumento |key|, mientras que el valor |x| se obtiene de la lista. Por ejemplo, si la función quiere saber si el valor de la lista es menor que el valor del usuario (list_val < user_val), entonces la función podría ser: less_than( list_val, user_val), la cual se lee en conjunto: "Si el valor de la lista |list_val| es menor que el valor del usuario |user_val|, devuelve verdadero".
 * @param key El valor contra el que se está comparando.
 * @return El número de elementos encontrados y borrados.
 */
size_t CDLL_Remove_if( CDLL* this, bool (*cmp)( int x, int y ), int key )
{
   assert( CDLL_IsEmpty( this ) == false );
   // ERR: no se puede eliminar nada de una lista vacía

   Node* it = this->first;
   // |it| es la abreviación de "iterator", o  en español, "iterador"

   size_t elems = 0;

   while( it != NULL ){

      if( cmp( it->datos, key ) == true ) 
      {
         erase( this, it );
         ++elems;
      }

      it = it->next;
   }

   return elems;
}


