#include<iostream>

class CGraph {
public:
	CGraph();
	CGraph(int vertexes, int edges);
	~CGraph();
	void readMatrix(int vertexes);
	void printSearchRoads();

private:
	int searchRoads();
	void createMatrix();
	int** _matrix;
	int _vertexes;
	int _edges;
	void deleteMatr();
};

CGraph::CGraph() : _vertexes(0), _edges(0), _matrix(nullptr)
{
}

CGraph::CGraph(int vertexes, int edges) : _vertexes(vertexes), _edges(edges), _matrix(nullptr)
{
}

CGraph::~CGraph()
{
	deleteMatr();
}

void CGraph::createMatrix()
{
	_matrix = new int* [_vertexes];
	for (int i = 0; i < _vertexes; i++)
	{
		_matrix[i] = new int[_vertexes] { 0 };
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

int main(int argc, char* argv[])
{
	int n = 0;
	std::cin >> n;

	CGraph roads;
	roads.readMatrix(n);
	roads.printSearchRoads();

	return 0;
}
