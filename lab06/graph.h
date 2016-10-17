#include <vector>
#include <iostream>
using namespace std;

class Node
    {
        public:
        string name_;
        int weight_;
        vector <Node> edges;
        Node();
        Node(string passed_name);
        void addEdge(Node* newEdge);
    };


class Graph
    {
        public:
        Graph();
        void AddVertex(string vertex_name);
        void AddEdge(string source, string target, int weight);
        void addToGraph(string vertex_name, string edge,int weight);
        void ToGraphviz(string file_name);
        Node* SearchGraph(string vertex_name);
        vector <Node> vertices;
    };
