#include<iostream>
#include<cmath>

class CEvolution {
public:
    CEvolution(int levels) : _levels(levels) {}
    long long findCommonAncestor(long long type1, long long type2) {
        while (type1 != type2) {
            type1 > type2 ? type1 /= 2 : type2 /= 2;
        }
        return type1;
    }
private:
    int _levels;
};

class CGraph {
public:
    CGraph(int vertexes, int edges) : _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edgesMatr(nullptr), _arrColors(nullptr) {}
    ~CGraph() { deleteMatr(); deleteEdges(); deleteArrColors(); }
    void readMatrix(int vertexes) {
        _vertexes = vertexes;
        createMatr();
        for (int i = 0; i < _vertexes; ++i)
            for (int j = 0; j < _vertexes; ++j)
                std::cin >> _matrix[i][j];
        std::cout << std::endl;
    }
    void readEdges(int edges) {
        _edges = edges;
        createEdges();
        for (int i = 0; i < _edges; ++i)
            for (int j = 0; j < 2; ++j)
                std::cin >> _edgesMatr[i][j];
        std::cout << std::endl;
    }
    void PrintMatrix() {
        if (_matrix == nullptr) {
            fillingMatr(_vertexes);
        }
        for (int i = 0; i < _vertexes; ++i) {
            for (int j = 0; j < _vertexes; ++j)
                std::cout << _matrix[i][j] << " ";
            std::cout << std::endl;
        }
    }
    int searchRoads() {
        int count = 0;
        for (int i = 0; i < _vertexes; ++i)
            for (int j = 0; j < _vertexes; j++)
                if (_matrix[i][j] == 1) ++count;
        return (count / 2);
    }
    void printSearchRoads() { std::cout << searchRoads() << std::endl; }
private:
    void createMatr() {
        if (_vertexes == 0) return;
        _matrix = new int* [_vertexes];
        for (int i = 0; i < _vertexes; i++) _matrix[i] = new int[_vertexes] { 0 };
    }
    void createEdges() {
        if (_edges == 0) return;
        _edgesMatr = new int* [_edges];
        for (int i = 0; i < _edges; i++) _edgesMatr[i] = new int[2] { 0 };
    }
    void fillingMatr(int vertexes) {
        _vertexes = vertexes + 1;
        createMatr();
        for (int i = 0; i < _edges; ++i)
            for (int j = 0; j < 2; ++j) {
                _matrix[_edgesMatr[i][1]][_edgesMatr[i][0]] = 1;
                _matrix[_edgesMatr[i][0]][_edgesMatr[i][1]] = 1;
            }
    }
    void deleteMatr() {
        if (_matrix != nullptr) {
            for (int i = 0; i < _vertexes; ++i) delete[] _matrix[i];
            delete[] _matrix;
            _matrix = nullptr;
        }
    }
    void deleteEdges() {
        if (_edgesMatr != nullptr) {
            for (int i = 0; i < _edges; ++i) delete[] _edgesMatr[i];
            delete[] _edgesMatr;
            _edgesMatr = nullptr;
        }
    }
    void deleteArrColors() { delete[] _arrColors; }
    int** _matrix;
    int _vertexes;
    int _edges;
    int** _edgesMatr;
    int* _arrColors;
};

int main(int argc, char* argv[]) {
    int N = 0;
    long long a = 0;
    long long b = 0;
    std::cin >> N >> a >> b;
    CEvolution evolution(N);
    long long result = evolution.findCommonAncestor(a, b);
    std::cout << result << std::endl;
    return 0;
}