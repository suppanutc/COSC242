#include <stdlib.h>
#include "mylib.h"
#include "bst.h"

struct bst_node {
  char *key;
  bst left;
  bst right;
};

void bst_inorder(bst b, void f(char *s)) {
  if (b == NULL) {
    return;
  }
  bst_inorder(b->left, f);
  f(b->key);
  bst_inorder(b->right, f);
}

void bst_preorder(bst b, void f(char *s)) {
  if (b == NULL) {
    return;
  }
  f(b->key);
  bst_preorder(b->left, f);
  bst_preorder(b->right, f);
}

bst bst_new(){
  return NULL;
}

bst bst_insert(bst b, char *str){
  if (b == NULL) {
    bst result = emalloc(sizeof *b);
    result->key = str;
    return result;
  } else {
    if (b->key == str){}
    else {
      if (str < b->key) {
        b->left = bst_insert(b->left, str);
      } else if (str > b->key) {
        b->right = bst_insert(b->right, str);
      }
    }
  }
}

int bst_search(bst b, char *str) {
  if (b == NULL) {
    return 0;
  } else {
    if (b->key == str) {
      return 1;
    } else {
      if (b->key > str) {
        return bst_search(b->left, str);
      } else if (b->key < str) {
        return bst_search(b->right, str);
      }
    }
  }
}

bst bst_free(bst b) {
  if (b != NULL) {
    b->left = bst_free(b->left);
    b->right = bst_free(b->right);
    free(b->key);
    free(b);
  }
  return NULL;
}
