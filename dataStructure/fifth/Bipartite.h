#include "graph.h"
#include "queue.h"
#define MAX_VERTICES 100
class BipartiteChecker {
private:
    Graph &graph;
    int *partition;  // 0 或 1，表示两个集合
    AQueue<int> queue;  // 使用 AQueue

public:
    explicit BipartiteChecker(Graph &g) : graph(g), queue(MAX_VERTICES) {
        partition = new int[graph.n()];
        for (int i = 0; i < graph.n(); ++i) {
            partition[i] = -1;  // 初始化为未访问
        }
    }

    ~BipartiteChecker() {
        delete[] partition;
    }

    bool isBipartite() {
        for (int i = 0; i < graph.n(); ++i) {
            if (partition[i] == -1) {
                if (!bfs(i)) {
                    cout << "该图不是二部图。" << endl;
                    return false;
                }
            }
        }
        cout << "该图是二部图。" << endl;
        outputPartition();
        return true;
    }

private:
    bool bfs(int start) {
        queue.enqueue(start);
        partition[start] = 0;

        while (!queue.empty()) {
            int current = queue.dequeue();

            for (int neighbor = graph.first(current); neighbor < graph.n(); neighbor = graph.next(current, neighbor)) {
                if (partition[neighbor] == -1) {
                    partition[neighbor] = 1 - partition[current];
                    queue.enqueue(neighbor);
                } else if (partition[neighbor] == partition[current]) {
                    return false;  // 图不是二部图
                }
            }
        }

        return true;  // 图是二部图
    }

    void outputPartition() {
        cout << "顶点的划分：" << endl;
        for (int i = 0; i < graph.n(); ++i) {
            cout << "顶点 " << i << ": 集合 " << partition[i] << endl;
        }
    }
};