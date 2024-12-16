#include <assert.h>
#include <endian.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/algorithm.h"
#include "../headers/color.h"
#include "../headers/common.h"

// We should know that "i_node" is only used for performance polymorphism

void rbt_validate_interface(rbtree_node_interface *i_node, uint64_t flags) {
  assert(i_node != NULL);
  if ((flags & IRBT_CONSTRUCT) != 0) {
    assert(i_node->construct_node != NULL);
  }
  if ((flags & IRBT_DESTRUCT) != 0) {
    assert(i_node->destruct_node != NULL);
  }
  if ((flags & IRBT_CHECKNULL) != 0) {
    assert(i_node->is_null_node != NULL);
  }
  if ((flags & IRBT_COMPARE) != 0) {
    assert(i_node->compare_nodes != NULL);
  }
  if ((flags & IRBT_PARENT) != 0) {
    assert(i_node->get_parent != NULL);
    assert(i_node->set_parent != NULL);
  }
  if ((flags & IRBT_LEFT) != 0) {
    assert(i_node->get_leftchild != NULL);
    assert(i_node->set_leftchild != NULL);
  }
  if ((flags & IRBT_RIGHT) != 0) {
    assert(i_node->get_rightchild != NULL);
    assert(i_node->set_rightchild != NULL);
  }
  if ((flags & IRBT_COLOR) != 0) {
    assert(i_node->get_color != NULL);
    assert(i_node->set_color != NULL);
  }
  if ((flags & IRBT_KEY) != 0) {
    assert(i_node->get_key != NULL);
    assert(i_node->set_key != NULL);
  }
}

void bst_internal_setchild(uint64_t parent, uint64_t child, child_t direction,
                           rbtree_node_interface *i_node) {
  rbt_validate_interface(i_node, IRBT_COMPARE | IRBT_CHECKNULL | IRBT_LEFT | IRBT_RIGHT);
  switch(direction) {
    case LEFT_CHILD:
      i_node->set_leftchild(parent, child);
      if (i_node->is_null_node(child) == 0) {
        i_node->set_parent(child, parent);
      }
      break;
    case RIGHT_CHILD:
      i_node->set_rightchild(parent, child);
      if (i_node->is_null_node(child) == 0) {
        i_node->set_parent(child, parent);
      }
      break;
    default:
      assert(0);
  }
}

void bst_internal_replace(uint64_t victim, uint64_t node,
                          rbtree_internal_t *tree,
                          rbtree_node_interface *i_node) {
  rbt_validate_interface(i_node, IRBT_COMPARE | IRBT_CHECKNULL | IRBT_PARENT |
                                     IRBT_LEFT | IRBT_RIGHT);
  assert(i_node->is_null_node(victim) == 0);
  assert(i_node->is_null_node(tree->root) == 0);

  uint64_t v_parent = i_node->get_parent(victim);
  if (i_node->compare_nodes(tree->root, victim) == 0) { // the same
    // victim is root
    assert(i_node->is_null_node(v_parent) == 1);
    tree->update_root(tree, node);
    i_node->set_parent(node, NULL_ID);
    return;
  } else {
    // victim has parent
    uint64_t v_parent_left = i_node->get_leftchild(v_parent);
    uint64_t v_parent_right = i_node->get_rightchild(v_parent);

    if (i_node->compare_nodes(v_parent_left, victim) == 0) {
      bst_internal_setchild(v_parent, node, LEFT_CHILD, i_node);
      return;
    } else if (i_node->compare_nodes(victim, v_parent_right) == 0) {
      bst_internal_setchild(v_parent, node, RIGHT_CHILD, i_node);
      return;
    } else {
      assert(0);
    }
  }
}

