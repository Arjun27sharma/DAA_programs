#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100
#define INF 999999


// structure to represent an edge
struct Edge{
    int src, dest, weight;
};

int parent[MAX_VERTICES];

//find set of an element
int find(int i){
    while (parent[i] != i)
    {
        i = parent[i];
    }
    return i; 
}

//union of two sets
void unionSets(int i, int j){
    int a = find(i);
    int b = find(j);

    parent[a] = b;
}