//
//  AVL.c
//  ADT_AVL
//
//  Created by Ayrton Cavalieri on 5/12/14.
//  Copyright (c) 2014 AyrtonC. All rights reserved.
//

#include "AVL.h"

struct tree{
    long ID;
    void *info;
    struct tree *left, *right;
};

struct tree* init(){
    return NULL;
}

struct tree* dealloc(struct tree *tree, void(*freeObj)(void *obj)){
    if(tree != NULL){
        tree->left = dealloc(tree->left, freeObj);
        freeObj(tree->info);
        tree->info = NULL;
        tree->right = dealloc(tree->right, freeObj);
        free(tree);
    }
    return NULL;
}

struct tree* insertObj(struct tree *tree, void *obj, long ID){
    if(tree != NULL){
        if(ID <= tree->ID){
            tree->left = insertObj(tree->left, obj, ID);
        }else{
            tree->right = insertObj(tree->right, obj, ID);
        }
    }else{
        tree = (struct tree*)malloc(sizeof(struct tree));
        if(tree != NULL){
            tree->info = obj;
            tree->ID = ID;
            tree->left = NULL;
            tree->right = NULL;
        }
    }
    return tree;
}

struct tree *removeNode(struct tree *tree, long ID){
    struct tree *aux = NULL;
    if(tree != NULL){
        if(ID < tree->ID){
            tree->left = removeNode(tree->left, ID);
        }else if(ID > tree->ID){
            tree->right = removeNode(tree->right, ID);
        }else{
            if(tree->left == NULL && tree ->right == NULL){
                free(tree);
                return NULL;
            }else if(tree->left == NULL || tree->right == NULL){
                if(tree->left == NULL){
                    aux = tree->right;
                }else{
                    aux = tree->left;
                }
                free(tree);
                return aux;
            }else{
                aux = tree->left;
                while(aux->right != NULL)
                    aux = aux->right;
                tree->ID = aux->ID;
                tree->info = aux->info;
                tree->left = removeNode(tree->left, aux->ID);
                return tree;
            }
        }
    }
    return NULL;
}

struct tree* removeObj(struct tree *tree, long ID, void(*freeObj)(void *obj)){
    void *Obj;
    Obj = retrieveObj(tree, ID);
    if(Obj != NULL){
        freeObj(Obj);
        Obj = NULL;
        tree = removeNode(tree, ID);
    }
    return tree;
}

void* retrieveObj(struct tree *tree, long ID){
    struct tree *p;
    for(p = tree; p != NULL;){
        if(ID < p->ID){
            p = p->left;
        }else if(ID > p->ID){
            p = p->right;
        }else{
            return p->info;
        }
    }
    return NULL;
}

long height(struct tree *tree){
    long hl, hr;
    if(tree == NULL){
        return 0;
    }else{
        hl = height(tree->left);
        hr = height(tree->right);
        return hl >= hr ? 1 + hl : 1 + hr;
    }
}

struct tree* balanceTree(struct tree *tree, long maxHeight){
    long hl, hr, aux1, aux2;
    void *auxp1, *auxp2;
    struct tree *p = NULL;
    if(tree != NULL){
        tree->left = balanceTree(tree->left, maxHeight);
        tree->right = balanceTree(tree->right, maxHeight);
        hl = height(tree->left);
        hr = height(tree->right);
        if(hl - hr > maxHeight){
            p = tree->left;
            while(p->right != NULL)
                p = p->right;
            aux1 = tree->ID;
            auxp1 = tree->info;
            aux2 = p->ID;
            auxp2 = p->info;
            tree->left = removeNode(tree->left, aux2);
            tree->right = insertObj(tree->right, auxp1, aux1);
            tree->ID = aux2;
            tree->info = auxp2;
            tree = balanceTree(tree, maxHeight);
        }else if(hr - hl > maxHeight){
            p = tree->right;
            while(p->left != NULL)
                p = p->left;
            aux1 = tree->ID;
            auxp1 = tree->info;
            aux2 = p->ID;
            auxp2 = p->info;
            tree->right = removeNode(tree->right, aux2);
            tree->left = insertObj(tree->left, auxp1, aux1);
            tree->ID = aux2;
            tree->info = auxp2;
            tree = balanceTree(tree, maxHeight);
        }
    }
    return tree;
}
