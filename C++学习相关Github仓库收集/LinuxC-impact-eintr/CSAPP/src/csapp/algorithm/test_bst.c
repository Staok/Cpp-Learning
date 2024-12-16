#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>

#include "../headers/algorithm.h"
#include "../headers/common.h"

rb_tree_t *bst_construct_keystr(char *str);
int bst_compare(rb_tree_t *a, rb_tree_t *b);
void bst_print(rb_node_t *node);
void bst_validate(rb_tree_t *tree);

static void test_build()
{
    printf("Testing build tree from string ...\n");

    rb_tree_t *tree;
    rb_node_t *r;
    char s[1000];

    memset(s, 0, sizeof(char) * 1000);
    strcpy(s, "#");
    tree = bst_construct_keystr(s);
    assert(tree->root == NULL_ID);
    bst_free(tree);

    memset(s, 0, sizeof(char) * 1000);
    strcpy(s, "(12, #, #)");
    tree = bst_construct_keystr(s);
    r = (rb_node_t *)tree->root;

    assert(r->parent == NULL);
    assert(r->left == NULL);
    assert(r->right == NULL);
    printf("TEST %ld\n", r->key);
    assert(r->key == 12);
    bst_free(tree);

    memset(s, 0, sizeof(char) * 1000);
    strcpy(s, 
        "("
            "6,"
            "("
                "3,"
                "("
                    "2,"
                    "(1,#,#),"
                    "#"
                "),"
                "("
                    "4,"
                    "#,"
                    "(5,#,#)"
                ")"
            "),"
            "("
                "7,"
                "#,"
                "(8,#,#)"
            ")"
        ")");
    tree = bst_construct_keystr(s);
    r = (rb_node_t *)tree->root;

    rb_node_t *n1 = r->left->left->left;
    rb_node_t *n2 = r->left->left;
    rb_node_t *n3 = r->left;
    rb_node_t *n4 = r->left->right;
    rb_node_t *n5 = r->left->right->right;
    rb_node_t *n6 = r;
    rb_node_t *n7 = r->right;
    rb_node_t *n8 = r->right->right;

    assert(n1->key == 1);
    assert(n1->parent == n2);
    assert(n1->left == NULL);
    assert(n1->right == NULL);

    assert(n2->key == 2);
    assert(n2->parent == n3);
    assert(n2->left == n1);
    assert(n2->right == NULL);

    assert(n3->key == 3);
    assert(n3->parent == n6);
    assert(n3->left == n2);
    assert(n3->right == n4);

    assert(n4->key == 4);
    assert(n4->parent == n3);
    assert(n4->left == NULL);
    assert(n4->right == n5);

    assert(n5->key == 5);
    assert(n5->parent == n4);
    assert(n5->left == NULL);
    assert(n5->right == NULL);

    assert(n6->key == 6);
    assert(n6->parent == NULL);
    assert(n6->left == n3);
    assert(n6->right == n7);

    assert(n7->key == 7);
    assert(n7->parent == n6);
    assert(n7->left == NULL);
    assert(n7->right == n8);

    assert(n8->key == 8);
    assert(n8->parent == n7);
    assert(n8->left == NULL);
    assert(n8->right == NULL);

    bst_free(tree);

    printf("\033[32;1m\tPass\033[0m\n");
}

static void test_insert()
{
    printf("Testing Binary Search Tree insertion ...\n");

    rb_tree_t *r = bst_construct_keystr(
        "(11,"
            "(2,(1,#,#),(7,(5,#,#),(8,#,#))),"
            "(14,#,(15,#,#)))"
    );
    bst_validate(r);

    // test insert
    bst_add(r, 4);
    bst_print((rb_node_t *)r->root);
    bst_validate(r);

    // check
    rb_tree_t *a = bst_construct_keystr(
        "(11,"
            "(2,(1,#,#),(7,(5,(4,#,#),#),(8,#,#))),"
            "(14,#,(15,#,#)))"
    );
    assert(bst_compare(r, a) == 1);

    // free
    bst_free(r);
    bst_free(a);

    // insertion the same value at the right child
    r = bst_construct_keystr(
        "(11,"
            "(2,(1,#,#),(7,(5,#,#),(8,#,#))),"
            "(14,#,(15,#,#)))"
    );

    // test insert
    bst_add(r, 8);
    bst_validate(r);

    // check
    a = bst_construct_keystr(
        "(11,"
            "(2,(1,#,#),(7,(5,#,#),(8,#,(8,#,#)))),"
            "(14,#,(15,#,#)))"
    );

    assert(bst_compare(r, a) == 1);

    // free
    bst_free(r);
    bst_free(a);
    
    // insert the same value in right sub tree
    r = bst_construct_keystr(
        "(11,"
            "(2,(1,#,#),(7,(5,#,#),(8,#,#))),"
            "(14,#,(15,#,#)))"
    );

    // test insert
    bst_add(r, 7);
    bst_validate(r);

    // check
    a = bst_construct_keystr(
        "(11,"
            "(2,(1,#,#),(7,(5,#,#),(8,(7,#,#),#))),"
            "(14,#,(15,#,#)))"
    );

    assert(bst_compare(r, a) == 1);

    // free
    bst_free(r);
    bst_free(a);

    printf("\033[32;1m\tPass\033[0m\n");
}

