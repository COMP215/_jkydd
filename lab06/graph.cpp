#include "graph.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

Node::Node()
{
    edges = {};
}
Node::Node(string passed_name)
    {
        name_ = passed_name;
        edges = {};
    }
void Node::addEdges(Node* newEdge)
{
    edges.push_back(*newEdge);
}
Graph::Graph()
{
    vertices = {};
};

void Graph::addToGraph(string vertex, string edge)
{
    if (vertices.size() == 0)
    {
        Node* vertexNode = new Node;
        Node* edgeNode = new Node;
        vertexNode->name_ = vertex;
        edgeNode->name_ = edge;
        vertexNode->edges.push_back(*edgeNode);
        vertices.push_back(*vertexNode);
    }
    else{

        for(int i =0; i<vertices.size();i++)
        {
            if(vertex == vertices[i].name_)
            {
                Node* newEdge = new Node;
                newEdge->name_ = edge;
                vertices[i].edges.push_back(*newEdge);
            }
            else{
                Node* vertexNode = new Node;
                Node* edgeNode = new Node;
                vertexNode->name_ = vertex;
                edgeNode->name_ = edge;
                vertexNode->edges.push_back(*edgeNode);
                vertices.push_back(*vertexNode);
            }
        }
    }
}

void Graph::print_to_file(string file_name)
{
    ofstream outfile;
    outfile.open(file_name);
    outfile << "graph G {" << endl;
    short i = 0;


    for (int i = 0; i < vertices.size(); i++)
    {
        cout << "going in loop 1" << endl;
         //cout << "going in if" << endl;
        if (vertices[i].edges.size() > 0)
        {
            for(int j = 0; j < vertices[i].edges.size(); j++)
            {
                //cout << "going in loop 2" << endl;
                cout << vertices[i].name_ << "--"  << vertices[i].edges[j].name_ << endl;
            }
        }
        // cout << "going in else" << endl;
        //else{
        //      cout << vertices[i].name_ << endl;
        //}
    }
    outfile << "}";
    outfile.close();
}
