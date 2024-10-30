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

        for (int i = 0; i < matrix_size; i++)
        {
            for (int j = 0; j < matrix_size; j++)
            {
                cout << matrix[i][j] << ' ';
            }
            cout << "\n";
        }
    }
}

int main()
{
    srand(time(nullptr));
    int matrix_size = 1 + rand() % 4;
    int max_value = 100;

    int **matrix = genRandMatrix(max_value, matrix_size);
    printMatrix(matrix, matrix_size);

    delete[] matrix;
    getchar();
    return 0;
}
