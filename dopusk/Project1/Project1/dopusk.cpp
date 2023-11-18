#include <iostream>
#include <cstdlib>
#include <ctime>

void printArray(int* a, int len);
void BubbleSort(int* a, int len);
void InsertionSort(int* a, int len);
void SelectionSort(int* a, int len);
void CountSort(int* a, int len);
void GnomeSort(int* a, int len);
void MonkeySort(int* a, int len);
void MixArray(int* a, int cnt);
bool isSorted(int* a, int n);
void printMenu();

int main(int argc, char* argv[])
{
    int* a = nullptr;
    int len = 0;
    std::cout << "Enter the length of the array: ";
    std::cin >> len;

    a = new int[len];
    srand(time(NULL));
    for (int i = 0; i < len; ++i)
    {
        a[i] = 1 + rand() % 5;
    }

    bool exit = false;
    while (!exit)
    {
        system("cls");
        printMenu();
        printArray(a, len);

        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 0:
            exit = true;
            break;
        case 1:
            BubbleSort(a, len);
            break;
        case 2:
            InsertionSort(a, len);
            break;
        case 3:
            SelectionSort(a, len);
            break;
        case 4:
            CountSort(a, len);
            break;
        case 5:
            GnomeSort(a, len);
            break;
        case 6:
            MonkeySort(a, len);
            break;
        case 7:
            MixArray(a, len);
            break;
        default:
            std::cout << "Unknown command" << std::endl;
            break;
        }
    }

    delete[] a;
    return 0;
}

void printArray(int* a, int len)
{
    if (a == nullptr)
    {
        std::cout << "EMPTY";
    }
    else
    {
        for (int i = 0; i < len; ++i)
        {
            std::cout << a[i] << " ";
        }
    }
    std::cout << std::endl;
}

void BubbleSort(int* a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                std::swap(a[j], a[j + 1]);
            }
        }
    }
    printArray(a, len);
}

void SelectionSort(int* a, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        int min_ind = i;
        for (int j = i + 1; j < len; j++)
        {
            if (a[min_ind] > a[j])
            {
                min_ind = j;
            }
        }
        if (min_ind != i)
        {
            std::swap(a[min_ind], a[i]);
        }
    }
}

void InsertionSort(int* a, int len)
{
    for (int i = 1; i < len; i++)
    {
        int sort = i - 1;
        while (sort > -1 && a[sort] > a[sort + 1])
        {
            std::swap(a[sort], a[sort + 1]);
            sort--;
        }
    }
    printArray(a, len);
}

void CountSort(int* a, int len)
{
    int a1[10];
    int count_a[10];
    int x = a[0];
    for (int i = 1; i < len; i++)
    {
        if (a[i] > x)
            x = a[i];
    }
    for (int i = 0; i <= x; ++i)
    {
        count_a[i] = 0;
    }
    for (int i = 0; i < len; i++)
    {
        count_a[a[i]]++;
    }
    for (int i = 1; i <= x; i++)
    {
        count_a[i] += count_a[i - 1];
    }
    for (int i = len - 1; i >= 0; i--)
    {
        a1[count_a[a[i]] - 1] = a[i];
        count_a[a[i]]--;
    }
    for (int i = 0; i < len; i++)
    {
        a[i] = a1[i];
    }

}

void GnomeSort(int* a, int len)
{
    int ind = 1;
    while (ind < len)
    {
        if (a[ind] >= a[ind - 1])
        {
            ind++;
        }
        else
        {
            std::swap(a[ind], a[ind - 1]);
            ind--;
        }
    }
}

void MonkeySort(int* a, int len)
{
    while (!isSorted(a, len)) 
    {
        MixArray(a, len);
    }
}

void MixArray(int* a, int len)
{
    for (int i = 0; i < len; i++)
    {
        int j = rand() % len; 
        std::swap(a[i], a[j]);
    }
}

bool isSorted(int* a, int cnt)
{
    for (int i = cnt - 1; i > 0; i--) 
    {
        if (a[i] < a[i - 1])
        {
            return false;
        }
    }
    return true; 
}

void printMenu()
{
    std::cout << "0 - EXIT" << std::endl;
    std::cout << "1 - BUBBLE SORT" << std::endl;
    std::cout << "2 - INSERTION SORT" << std::endl;
    std::cout << "3 - SELECTION SORT" << std::endl;
    std::cout << "4 - COUNT SORT" << std::endl;
    std::cout << "5 - GNOME SORT" << std::endl;
    std::cout << "6 - MONKEY SORT" << std::endl;
    std::cout << "7 - MIX ARRAY" << std::endl;
}