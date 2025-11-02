/*14. Write a program to demonstrate a tree for a book that consists of chapters, the 
chapters consist of sections and sections consist of subsections. Construct a tree 
and print the nodes.*/

/*14. Write a program to demonstrate a tree for a book that consists of chapters, the 
chapters consist of sections and sections consist of subsections. Construct a tree 
and print the nodes.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    struct Node *child[10];   // Each node can have up to 10 children
    int childCount;            // Number of children
};

struct Node *createNode(char name[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->name, name); // strcpy() copies each character from name into newNode->name.
    newNode->childCount = 0;     // Initially no children
    return newNode;
}

int main() {
    struct Node *book, *chapter, *section, *subsection;
    char name[50];
    int chCount, secCount, subSecCount;   //variables for counts

    // Book
    printf("Enter book name: ");
    gets(name);      // reads full line including spaces
    book = createNode(name);

    // Ask how many chapters
    printf("Enter number of chapters: ");
    scanf("%d", &chCount);
    getchar(); // clear newline from buffer

    // Loop for multiple chapters
    for (int i = 0; i < chCount; i++) {
        printf("\nEnter chapter name %d: ", i + 1);
        gets(name);
        chapter = createNode(name);
        book->child[book->childCount] = chapter;
        book->childCount++;

        // Ask number of sections in each chapter
        printf("Enter number of sections in %s: ", chapter->name);
        scanf("%d", &secCount);
        getchar();

        for (int j = 0; j < secCount; j++) {
            printf("  Enter section name %d: ", j + 1);
            gets(name);
            section = createNode(name);
            chapter->child[chapter->childCount] = section;
            chapter->childCount++;

            // Ask number of subsections in each section
            printf("  Enter number of subsections in %s: ", section->name);
            scanf("%d", &subSecCount);
            getchar();

            for (int k = 0; k < subSecCount; k++) {
                printf("    Enter subsection name %d: ", k + 1);
                gets(name);
                subsection = createNode(name);
                section->child[section->childCount] = subsection;
                section->childCount++;
            }
        }
    }

    // Display Tree
    printf("\nBook: %s\n", book->name);
    for (int i = 0; i < book->childCount; i++) {
        printf("  Chapter: %s\n", book->child[i]->name);

        for (int j = 0; j < book->child[i]->childCount; j++) {
            printf("    Section: %s\n", book->child[i]->child[j]->name);
            
            for (int k = 0; k < book->child[i]->child[j]->childCount; k++) {
                printf("      Subsection: %s\n", book->child[i]->child[j]->child[k]->name);
            }
        }
    }

    return 0;
}
