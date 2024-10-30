#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int **genRandMatrix(int max_value, int matrix_size)
{

    int **matrix = new int *[matrix_size];
    for (int i = 0; i < matrix_size; i++)
    {
        matrix[i] = new int[matrix_size];
    }
    for (int i = 0; i < matrix_size; i++)
    {
        for (int j = 0; j < matrix_size; j++)
        {
            matrix[i][j] = rand() % max_value;
        }
    }
    return matrix;
}

void printMatrix(int **matrix, int matrix_size)
{
    if (matrix != nullptr)
    {
        cout << matrix_size << '\n';
        for (int i = 0; i < matrix_size; i++)
        {
            for (int j = 0; j < matrix_size; j++)
            {
                cout << matrix[i][j] << '\t';
            }
            cout << '\n';
        }
    }
}

void printSlash(int **matrix, int size)
{
    if (matrix != nullptr)
    {
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                temp = size - 1 - j - i;
                if (temp < 0)
                {
                    temp = size + temp;
                }
                cout << matrix[j][temp] << '\t';
            }
            cout << '\n';
        }
    }
}

void printBackSlash(int **matrix, int size)
{
    if (matrix != nullptr)
    {
        int temp;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                temp = j + i;
                if (temp >= size)
                {
                    temp = temp - size;
                }
                cout << matrix[j][temp] << '\t';
            }
            cout << '\n';
        }
    }
}

/*
void printSpiralCenter(int **matrix, int size);
void printSpiralFirstElem(int **matrix, int size);*/

int main()
{
    srand(time(nullptr));
    int matrix_size = 1 + rand() % 4;
    int max_value = 100;

    int **matrix = genRandMatrix(max_value, matrix_size);

    printMatrix(matrix, matrix_size);
    cout << '\n';
    printSlash(matrix, matrix_size);
    cout << '\n';
    printBackSlash(matrix, matrix_size);
    cout << '\n';

    delete[] matrix;
    getchar();
    return 0;
}
