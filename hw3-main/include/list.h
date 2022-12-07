#ifndef _LIST_H
#define _LIST_H

#include <stdio.h>
#include <stdlib.h>

#include "info.h"

typedef enum{ Int, Void, Real, String, Array } returnType;

typedef enum{ Function, Data } dataType;

typedef struct SymbolObj{
    returnType type;
} symbolobj;

typedef struct ArraySymbolObj{
    returnType type;
    symbolobj* data;
    int start;
    int end;
} arraysymbolobj;

typedef struct PassInObj{
    symbolobj* data;
    symbolobj* next;
} passinobj;

typedef struct FuncSymbolObj{
    returnType type;
    symbolobj* passInType;
    int check;
} funcsymbolobj;

typedef struct List{
    dataType nodeType;
    char* id;
    int scope;
    symbolobj* data;
    struct List* next;
    struct List* prev;
} list;

void list_push_back( list*, list* );

list* newdatalist( char*, int, returnType, dataType );

list* newarraylist( char*, int, returnType, dataType );

list* newfunclist( char*, int, returnType, dataType );

void list_printTable( list* );

int checkList( list*, char*, int, dataType );

void listRemove( list*, int );

int GetList( list* , list**, char* );

#endif