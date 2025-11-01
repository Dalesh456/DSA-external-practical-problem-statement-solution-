#include <stdio.h>
void display(int size, int arr[]);
void insertionSort(int size, int arr[]);

int main()
{
    int i, size;
    int arr[10]={88, 76, 15, 80, 44, 5,37,1, 28, 65 };
    size= sizeof(arr)/sizeof(arr[0]);

    printf("Your array is:\t");
    display(size, arr);

    insertionSort(size, arr);
}

// displaying array
void display(int size, int arr[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");
}

void insertionSort(int size, int arr[])
{
    int i, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Array after insertion sort: ");
    display(size, arr);
}