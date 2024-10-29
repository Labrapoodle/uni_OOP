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

int main()
{
    srand(time(nullptr));
    int size = rand() % 10;
    int maxValue = 100;

    int *arr = genRandArray(size, maxValue);
    print_arr(arr);

    delete[] arr;
    getchar();
    return 0;
};
