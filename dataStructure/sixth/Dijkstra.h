#include "graph.h"

class djikstra{
private:
    Graph &G;
    int *D; // 源点到结点的最短距离
    int *predecessor; // 当前结点的前一个结点
public:
    explicit djikstra(Graph &g) : G(g) {
        D = new int (g.n());
        predecessor = new int[g.n()];
        for(int i =0;i<g.n();i++)
        {
            D[i] = INT16_MAX;
            predecessor[i] = -1;
        }
    }
    ~djikstra() {
        delete[] D;
        delete[] predecessor;
    }
    int minVertex()
    {
        int i;
        int v = -1;
        for(i = 0; i < G.n(); i++)
        {
            if(G.getMark(i) == UNVISITED) {
                v = i;
                break;
            }
        }
        for(i++;i<G.n();i++)
        {
            if(G.getMark(i)==UNVISITED && D[i]<D[v])
            {
                v = i;
            }
        }
        return v;
    }
    void run(int s)
    {
        int v,w;
        D[s] = 0;
        for(int i=0;i<G.n();i++)
        {
            v= minVertex();
            // 没有连接的点了
            if(D[v] == INT16_MAX)
            {
                return;
            }
            G.setMark(v,VISITED);
            for(w=G.first(v);w<G.n();w = G.next(v,w))
            {
                if((D[v]+G.weight(v,w))<D[w])
                {
                    D[w] = D[v]+G.weight(v,w);
                    predecessor[w] = v;
                }
            }
        }
    }
    int minRouteValue(int v)
    {
        if(D[v] != INT16_MAX)
        {
            return D[v];
        }
        else {
            cout<<"no route can get to" << v << "node"<<endl;
            return -1;
        }
    }
    void printPath(int v) {
        if (predecessor[v] != -1) {
            printPath(predecessor[v]);
        }
        cout << v << "->";
    }
};