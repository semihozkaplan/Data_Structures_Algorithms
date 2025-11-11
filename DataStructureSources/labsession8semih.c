/*
* Name Surname: Semih Özkaplan
* Student No: 201504013
* Lab Session 8
* Date: 09.12.2022
*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

struct Root {

	int value;
	struct Root* right;
	struct Root* left;

};

struct root* newNode(int x) {

	struct Root* root = (struct Root*)malloc(sizeof(struct Root));

	root->value = x;

	root->left = NULL;
	root->right = NULL;

	return root;

}

void printTree(struct Root* root) {

	if (root->left)
		printTree(root->left);
	printf("%d\n", root->value);

	if (root->right)
		printTree(root->right);
}

int main(void) {

	struct Root* r1 = NULL;

	//r1 = newNode(50);
	//r1->left = newNode(30);
	//r1->right = newNode(20);
	//r1->left->left = newNode(10);
	//r1->right->right = newNode(70);
	//r1->right->right->right = newNode(90);
	//r1->right->right->left = newNode(80);

	r1 = newNode(10);
	r1->left = newNode(20);
	r1->left->right = newNode(40);
	r1->left->right->left = newNode(70);
	r1->right = newNode(30);
	r1->right->left = newNode(50);
	r1->right->right = newNode(60);
	r1->right->right->left = newNode(80);

	printTree(r1);


	return 0;
}

