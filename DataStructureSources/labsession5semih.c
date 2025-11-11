/*
* Name: Semih Özkaplan
* Student No: 201504013
* Date: 04.11.2022
* Lab Session 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to insert node in a linked list
void insert(struct Node** root, int item)
{
    struct Node* ptr, * temp;
    /* allocate node */
    temp = (struct Node*)malloc(sizeof(struct Node));

    temp->data = item;
    temp->next = NULL;

    if (*root == NULL)
        *root = temp;
    else {
        ptr = *root;
        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
    }
}

// Function which returns new linked list
struct Node* newList(struct Node* root1, struct Node* root2)
{
    struct Node* ptr1 = root1, * ptr2 = root2, * ptr;
    struct Node* root = NULL, * temp;

    while (ptr1 != NULL) {

        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->next = NULL;

        // Compare for greater node
        if (ptr1->data < ptr2->data)
            temp->data = ptr2->data;
        else
            temp->data = ptr1->data;

        if (root == NULL)
            root = temp;
        else {
            ptr = root;
            while (ptr->next != NULL)
                ptr = ptr->next;

            ptr->next = temp;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return root;
}

void display(struct Node* root)
{
    while (root != NULL) {
        printf("%d->", root->data);
        root = root->next;
    }

    printf("\n");
}

struct Node* MergeSortedList(struct Node* node1, struct Node* node2) {

    struct Node* result = NULL;

    if (node1 == NULL)
        return node2;

    if (node2 == NULL)
        return node1;

    if (node1->data <= node2->data) {

        result = node1;
        result->next = MergeSortedList(node1->next, node2);

    }

    else
    {
        result = node2;
        result->next = MergeSortedList(node2->next, node1);
    }

    return result;

}

struct Node* reverseList(struct Node* head) {

    struct Node* current = NULL;
    struct Node* prev_node = NULL;
    struct Node* nextNode = NULL;

    current = head;

    while (current != NULL) {

        nextNode = current->next;
        current->next = prev_node;
        prev_node = current;
        current = nextNode;

    }
      
    return prev_node;

}

int isPalindrome(struct Node* head) {

    int count = 0;
    int midpoint;
    bool flag = true;

    struct Node* current = NULL;
    struct Node* traverse = NULL;

    current = head;
    traverse = head;

    while (traverse != NULL) {

        traverse = traverse->next;
        ++count;

    }

    midpoint = count / 2;

    for (int i = 0; i < midpoint - 1; i++)
    {

        if (reverseList(head)->data == current->data)
            return 1;

        else
            return 0;

    }


}

// Driver code
int main(void)
{
    struct Node* head = NULL, * tail = NULL;

    // First linked list
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 2);
    insert(&head, 0);

    display(head);

    if (isPalindrome(head) == 1) {

        printf("It is pal");

    }

    else
    {
        printf("It is not pal");
    }

    return 0;
}