void bst_internal_insert(rbtree_internal_t *tree, rbtree_node_interface *i_node,
                         uint64_t node_id) {
  if (tree == NULL) {
    return;
  }
  assert(tree->update_root != NULL);
  rbt_validate_interface(i_node, IRBT_CHECKNULL | IRBT_PARENT | IRBT_LEFT |
                                     IRBT_RIGHT | IRBT_COLOR | IRBT_KEY);
  assert(i_node->is_null_node(node_id) == 0);

  uint64_t x = node_id;
  if (i_node->is_null_node(tree->root) == 1) {
    i_node->set_parent(x, NULL_ID);
    i_node->set_leftchild(x, NULL_ID);
    i_node->set_rightchild(x, NULL_ID);
    // For RBT create its root
    i_node->set_color(x, COLOR_BLACK);

    tree->update_root(tree, x);
    return;
  }

  uint64_t p = tree->root; // parent iterator
  uint64_t x_key = i_node->get_key(x);

  while(i_node->is_null_node(p) == 0) {
    uint64_t p_key = i_node->get_key(p);

    if (x_key < p_key) {
      uint64_t p_left = i_node->get_leftchild(p);

      if (i_node->is_null_node(p_left) == 1) {
        bst_internal_setchild(p, x, LEFT_CHILD, i_node);
        return;
      } else {
        p = p_left;
      }
    } else { // if (x_key <= p_key)
      uint64_t p_right = i_node->get_rightchild(p);

      if (i_node->is_null_node(p_right) == 1) {
        bst_internal_setchild(p, x, RIGHT_CHILD, i_node);
        return;
      } else {
        p = p_right;
      }
    }
  }
}

void bst_internal_delete(rbtree_internal_t *tree, rbtree_node_interface *i_node,
                         uint64_t node_id, int is_rbt, uint64_t *db_parent) {
  *db_parent = NULL_ID;
  if (tree == NULL) {
    return;
  }
  assert(tree->update_root != NULL);
  rbt_validate_interface(i_node, IRBT_CHECKNULL | IRBT_PARENT | IRBT_RIGHT |
                                     IRBT_LEFT | IRBT_COLOR | IRBT_KEY);

  if (i_node->is_null_node(tree->root) == 1) {
    // nothing to delete
    return;
  }
  if (i_node->is_null_node(node_id) == 1) {
    // delete a null
    return;
  }

  uint64_t x = node_id;
  uint64_t x_left = i_node->get_leftchild(x);
  uint64_t x_right = i_node->get_rightchild(x);
  int is_x_left_null = i_node->is_null_node(x_left);
  int is_x_right_null = i_node->is_null_node(x_right);

  if (is_x_left_null == 1 && is_x_right_null == 1) {
    // case 1: left node: (x,#,#)
    if (is_rbt == 1) {
      rb_color_t x_color = i_node->get_color(x);
      if (x_color == COLOR_BLACK) {
        // null is double black
        // report double black node to RBT
        // may report NULL to RBT delete
        // then x is the root node, no db rebalancing
        *db_parent = i_node->get_parent(x);
      }
    }
    bst_internal_replace(x, NULL_ID, tree, i_node);
    return;

  } else if (is_x_left_null == 1 || is_x_right_null == 1) {
    // case 2: only one null child
    // (x,y,#) or (x,#,y)
    if (is_rbt == 1) {
      assert(i_node->get_color(x) == COLOR_BLACK);
    }
    // the only non-null sub-tree
    uint64_t y = NULL_ID;
    if (is_x_left_null == 0) {
      y = x_left;
    } else if (is_x_right_null == 0) {
      y = x_right;
    } else {
      assert(0);
    }

    if (is_rbt == 1) {
      // left child should be the red leaf node
      assert(i_node->get_color(y) == COLOR_RED);
      assert(i_node->is_null_node(i_node->get_leftchild(y)) == 1);
      assert(i_node->is_null_node(i_node->get_rightchild(y)) == 1);
      i_node->set_color(y, COLOR_BLACK);
    }
    bst_internal_replace(x, y, tree, i_node);
    return;

  } else {
    // case 3: no null child: (x,A,B)
    // check the n->right->left.
    //         X                 B
    //       /   \             /   \
    //      A     B      =>   A     X
    //          /   \             /   \
    //         #     C           #     C
    uint64_t x_right_left = i_node->get_leftchild(x_right);
    int is_x_right_left_null = i_node->is_null_node(x_right_left);

    // successor
    uint64_t s = x_right;

    // swap the position: x and successor
    if (is_x_right_left_null == 1) {
      // 3.1 x.right is the successor
      i_node->set_rightchild(x, NULL_ID);
      i_node->set_parent(s, NULL_ID);
      bst_internal_replace(x, s, tree, i_node);

      bst_internal_setchild(s, x_left, LEFT_CHILD, i_node);
      bst_internal_setchild(x, i_node->get_rightchild(s), RIGHT_CHILD, i_node);
      bst_internal_setchild(x, NULL_ID, LEFT_CHILD, i_node);
      bst_internal_setchild(s, x, RIGHT_CHILD, i_node);
    } else {
      // 3.2 x.right.left...left is the successor
      //         X                   Ln
      //       /   \               /   \
      //      A     B      =>     A     B
      //          /   \               /   \
      //         L1    R1            L1    R1
      //        /   \               /   \
      //       Ln    Rn            X    Rn
      //     /   \               /   \
      //    #     Rn+1          #     Rn-1
      s = x_right;
      uint64_t s_left = i_node->get_leftchild(s);
      while (i_node->is_null_node(s_left) == 0) {
        s = s_left;
        s_left = i_node->get_leftchild(s);
      }
      uint64_t s_parent = i_node->get_parent(s);
      assert(i_node->is_null_node(s_parent) == 0); // must be not null

      // swap
      bst_internal_setchild(x, i_node->get_rightchild(s), RIGHT_CHILD, i_node);
      bst_internal_setchild(x, NULL_ID, LEFT_CHILD, i_node);
      bst_internal_setchild(s, x_left, LEFT_CHILD, i_node);
      bst_internal_setchild(s, x_right, RIGHT_CHILD, i_node);

      bst_internal_replace(x, s, tree, i_node);
      bst_internal_setchild(s_parent, x, LEFT_CHILD, i_node);
    }

    if (is_rbt == 1) {
      // swap node and successor color
      rb_color_t x_color = i_node->get_color(x);
      i_node->set_color(x, i_node->get_color(s));
      i_node->set_color(s, x_color);
    }
    // NOTE : switch to case 1 and case 2, we will delete X in case1/2
    assert(i_node->is_null_node(x) == 0);
    assert(i_node->is_null_node(i_node->get_leftchild(x)) == 1);
    bst_internal_delete(tree, i_node, x, is_rbt, db_parent);

    return;
  }
}

