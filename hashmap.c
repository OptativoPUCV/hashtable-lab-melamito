#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "hashmap.h"

typedef struct Pair Pair;
typedef struct HashMap HashMap;
int enlarge_called=0;

struct Pair {
     char * key;
     void * value;
};

struct HashMap {
    Pair ** buckets;
    long size; //cantidad de datos/pairs en la tabla
    long capacity; //capacidad de la tabla
    long current; //indice del ultimo dato accedido
};

Pair * createPair( char * key,  void * value) {
    Pair * new = (Pair *)malloc(sizeof(Pair));
    new->key = key;
    new->value = value;
    return new;
}

long hash( char * key, long capacity) {
    unsigned long hash = 0;
     char * ptr;
    for (ptr = key; *ptr != '\0'; ptr++) {
        hash += hash*32 + tolower(*ptr);
    }
    return hash%capacity;
}

int is_equal(void* key1, void* key2){
    if(key1==NULL || key2==NULL) return 0;
    if(strcmp((char*)key1,(char*)key2) == 0) return 1;
    return 0;
}


void insertMap(HashMap * map, char * key, void * value) {
   long idx = hash(key, map->capacity);
    
    while (map->buckets[idx] != NULL && map->buckets[idx]->key != NULL){
        if(is_equal(map->buckets[idx]->key, key) == 1) return; //el dato ya existe
        idx = (idx + 1) % map->capacity;
    }
    
    if (map->buckets[idx] != NULL) {
        map->buckets[idx]->key = key;
        map->buckets[idx]->value = value;
    } else 
        map->buckets[idx] = createPair(key, value);
    
    map->size += 1;
    
    if ((double)map->size/(double)map->capacity > 0.75) enlarge(map);
}


void enlarge(HashMap * map) {
    enlarge_called = 1; //no borrar (testing purposes)


}


HashMap * createMap(long capacity) {
    HashMap * nuevo = (HashMap*) malloc (sizeof(HashMap));
    nuevo->buckets= (Pair**)malloc(capacity*sizeof(Pair*));
    nuevo->size= 0; //cantidad de datos/pairs en la tabla
    nuevo->capacity=capacity; //capacidad de la tabla
    nuevo->current=-1; //indice del ultimo dato accedido
    return nuevo;
}

void eraseMap(HashMap * map,  char * key) {    


}

void * searchMap(HashMap * map,  char * key) {   


    return NULL;
}

void * firstMap(HashMap * map) {

    return NULL;
}

void * nextMap(HashMap * map) {

    return NULL;
}
