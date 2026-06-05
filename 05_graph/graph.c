#include <stdio.h>
#include "err.h"
#include "graph.h"
#include "lqueue.h"

#define NOT_FOUND 0
#define OPENED 1
#define CLOSED 2

struct GraphRecord{
    int adj[max][max];
    int visited[max];
    int nodes;
};

Graph CreateGraph(int NodesCount){
    Graph G;
    G = malloc(sizeof(struct GraphRecord));
    if(G == NULL) Error( "Out of space!!!" );

    G->nodes = NodesCount;
    return G;
}

void DisposeGraph(Graph G){
    free(G);
}

/* a function to build adjacency matrix of a graph */
void buildadjm(Graph G){
    int i,j;
    for(i=0;i<G->nodes;i++)
        for(j=0;j<G->nodes;j++){
            printf("enter 1 if there is an edge from %d to %d, otherwise enter 0 \n", i,j);
            scanf("%d",&(G->adj[i][j]));
        }
}

void printadjm(Graph G){
    int i,j;
    for(i=0;i<G->nodes;i++){
        for(j=0;j<G->nodes;j++) printf(" %d",G->adj[i][j]);
        putchar('\n');
    }
}

void ClearVisited(Graph G){
    int n;
    for(n=0; n<G->nodes; n++) G->visited[n] = NOT_FOUND;
}

void check_inputs(Graph G, int v0){
    if (!G || G->nodes < 1 || v0 < 0 || v0 >= G->nodes || G->nodes > max) exit(EXIT_FAILURE);

    for (int i = 0; i < G->nodes; ++i) {
        if (!(G->visited[i] == NOT_FOUND ||
              G->visited[i] == OPENED ||
              G->visited[i] == CLOSED))
            exit(EXIT_FAILURE);
        if (G->visited[i] >= G->nodes)
            exit(EXIT_FAILURE);
        for (int j = 0; j < G->nodes; ++j) {
            if (!(G->adj[i][j] == 0 || G->adj[i][j] == 1))
                exit(EXIT_FAILURE);
            if (i == j && G->adj[i][j] == 1)
                exit(EXIT_FAILURE);
        }
    }
}

void dfs(Graph G, int v0){
    check_inputs(G,v0);
    ClearVisited(G);

    dfs2(G,v0);
    for (int v = v0 +1; v < G->nodes; ++v)
        if (G->visited[v] == NOT_FOUND)
            dfs2(G,v);
}

void dfs2(Graph G, int v){
    printf("The node opened: %d\n",v);

    G->visited[v] = OPENED;
    for(int w = 0; w<G->nodes; w++)
        if(G->adj[v][w] == 1 && G->visited[w] == NOT_FOUND)
            dfs2(G,w);
    G->visited[v] = CLOSED;
}

void dfsst(Graph G, int v0) {
    check_inputs(G,v0);
    ClearVisited(G);

    dfsst2(G, v0);
    for (int v = v0 +1; v < G->nodes; v++)
        if (G->visited[v] == NOT_FOUND)
            dfsst2(G, v);
}

void dfsst2(Graph G, int v) {
    G->visited[v] = OPENED;

    for (int w = 0; w < G->nodes; w++)
        if (G->adj[v][w] == 1 && G->visited[w] == NOT_FOUND) {
            printf("Edge: <%d,%d>\n", v, w);
            dfsst2(G, w);
        }

    G->visited[v] = CLOSED;
}

void bfs(Graph G, int v0) {
    check_inputs(G,v0);
    ClearVisited(G);
    LQueue Q = CreateQueue();

    G->visited[v0] = OPENED;
    Enqueue(v0, Q);

    while (!IsEmptyQueue(Q)) {
        int v = FrontAndDequeue(Q);
        printf("The node opened: %d\n",v);

        for (int w = 0; w < G->nodes; w++) {
            if (G->adj[v][w] == 1 && G->visited[w] == NOT_FOUND) {
                Enqueue(w, Q);
                G->visited[w] = OPENED;
            }
        }
        G->visited[v] = CLOSED;
    }

    RemoveQueue(&Q);
}

void bfsst(Graph G, int v0) {
    check_inputs(G,v0);
    ClearVisited(G);
    LQueue Q = CreateQueue();

    for (int i = v0; i < G->nodes; i++){
        if (G->visited[i] != NOT_FOUND) continue;
        Enqueue(i, Q);
        G->visited[i] = OPENED;

        while (!IsEmptyQueue(Q)) {
            int v = FrontAndDequeue(Q);
            G->visited[v] = CLOSED;

            for (int w = 0; w < G->nodes; w++) {
                if (G->adj[v][w] == 1 && G->visited[w] == NOT_FOUND) {
                    Enqueue(w, Q);
                    G->visited[w] = OPENED;
                    printf("Edge: <%d, %d>\n", v, w);
                }
            }
        }
    }
    RemoveQueue(&Q);
}