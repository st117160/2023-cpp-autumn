#include<iostream>
#include<cmath>

class CEvolution {
public:
	CEvolution();
	CEvolution(int levels);
	~CEvolution();

	long long findCommonAncestor(long long type1, long long type2);

private:
	int _levels;
};

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();

	void readMatrix(int vertexes);
	void readEdges(int edges);
	void printSearchRoads();
	void PrintMatrix();
	void PrintEdges();
	void trLights(int vertexes);
	void colorHill(int vertexes);
	void colorBrige(int vertexes);
	void travelRing(int vertexes);
	void starwarsPL();
	int numberEdgesFromMatrix();

private:
	int searchRoads();
	void createMatr();
	void createEdges();
	void fillingMatr(int vertexes);
	void fillingEdges(int edges);

	int** _matrix;
	int _vertexes;
	int _edges;
	int** _edgesMatr;
	int* _arrColors;

	void deleteMatr();
	void deleteEdges();
	void deleteArrColors();
};

CEvolution::CEvolution() : _levels(0) {}

CEvolution::CEvolution(int levels) : _levels(levels) {}

CEvolution::~CEvolution() {}

long long CEvolution::findCommonAncestor(long long type1, long long type2)
{
	while (type1 != type2)
	{
		if (type1 > type2)
		{
			type1 /= 2;
		}
		else
		{
			type2 /= 2;
		}
	}
	return type1;
}

CGraph::CGraph() : _vertexes(0), _edges(0), _matrix(nullptr), _edgesMatr(nullptr), _arrColors(nullptr)
{
}

CGraph::CGraph(int vertexes, int edges) : _vertexes(vertexes), _edges(edges), _matrix(nullptr), _edgesMatr(nullptr), _arrColors(nullptr)
{
}

CGraph::~CGraph()
{
	deleteMatr();
	deleteEdges();
	deleteArrColors();
}

void CGraph::createMatr()
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

void CGraph::readEdges(int edges)
{
	_edges = edges;
	createEdges();
	for (int i = 0; i < _edges; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cin >> _edgesMatr[i][j];
		}
	}
	std::cout << std::endl;
}

void CGraph::createEdges()
{
	if (_edges == 0)
	{
		return;
	}

	_edgesMatr = new int* [_edges];
	for (int i = 0; i < _edges; i++)
	{
		_edgesMatr[i] = new int[2] { 0 };
	}
}

void CGraph::readMatrix(int vertexes)
{
	_vertexes = vertexes;
	createMatr();
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			std::cin >> _matrix[i][j];
		}
	}
	std::cout << std::endl;
}

void CGraph::fillingEdges(int edges)
{
	createEdges();
	int edgeIndex = 0;
	for (int i = 0; i < _vertexes; ++i) {
		for (int j = 0; j < _vertexes; ++j)
		{
			if (_matrix[i][j] == 1) {
				_edgesMatr[edgeIndex][0] = i + 1;
				_edgesMatr[edgeIndex][1] = j + 1;
				++edgeIndex;
			}
		}
	}
}

int CGraph::numberEdgesFromMatrix()
{
	_edges = 0;
	for (int i = 0; i < _vertexes; i++)
	{
		for (int j = 0; j < _vertexes; j++)
		{
			_edges += _matrix[i][j];
		}
	}

	return _edges;
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

void CGraph::PrintMatrix()
{
	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			std::cout << _matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::PrintEdges()
{
	for (int i = 0; i < _edges; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			std::cout << _edgesMatr[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void CGraph::fillingMatr(int vertexes)
{
	_vertexes = vertexes + 1;
	createMatr();
	for (int i = 0; i < _edges; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			_matrix[_edgesMatr[i][1]][_edgesMatr[i][0]] = 1;
			_matrix[_edgesMatr[i][0]][_edgesMatr[i][1]] = 1;
		}
	}
}

void CGraph::trLights(int vertexes)
{
	_vertexes = vertexes;
	for (int q = 1; q <= _vertexes; q++)
	{
		int sumEd = 0;
		for (int i = 0; i < _edges; ++i)
		{

			for (int j = 0; j < 2; ++j)
			{
				if (_edgesMatr[i][j] == q)
				{
					++sumEd;
				}
			}
		}
		std::cout << sumEd << " ";
	}

}

void CGraph::colorBrige(int vertexes)
{
	int count = 0;

	_vertexes = vertexes;
	for (int i = 0; i < _vertexes; i++)
	{
		for (int j = 0; j < _vertexes; j++)
		{
			if (_matrix[i][j] == 1)
			{
				_matrix[i][j] = _arrColors[i];
			}
		}
	}
	for (int i = 0; i < _vertexes; i++)
	{
		for (int j = 0; j < _vertexes; j++)
		{
			if (_matrix[i][j] != _matrix[j][i])
			{
				++count;
			}
		}
	}

	std::cout << count / 2;
}

void CGraph::colorHill(int vertexes)
{
	_vertexes = vertexes;
	_arrColors = new int[_vertexes] { 0 };
	for (int i = 0; i < _vertexes; i++)
	{
		std::cin >> _arrColors[i];
	}
	std::cout << std::endl;
}

void CGraph::travelRing(int vertexes)
{
	_vertexes = vertexes;
	int minDist = 10000000;

	for (int i = 0; i < _vertexes; ++i)
	{
		for (int j = 0; j < _vertexes; ++j)
		{
			for (int k = 0; k < _vertexes; ++k)
			{
				if (i != j && j != k && k != i)
				{
					int dist = _matrix[i][j] + _matrix[j][k] + _matrix[k][i];
					minDist = std::min(minDist, dist);
				}
			}
		}
	}

	std::cout << minDist;
}

void CGraph::starwarsPL()
{
	int countPlanet = 0;
	for (int i = 1; i <= _edges + 1; i++)
	{
		int count = 0;
		for (int j = 0; j < _edges; j++)
		{
			for (int q = 0; q < 2; q++)
			{
				if (_edgesMatr[j][q] == i)
				{
					++count;
				}
			}
		}

		if (count > 1)
		{
			++countPlanet;
		}
	}

	std::cout << countPlanet << std::endl;
}

void CGraph::printSearchRoads()
{
	std::cout << searchRoads() << std::endl;
}

void CGraph::deleteMatr()
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
	if (_edgesMatr != nullptr)
	{
		for (int i = 0; i < _edges; ++i)
		{
			delete[] _edgesMatr[i];
		}
		delete[] _edgesMatr;
		_edgesMatr = nullptr;
	}
}

void CGraph::deleteArrColors()
{
	delete[] _arrColors;
}

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	CGraph adjmatr;
	adjmatr.readMatrix(n);
	std::cout << n << " " << adjmatr.numberEdgesFromMatrix() << std::endl;
	adjmatr.PrintEdges();

	return 0;
}
