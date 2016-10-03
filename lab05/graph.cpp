#include "graph.h"
#include <vector>
#include <iostream>

using namespace std;
Vertex::Vertex(string data)
{
    name_ = data;
};

void Vertex::addEdge(string destination)
{
    connections.push_back(destination);
}
Graph::Graph()
    {

    };

void Graph::addVertex(string name)
{
    vertices.push_back(Vertex(name));
}

bool Graph::IsBipartite();
{
    i = 0;
    for (i;i < vertices.size(); i++)
        if vertices[i].connections.size() > 1{
            bipartite1.push_back(vertices[i]);
        }else{
            bipartite2.push_back(vertices[i]);
        }
}
