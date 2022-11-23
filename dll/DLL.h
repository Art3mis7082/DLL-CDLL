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


#ifndef  DLL_INC
#define  DLL_INC

#include <stdlib.h>
// para malloc and friends y size_t

#include <stdbool.h>
// para bool and friends

#include <assert.h>
// para las aserciones: assert()

#include <stdio.h>
// para fprintf()

#include "defs.h"

typedef struct Node
{
	int datos;

	struct Node* next;
	struct Node* prev;
} Node;

typedef struct
{
	Node* first;
	Node* last;
	Node* cursor;
	size_t len;
} DLL;


DLL* DLL_New();
void DLL_Delete( DLL** this );

int DLL_Front( DLL* this );
int DLL_Back( DLL* this );

void DLL_Push_front( DLL* this, int item );
void DLL_Push_back( DLL* this, int item );
void DLL_Insert( DLL* this, int item );

void DLL_Pop_front( DLL* this );
void DLL_Pop_back( DLL* this );

void DLL_Erase( DLL* this );
void DLL_Remove( DLL* this, int key );

void DLL_MakeEmpty( DLL* this );

bool DLL_Find( DLL* this, int key );

int  DLL_Cursor_Get( DLL* this );
void DLL_Cursor_front( DLL* this );
void DLL_Cursor_back( DLL* this );
void DLL_Cursor_next( DLL* this );
void DLL_Cursor_prev( DLL* this );
bool DLL_Cursor_end( DLL* this );

bool DLL_IsEmpty( DLL* this );
size_t DLL_Len( DLL* this );


void DLL_PrintStructure( DLL* this );

// avanzadas:
void DLL_For_each( DLL* this, void (*p_fn)( int item ) );
Node* DLL_Find_if( DLL* this, bool (*p_fn)( int, int ), int key );
size_t DLL_Remove_if( DLL* this, bool (*cmp)( int x, int y ), int key );


#endif   /* ----- #ifndef DLL_INC  ----- */