uint64_t bst_internal_find(rbtree_internal_t *tree,
                           rbtree_node_interface *i_node, uint64_t key) {
  if (tree == NULL) {
    return NULL_ID;
  }
  rbt_validate_interface(i_node, IRBT_CHECKNULL | IRBT_LEFT | IRBT_RIGHT | IRBT_KEY);
  if (i_node->is_null_node(tree->root) == 1) {
    return NULL_ID;
  }

  uint64_t p = tree->root;

  while (i_node->is_null_node(p) == 0) {
    uint64_t p_key = i_node->get_key(p);
    if (key == p_key) {
      return p;
    } else if (key < p_key){
      p = i_node->get_leftchild(p);
    } else {
      p = i_node->get_rightchild(p);
    }
  }
  return NULL_ID;
}

uint64_t bst_internal_find_succ(rbtree_internal_t *tree,
                                rbtree_node_interface *i_node, uint64_t key) {
  if (tree == NULL) {
    return NULL_ID;
  }
  rbt_validate_interface(i_node, IRBT_CHECKNULL | IRBT_LEFT | IRBT_RIGHT | IRBT_KEY);
  if (i_node->is_null_node(tree->root) == 1) {
    return NULL_ID;
  }

  uint64_t p = tree->root;
  uint64_t successor = NULL_ID;
  uint64_t successor_key = 0x7FFFFFFFFFFFFFFF;

  while (i_node->is_null_node(p) == 0) {
    uint64_t p_key = i_node->get_key(p);
    if (key == p_key) {
      return p;
    } else if (key < p_key){
      if (p_key <= successor_key) {
        successor = p;
        successor_key = p_key;
      }
      p = i_node->get_leftchild(p);
    } else {
      p = i_node->get_rightchild(p);
    }
  }
  // if no node key <= target key, return NULL_ID
  return successor; /// reutnr supremum(上确界)
}