static void test_find()
{
    printf("Testing Binary Search Tree searching ...\n");

    rb_tree_t *t = bst_construct_keystr(
        "(70,"
            "(40,"
                "(20,(10,#,#),(30,(20,#,#),#)),"
                "(50,(40,#,#),(50,#,(60,#,#)))),"
            "(120,"
                "(90,(80,#,#),(110,(100,#,#),#)),"
                "(130,(120,#,(120,#,#)),(140,#,#))))"
    );
    rb_node_t *r = (rb_node_t *)t->root;

    rb_node_t *f;
    rb_node_t *g;
    
    f = bst_find(t, 10);
    assert(f == r->left->left->left);
    for (int i = 0; i < 10; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 20);
    assert(f == r->left->left);
    for (int i = 11; i < 20; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 30);
    assert(f == r->left->left->right);
    for (int i = 21; i < 30; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 40);
    assert(f == r->left);
    for (int i = 31; i < 40; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 50);
    assert(f == r->left->right);
    for (int i = 41; i < 50; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 60);
    assert(f == r->left->right->right->right);
    for (int i = 51; i < 60; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 70);
    assert(f == r);
    for (int i = 61; i < 70; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 80);
    assert(f == r->right->left->left);
    for (int i = 71; i < 80; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 90);
    assert(f == r->right->left);
    for (int i = 81; i < 90; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 100);
    assert(f == r->right->left->right->left);
    for (int i = 91; i < 100; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 110);
    assert(f == r->right->left->right);
    for (int i = 101; i < 110; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 120);
    assert(f == r->right);
    for (int i = 111; i < 120; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 130);
    assert(f == r->right->right);
    for (int i = 121; i < 130; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    f = bst_find(t, 140);
    assert(f == r->right->right->right);
    for (int i = 131; i < 140; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == f);
    }

    for (int i = 141; i < 1000; ++ i)
    {
        g = bst_find_succ(t, i);
        assert(g == NULL);
    }

    bst_free(t);

    printf("\033[32;1m\tPass\033[0m\n");
}

