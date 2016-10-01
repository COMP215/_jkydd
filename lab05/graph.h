#include <vector>
#include <iostream>

using namespace std;

class Vertex
    {
        Vertex(string data_);
        string data_;
        vector<Vertex*> edges;
    };

class Graph
    {
        Graph();
        vector<Vertex*> vertices;
        addVertex(string data);
        bool IsBipartite();
    };
