//
//  AVL.h
//  ADT_AVL
//
//  Created by Ayrton Cavalieri on 5/12/14.
//  Copyright (c) 2014 AyrtonC. All rights reserved.
//

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