static void test_delete()
{
    printf("Testing Binary Search Tree deletion ...\n");

    rb_tree_t *r = bst_construct_keystr(
        "(10,"
            "(4,"
                "(2,(1,#,#),(3,#,#)),"
                "(7,"
                    "(6,(5,#,#),#),"
                    "(8,#,(9,#,#))"
                ")"
            "),"
            "(17,"
                "(12,(11,#,#),(13,#,(15,(14,#,#),(16,#,#)))),"
                "(19,(18,#,#),(24,(22,(20,#,(21,#,#)),(23,#,#)),(25,#,#)))"
            ")"
        ")"
    );
    rb_tree_t *a;

    // case 1: leaf node - parent's left child
    bst_remove(r, 1);
    bst_validate(r);
    a = bst_construct_keystr(
        "(10,"
            "(4,"
                "(2,#,(3,#,#)),"
                "(7,"
                    "(6,(5,#,#),#),"
                    "(8,#,(9,#,#))"
                ")"
            "),"
            "(17,"
                "(12,(11,#,#),(13,#,(15,(14,#,#),(16,#,#)))),"
                "(19,(18,#,#),(24,(22,(20,#,(21,#,#)),(23,#,#)),(25,#,#)))"
            ")"
        ")"
    );
    assert(bst_compare(r, a) == 1);
    bst_free(a);
    printf("case 1 check\n");

    // case 2: leaf node - parent's right child
    bst_remove(r, 3);
    bst_validate(r);
    a = bst_construct_keystr(
        "(10,"
            "(4,"
                "(2,#,#),"
                "(7,"
                    "(6,(5,#,#),#),"
                    "(8,#,(9,#,#))"
                ")"
            "),"
            "(17,"
                "(12,(11,#,#),(13,#,(15,(14,#,#),(16,#,#)))),"
                "(19,(18,#,#),(24,(22,(20,#,(21,#,#)),(23,#,#)),(25,#,#)))"
            ")"
        ")"
    );
    assert(bst_compare(r, a) == 1);
    bst_free(a);
    printf("case 2 check\n");

    // case 3: right NULL
    bst_remove(r, 6);
    bst_validate(r);
    a = bst_construct_keystr(
        "(10,"
            "(4,"
                "(2,#,#),"
                "(7,"
                    "(5,#,#),"
                    "(8,#,(9,#,#))"
                ")"
            "),"
            "(17,"
                "(12,(11,#,#),(13,#,(15,(14,#,#),(16,#,#)))),"
                "(19,(18,#,#),(24,(22,(20,#,(21,#,#)),(23,#,#)),(25,#,#)))"
            ")"
        ")"
    );
    assert(bst_compare(r, a) == 1);
    bst_free(a);
    printf("case 3 check\n");

    // case 4: left NULL
    bst_remove(r, 8);
    bst_validate(r);
    a = bst_construct_keystr(
        "(10,"
            "(4,"
                "(2,#,#),"
                "(7,"
                    "(5,#,#),"
                    "(9,#,#)"
                ")"
            "),"
            "(17,"
                "(12,(11,#,#),(13,#,(15,(14,#,#),(16,#,#)))),"
                "(19,(18,#,#),(24,(22,(20,#,(21,#,#)),(23,#,#)),(25,#,#)))"
            ")"
        ")"
    );
    assert(bst_compare(r, a) == 1);
    bst_free(a);
    printf("case 4 check\n");

    // case 5: right child's left NULL
    bst_remove(r, 12);
    bst_validate(r);
    a = bst_construct_keystr(
        "(10,"
            "(4,"
                "(2,#,#),"
                "(7,"
                    "(5,#,#),"
                    "(9,#,#)"
                ")"
            "),"
            "(17,"
                "(13,(11,#,#),(15,(14,#,#),(16,#,#))),"
                "(19,(18,#,#),(24,(22,(20,#,(21,#,#)),(23,#,#)),(25,#,#)))"
            ")"
        ")"
    );
    assert(bst_compare(r, a) == 1);
    bst_free(a);
    printf("case 5 check\n");

    // case 6: right child's left not NULL
    bst_remove(r, 19);
    bst_validate(r);
    a = bst_construct_keystr(
        "(10,"
            "(4,"
                "(2,#,#),"
                "(7,"
                    "(5,#,#),"
                    "(9,#,#)"
                ")"
            "),"
            "(17,"
                "(13,(11,#,#),(15,(14,#,#),(16,#,#))),"
                "(20,(18,#,#),(24,(22,(21,#,#),(23,#,#)),(25,#,#)))"
            ")"
        ")");
    assert(bst_compare(r, a) == 1);
    bst_free(a);
    printf("case 6 check\n");

    // case 7: delete root
    bst_remove(r, 10);
    bst_validate(r);
    a = bst_construct_keystr(
        "(11,"
            "(4,"
                "(2,#,#),"
                "(7,"
                    "(5,#,#),"
                    "(9,#,#)"
                ")"
            "),"
            "(17,"
                "(13,#,(15,(14,#,#),(16,#,#))),"
                "(20,(18,#,#),(24,(22,(21,#,#),(23,#,#)),(25,#,#)))"
            ")"
        ")");
    int equal = bst_compare(r, a);

    assert(bst_compare(r, a) == 1);
    bst_free(a);
    printf("case 7 check\n");

    bst_free(r);

    printf("\033[32;1m\tPass\033[0m\n");
}

static void test_insert_delete()
{
    printf("Testing Binary Search Tree insertion and deletion ...\n");

    rb_tree_t *tree = bst_construct();
    
    // insert
    int loops = 50000;
    int iteration = 1000;

    uint64_t *array = malloc(loops * sizeof(uint64_t));
    for (int i = 0; i < loops; ++ i)
    {
        if (i % iteration == 0)
        {
            printf("insert %d / %d\n", i, loops);
        }
        uint64_t key = rand() % 1000000;
        bst_add(tree, key);
        bst_validate(tree);
        array[i] = key;
    }

    // mark
    for (int i = 0; i < loops; ++ i)
    {
        if (i % iteration == 0)
        {
            printf("delete %d / %d\n", i, loops);
        }

        int index = rand() % loops;

        bst_remove(tree, array[index]);
        bst_validate(tree);
        array[index] = 0xFFFFFFFFFFFFFFFF;
    }

    // sweep
    for (int i = 0; i < loops; ++ i)
    {
        if (array[i] != 0xFFFFFFFFFFFFFFFF)
        {
            bst_remove(tree, array[i]);
            bst_validate(tree);
        }
    }

    assert(tree->root == 0);

    free(array);
    bst_free(tree);

    printf("\033[32;1m\tPass\033[0m\n");
}

int main()
{
    srand(123456);
    //test_build();
    //test_insert();
    //test_find();
    test_delete();
    test_insert_delete();
    return 0;
}
