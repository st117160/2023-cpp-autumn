#include <iostream>

const int MAX_N = 100;
int graph[MAX_N][MAX_N];
bool isSource[MAX_N];
bool isSink[MAX_N];

class CGraph {
public:
    void readGraph(int N);
    void findSourcesAndSinks(int N);
    void printSourcesAndSinks(int N);
};

void CGraph::readGraph(int N) {
    for (int i = 0; i < N; i++) {
        isSource[i] = true;
        isSink[i] = true;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> graph[i][j];
            if (graph[i][j] == 1) {
                isSink[i] = false;
                isSource[j] = false;
            }
        }
    }
}

void CGraph::findSourcesAndSinks(int N) {
    int sourceCount = 0;
    for (int i = 0; i < N; i++) {
        if (isSource[i]) sourceCount++;
    }
    std::cout << sourceCount;
    for (int i = 0; i < N; i++) {
        if (isSource[i]) std::cout << " " << i + 1;
    }
    std::cout << std::endl;

    int sinkCount = 0;
    for (int i = 0; i < N; i++) {
        if (isSink[i]) sinkCount++;
    }
    std::cout << sinkCount;
    for (int i = 0; i < N; i++) {
        if (isSink[i]) std::cout << " " << i + 1;
    }
    std::cout << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    CGraph graph;
    graph.readGraph(N);
    graph.findSourcesAndSinks(N);

    return 0;
}
