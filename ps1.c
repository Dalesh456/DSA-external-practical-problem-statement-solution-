/*1.   Write a program to perform following operations on Arrays Data Structures: 
insertion, deletion, search, update, and display. */

#include<stdio.h>
void display(int n, int arr[]);
void insertArray(int n, int arr[]);
void deleteArray(int n, int arr[]);
void searchArray(int n, int arr[]);
void updateArray(int n, int arr[]);

int main()
{
    // inserting array elements from user
    int i, n, choice;
    printf("enter size of array : ");
    scanf("%d", &n);
    int arr[100];
    printf("enter elements of array :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("your array is:\t");
    display(n, arr);

    while(1) {
        printf("\nArray Operations Menu:\n");
        printf("0. Exit\n");
        printf("1. Display array\n");
        printf("2. Insert element\n");
        printf("3. Delete element\n");
        printf("4. Search element\n");
        printf("5. Update element\n");
        printf("Enter your choice (0-5): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nCurrent array is:\n");
                display(n, arr);
                break;
            case 2:
                insertArray(n, arr);
                break;
            case 3:
                deleteArray(n, arr);
                break;
            case 4:
                searchArray(n, arr);
                break;
            case 5:
                updateArray(n, arr);
                break;
            case 0:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a number between 0 and 5.\n");
        }
    }

    return 0;
}


// displaying array
void display(int n, int arr[])
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n\n");
}

// inserting in between
void insertArray(int n, int arr[])
{
    int i, position, value;
    printf("\nenter index where you want to insert : ");
    scanf("%d", &position);
    printf("enter value of element which you want to insert: ");
    scanf("%d", &value);
    for (i = n - 1; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = value;

    printf("your array after inserting new value: ");
    display(n, arr);
}

// deleting value from array
void deleteArray(int n, int arr[])
{
    int i, pos;
    printf("\nenter index of array which you want to delete : ");
    scanf("%d", &pos);
    for (i = pos; i < n-1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[n - 1] = 0;
    n--;

    printf("your array after deleting one element: ");
    display(n, arr);
}

// searching
void searchArray(int n, int arr[])
{
    int key, i;
    printf("enter element you want to search: ");
    scanf("%d", &key);

    for (i = 0; i < n; i++)
    {
        if (key == arr[i])
        {
            printf("%d is found at index %d\n", key, i);
            return ;
        }
    }
    printf("%d is not found", key);
}

// updating array value
void updateArray(int n, int arr[])
{
    int index, value;
    printf("\nenter index which you want to update : ");
    scanf("%d", &index);
    if (index < 0 || index >= n)
    {
        printf("Invalid index. Valid range: 0 to %d\n", n - 1);
        return;
    }
    printf("enter new value : ");
    scanf("%d", &value);
    arr[index] = value;

    printf("your array after update: ");
    display(n, arr);
}



