#include <vector>
#include <iostream>
using namespace std;
class Edge
    {
        public:
            string source_;
            string target_;
            int weight_;
            Edge(string source,string target,int weight);
            bool sortByWeight(const Edge &lhs, const Edge &rhs);
    };

class Node
    {
        public:
            string name_;
            vector <Edge> edges;
            Node();
            Node(string passed_name);
            void addEdge(Edge* newEdge);
    };



class Graph
    {
        public:
        Graph();
        int SearchGraph(string vertex_name);
        bool SearchGraphBool(string vertex_name);
        void AddVertex(string vertex_name);
        void AddEdge(string source, string target, int weight);
        void addToGraph(string vertex_name, string edge,int weight);
        void ToGraphviz(string file_name);
        void MSTToGraphviz(string file_name);
        void isBipartite();
        void PrimMST();
        void KruskalMST();
        vector <Node> vertices;
        vector <Node> open;
        vector <Node> closed;
        vector <Edge> allEdges;
    };