static void bst_internal_dfs_print(uint64_t node, rbtree_node_interface *i_node,
                                   int depth) {
  rbt_validate_interface(i_node, IRBT_CHECKNULL | IRBT_LEFT | IRBT_RIGHT |
                                     IRBT_KEY | IRBT_COLOR);

  if (depth >= 10) {
    // meanless to print depth >= 10
    printf("*");
    return;
  }

  if (i_node->is_null_node(node) == 1) {
    printf("#");
    return;
  }

  if (i_node->get_color(node) == COLOR_RED) {
    printf("(0x%lx/%lu:"REDSTR("%lu")",", node, node, i_node->get_key(node));
  } else {
    printf("(0x%lx/%lu:%lu,", node, node, i_node->get_key(node));
  }

  bst_internal_dfs_print(i_node->get_leftchild(node), i_node, depth + 1);
  printf(",");
  bst_internal_dfs_print(i_node->get_rightchild(node), i_node, depth + 1);
  printf(")");
}

void bst_internal_print(uint64_t node, rbtree_node_interface *i_node) {
  bst_internal_dfs_print(node, i_node, 0);
  printf("\n");
}

// -------------------------------------
//       For Unit Test
// -------------------------------------
void internal_tree_construct_keystr(rbtree_internal_t *tree,
                                    rbtree_node_interface *i_node, char *str) {
  assert(tree != NULL);
  assert(tree->update_root != NULL);
  rbt_validate_interface(i_node, IRBT_CHECKNULL | IRBT_COMPARE |
                                     IRBT_CONSTRUCT | IRBT_PARENT | IRBT_LEFT |
                                     IRBT_RIGHT | IRBT_KEY | IRBT_VALUE);

  uint64_t todo = 1;
  uint64_t stack[1000];
  int top = -1;

  int i = 0;
  while (i < strlen(str)) {
    if (str[i] == '(') {
      // push the node as being processed
      top++;

      uint64_t x = i_node->construct_node();
      i_node->set_parent(x, NULL_ID);
      i_node->set_leftchild(x, todo);
      i_node->set_rightchild(x, todo);

      int j = i +1;
      while('0' <= str[j] && str[j] <= '9') {
        ++j;
      }
      i_node->set_key(x, string2uint_range(str, i + 1, j - 1));

      // push to stack
      stack[top] = x;

      // move to next node
      i = j + 1;
      continue;
    } else if (str[i] == ')') {
      // pop the beinbg processed node
      if (top == 0) {
        // pop root
        uint64_t first = stack[0];
        uint64_t first_left = i_node->get_leftchild(first);
        uint64_t first_right = i_node->get_rightchild(first);

        assert(i_node->compare_nodes(first_left, todo) != 0 &&
               i_node->compare_nodes(first_right, todo) != 0);

        tree->update_root(tree, first);
        return;
      }

      // pop a non-root node
      uint64_t p = stack[top - 1]; // the parent of the top
      uint64_t t = stack[top];     // the poped top can be left or parent

      // when top pop, its left & right subtree are all reduced
      assert(i_node->compare_nodes(i_node->get_leftchild(t), todo) != 0 &&
             i_node->compare_nodes(i_node->get_rightchild(t), todo) != 0);

      // pop this node
      top--;

      uint64_t p_left = i_node->get_leftchild(p);
      uint64_t p_right = i_node->get_rightchild(p);
      if (i_node->compare_nodes(p_left, todo) == 0) {
        i_node->set_leftchild(p, t);
        i_node->set_parent(t, p);
        i++;
        continue;
      } else if (i_node->compare_nodes(p_right, todo) == 0) {
        i_node->set_rightchild(p, t);
        i_node->set_parent(t, p);
        i++;
        continue;
      }
      printf("node %lx:%lx is not having any unprocessed sub-tree\n  while "
             "%lx:%lx is redblack into it.\n",
             p, i_node->get_key(p), t, i_node->get_key(t));
      assert(0);
    } else if (str[i] == '#') {
      if (top < 0) {
        assert(strlen(str) == 1);
        return;
      }

      uint64_t top_id = stack[top];
      if (i_node->compare_nodes(i_node->get_leftchild(top_id), todo) == 0) {
        i_node->set_leftchild(top_id, NULL_ID);
        i++;
        continue;
      }else if (i_node->compare_nodes(i_node->get_rightchild(top_id), todo) == 0) {
        i_node->set_rightchild(top_id, NULL_ID);
        i++;
        continue;
      }
      printf("node %lx:(%lx) is not having any unprocessed sub-tree\n  while "
             "NULL is redblack into it.\n",
             top_id, i_node->get_key(top_id));
      assert(0);
    } else {
      i++;
      continue;
    }
  }
}

