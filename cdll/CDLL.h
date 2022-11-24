
#ifndef  CDLL_INC
#define  CDLL_INC

#include <stdlib.h>
// para malloc and friends y size_t

#include <stdbool.h>
// para bool and friends

#include <assert.h>
// para las aserciones: assert()

#include <stdio.h>
// para fprintf()

#include "defs.h"

typedef struct Song
{
   char nombre;
   char autor;
   int duracion;
}Song;

typedef struct Node
{
	Song* cancion;

	struct Node* next;
	struct Node* prev;
} Node;

typedef struct 
{
	Node* first;
	Node* last;
	Node* cursor;
	size_t len;
} CDLL;


CDLL* CDLL_New();
void CDLL_Delete( CDLL** this );

int CDLL_Front( CDLL* this );
int CDLL_Back( CDLL* this );

void CDLL_Push_front( CDLL* this, int time, char name, char author);
void CDLL_Push_back( CDLL* this, int time, char name, char author );
void CDLL_Insert( CDLL* this, int time, char name, char author );

void CDLL_Pop_front( CDLL* this );
void CDLL_Pop_back( CDLL* this );

void CDLL_Erase( CDLL* this );
void CDLL_Remove( CDLL* this, int key );

void CDLL_MakeEmpty( CDLL* this );

bool CDLL_Find( CDLL* this, int key );

int  CDLL_Cursor_Get( CDLL* this );
void CDLL_Cursor_front( CDLL* this );
void CDLL_Cursor_back( CDLL* this );
void CDLL_Cursor_next( CDLL* this );
void CDLL_Cursor_prev( CDLL* this );
bool CDLL_Cursor_end( CDLL* this );

bool CDLL_IsEmpty( CDLL* this );
size_t CDLL_Len( CDLL* this );


void CDLL_PrintStructure( CDLL* this );

// avanzadas:
void CDLL_For_each( CDLL* this, void (*p_fn)( int time, char name, char author ) );
Node* CDLL_Find_if( CDLL* this, bool (*p_fn)( int, int ), int key );
size_t CDLL_Remove_if( CDLL* this, bool (*cmp)( int x, int y ), int key );


#endif   /* ----- #ifndef CDLL_INC  ----- */

