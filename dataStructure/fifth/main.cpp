#include <iostream>
#include "Dijkstra.h"
#include "queue.h"
// Ԥ�ȷ��ʵĺ������������������������������
void PreVisit(Graph *G, int v) {
    cout << "PreVisit vertex " << v << "\n";
}

// �������ʵĺ������������������������������
void PostVisit(Graph *G, int v) {
    cout << "PostVisit vertex " << v << "\n";
}

// ������������㷨
void dfs(Graph *G, int v) {
    PreVisit(G, v);
    G->setMark(v, VISITED);
    for (int w = G->first(v); w < G->n(); w = G->next(v, w))
        if (G->getMark(w) == UNVISITED)
            dfs(G, w);
}

// ������������㷨
void bfs(Graph *G, int start, AQueue<int> *Q) {
    int v, w;
    for (int i = 0; i < G->n(); i++)
        G->setMark(i, UNVISITED);
    Q->enqueue(start);
    G->setMark(start, VISITED);
    while (Q->length() != 0) {
        v = Q->dequeue();
        PreVisit(G, v);
        for (w = G->first(v); w < G->n(); w = G->next(v, w))
            if (G->getMark(w) == UNVISITED) {
                G->setMark(w, VISITED);
                Q->enqueue(w);
            }
    }
}

// ��ӡ����ֵ�ĸ�������
void printout(int v) {
    cout << v << " "<<endl;
}

// ��������ĸ�������
void topHelp(Graph *G, int v) {
    G->setMark(v, VISITED);
    for (int w = G->first(v); w < G->n(); w = G->next(v, w))
        if (G->getMark(w) == UNVISITED)
            topHelp(G, w);
    printout(v);
}

// ���������㷨
void topSort(Graph *G) {
    int i;
    for (i = 0; i < G->n(); i++)
        G->setMark(i, UNVISITED);
    for (i = 0; i < G->n(); i++)
        if (G->getMark(i) == UNVISITED)
            topHelp(G, i);
}

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
    cout<<"Դ�㣺"<<s<<endl<<"���·��";
    for (int i = 2; i < myGraph.n(); ++i) {
        cout<<"Դ��"<<s<<"�����"<<i<<"���·�����ȣ�"<<d.minRouteValue(i)<<",·��Ϊ��";
        d.printPath(i);
        cout<<endl;
    }
    return 0;
}
