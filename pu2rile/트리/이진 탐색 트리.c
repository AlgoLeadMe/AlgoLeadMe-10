#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

// 새로운 노드를 생성하는 함수
TreeNode* new_node(int key) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = key;
    node->left = node->right = NULL;
    return node;
}

// 전위 순회 배열을 이용해 BST를 생성하는 함수
TreeNode* construct_bst(int pre[], int* preIndex, int key, int min, int max, int size) {
    // 트리가 공백이면 NULL 반환
    if (*preIndex >= size)
        return NULL;

    TreeNode* root = NULL;

    // 현재 key가 min과 max 사이에 있을 때만 노드를 생성
    if (key > min && key < max) {
        root = new_node(key);
        *preIndex = *preIndex + 1;

        if (*preIndex < size) {
            // 왼쪽 서브트리를 구성
            root->left = construct_bst(pre, preIndex, pre[*preIndex], min, key, size);
        }
        if (*preIndex < size) {
            // 오른쪽 서브트리를 구성
            root->right = construct_bst(pre, preIndex, pre[*preIndex], key, max, size);
        }
    }
    return root;
}

// 후위 순회 함수
void post_order(TreeNode* root) {
    if (root) {
        post_order(root->left);  // 왼쪽 서브 트리 순회
        post_order(root->right); // 오른쪽 서브 트리 순회
        printf("%d\n", root->data); // 노드 방문
    }
}

int main(void) {
    int pre[10000]; // 최대 10000개의 노드를 입력받을 수 있도록 배열 크기를 지정
    int key;
    int size = 0;

    while (scanf("%d", &key) != EOF) {
        pre[size++] = key;
    }

    int preIndex = 0;
    if (size > 0) {
        TreeNode* root = construct_bst(pre, &preIndex, pre[0], INT_MIN, INT_MAX, size);
        post_order(root);
    }

    return 0;
}
