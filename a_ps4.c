#include <stdio.h>
#include <stdlib.h>

struct Node {
    int roll;
    struct Node *next;
};

struct Node *head = NULL , *temp = NULL;

// Add new member (at end)
void addMember(int roll) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->roll = roll;
    newNode->next = NULL;

    if (head == NULL)
        head = newNode;
    else {
        temp = head;
        while (temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Member added successfully!\n");
}

// Delete a member
void deleteMember(int roll) {
    struct Node *temp = head, *prev = NULL;

    while (temp->next != NULL && temp->roll != roll) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Member not found!\n");
        return;
    }
    if (head == temp) // Deleting head
        head = head->next;
    else
        prev->next = temp->next;

    free(temp);
    printf("Member deleted successfully!\n");
}

// Display all members
void displayMembers() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("No members in the club.\n");
        return;
    }
    printf("Club Members: ");
    while (temp->next != NULL) {
        printf("%d ", temp->roll);
        temp = temp->next;
    }
    temp = temp->next;
    printf("\n");
}

// Count total members
void countMembers() {
    int count = 0;
    struct Node *temp = head;
    while (temp->next != NULL) {
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
        printf("4. Count Members\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
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
                countMembers();
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
