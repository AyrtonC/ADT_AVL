/*=====================================================================

 ADT_AVL, Open Source AVL Abstract Data Type

 (c) 2015 ADT_AVL Authors

 This file is part of the ADT_AVL project

 ADT_AVL is free software: you can redistribute it and/or modify
 it under the terms of the GNU Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 ADT_AVL is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with ADT_AVL. If not, see <http://www.gnu.org/licenses/>.

 ======================================================================*/

#include <stdlib.h>

#ifndef ADTTree_h
#define ADTTree_h

typedef struct tree* ADTTree;

//Initialize the structure.
ADTTree init();

//Dealloc the structure e free whatever it is pointing to. Pass the dealocation function of the structure it's pointing as parameter to allow the job to be done.
ADTTree dealloc(ADTTree tree, void(*freeObj)(void *obj));

//Insert an object on the tree.
ADTTree insertObj(ADTTree tree, void *obj, long ID);

//Remove an object of the tree. Pass the deallocation function of the structure it's pointing as parameter to allow the job to be done.
ADTTree removeObj(ADTTree tree, long ID, void(*freeObj)(void *obj));

//Retrive an object via ID, it can also be used to check if the ID is on the tree. If it's not there, this function returns NULL.
void* retrieveObj(ADTTree tree, long ID);

//Use this function to balance the tree in order to have the maximum performance of the structure. WARNING: This is a very time & memory consuming operation, use wisely.
ADTTree balanceTree(ADTTree tree, long maxHeight);

#endif