int internal_tree_compare(uint64_t a, uint64_t b, rbtree_node_interface *i_node,
                          int is_rbt) {
  rbt_validate_interface(i_node, IRBT_CHECKNULL | IRBT_PARENT | IRBT_LEFT |
                                     IRBT_RIGHT | IRBT_COLOR | IRBT_KEY);

  int is_a_null =i_node->is_null_node(a);
  int is_b_null =i_node->is_null_node(b);

  if (is_a_null == 1 && is_b_null == 1) {
    return 1;
  }

  if (is_a_null == 1 || is_b_null == 1) {
    return 1;
  }

  // both not NULL
  if (i_node->get_key(a) == i_node->get_key(b)) {
    uint64_t a_p = i_node->get_parent(a);
    uint64_t b_p = i_node->get_parent(b);

    int is_ap_null = i_node->is_null_node(a_p);
    int is_bp_null = i_node->is_null_node(b_p);

    if (is_ap_null == 0) {
      uint64_t ap_key = i_node->get_key(a_p);
      uint64_t bp_key = i_node->get_key(b_p);
      if (ap_key != bp_key) {
        return 0;
      }
    }

    if (is_rbt == 0) {
      return internal_tree_compare(i_node->get_leftchild(a),
                                   i_node->get_leftchild(b), i_node, is_rbt) &&
             internal_tree_compare(i_node->get_rightchild(a),
                                   i_node->get_rightchild(b), i_node, is_rbt);
    } else if (is_rbt == 1) {
      if (i_node->get_color(a) == i_node->get_color(b)) { // TODO Why?
        return internal_tree_compare(i_node->get_leftchild(a),
                                     i_node->get_leftchild(b), i_node,
                                     is_rbt) &&
               internal_tree_compare(i_node->get_rightchild(a),
                                     i_node->get_rightchild(b), i_node, is_rbt);
      }
    }
    assert(0);
  }

  return 0;
}

static void rbt_verify_dfs(uint64_t p, uint64_t *black_height,
                           uint64_t *key_min, uint64_t *key_max,
                           rbtree_node_interface *i_node, int is_rbt) {
  rbt_validate_interface(i_node, IRBT_CHECKNULL | IRBT_PARENT | IRBT_LEFT |
                                     IRBT_RIGHT | IRBT_COLOR | IRBT_KEY);

  if (i_node->is_null_node(p) == 1) {
    *black_height = 0;
    *key_min = 0xFFFFFFFFFFFFFFFF;
    *key_max = 0;
    return;
  }

  uint64_t p_left = i_node->get_leftchild(p);
  uint64_t p_right = i_node->get_rightchild(p);
  rb_color_t p_color = i_node->get_color(p);
  uint64_t p_key = i_node->get_key(p);

  // verify left sub-tree
  uint64_t p_left_bh = 0xFFFFFFFFFFFFFFFF;
  uint64_t p_left_key_min = 0xFFFFFFFFFFFFFFFF;
  uint64_t p_left_key_max = 0xFFFFFFFFFFFFFFFF;
  rbt_verify_dfs(p_left, &p_left_bh, &p_left_key_min, &p_left_key_max, i_node,
                 is_rbt);

  // verify right sub-tree
  uint64_t p_right_bh = 0xFFFFFFFFFFFFFFFF;
  uint64_t p_right_key_min = 0xFFFFFFFFFFFFFFFF;
  uint64_t p_right_key_max = 0xFFFFFFFFFFFFFFFF;
  rbt_verify_dfs(p_right, &p_right_bh, &p_right_key_min, &p_right_key_max,
                 i_node, is_rbt);

  if (is_rbt == 1) {
    assert(p_left_bh == p_right_bh);
    if (p_color == COLOR_RED) {
      assert(i_node->get_color(p_left) == COLOR_BLACK);
      assert(i_node->get_color(p_right) == COLOR_BLACK);
      *black_height = p_left_bh;
    } else if (p_color == COLOR_BLACK) {
      *black_height = p_left_bh + 1;
    } else {
      assert(0);
    }
  }

  // check key -RBT & BST
  *key_min = p_key;
  *key_max = p_key;
  if (i_node->is_null_node(p_left) == 0) {
    assert(p_left_key_max <= p_key);
    *key_min = p_left_key_min;
  }
  if (i_node->is_null_node(p_right) == 0) {
    assert(p_key <= p_right_key_min);
    *key_max = p_right_key_max;
  }
}

