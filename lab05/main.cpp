#include <iostream>
#include "graph.h"
using namespace std;

int main()
{
    Vertex foo("a");
    Vertex noo("b");
    foo.addEdge("b");
    cout << foo.name_ << endl;
    cout << foo.connections[0] << endl;
    Graph mygraph;
    mygraph.addVertex("a");
}
