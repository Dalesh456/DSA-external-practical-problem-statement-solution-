/*2.   Write a program to demonstrate Bubble sort techniques using arrays: Arrange 
following roll list of students in ascending order 8, 73, 15, 86, 54, 22, 34, 3, 18, 51 */

#include <stdio.h>
void display(int size, int arr[]);
void bubbleSort(int size, int arr[]);

int main()
{
    int i;
    int arr[10] = {8, 73, 15, 86, 54, 22, 34, 3, 18, 51};
    int size= sizeof(arr)/sizeof(arr[0]);
    printf("array for sorting:\t");
    display(size, arr);

    bubbleSort(size, arr);
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

// bubble sort
void bubbleSort(int size, int arr[])
{
    int i, j;
    for (i = 0; i < size - 1; i++)
    {=
        for (j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("after sorting array is:\t");
    display(size, arr);
}
