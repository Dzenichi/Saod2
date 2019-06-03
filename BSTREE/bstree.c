#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"
#include <string.h>

struct bstree *bstree_create(char *key, int value)			//Создание узла.
{
    struct bstree *node;

    node = malloc(sizeof(*node));
	if (node != NULL) {
		node->key = key;
		node->value = value;
		node->left = NULL;
		node->right = NULL;
	}
	return node;
}

void bstree_add(struct bstree *tree, char *key, int value)		//Добавление элемента в BST.
{
	if (tree == NULL)
		return;
	struct bstree *parent, *node;
	while (tree != NULL) {
		parent = tree;
		if (strcmp(key, tree->key) < 0)
			tree = tree->left;
		else if (strcmp(key, tree->key) > 0)
			tree = tree->right;
		else
			return;
	}
	node = bstree_create(key, value);
	if (strcmp(key, parent->key) < 0)
		parent->left = node;
	else
		parent->right = node;
}

struct bstree *bstree_lookup(struct bstree *tree, char *key)	//Поиск элемента в BST.
{
	while (tree != NULL) {
		if (strcmp(key, tree->key) == 0)
			return tree;
		else if (strcmp(key, tree->key) < 0)
			tree = tree->left;
		else
			tree = tree->right;
	}
	printf("Node not found\n");
	return NULL;
}

struct bstree *bstree_min(struct bstree *tree)		//Поиск минимального значения.
{
	if (tree == NULL)
		return NULL;

	while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

struct bstree *bstree_max(struct bstree *tree) //Поиск максимального значения.
{
	if (tree == NULL)
		return NULL;

	while (tree->right != NULL)
		tree = tree->right;
	return tree;
}

void bstree_delete(struct bstree *tree, char *key)
{
	struct bstree *predoc, *root, *copy;

		while (tree != NULL) {
			if (strcmp(key, tree->key) == 0)
				break;
			else if (strcmp(key, tree->key) < 0){
				predoc = tree;
				tree = tree->left;
			}
			else{
				predoc = tree;
				tree = tree->right;
			}
		}
		root = tree->right;

		if((tree->right == NULL) && (tree->left == NULL)){
			if(tree == predoc->left){
				free(tree);
				predoc->left = NULL;
			}else if(tree == predoc->right){
				free(tree);
				predoc->right = NULL;
			}			
			return;
		}
	
		if((tree->right != NULL) && (tree->left == NULL)){
			if(predoc->right == tree)
				predoc->right = tree->right;
			else if(predoc->left == tree)
				predoc->left = tree->right;
			free(tree);
			return;
		}

		if((tree->right == NULL) && (tree->left != NULL)){
			if(predoc->right == tree)
				predoc->right = tree->left;
			else if(predoc->left == tree)
				predoc->left = tree->left;
			free(tree);
			return;
		}

		if((tree->right != NULL) && (tree->left != NULL)){
			struct bstree *min_tree, *predoc_two;
			min_tree = root;
			predoc_two = min_tree;
			while (min_tree->left != NULL){
				predoc_two = min_tree;
				min_tree = min_tree->left;
			}
			tree->key = min_tree->key;
			tree->value = min_tree->value;

			if((min_tree->right != NULL) && (min_tree->left == NULL)){
					predoc_two->left = min_tree->right;
			} else
				predoc_two->left = NULL;

			free(min_tree);
		}

}