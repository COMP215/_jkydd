#include "graph.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

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

void Node::addEdge(Edge* new_edge)
{
    edges.push_back(*new_edge);
}

bool sortByWeight(const Edge &lhs, const Edge &rhs)
{
    return lhs.weight_ < rhs.weight_;
}

Graph::Graph()
{
    vertices = {};
};

Edge::Edge(string source,string target,int weight)
{
    source_ = source;
    target_ = target;
    weight_ = weight;
}
void Graph::AddVertex(string vertex_name)
{
    Node* vertexNode = new Node;
    vertexNode->name_ = vertex_name;
    vertices.push_back(*vertexNode);
    open.push_back(*vertexNode);
    //justVertices.push_back(*vertexNode);
}

void Graph::AddEdge(string source, string target, int weight)
{
    Edge* newEdge = new Edge(source,target,weight);
    vertices[SearchGraph(source)].edges.push_back(*newEdge);
    allEdges.push_back(*newEdge);
    open[SearchGraph(source)].edges.push_back(*newEdge);
}

/*void Graph::addToGraph(string vertex_name, string edge, int weight)
{
    if (vertices.size() == 0)//graph is empty
    {
        Node* vertexNode = new Node;
        Node* edgeNode = new Node;
        vertexNode->name_ = vertex_name;
        edgeNode->name_ = edge;
        edgeNode->weight_ = weight;
        edgeNode->sourceNode = vertex_name;
        vertexNode->edges.push_back(*edgeNode);
        vertices.push_back(*vertexNode);
    }else{
        for(int i = 0; i<vertices.size();i++)//check if vertex is in graph
        {
            cout<<vertices[i].name_ << endl;
            if(vertex_name == vertices[i].name_)//vertex already exists
            {
                Node* newEdge = new Node;
                newEdge->name_ = edge;
                vertices[i].edges.push_back(*newEdge);
                newEdge->weight_ = weight;
            }
            else if (i==vertices.size()-1)//vertex does not exist
            {
                Node* vertexNode = new Node;
                Node* edgeNode = new Node;
                vertexNode->name_ = vertex_name;
                edgeNode->name_ = edge;
                vertexNode->edges.push_back(*edgeNode);
                vertices.push_back(*vertexNode);
                edgeNode->weight_ = weight;
            }
        }
    }
}*/


void Graph::ToGraphviz(string file_name)
{
    ofstream outfile;
    outfile.open(file_name);
    outfile << "graph G {" << endl;
    for (int i = 0; i < vertices.size(); i++)
    {
        for(int j = 0; j < vertices[i].edges.size(); j++)
        {
            cout << vertices[i].name_ << "--"  << vertices[i].edges[j].target_ << " [label=\"" << vertices[i].edges[j].weight_ << "\"]" <<endl;
            outfile << vertices[i].name_ << "--"  << vertices[i].edges[j].target_ << " " << vertices[i].edges[j].weight_ << endl;
        }
    }
    outfile << "}";
    outfile.close();
}

/*void Graph::MSTToGraphviz(string file_name)
{
    ofstream outfile;
    outfile.open(file_name);
    outfile << "graph G {" << endl;
    for (int i = 0; i < justVertices.size(); i++)
    {
        for(int j = 0; j < justVertices[i].edges.size(); j++)
        {
            cout << justVertices[i].name_ << "--"  << justVertices[i].edges[j].target_ << " [label=\"" << justVertices[i].edges[j].weight_ <<"\"]" << endl;
            outfile << justVertices[i].name_ << "--"  << justVertices[i].edges[j].target_ << " [label=\"" << justVertices[i].edges[j].weight_ <<"\"]" << endl;
        }
    }
    outfile << "}";
    outfile.close();
}*/

int Graph::SearchGraph(string vertex_name)
{
    for(int i = 0; i<vertices.size(); i++)
        {
            if(vertex_name == vertices[i].name_)
            {
                return i;
            }
        }
}

Node* Graph::SearchGraphNode(string vertex_name)
{
    for(int i = 0; i<vertices.size(); i++)
        {
            if(vertex_name == vertices[i].name_)
            {
                return Node* vertices[i];
            }
        }
}

bool Graph::SearchGraphBool(string vertex_name)
{
    for(int i = 0; i<usedVertices.size(); i++)
        {
            if(vertex_name == usedVertices[i].name_)
            {
                return true;
            }
        }
    return false;
}

void Graph::isBipartite()
{
    while(!open.empty())
    {
        if (open.empty())
    }

}

void Graph::PrimMST()
{
    int i = 0;
    //start at a node
    while(!open.empty())
    {
        int i++;
        closed.push_back(open[i]);//add vertex to closed list
        Edge* smallestedge = open[i].edges.end();//find smallest edge
        for (int y = 0; y<open[i].edges.size(); y++)
        {
            if (open[i].edges[y].weight_ < smallestedge.weight_)
                smallestedge = open[i].edges[y];
        }
        if (!searchclosed(smallestedge.target_));//if node is not already on closed list
        closed[i].edges.push_back(smallestedge);//add smallest edge to vertex in closed list
        closed.push_back(SearchGraphNode(closed[i].edges[0].target_));//find end of edge and add to closed list
        open.erase(open[i]); //delete first edge
        open.erase((SearchGraph(closed[i].edges[0].target_));
    }
    //list all connections
    //closed list = c
    //open list = s,a,b  d
    //sort closed list
    //add smallest edge to mst
    //edge connects to a so add a to closed list
    //move to a in closed list
    //look through all edges connected to a--c except a--c and add smallest edge to mst and end of edge to closed list
}

/*void Graph::KruskalMST()
{
    //create justVertices with no edges
    //cout << allEdges[0].weight_ << endl;
    sort(allEdges.begin(), allEdges.end(), sortByWeight);//sort allEdges
    //find smallest edge in allEdges
    for (int i = 0; i < allEdges.size(); i++)//LOOP allEdges
    {
        usedVertices.push_back(justVertices[i]);//create list of used vertices
        if (SearchGraphBool(justVertices[i].name_))//check if edge forms a cycle by checking current vertex vs used vertices
        {
            justVertices[i].edges.push_back(allEdges[i]);//add smallest edge to justVertices
        }
        //num of edges = num of vertices -1
    }

}*/

/*void Graph::Dihjstras
{
    //open list:
    //closed list:

    //assign total path cost of infinity to each vertex
    //update start vertex path cost to 0
    //while open is not empty
        //find vertex with smallest total path cost in open
        //look at all edges incident on smallest vertex and update graph
        //move smallest vertex found from open list to closed

}*/
