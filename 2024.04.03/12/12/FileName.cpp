#include <iostream>

const int MAX_N = 100;
int adjMatrix[MAX_N][MAX_N]; // ������� ���������

int main() {
    int N;
    std::cin >> N;

    // ������ ������� ���������
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> adjMatrix[i][j];
        }
    }

    // �������� �� �����
    for (int i = 0; i < N; ++i) {
        if (adjMatrix[i][i] != 0) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }

    // �������� �� ��������������
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

    // ���� ������� ��������� �� ����������� � ��� ������, �� ��� ��������������� ����
    std::cout << (isSymmetric ? "NO" : "YES") << std::endl;

    return 0;
}
