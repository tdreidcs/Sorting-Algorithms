#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "bst.h"


// Public API.

TNODE *tree_add(TNODE*p, const KEY k, const VALUE v) {
	//if ((p = (double*) malloc(n * sizeof(double))) == NULL) {
	//	return NULL; //check this
	//}
	int cond;
	if (p == NULL){
		LNODE *headlist = lalloc(k);
		p = talloc(k);
		p->left = NULL;
		p->right = NULL;
		p->head = headlist;
		p->tail = headlist;
		return(p);
	}

	else if ((cond = strcmp (k, p->key)) == 0){
		LNODE *newlistitem = lalloc(k);
		p->tail->next = newlistitem;
		p->tail = newlistitem;
	}

	else if (cond<0) p->left = tree_add(p->left, k, v);
	else p->right = tree_add(p->right, k, v);
	return p;
}

TNODE *tree_find(TNODE *p, const KEY k) {
	if (p == NULL || p == k) {
		return *p;
	}
	else if (k < p) {
		p->left;
		tree_find(p, k);
	}
	else {
		p->right;
		tree_find(p, k);
	}
}

int height (const TNODE* const p) {
	long int HL = height(p->left);
	long int HR = height(p->right);
	if (HL <= HR) {
		return HL;
	}
	else {
		return HR;
	}
}

void nuke_tree(TNODE*n) {
	free(n);
}

// Internal BST functions.
TNODE *talloc(const KEY k) {
	TNODE *t = (long int *)malloc(sizeof(long int));
	if (NULL == t) {
		return NULL;
	}
	t->key = k;
	t->is_red = false;
	t->head = NULL;
	t->tail = NULL;
	t->left = NULL;
	t->right = NULL;
	return t;
}
	
LNODE *lalloc(const VALUE v) {
	TNODE *t = (long int *)malloc(sizeof(long int));
	if (NULL == t) {
		return NULL;
	}
	t->key = v;
	t->is_red = false;
	t->head = NULL;
	t->tail = NULL;
	t->left = NULL;
	t->right = NULL;
	return t;
}

// Internal red-black tree functions.
TNODE *rotate_left (TNODE *h) {
	TNODE x = h.right;
	h.right = x.left;
	x.left = h;
	x.color = h.color;
	h.color = RED;
	x.N = h.N;
	h.N = 1 + sizeof(h.left) + sizeof(h.right);
	return x;
}
	
TNODE *rotate_right (TNODE *h) {
	TNODE x = h.left;
	h.left = x.right;
	x.right = h;
	x.color = h.color;
	h.color = RED;
	x.N = h.N;
	h.N = 1 + sizeof(h.left) + sizeof(h.right);
	return x;
}
	
void flip_colors(TNODE *p) {
	p.color = RED;
	p.left.color = BLACK;
	p.right.color = BLACK;
}

bool is_red(const TNODE *p) {
	if (p->is_red) {
	return true;
	}
	else {
	return false;
	}
}
