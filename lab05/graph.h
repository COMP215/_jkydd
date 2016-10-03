#include <vector>
#include <iostream>

using namespace std;

class Edge
{
    Vertex* origin_;
    vertex* destination_;
};

class Vertex
    {
        public:
            string data_;
            Vertex(string);
            vector<Edge> edges;
    };

class Graph
    {
        public:
            Graph();
            void addVertex(string data);
            bool IsBipartite();
            vector<Vertex*> vertices;
    };
