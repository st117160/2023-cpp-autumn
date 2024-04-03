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
    CGraph() : _vertexes(0), _edges(0), _matrix(nullptr), _edgesMatr(nullptr), _arrColors(nullptr) {}
    CGraph(int vertexes, int edges) : _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edgesMatr(nullptr), _arrColors(nullptr) { searchRoads(); }
    ~CGraph() { deleteAll(); }
    void readMatrix(int vertexes) { _vertexes = vertexes; createMatr(); readMatrixInput(); }
    void readEdges(int edges) { _edges = edges; createEdges(); readEdgesInput(); }
    void starwarsPL() { int countPlanet = 0; for (int i = 1; i <= _edges + 1; i++) { int count = countOccurrences(i); if (count > 1) ++countPlanet; } std::cout << countPlanet << std::endl; }
    void printSearchRoads() { std::cout << searchRoads() << std::endl; }
private:
    int** _matrix;
    int _vertexes;
    int _edges;
    int** _edgesMatr;
    int* _arrColors;
    void deleteAll() { deleteMatr(); deleteEdges(); deleteArrColors(); }
    void createMatr() { _matrix = new int* [_vertexes]; for (int i = 0; i < _vertexes; ++i) _matrix[i] = new int[_vertexes](); }
    void createEdges() { _edgesMatr = new int* [_edges]; for (int i = 0; i < _edges; ++i) _edgesMatr[i] = new int[2](); }
    void deleteMatr() { if (_matrix != nullptr) { for (int i = 0; i < _vertexes; ++i) delete[] _matrix[i]; delete[] _matrix; _matrix = nullptr; } }
    void deleteEdges() { if (_edgesMatr != nullptr) { for (int i = 0; i < _edges; ++i) delete[] _edgesMatr[i]; delete[] _edgesMatr; _edgesMatr = nullptr; } }
    void deleteArrColors() { delete[] _arrColors; }
    void readMatrixInput() { for (int i = 0; i < _vertexes; ++i) for (int j = 0; j < _vertexes; ++j) std::cin >> _matrix[i][j]; }
    void readEdgesInput() { for (int i = 0; i < _edges; ++i) for (int j = 0; j < 2; ++j) std::cin >> _edgesMatr[i][j]; }
    int countOccurrences(int value) { int count = 0; for (int i = 0; i < _edges; ++i) if (_edgesMatr[i][0] == value || _edgesMatr[i][1] == value) ++count; return count; }
    int searchRoads() { int count = 0; for (int i = 0; i < _vertexes; ++i) for (int j = 0; j < _vertexes; ++j) if (_matrix[i][j] == 1) ++count; return (count / 2); }
};

int main(int argc, char* argv[]) {
    int n = 0;
    std::cin >> n;
    CGraph starwars;
    starwars.readEdges(n - 1);
    starwars.starwarsPL();
    return 0;
}
