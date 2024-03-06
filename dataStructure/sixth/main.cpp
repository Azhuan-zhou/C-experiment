#include <iostream>
#include "Dijkstra.h"
int main() {
    Graph myGraph(7);
    myGraph.setEdge(1,2,10);
    myGraph.setEdge(2,1,10);
    myGraph.setEdge(2,4,5);
    myGraph.setEdge(4,2,5);
    myGraph.setEdge(1,4,20);
    myGraph.setEdge(4,1,20);
    myGraph.setEdge(1,6,2);
    myGraph.setEdge(6,1,2);
    myGraph.setEdge(6,4,10);
    myGraph.setEdge(4,6,10);
    myGraph.setEdge(2,3,3);
    myGraph.setEdge(3,2,3);
    myGraph.setEdge(5,6,3);
    myGraph.setEdge(6,5,3);
    myGraph.setEdge(4,5,11);
    myGraph.setEdge(5,4,11);
    myGraph.setEdge(3,5,15);
    myGraph.setEdge(5,3,15);
    djikstra d(myGraph);
    int s = 1;
    d.run(s);
    cout<<"源点："<<s<<endl<<"最短路径";
    for (int i = 2; i < myGraph.n(); ++i) {
        cout<<"源点"<<s<<"到结点"<<i<<"最短路径长度："<<d.minRouteValue(i)<<",路径为：";
        d.printPath(i);
        cout<<endl;
    }
    return 0;
}
