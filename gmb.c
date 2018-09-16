#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

int insert(int data, struct node **leaf){
  if(*leaf == 0){
      *leaf = (struct node*) malloc(sizeof(struct node));
      (*leaf)->data = data;
      (*leaf)->left = NULL;
      (*leaf)->right = NULL;
  } else if( data < (*leaf)->data ){
      insert( data, &(*leaf)->left );
  } else if( data > (*leaf)->data ){
      insert( data, &(*leaf)->right );
  }  

    return 0;
}

void destroy(struct node *leaf){
    if( leaf != NULL ){
        destroy(leaf->left);
        destroy(leaf->right);
        free(leaf);
    }
}

void postorder(struct node* node){

    if(node == NULL){
        return;
    }

    postorder(node->left);
    postorder(node->right);
    printf(" %d", node->data);
}

void inorder(struct node* node){

    if(node == NULL){
        return;
    }

    inorder(node->left);
    printf(" %d", node->data);
    inorder(node->right);
}

void preorder(struct node* node){

    if(node == NULL){
        return;
    }

    printf(" %d", node->data);
    preorder(node->left);
    preorder(node->right);

}

int main(){
    
    int testNumber, nodesNumber, element;

    scanf("%d", &testNumber);
    for(int j = 1; j < (testNumber + 1); j++){
    scanf("%d", &nodesNumber);

    for(int i = 0; i < nodesNumber; i++){
        scanf("%d", &element);
        insert(element, &root);
    }

    printf("Case %d:",j);
    printf("\nPre.:");
    preorder(root);
    printf("\nIn..:");
    inorder(root);
    printf("\nPost:");
    postorder(root);
    printf("\n");

    destroy(root);
    }
}
