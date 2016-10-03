#include <vector>
#include <iostream>

using namespace std;

class Vertex
    {
        public:
            string name_;
            Vertex(string name_);
            void addEdge(string destination);
            vector<string> connections;
    };

class Graph
    {
        public:
            Graph();
            void addVertex(string name);
            bool IsBipartite();
            vector<Vertex> vertices;
    };
