#include <iostream>
#include "graph.h"

using namespace std;

int main()
{
    Graph mygraph;
    mygraph.addToGraph("a","b");
    mygraph.addToGraph("a","c");
    mygraph.addToGraph("d","g");
    mygraph.addToGraph("c","b");
    mygraph.addToGraph("a","g");
    mygraph.AddEdge("a","b",9);
    mygraph.ToGraphviz("graph1.dot");
}
