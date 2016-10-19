#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    Graph mygraph;
    //mygraph.addToGraph("a","b",1);
    //mygraph.addToGraph("a","c",3);
    //mygraph.addToGraph("d","g",8);
    //mygraph.addToGraph("c","b",4);
    //mygraph.addToGraph("a","g",8);
    mygraph.AddVertex("s");
    mygraph.AddVertex("a");
    mygraph.AddVertex("b");
    mygraph.AddVertex("c");
    mygraph.AddVertex("d");
    mygraph.AddEdge("s","a",9);
    mygraph.AddEdge("s","c",5);
    mygraph.AddEdge("a","c",2);
    mygraph.AddEdge("a","b",1);
    mygraph.AddEdge("b","c",9);
    mygraph.AddEdge("b","d",6);
    mygraph.AddEdge("c","d",4);
    mygraph.ToGraphviz("graph1.dot");
    //mygraph.KruskalMST();
    //mygraph.MSTToGraphviz("MSTgraph.dot");
}
