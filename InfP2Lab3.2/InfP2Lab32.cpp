// InfP2Lab3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <stdlib.h>
#include <conio.h>

struct Tree
{
	int key;
	Tree *left;
	Tree *right;
};

void deepRecurse(Tree *tree);
void showTree(Tree *tree);
Tree *addElement(Tree *tree, Tree *newElement);
Tree createElement();
Tree createDefaultElement(int n);
Tree *search(Tree *tree, int find);
void findElement(Tree *tree);
Tree *maximum(Tree *tree);
void remove(Tree *tree);
Tree *removeElement(Tree *tree, Tree *element);
void outMenu();
void menu(Tree *tree);

void main()
{
	outMenu();

	Tree Head = { 19, NULL, NULL };

	addElement(&Head, &createDefaultElement(10));
	addElement(&Head, &createDefaultElement(1));
	addElement(&Head, &createDefaultElement(15));
	addElement(&Head, &createDefaultElement(12));
	addElement(&Head, &createDefaultElement(17));
	addElement(&Head, &createDefaultElement(40));
	addElement(&Head, &createDefaultElement(22));
	addElement(&Head, &createDefaultElement(54));
	menu(&Head);
}

void showTree(Tree *tree)
{
	deepRecurse(tree);
	printf("\n");
}

void deepRecurse(Tree *tree)
{
	if (tree == NULL)
	{
		return;
	}
	printf("%d, ", tree->key);
	deepRecurse(tree->left);
	deepRecurse(tree->right);
}

Tree *addElement(Tree *tree, Tree *newElement)
{
	if (tree == NULL)
	{
		return newElement;
	}
	if (tree->key > newElement->key)
	{
		tree->left = addElement(tree->left, newElement);
	}
	else
	{
		tree->right = addElement(tree->right, newElement);
	}
	return tree;
}

Tree createElement()
{
	Tree tree;
	printf("Input vertex: ");
	scanf("%d", &tree.key);
	tree.left = NULL;
	tree.right = NULL;
	printf("---Added---\n");
	return tree;
}

Tree createDefaultElement(int n)
{
	Tree tree;
	tree.key = n;
	tree.left = NULL;
	tree.right = NULL;
	return tree;
}

Tree *maximum(Tree *tree)
{
	if (tree->right == NULL)
	{
		return tree;
	}
	return maximum(tree->right);
}

Tree *search(Tree *tree, int find)
{
	if (tree == NULL || find == tree->key)
	{
		return tree;
	}
	if (find < tree->key)
	{
		return search(tree->left, find);

	}
	else
	{
		return search(tree->right, find);
	}
}

void findElement(Tree *tree)
{
	int find;
	printf("Input element to find: ");
	scanf("%d", &find);
	printf("Key: %d\n", search(tree, find)->key);
	if (search(tree, find)->left == NULL)
	{
		printf("Left: NO\n");
	}
	else
	{
		printf("Left: %d\n", search(tree, find)->left->key);
	}
	if (search(tree, find)->right == NULL)
	{
		printf("Right: NO\n");
	}
	else
	{
		printf("Right: %d\n", search(tree, find)->right->key);
	}
}

void remove(Tree *tree)
{
	int remove;
	printf("Input number to delete: ");
	scanf("%d", &remove);
	removeElement(tree, search(tree, remove));
	printf("---Removed---\n");
}

Tree *removeElement(Tree *tree, Tree *element)
{
	if (tree == NULL)
	{
		return tree;
	}
	if (tree->key > element->key)
	{
		tree->left = removeElement(tree->left, element);
	}
	else if (tree->key < element->key)
	{
		tree->right = removeElement(tree->right, element);
	}
	else if (tree->left != NULL && tree->right != NULL)
	{
		tree->key = maximum(tree->left)->key;
		tree->left = removeElement(tree->left, tree);
	}
	else if (tree->left != NULL)
	{
		tree = tree->left;
	}
	else
	{
		tree = tree->right;
	}
	return tree;
}

void outMenu()
{
	printf("Select an action\n");
	printf("| 1 | Show tree      |\n");
	printf("----------------------\n");
	printf("| 2 | Add element    |\n");
	printf("----------------------\n");
	printf("| 3 | Remove Element |\n");
	printf("----------------------\n");
	printf("| 4 | Search Element |\n");
	printf("----------------------\n");
	printf("| 0 | Exit           |\n");
	printf("----------------------\n");
}

void menu(Tree *tree)
{
	while (true)
	{
		int key = _getch();
		switch (key)
		{
		case 0x31:
			showTree(tree);
			break;
		case 0x32:
			addElement(tree, &createElement());;
			break;
		case 0x33:
			remove(tree);
			break;
		case 0x34:
			findElement(tree);
			break;
		case 0x30:
			exit(0);
			break;
		}
	}
}