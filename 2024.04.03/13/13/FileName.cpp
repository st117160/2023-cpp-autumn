#include <iostream>
#include <cstring>

const int MAX_N = 101;
bool matrix[MAX_N][MAX_N];

class CGraph {
public:
    CGraph();
    ~CGraph();

    void readEdges(int edges);
    bool isCompleteGraph(int vertexes);

private:
    void initializeMatrix();
};

CGraph::CGraph() {
    initializeMatrix();
}

CGraph::~CGraph() {}

void CGraph::initializeMatrix() {
    memset(matrix, false, sizeof(matrix));
}

bool CGraph::isCompleteGraph(int vertexes) {
    bool isComplete = true;
    for (int i = 1; i <= vertexes; ++i) {
        for (int j = 1; j <= vertexes; ++j) {
            if (i != j && !matrix[i][j]) {
                isComplete = false;
                break;
            }
        }
        if (!isComplete) break;
    }
    return isComplete;
}

void CGraph::readEdges(int edges) {
    for (int i = 0; i < edges; ++i) {
        int u, v;
        std::cin >> u >> v;
        matrix[u][v] = matrix[v][u] = true;
    }
}

int main() {
    int N, M;
    std::cin >> N >> M;

    CGraph graph;
    graph.readEdges(M);

    bool isComplete = graph.isCompleteGraph(N);

    std::cout << (isComplete ? "YES" : "NO");

    return 0;
}
