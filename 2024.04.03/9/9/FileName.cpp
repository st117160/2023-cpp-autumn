#include <iostream>

class CGraph {
public:
    CGraph(int vertexes);
    ~CGraph();
    void readAdjacencyList();
    void printAdjacencyMatrix();

private:
    int _vertexes;
    int** _adjacencyMatrix;
    void deleteMatrix();
};

CGraph::CGraph(int vertexes) : _vertexes(vertexes), _adjacencyMatrix(nullptr)
{
    _adjacencyMatrix = new int* [_vertexes];
    for (int i = 0; i < _vertexes; ++i) {
        _adjacencyMatrix[i] = new int[_vertexes] {0};
    }
}

CGraph::~CGraph() {
    deleteMatrix();
}

void CGraph::deleteMatrix()
{
    if (_adjacencyMatrix != nullptr)
    {
        for (int i = 0; i < _vertexes; ++i)
        {
            delete[] _adjacencyMatrix[i];
        }
        delete[] _adjacencyMatrix;
        _adjacencyMatrix = nullptr;
    }
}

void CGraph::readAdjacencyList() {
    for (int i = 0; i < _vertexes; ++i) {
        int edgeCount;
        std::cin >> edgeCount;
        for (int j = 0; j < edgeCount; ++j) {
            int vertex;
            std::cin >> vertex;
            _adjacencyMatrix[i][vertex - 1] = 1;
        }
    }
}

void CGraph::printAdjacencyMatrix() {
    std::cout << _vertexes << std::endl;
    for (int i = 0; i < _vertexes; ++i) {
        for (int j = 0; j < _vertexes; ++j) {
            std::cout << _adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    CGraph graph(n);

    graph.readAdjacencyList();
    graph.printAdjacencyMatrix();

    return 0;
}
