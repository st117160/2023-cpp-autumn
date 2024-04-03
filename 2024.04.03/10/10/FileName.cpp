#include <iostream>

class CEvolution {
public:
    CEvolution();
    CEvolution(int levels);
    ~CEvolution();

    long long findCommonAncestor(long long type1, long long type2);

private:
    int _levels;
};

CEvolution::CEvolution() : _levels(0) {}

CEvolution::CEvolution(int levels) : _levels(levels) {}

CEvolution::~CEvolution() {}

long long CEvolution::findCommonAncestor(long long type1, long long type2) {
    while (type1 != type2) {
        if (type1 > type2) {
            type1 /= 2;
        }
        else {
            type2 /= 2;
        }
    }
    return type1;
}

class CGraph {
public:
    CGraph();
    CGraph(int vertexes, int edges);
    ~CGraph();

    void readMatrix(int vertexes);
    void printArrPow();

private:
    void createMatrix(int size);
    void deleteMatrix();

    int** _matrix;
    int _vertexes;
    int _edges;
    int* _arrPow;
};

CGraph::CGraph() : _vertexes(0), _edges(0), _matrix(nullptr), _arrPow(nullptr) {}

CGraph::CGraph(int vertexes, int edges) : _vertexes(vertexes), _edges(edges), _matrix(nullptr), _arrPow(nullptr) {}

CGraph::~CGraph() {
    deleteMatrix();
    delete[] _arrPow;
}

void CGraph::readMatrix(int vertexes) {
    _vertexes = vertexes;
    createMatrix(vertexes);
    for (int i = 0; i < _vertexes; ++i) {
        for (int j = 0; j < _vertexes; ++j) {
            std::cin >> _matrix[i][j];
        }
    }
    std::cout << std::endl;
}

void CGraph::createMatrix(int size) {
    _matrix = new int* [size];
    for (int i = 0; i < size; ++i) {
        _matrix[i] = new int[size] {0};
    }
}

void CGraph::deleteMatrix() {
    if (_matrix != nullptr) {
        for (int i = 0; i < _vertexes; ++i) {
            delete[] _matrix[i];
        }
        delete[] _matrix;
        _matrix = nullptr;
    }
}

void CGraph::printArrPow() {
    if (_arrPow == nullptr) {
        _arrPow = new int[_vertexes] {0};
        for (int i = 0; i < _vertexes; i++) {
            int count = 0;
            for (int j = 0; j < _vertexes; j++) {
                count += _matrix[i][j];
            }
            _arrPow[i] = count;
        }
    }
    for (int i = 0; i < _vertexes; i++) {
        std::cout << _arrPow[i] << " ";
    }
}

int main(int argc, char* argv[]) {
    int v = 0;
    std::cin >> v;

    CGraph pV;
    pV.readMatrix(v);
    pV.printArrPow();

    return 0;
}
