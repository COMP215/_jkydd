#include <vector>
#include <iostream>

using namespace std;


class Vertex
    {
        Vertex(string data_);
        string data_;
        vector<Edge> edges;
    };

class Edge
    {
        Edge();
        Vertex* origin_;
        Vertex* destination_;
    };

class Graph
    {
        Graph();
        vector<Vertex*> vertices;
        addVertex(string data);
        bool IsBipartite();
    };
