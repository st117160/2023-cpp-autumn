#include <iostream>

const int MAX_N = 30001;

class CGraph {
public:
    void initialize(int N);
    void setParent(int vertex, int parent);
    int findCommonAncestor(int a, int b);

private:
    int parent[MAX_N];
};

void CGraph::initialize(int N) {
    for (int i = 1; i <= N; ++i) {
        parent[i] = 0;
    }
    parent[1] = -1;
}

void CGraph::setParent(int vertex, int p) {
    parent[vertex] = p;
}

int CGraph::findCommonAncestor(int a, int b) {
    bool visited[MAX_N] = { false };

    while (a != -1) {
        visited[a] = true;
        a = parent[a];
    }

    while (!visited[b]) {
        b = parent[b];
    }

    return b;
}

int main() {
    int N, a, b;
    std::cin >> N >> a >> b;

    CGraph tree;
    tree.initialize(N);

    for (int i = 2; i <= N; ++i) {
        int p;
        std::cin >> p;
        tree.setParent(i, p);
    }

    std::cout << tree.findCommonAncestor(a, b);

    return 0;
}
