#include <iostream>
#include <windows.h>


void CocktailSort(int arr[], int size)
{
    bool swapped = true;
    int start = 0;
    int end = size - 1;
 
    while(swapped)
    {
        swapped = false;
 
        // loop from left to right same as
        // the bubble sort
        for (int i = start; i < end; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
        if (!swapped)
        {
            break;
        }
        swapped = false;
 
        // move the end point back by one, because
        // item at the end is in its rightful spot
        end--;
 
        // from right to left, doing the
        // same comparison as in the previous stage
        for (int i = end - 1; i >= start; --i)
        {
            if (arr[i] > arr[i + 1])
            {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }
 
        // increase the starting point, because
        // the last stage would have moved the next
        // smallest number to its rightful spot.
        ++start;
    }
}

void GnomeSort(int arr[], int size)
{
    //Gnome Sort also called Stupid sort is based on the concept of a Garden Gnome sorting his flower pots.
    //He looks at the flower pot next to him and the previous one; if they are in the right order he steps one pot forward, otherwise he swaps them and steps one pot backwards.
    //If there is no previous pot (he is at the starting of the pot line), he steps forwards; if there is no pot next to him (he is at the end of the pot line), he is done.

    int index = 1;

    while(index < size)
    {
        if (arr[index] >= arr[index - 1])
        {
            index++;
        }
        else {
            std::swap(arr[index], arr[index - 1]);
            index--;
        }
    }
    return;
}

int Partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    //Index of smaller element and Indicate
    //the right position of pivot found so far
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        //If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            //Increment index of smaller element
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int high, int low = 0)
{
    if (low < high)
    {
        //partition return index of pivot

        int pivot = Partition(arr, low, high);

        //Recursion Call
        //smaller element than pivot goes left and
        //higher element goes right
        QuickSort(arr, pivot - 1, low);
        QuickSort(arr, high, pivot + 1);
    }
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n\n";
}

void printArray(int arr[], int size, int copy[])
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n\n";
    for (int i = 0; i < size; i++)
    {
        arr[i] = copy[i];
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int size = 11;
    int copy[size] = { 5, 1, 4, 2, 8, 0, 2, 34, 2, 10, -9 };
    int arr[size] = { 5, 1, 4, 2, 8, 0, 2, 34, 2, 10, -9 };
    printArray(arr, size);

    std::cout << "Cocktail sort\n";
    CocktailSort(arr, size);
    std::cout << "Результат:\n";
    printArray(arr, size, copy);
    std::cout << '\n';

    std::cout << "Gnome sort\n";
    GnomeSort(arr, size);
    std::cout << "Результат:\n";
    printArray(arr, size, copy);
    std::cout << '\n';


    std::cout << "Quick sort\n";
    QuickSort(arr, size - 1);
    std::cout << "Результат:\n";
    printArray(arr, size, copy);
    std::cout << '\n';


    return 0;
}