#include <stdio.h>
struct edge
{
    int src;
    int dest;
    int wt;
};

// global variable for storing number of vertex and edges
int V, E;

// bellman For Algorithm Implementation
void BellmanFord(struct edge *Edge, int source)
{
    int Infinity = 100000, u, v, w; // Defining the infinity value and some useful variable
    int distance[V];                // Array to store the distance of  each vertex from source

    // making all the distance as Infinity
    for (int i = 0; i < V; i++)
        distance[i] = Infinity;

    // making source as the zero
    distance[source] = 0;

    // printing initial distance array

    // V-1 Iteration for calculating the Distance from Source
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            u = Edge[j].src;
            v = Edge[j].dest;
            w = Edge[j].wt;

            if (distance[u] + w < distance[v])
            {
                distance[v] = distance[u] + w;
            }
        }
    }
    // Checking whether given graph form **negative cycle** or not
    for (int j = 0; j < E; j++)
    {
        u = Edge[j].src;
        v = Edge[j].dest;
        w = Edge[j].wt;
        if (distance[v] > distance[u] + w)
        {
            printf("\n Graph is generated the Negative Cycle\n" 
			"bellman ford algorithm does not work when the graph contains the negative weight cycle.");
            return;
        }
    }

    // printing the calculated minimum distance of each vertex from Source
    printf("\n\t Final Distance\n\n");
    printf("\nVertex\t:\tDistance");
    for (int i = 0; i < V; i++)
        printf("\n%d\t:\t%d", i, distance[i]);
    printf("\n===============================================");
}
void main()
{

    // taking Number of Vertex
    printf("Enter the Number of Vertex : ");
    scanf("%d", &V);

    // taking number of Edge
    printf("Enter the Number of Edge : ");
    scanf("%d", &E);

    struct edge Edge[E]; // defining the array of structure

    // taking each edge
    printf("Enter the Each Edge (give name 1st vertex as 0)");
    printf("\n     Source\tDestination\tWeight\n\n");
    for (int i = 0; i < E; i++)
    {

        printf("Edge %d   ", i + 1);
       
        scanf("%d", &Edge[i].src);
       
        scanf("%d", &Edge[i].dest);
       
        scanf("%d", &Edge[i].wt);
    }
    printf("\n------------------------------------------------------------------------");
   
    BellmanFord(Edge, 0);
}


/*

We iterate over all edges once more.
For each edge (u,v), we check if the condition distance[u] + w < distance[v] is still true.
If it is, this means that even after V−1 iterations, we can still reduce the distance to v, 
which indicates that there’s a negative weight cycle in the graph.

If such a cycle is detected, the algorithm prints a warning that the Bellman-Ford algorithm 
cannot handle negative weight cycles and exits.

Summary
1st Loop: Finds shortest paths by relaxing edges V−1 times.
2nd Loop: Detects if a negative weight cycle exists by checking if any edge can still be relaxed.


*/


/*
Enter the Number of Vertex : 7
Enter the Number of Edge : 10
Enter the Each Edge (give name 1st vertex as 0)
     Source     Destination     Weight

Edge 1   0 1 6
Edge 2   0 2 4
Edge 3   0 3 5
Edge 4   1 4 -1
Edge 5   2 1 -2
Edge 6   2 4 1
Edge 7   3 2 -2
Edge 8   3 5 -1
Edge 9   4 6 3
Edge 10   5 6 3

------------------------------------------------------------------------
         Final Distance


Vertex  :       Distance
0       :       0
1       :       1
2       :       3
3       :       5
4       :       0
5       :       4
6       :       3
===============================================

...Program finished with exit code 0
Press ENTER to exit console.


*/

/*
==============================

NEGATIVE EDGE EXAMPLE 

Enter the Number of Vertex : 4
Enter the Number of Edge : 5
Enter the Each Edge (give name 1st vertex as 0)
     Source     Destination     Weight

Edge 1   0 1 4
Edge 2   0 3 5
Edge 3   1 3 5
Edge 4   2 1 -10
Edge 5   3 2 3

------------------------------------------------------------------------
 Graph is generated the Negative Cycle
bellman ford algorithm does not work when the graph contains the negative weight cycle.

...Program finished with exit code 0
Press ENTER to exit console.

===============================
*/