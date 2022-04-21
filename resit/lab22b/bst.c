#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mylib.h"
#include "bst.h"


struct bst_node {
    char *key;
    bst left;
    bst right;
};

bst bst_new() {
    return NULL;
}

void bst_inorder(bst b, void f(char *str)) {
    if (b == NULL) {
      return ;
    }

    bst_inorder(b->left, f);
    f(b->key);
    bst_inorder(b->right, f);

}

void bst_preorder(bst b, void f(char *str)) {
    if (b == NULL) {
      return ;
    }
      f(b->key);
      bst_preorder(b->left, f);
      bst_preorder(b->left, f);
  }

bst bst_insert(bst b, char *str){
    if (b == NULL) {
        bst result = emalloc(sizeof *result);
        result->key = str;
        result->left = NULL;
        result->right = NULL;
        return result;
    } else {
        if (b->key == str) {
        } else if (str < b->key){
            b->left = bst_insert(b->left, str);
        } else {
            b->right = bst_insert(b->right, str);
        }
        return b;
    }
}

int bst_search(bst b, char *str) {
    if (b == NULL) {return 0;}
    if (str < b->key) {
        bst_search(b->left, str);
    } else if (str > b->key) {
        bst_search(b->right, str);
    } else if (str == b->key) {
        return 1;
    } else {
        return 0;
    }
}

void bst_test(bst b) {
  printf("%s\n", b->right->right->key);
}

bst bst_free(bst b){
  if (b==NULL) {
    return NULL;
  }
    b->left = bst_free(b->left);
    b->right = bst_free(b->right);
    free(b);
    return NULL;
}
