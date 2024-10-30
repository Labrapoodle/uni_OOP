#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

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
                cout << matrix[j][temp] << ' ';
            }
        }
        cout << '\n';
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
                cout << matrix[j][temp] << ' ';
            }
        }
        cout << '\n';
    }
}

void printSpiralCenter(int **matrix, int size)
{
    int x = 0; // current position; x
    int y = 0; // current position; y
    int d = 0; // current direction; 0=RIGHT, 1=DOWN, 2=LEFT, 3=UP
    int c = 0; // counter
    int s = 1; // chain size

    // starting point
    if (size % 2 == 0)
    {
        x = ((int)floor(size / 2.0)) - 1;
        y = ((int)floor(size / 2.0)) - 1;
    }
    else
    {
        x = (size - 1) / 2;
        y = (size - 1) / 2;
    }

    for (int k = 1; k <= (size - 1); k++)
    {
        for (int j = 0; j < (k < (size - 1) ? 2 : 3); j++)
        {
            for (int i = 0; i < s; i++)
            {
                std::cout << matrix[x][y] << " ";
                c++;

                switch (d)
                {
                case 0:
                    y = y + 1;
                    break;
                case 1:
                    x = x + 1;
                    break;
                case 2:
                    y = y - 1;
                    break;
                case 3:
                    x = x - 1;
                    break;
                }
            }
            d = (d + 1) % 4;
        }
        s = s + 1;
    }
    std::cout << matrix[x][y] << '\n';
}

void printSpiralFirstElem(int **matrix, int size)
{
    int top = 0, bottom = size - 1, left = 0, right = size - 1;

    // Iterate until all elements are printed
    while (top <= bottom && left <= right)
    {
        // Print top row from left to right
        for (int i = left; i <= right; ++i)
        {
            cout << matrix[top][i] << " ";
        }
        top++;

        // Print right column from top to bottom
        for (int i = top; i <= bottom; ++i)
        {
            cout << matrix[i][right] << " ";
        }
        right--;

        // Print bottom row from right to left (if exists)
        if (top <= bottom)
        {
            for (int i = right; i >= left; --i)
            {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        // Print left column from bottom to top (if exists)
        if (left <= right)
        {
            for (int i = bottom; i >= top; --i)
            {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << '\n';
}

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
    printSpiralFirstElem(matrix, matrix_size);
    cout << '\n';
    printSpiralCenter(matrix, matrix_size);
    cout << '\n';

    delete[] matrix;
    getchar();
    return 0;
}
