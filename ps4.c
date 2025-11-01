/*
Write a program to demonstrate a singly linked list: Students can be granted 
membership of the club on request. Store the student roll no. Write functions to 
a)      Add and delete the members. 
b)     Compute total number of members of club 
c)      Display members
*/

#include <stdio.h>
#include <stdlib.h>   // for malloc and free functions

struct Node {
    int roll_no;
    struct Node* next;
};

struct Node* head = NULL;

void addMember(int roll_no) {
    struct Node* new_member = (struct Node*)malloc(sizeof(struct Node));
    new_member->roll_no = roll_no;
    new_member->next = head;
    head = new_member;
    printf("Member with roll no %d added.\n", roll_no);
}

void deleteMember(int roll_no) {
    struct Node* current = head;
    struct Node* previous = NULL;

    while (current != NULL && current->roll_no != roll_no) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Member with roll no %d not found.\n", roll_no);
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Member with roll no %d deleted.\n", roll_no);
}

int countMembers() {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void displayMembers() {
    struct Node* current = head;
    if (current == NULL) {
        printf("No members found.\n");
        return;
    }
    printf("Club Members (Roll No): ");
    while (current != NULL) {
        printf("%d ", current->roll_no);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, roll_no;

    while (1) {
        printf("\nClub Membership Menu:\n");
        printf("1. Add Member\n");
        printf("2. Delete Member\n");
        printf("3. Count Members\n");
        printf("4. Display Members\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll no to add: ");
                scanf("%d", &roll_no);
                addMember(roll_no);
                break;
            case 2:
                printf("Enter roll no to delete: ");
                scanf("%d", &roll_no);
                deleteMember(roll_no);
                break;
            case 3:
                printf("Total members: %d\n", countMembers());
                break;
            case 4:
                displayMembers();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}