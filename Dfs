
#include <stdio.h>
#include <stdlib.h>
//Node of Adjacency List
struct node
{
    int vertex_no;
    struct node *next_vertex;
};
struct Graph
{
    int total_vertices;
    // A boolean flag
    int *visitedRecord;
    struct node **adjacency_lists;
};
struct node *create(int v)
{
    struct node *new_node = malloc(sizeof(struct node));
    new_node -> vertex_no = v;
    new_node -> next_vertex = NULL;
    return new_node;
};

void edge_graph(struct Graph *graph, int src, int dest)
{
    struct node *new_node = create(dest);
    new_node -> next_vertex = graph -> adjacency_lists[src];
    graph -> adjacency_lists[src] = new_node;
    new_node = create(src);
    new_node -> next_vertex = graph -> adjacency_lists[dest];
    graph -> adjacency_lists[dest] = new_node;
}

struct Graph *create_graph(int vertices)
{
    int i;
    struct Graph *graph = malloc(sizeof(struct Graph));
    graph -> total_vertices = vertices;
    graph -> adjacency_lists = malloc(vertices * sizeof(struct node *));
    graph -> visitedRecord = malloc(vertices * sizeof(int));
    for (i = 0; i < vertices; i++)
    {
        graph -> adjacency_lists[i] = NULL;
        graph -> visitedRecord[i] = 0;
    }
    return graph;
}

void dfs(struct Graph *graph, int vertex_no)
{
    struct node *AL = graph -> adjacency_lists[vertex_no];
    struct node *temp = AL;

    graph -> visitedRecord[vertex_no] = 1;
    printf("%d ", vertex_no);

    while (temp != NULL)
    {
        int connectedVertex = temp -> vertex_no;

        if (graph -> visitedRecord[connectedVertex] == 0)
        {
            dfs(graph, connectedVertex);
        }
        temp = temp -> next_vertex;
    }
}

int main()
{
    int total_vertices, total_edges, i;
    int src, dest;
    int starting_vertex;

    printf("Enter Number of Vertices and Edges in the Graph: ");
    scanf("%d%d", &total_vertices, &total_edges);
    struct Graph *graph = create_graph(total_vertices);

    printf("Add %d Edges of the Graph(Vertex numbering should be from 0 to %d)\n", total_edges, total_vertices - 1);
    for (i = 0; i < total_edges; i++)
    {
        scanf("%d%d", &src, &dest);
        edge_graph(graph, src, dest);
    }

    printf("Enter Starting Vertex for DFS Traversal: ");
    scanf("%d", &starting_vertex);

    if (starting_vertex < total_vertices)
    {
        printf("DFS Traversal: ");
dfs(graph, starting_vertex);
    }
