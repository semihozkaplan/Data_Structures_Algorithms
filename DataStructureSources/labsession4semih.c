/*
* Semih Özkaplan
* Lab Session 4
* Date: 31.10.2022
*/

// C program to create a new linked list
// from two given linked list
// of the same size with
// the greater element among the two at each node

#include <stdio.h>
#include<stdlib.h>

// Representation of node
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

void push(struct Node** head_ref, int data) {

    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;

}

void sortedLinkedList(struct Node* a)
{
    struct Node* node = NULL, * head = NULL;
    int temp;
    node = a;

    while (node != NULL)
    {
        head = node;
        while (head->next != NULL)
        {
            if (head->data > head->next->data)
            {
                temp = head->data;
                head->data = head->next->data;
                head->next->data = temp;
            }
            head = head->next;    
        }
        node = node->next;    
    }
}


void intersectTwoLinkedList(struct Node* a, struct Node* b) {
    
    int count = 1;

    while (a != NULL) {
            
        while (a != NULL && b != NULL)
        {
           
        if (a->data == b->data)
        {
            printf("The %d. Intersect-> %d\n",count, a->data);
            b = b->next;
            ++count;
        }

        else
        {
            b = b->next;
        }
     
        a = a->next;

        }

    }

}

void display(struct Node* root)
{
    while (root != NULL) {
        printf("%d->", root->data);
        root = root->next;
    }

    printf("\n");
}

// Driver code
int main()
{

    struct Node* root1 = NULL, * root2 = NULL, * root = NULL;
    
    // First linked list
    insert(&root1, 5);
    insert(&root1, 2);
    insert(&root1, 3);

    printf("First List:  ");
    display(root1);

    // Second linked list
    insert(&root2, 1);
    insert(&root2, 2);
    insert(&root2, 3);

    printf("Second List: ");
    display(root2);

    // Intersect Part
    intersectTwoLinkedList(root1, root2);
    printf("\n");
    
    // Merge
    insert(&root1, root2->data);
    insert(&root1, root2->next->data);
    insert(&root1, root2->next->next->data);
    
    // After Merge, Apply Bubble Sort 
    sortedLinkedList(root1);

    printf("Merge List: ");
    display(root1);
    printf("\n");

    
    return 0;
}