void rbt_internal_verify(rbtree_internal_t *tree, rbtree_node_interface *i_node,
                         int is_rbt) {
  if (tree == NULL) {
    return;
  }
  rbt_validate_interface(i_node, IRBT_CHECKNULL | IRBT_COLOR);

  uint64_t root = tree->root;
  if (i_node->is_null_node(root) == 1) {
    // empty tree
    return;
  }

  if (is_rbt == 1) {
    // assert root is black
    assert(i_node->get_color(root) == COLOR_BLACK);
  }

  uint64_t tree_bh = 0;
  uint64_t tree_min = 0xFFFFFFFFFFFFFFFF;
  uint64_t tree_max = 0;
  rbt_verify_dfs(root, &tree_bh, &tree_min, &tree_max, i_node, is_rbt);
}

// =====================================
//         Default Implementation
// =====================================
//Implementation of BST node access
static int is_null_node(uint64_t node_id) {
  if (node_id == NULL_ID) {
    return 1;
  }
  return 0;
}

static uint64_t construct_node() {
  rb_node_t *node = malloc(sizeof(rb_node_t));
  if (node != NULL) {
    node->parent = NULL;
    node->left = NULL;
    node->right = NULL;
    node->color = COLOR_BLACK;
    node->key = 0;
    node->value = 0;

    return (uint64_t)node;
  }
  return NULL_ID;
}

static int destruct_node(uint64_t node_id) {
  if (is_null_node(node_id) == 1) {
    return 0;
  }
  rb_node_t *ptr = (rb_node_t *)node_id;
  if (ptr != NULL) {
    free(ptr);
  }
  return 1;
}

static int compare_nodes(uint64_t first, uint64_t second) {
  return !(first == second);
}

static uint64_t get_parent(uint64_t node_id) {
  if (is_null_node(node_id) == 1) {
    return NULL_ID;
  }
  return (uint64_t)(((rb_node_t *)node_id)->parent);
}

static int set_parent(uint64_t node_id, uint64_t parent_id) {
  if (is_null_node(node_id) == 1) {
    return 0;
  }
  *(uint64_t *)&(((rb_node_t *)node_id)->parent) = parent_id;
  return 1;
}

static uint64_t get_leftchild(uint64_t node_id) {
  if (is_null_node(node_id) == 1) {
    return NULL_ID;
  }
  return (uint64_t)(((rb_node_t *)node_id)->left);
}

static int set_leftchild(uint64_t node_id, uint64_t left_id) {
  if (is_null_node(node_id) == 1) {
    return 0;
  }
  *(uint64_t *)&(((rb_node_t *)node_id)->left) = left_id;
  return 1;
}

static uint64_t get_rightchild(uint64_t node_id) {
  if (is_null_node(node_id) == 1) {
    return NULL_ID;
  }
  return (uint64_t)(((rb_node_t *)node_id)->right);
}

static int set_rightchild(uint64_t node_id, uint64_t right_id) {
  if (is_null_node(node_id) == 1) {
    return 0;
  }
  *(uint64_t *)&(((rb_node_t *)node_id)->right) = right_id;
  return 1;
}

static rb_color_t get_color(uint64_t node_id) {
  if (is_null_node(node_id) == 1) {
    return NULL_ID;
  }
  return ((rb_node_t *)node_id)->color;
}

static int set_color(uint64_t node_id, rb_color_t color) {
  if (is_null_node(node_id) == 1) {
    return 0;
  }
  ((rb_node_t *)node_id)->color = color;
  return 1;
}

static uint64_t get_key(uint64_t node_id) {
  if (is_null_node(node_id) == 1) {
    return NULL_ID;
  }
  return ((rb_node_t *)node_id)->key;
}

static int set_key(uint64_t node_id, uint64_t key) {
  if (is_null_node(node_id) == 1) {
    return 0;
  }
  ((rb_node_t *)node_id)->key = key;
  return 1;
}

