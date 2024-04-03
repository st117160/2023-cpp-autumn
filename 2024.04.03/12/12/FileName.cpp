#include <iostream>

const int MAX_N = 100;
int adjMatrix[MAX_N][MAX_N]; // Матрица смежности

int main() {
    int N;
    std::cin >> N;

    // Чтение матрицы смежности
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> adjMatrix[i][j];
        }
    }

    // Проверка на петли
    for (int i = 0; i < N; ++i) {
        if (adjMatrix[i][i] != 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    // Проверка на симметричность
    bool isSymmetric = true;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (adjMatrix[i][j] != adjMatrix[j][i]) {
                isSymmetric = false;
                break;
            }
        }
        if (!isSymmetric) break;
    }

    // Если матрица смежности не симметрична и нет петель, то это ориентированный граф
    std::cout << (isSymmetric ? "NO" : "YES") << std::endl;

    return 0;
}
