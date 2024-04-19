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
	void trLights(int vertexes);
	void colorHill(int vertexes);
	void colorBrige(int vertexes);

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
	for (int i = 0; i <= _vertexes + 1; i++)
	{
		for (int j = 0; j <= _vertexes + 1; j++)
		{
			_matrix[_edgesMatrix[j][1]][_edgesMatrix[j][0]] = 1;
			_matrix[_edgesMatrix[j][0]][_edgesMatrix[j][1]] = 1;
		}
	}
}

void CGraph::trLights(int vertexes)
{
	_vertexes = vertexes;
	for (int q = 1; q <= _vertexes; q++)
	{
		int sumEdges = 0;
		for (int i = 0; i < _edges; ++i)
		{

			for (int j = 0; j < 2; ++j)
			{
				if (_edgesMatrix[i][j] == q)
				{
					++sumEdges;
				}
			}
		}
		std::cout << sumEdges << " ";
	}

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
	int n = 0;
	std::cin >> n;

	CGraph brigeBad;
	brigeBad.readMatrix(n);
	brigeBad.colorHill(n);
	brigeBad.colorBrige(n);

	return 0;
}

