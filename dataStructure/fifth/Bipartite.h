#include "graph.h"
#include "queue.h"
#define MAX_VERTICES 100
class BipartiteChecker {
private:
    Graph &graph;
    int *partition;  // 0 �� 1����ʾ��������
    AQueue<int> queue;  // ʹ�� AQueue

public:
    explicit BipartiteChecker(Graph &g) : graph(g), queue(MAX_VERTICES) {
        partition = new int[graph.n()];
        for (int i = 0; i < graph.n(); ++i) {
            partition[i] = -1;  // ��ʼ��Ϊδ����
        }
    }

    ~BipartiteChecker() {
        delete[] partition;
    }

    bool isBipartite() {
        for (int i = 0; i < graph.n(); ++i) {
            if (partition[i] == -1) {
                if (!bfs(i)) {
                    cout << "��ͼ���Ƕ���ͼ��" << endl;
                    return false;
                }
            }
        }
        cout << "��ͼ�Ƕ���ͼ��" << endl;
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
                    return false;  // ͼ���Ƕ���ͼ
                }
            }
        }

        return true;  // ͼ�Ƕ���ͼ
    }

    void outputPartition() {
        cout << "����Ļ��֣�" << endl;
        for (int i = 0; i < graph.n(); ++i) {
            cout << "���� " << i << ": ���� " << partition[i] << endl;
        }
    }
};