#include "func.h"

// Функция для создания нового узла
Node* createNode(char* word) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->count = 1;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Функция для добавления слова в бинарное дерево
Node* insert(Node* root, char* word) {
    if (root == NULL) {
        return createNode(word);
    }

    int cmp = strcmp(word, root->word);
    if (cmp == 0) {
        root->count++;
    } else if (cmp < 0) {
        root->left = insert(root->left, word);
    } else {
        root->right = insert(root->right, word);
    }
    
    return root;
}

// Функция для вывода слов и их частоты повторения в алфавитном порядке
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%s - %d\n", root->word, root->count);
        printInOrder(root->right);
    }
}

// Функция для вывода слов и их частоты повторения в обратном алфавитном порядке
void printOutOrder(Node* root) {
    if (root != NULL) {
        printOutOrder(root->right);
        printf("%s - %d\n", root->word, root->count);
        printOutOrder(root->left);
        
    }
}

// Функция для освобождения памяти, занятой бинарным деревом
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root->word);
        free(root);
    }
}