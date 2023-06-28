#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Структура для представления узла бинарного дерева
typedef struct Node {
    char* word;
    int count;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(char* word);
Node* insert(Node* root, char* word);
void printInOrder(Node* root);
void printOutOrder(Node* root);
void freeTree(Node* root);