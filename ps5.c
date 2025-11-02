#include <stdio.h>
#include <stdlib.h>

// Structure for doubly linked list node
struct Node {
    int roll;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;

// Add new member at end
void addMember(int roll) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    printf("Member added successfully!\n");
}

// Delete a member by roll number
void deleteMember(int roll) {
    struct Node *temp = head;

    while (temp != NULL && temp->roll != roll)
        temp = temp->next;

    if (temp == NULL) {
        printf("Member not found!\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next; // deleting first node

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Member deleted successfully!\n");
}

// Display members from start to end
void displayMembers() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("No members in the club.\n");
        return;
    }

    printf("Club Members (Forward): ");
    while (temp != NULL) {
        printf("%d ", temp->roll);
        temp = temp->next;
    }
    printf("\n");
}

// Display list in reverse order
void displayReverse() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("No members in the club.\n");
        return;
    }

    // Go to the last node
    while (temp->next != NULL)
        temp = temp->next;

    printf("Club Members (Reverse): ");
    while (temp != NULL) {
        printf("%d ", temp->roll);
        temp = temp->prev;
    }
    printf("\n");
}

// Count total members
void countMembers() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Total Members: %d\n", count);
}

int main() {
    int choice, roll;

    do {
        printf("\n--- Club Membership Menu ---\n");
        printf("1. Add Member\n");
        printf("2. Delete Member\n");
        printf("3. Display Members\n");
        printf("4. Display Reverse\n");
        printf("5. Count Members\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll number: ");
                scanf("%d", &roll);
                addMember(roll);
                break;

            case 2:
                printf("Enter roll number to delete: ");
                scanf("%d", &roll);
                deleteMember(roll);
                break;

            case 3:
                displayMembers();
                break;

            case 4:
                displayReverse();
                break;

            case 5:
                countMembers();
                break;

            case 6:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
