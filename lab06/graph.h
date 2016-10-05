#include <vector>
#include <iostream>
using namespace std;

class Node
    {
        public:
        string name_;
        vector <Node> edges;
        Node();
        Node(string passed_name);
        void addEdges(Node* newEdge);
    };


class Graph
    {
        public:
        Graph();
        void addToGraph(string vertex,string edge);
        void print_to_file(string file_name);
        vector <Node> vertices;
    };
