#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
  char name[20];
  struct node *root;
};

int main(void) {
  int line, count, row;
  char node[20], root[20];
  char *roots[20];
  struct node *tree[20];
  
  for (line=0; line < 100 && scanf("%s %s\n", node, root) > 0; line++) {
    tree[line] = malloc(sizeof(*tree[line]));
    strcpy(tree[line]->name, node);
    roots[line] = malloc(20*sizeof(char));
    strcpy(roots[line], root);
  }
  count = line;
  
  for (line=0; line<count; line++) {
    
    for (row=0; row<count; row++) {
      if (strcmp(roots[line], tree[row]->name) == 0) {
        tree[line]->root = tree[row];
      }
    }
    free(roots[line]);
    
    printf("node=%s root=%s\n", tree[line]->name, tree[line]->root->name);
  }
  
  for (line=0; line<count; line++) {
    free(tree[line]);
  }
  
  return 0;
}
