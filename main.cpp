#include <iostream>
#include <random>
#include <assert.h>
#include <string.h>

using namespace std;

#define MIN 1
#define MAX 10

mt19937 rng;

int generateRandomInt(int min, int max);
void printArray(int *array, size_t size);
void heapsort(int* array, size_t size);
void heapify(int* array, size_t size, int i);
bool validate(int* array, size_t size);

int main(int argc, char *argv[]) {
    rng.seed(random_device()());
    cout << "===========================================================" << endl;
    cout << "\tHeapsort Practice" << endl;
    cout << "===========================================================" << endl << endl;

    const int numberOfElements = generateRandomInt(MIN, MAX);
    int *numbers = new int[numberOfElements];
    for (int i = 0; i < numberOfElements; i++) {
        numbers[i] = generateRandomInt(0, 100);
    }

    printArray(numbers, numberOfElements);
    heapsort(numbers, numberOfElements);
    cout << "//////////////////////////////////////" << endl;
    printArray(numbers, numberOfElements);
    assert(validate(numbers, numberOfElements) && "The sort is not ordering all the elements");

    system("pause");
    return EXIT_SUCCESS;
}

int generateRandomInt(int min, int max) {
    uniform_int_distribution<mt19937::result_type> distribution(min, max);
    return distribution(rng);
}

void printArray(int *array, size_t size) {
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}
void heapify(int* array, size_t size, int i)
{
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    if (left < size && array[left] > array[largest])
        largest = left;
    if (right < size && array[right] > array[largest])
        largest = right;
    if (largest != i)
    {
        swap(array[i], array[largest]);
        heapify(array, size, largest);
    }
}
void heapsort(int* array, size_t size) {
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(array, size, i);
    for (int i=size-1; i>=0; i--)
    {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

bool validate(int* array, size_t size) {
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return false;
        }
    }
    return true;
}
