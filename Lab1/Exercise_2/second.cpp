#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int *genRandArray(int size, int maxValue)
{
    int *arr = new int[size + 1];
    if (size < 0)
    {
        return nullptr;
    }
    arr[0] = size;
    for (int i = 1; i <= size; i++)
    {
        arr[i] = rand() % maxValue;
    }

    return arr;
}

void print_arr(int *arr)
{
    if (arr != nullptr)
    {
        cout << arr[0] << '\t';
    }
    for (int i = 1; i <= arr[0]; i++)
    {
        cout << arr[i] << '\t';
    }
    cout << '\n';
}

int **genRandMatrix(int row_amount, int maxValue)
{
    if (row_amount == 0)
    {
        return nullptr;
    }
    int **matrix = new int *[row_amount];
    int array_size;
    for (int i = 0; i < row_amount; i++)
    {
        array_size = rand() % 10;
        matrix[i] = genRandArray(array_size, maxValue);
    }
    return matrix;
}
void printMatrix(int **matrix, int rows_amount)
{
    if (matrix != nullptr)
    {
        for (int i = 0; i < rows_amount; i++)
        {
            print_arr(matrix[i]);
        }
    }
}

int main()
{
    srand(time(nullptr));
    int rows_amount = rand() % 10;
    int max_value = 100;

    int **matrix = genRandMatrix(rows_amount, max_value);
    cout << rows_amount << '\n';
    printMatrix(matrix, rows_amount);
    getchar();

    delete[] matrix;
    return 0;
}
