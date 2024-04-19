#include<iostream>

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();

	void readMatrix(int vertexes);
	void readEdges(int edges);
	void fillMatrix(int vertexes);
	void printSearchRoads();
	void travelRing(int vertexes);

private:
	int searchRoads();
	void createMatrix();
	void createEdges();

	int** _matrix;
	int _vertexes;
	int _edges;
	int** _edgesMatrix;
	int* _arrColors;

	void deleteMatrix();
	void deleteEdges();
	void deleteArrColors();
};

CGraph::CGraph() : _vertexes(0), _edges(0), _matrix(nullptr), _edgesMatrix(nullptr), _arrColors(nullptr)
{
}

CGraph::CGraph(int vertexes, int edges) : _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edgesMatrix(nullptr), _arrColors(nullptr)
{
}

CGraph::~CGraph()
{
	deleteMatrix();
	deleteEdges();
	deleteArrColors();
}

void CGraph::createMatrix()
{
	if (_vertexes == 0)
	{
		return;
	}

	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; i++)
	{
		_matrix[i] = new int[_vertexes] { 0 };
	}
}

void CGraph::createEdges()
{
	if (_edges == 0)
	{
		return;
	}

	_edgesMatrix = new int* [_edges];
	for (int i = 0; i < _edges; i++)
	{
		_edgesMatrix[i] = new int[2] { 0 };
	}
}

void CGraph::readMatrix(int vertexes)
{
	_vertexes = vertexes;
	createMatrix();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			std::cin >> _matrix[i][j];
		}
	}
	std::cout << std::endl;
}

void CGraph::readEdges(int edges)
{
	_edges = edges;
	createEdges();
	for (int i = 0; i < _edges; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cin >> _edgesMatrix[i][j];
		}
	}
	std::cout << std::endl;
}

void CGraph::fillMatrix(int vertexes)
{
	_vertexes = vertexes + 1;
	createMatrix();
	for (int i = 0; i < _edges; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			_matrix[_edgesMatrix[i][1]][_edgesMatrix[i][0]] = 1;
			_matrix[_edgesMatrix[i][0]][_edgesMatrix[i][1]] = 1;
		}
	}
}

void CGraph::travelRing(int vertexes)
{
	_vertexes = vertexes;
	int MINDist = 10000000;

	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			for (int k = 0; k < _vertexes; ++k)
			{
				if (i != j && j != k && k != i)
				{
					int dist = _matrix[i][j] + _matrix[j][k] + _matrix[k][i];
					MINDist = std::min(MINDist, dist);
				}
			}
		}
	}

	std::cout << MINDist;
}

int CGraph::searchRoads()
{
	int count = 0;
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; j++)
		{
			if (_matrix[i][j] == 1)
			{
				++count;
			}
		}
	}

	return (count / 2);
}

void CGraph::printSearchRoads()
{
	std::cout << searchRoads() << std::endl;
}

void CGraph::deleteMatrix()
{
	if (_matrix != nullptr)
	{
		for (int i = 0; i < _vertexes; ++i)
		{
			delete[] _matrix[i];
		}
		delete[] _matrix;
		_matrix = nullptr;
	}
}

void CGraph::deleteEdges()
{
	if (_edgesMatrix != nullptr)
	{
		for (int i = 0; i < _edges; ++i)
		{
			delete[] _edgesMatrix[i];
		}
		delete[] _edgesMatrix;
		_edgesMatrix = nullptr;
	}
}

void CGraph::deleteArrColors()
{
	delete[] _arrColors;
}

int main(int argc, char* argv[])
{
	int v = 0;
	std::cin >> v;

	CGraph travel;
	travel.readMatrix(v);
	travel.travelRing(v);

	return 0;
}