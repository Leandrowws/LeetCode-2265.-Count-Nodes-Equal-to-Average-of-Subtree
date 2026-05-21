#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

struct TreeNode* Insert(struct TreeNode* root, int val) {
    if(root == NULL) {
        struct TreeNode *aux = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        aux->val = val;
        aux->left = NULL;
        aux->right = NULL;
        return aux;
    } else {
        if(val < root->val) {
            root->left = Insert(root->left, val);
        } else {
            root->right = Insert(root->right, val);
        }
        return root;
    }
}

typedef struct {
    int qtdNos;
    int somaNos;
}Info;

Info Dados(struct TreeNode *root, int *cont) {
    Info info;

    if(root==NULL) {
        info.qtdNos = 0;
        info.somaNos = 0;
        return info;
    } 

    Info esq = Dados(root->left, cont);
    Info dir = Dados(root->right, cont);

    info.qtdNos = 1 + esq.qtdNos + dir.qtdNos;
    info.somaNos = root->val + esq.somaNos + dir.somaNos;

    if(info.somaNos / info.qtdNos == root->val) {
        (*cont)++;
    }

    return info;
}

int averageOfSubtree(struct TreeNode* root) {

    int cont = 0;

    Dados(root, &cont);
    
    return cont;
}

void Imprimir(struct TreeNode *root) {
    if(root != NULL)  {
        Imprimir(root->left);
        printf("%d ", root->val);
        Imprimir(root->right);
    }
}

void FreeArv(struct TreeNode *root) {
    if(root!=NULL) {
        FreeArv(root->left);
        FreeArv(root->right);
        free(root);
    }
}

int main() {
    struct TreeNode* arv = NULL; 

    arv = Insert(arv, 10);
    arv = Insert(arv, 9);
    arv = Insert(arv, 11);
    arv = Insert(arv, 8);
    arv = Insert(arv, 12);
    arv = Insert(arv, 7);
    arv = Insert(arv, 13);
 
    Imprimir(arv);

    printf("\n------------------\nNumero de nodos com a media de sua subarvore igual ao seu valor: %d\n------------------\n", averageOfSubtree(arv));

    FreeArv(arv);

    return 0;
}