static uint64_t get_value(uint64_t node_id) {
  if (is_null_node(node_id) == 1) {
    return NULL_ID;
  }
  return ((rb_node_t *)node_id)->value;
}

static int set_value(uint64_t node_id, uint64_t value) {
  if (is_null_node(node_id) == 1) {
    return 0;
  }
  ((rb_node_t *)node_id)->value = value;
  return 1;
}

// shared with red-black tree
rbtree_node_interface default_i_rbt_node = {
    .construct_node = &construct_node,
    .destruct_node = &destruct_node,
    .is_null_node = &is_null_node,
    .compare_nodes = &compare_nodes,
    .get_parent = &get_parent,
    .set_parent = &set_parent,
    .get_leftchild = &get_leftchild,
    .set_leftchild = &set_leftchild,
    .get_rightchild = &get_rightchild,
    .set_rightchild = &set_rightchild,
    .get_color = &get_color,
    .set_color = &set_color,
    .get_key = &get_key,
    .set_key = &set_key,
    .get_value = &get_value,
    .set_value = &set_value,
};

// child class of base class
static int update_root(rbtree_internal_t *this, uint64_t new_root) {
  if (this == NULL) {
    return 0;
  }
  this->root = new_root;
  return 1;
}

// ----------------------------
//  The exposed interfaces
// ----------------------------

// constructor and destructor
rb_tree_t *bst_construct() {
  rb_tree_t *tree = malloc(sizeof(rb_tree_t));
  tree->root = NULL_ID;
  tree->update_root = &update_root;
  return tree;
}

// for test use
rb_tree_t *bst_construct_keystr(char *str) {
  rb_tree_t *tree = bst_construct();
  internal_tree_construct_keystr(&(tree->base), &default_i_rbt_node, str);
  return tree;
}

void bst_print(rb_node_t *node) {
  bst_internal_print((uint64_t)node, &default_i_rbt_node);
}

static void bst_destruct_subtree(uint64_t root) {
  if (default_i_rbt_node.is_null_node(root) == 1) {
    return;
  }
  bst_destruct_subtree(default_i_rbt_node.get_leftchild(root));
  bst_destruct_subtree(default_i_rbt_node.get_rightchild(root));

  default_i_rbt_node.destruct_node(root);
  return;
}

void bst_free(rb_tree_t *tree) {
  if (tree == NULL) {
    return;
  }
  bst_destruct_subtree(tree->root);
  free(tree);
}

void bst_add(rb_tree_t *tree, uint64_t key) {
  rb_node_t *n = (rb_node_t *)default_i_rbt_node.construct_node();
  n->key = key;
  bst_insert(tree, n);
}

void bst_insert(rb_tree_t *tree, rb_node_t *node) {
  bst_internal_insert(&(tree->base), &default_i_rbt_node, (uint64_t)node);
}

void bst_remove(rb_tree_t *tree, uint64_t key) {
  rb_node_t *node = bst_find(tree, key);
  if (node == NULL) {
    return;
  }
  bst_delete(tree, node);
}

void bst_delete(rb_tree_t *tree, rb_node_t *node) {
  uint64_t db_parent;
  bst_internal_delete(&(tree->base), &default_i_rbt_node, (uint64_t)node, 0, &db_parent);
}

rb_node_t *bst_find(rb_tree_t *tree, uint64_t key) {
  uint64_t node_id = bst_internal_find(&(tree->base), &default_i_rbt_node, key);
  if (default_i_rbt_node.is_null_node(node_id) == 1) {
    return NULL;
  }
  return (rb_node_t *)node_id;
}

rb_node_t *bst_find_succ(rb_tree_t *tree, uint64_t key) {
  uint64_t node_id = bst_internal_find_succ(&(tree->base), &default_i_rbt_node, key);
  if (default_i_rbt_node.is_null_node(node_id) == 1) {
    return NULL;
  }
  return (rb_node_t *)node_id;
}

int bst_compare(rb_tree_t *a, rb_tree_t *b) {
  if (a == NULL && b == NULL) {
    return 1;
  }
  if (a == NULL || b == NULL) {
    return 0;
  }
  return internal_tree_compare(a->root, b->root, &default_i_rbt_node, 0);
}

void bst_validate(rb_tree_t *tree) {
  rbt_internal_verify(&tree->base, &default_i_rbt_node, 0);
}
