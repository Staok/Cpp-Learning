#include <assert.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#include "../headers/algorithm.h"

#define DEBUG_TRIE

#ifdef DEBUG_TRIE
static void trie_dfs_print(trie_node_t *x, int level, char c) {
  if (x->next != NULL) {
    if (level > 0) {
      for (int i = 0; i < level - 1; ++i)
        printf("\t");
      printf("|_[%c] 0x%lx\n", c, x->isvalue == 1 ? x->value : 0);
    }

    assert(x->next != NULL);
    for (int j = 0; j < x->next->num; ++j) {
      hashtable_bucket_t *b = x->next->directory[j];
      for (int k = 0; k < b->counter; ++k) {
        trie_node_t *subtree = (trie_node_t *)b->varray[k];
        char *key = b->karray[k];
        assert(strlen(key) >= 1);
        trie_dfs_print(subtree, level + 1, key[0]);
      }
    }
  } else {
    if (level > 0) {
      for (int i = 0; i < level - 1; ++i)
        printf("\t");
      printf("|_[%c] 0x%lx\n", c, x->isvalue == 1 ? x->value : 0);
    }
  }
}

void trie_print(trie_node_t *root) {
  if (root == NULL) {
    printf("NULL\n");
  } else  {
    printf("Print Trie:\n");
  }

  trie_dfs_print(root, 0, 0);
}
#endif

trie_node_t *trie_construct() {
  trie_node_t *root = malloc(sizeof(trie_node_t));
  root->next = hashtable_construct();
  root->isvalue = 0;
  root->value = 0;
  return root;
}

void trie_free(trie_node_t *root) {
  // two ways:
  // 1. like the mark-sweep algorithm
  // 2. recursive *
  if (root == NULL) {
    return;
  }

  // free sub trees
  hashtable_t *next_table = root->next;

  if (next_table != NULL) {
    // sub trees
    for (int i = 0; i < next_table->num; ++i) {
      hashtable_bucket_t *b = next_table->directory[i];
      for (int j = 0; j < b->counter; ++j) {
        uint64_t subtree_addr = b->varray[j];
        trie_free((trie_node_t *)subtree_addr);
      }
    }

    // free this hash table
    hashtable_free(next_table);
  }

  // free root node
  free(root);
}

trie_node_t *trie_insert(trie_node_t *root, char *key, uint64_t value) {
  trie_node_t *p = root;
  if (p == NULL) {
    return NULL;
  }

  for (int i = 0;i < strlen(key);++i) {
    if (p->next == NULL) {
      p->next = hashtable_construct();
    }
    // char as hash key
    char hashkey[2];
    hashkey[0] = key[i];
    hashkey[1] = '\0';
    uint64_t trie_node_addr;

    if (hashtable_get(p->next, hashkey, &trie_node_addr) == 1) {
      // found next node in this root
      p = (trie_node_t *)trie_node_addr;
      continue;
    } else {
      // no next node in this root
      // create new node
      trie_node_t *n = malloc(sizeof(trie_node_t));
      n->value = 0;
      n->isvalue = 0;
      n->next = NULL; // leaf node has no next

      p->next = hashtable_insert(p->next, hashkey, (uint64_t)n);
      // goto next node
      p = n;
      continue;
    }
  }

  p->value = value;
  p->isvalue = 1;
  return root;
}

trie_node_t *trie_next(trie_node_t *current, char input) {
  if (current == NULL) {
    return NULL;
  }

  // go to next
  if (current->next != NULL) {
    char hashkey[2];
    hashkey[0] = input;
    hashkey[1] = '\0';
    uint64_t trie_node_addr;
    if (hashtable_get(current->next, hashkey, &trie_node_addr) == 1) {
      return (trie_node_t *)trie_node_addr;
    }
  }
  // 1 - no mapping
  // 2 - node does not exist in mapping
  return NULL;
}

int trie_get(trie_node_t *root, char *key, uint64_t *valptr) {
  trie_node_t *p = root;
  for (int i = 0;i < strlen(key);++i) {
    if (p == NULL) {
      // not found
      return 0;
    }
    p = trie_next(p, key[i]);
  }

  if (p != NULL && p->isvalue == 1) {
    *valptr = p->value;
    return 1;
  }
  return 0;
}

