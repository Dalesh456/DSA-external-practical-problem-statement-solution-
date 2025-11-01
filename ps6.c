/*6. Write a program using binary search to find 7.88, 9.22, 7.14 from the 
following list of CGPA 
8.12, 5.67, 9.22, 6.55, 7.88, 5.03, 9.93, 6.79, 8.50, 7.14 */

#include <stdio.h>
void display(int size, float arr[]);
int binarySearch(int size, float arr[]);

int main()
{
    int i, size;
    float arr[10]={8.12, 5.67, 9.22, 6.55, 7.88, 5.03, 9.93, 6.79, 8.50, 7.14};
    size=sizeof(arr)/sizeof(arr[0]);

    printf("your array is:\t");
    display(size, arr);
    binarySearch(size, arr);
}

// displaying array
void display(int size, float arr[])
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%.2f\t", arr[i]);
    }
    printf("\n\n");
}

// binary search
int binarySearch(int size, float arr[])
{
    int i, j, mid;
    float key;
    int start = 0, end = size - 1;
    printf("enter your number to search: ");
    scanf("%f", &key);
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            printf("element found elemnt at index %d\n", mid);
            return 0;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    printf("element not found");
    return 0;
}
