#ifndef TREE_H
#define TREE_H
#include "treenode.h"

using namespace std;

class Tree
{

friend ostream &operator<<(ostream &, const Tree &);
friend istream &operator>>(istream &, Tree &);

private:
    TreeNode *rootPtr;
    int flag = 0;

    TreeNode *findMaximumKey(TreeNode *);
    void createTreeRandomly_helper(TreeNode **);
    void createTreeManually_helper(TreeNode **);
    void insertNode_helper(TreeNode **, int);
    void deleteTree_helper(TreeNode *&);
    void inOrder_helper(TreeNode *) const;
    void preOrder_helper(TreeNode *) const;
    void postOrder_helper(TreeNode *) const;
    void removeElem_helper(TreeNode *&, int);
    void deleteDuplicates_helper(TreeNode **);
    int height_helper(TreeNode *) const;
    void print_helper(TreeNode *, int = 0) const;
    void floor_by_floor_helper(TreeNode *) const;
    void postOrder_floor(TreeNode *, int, int) const;
    void copy_helper(const TreeNode *);
    void check_dup(TreeNode *, int);

public:
    Tree();
    Tree & operator=(const Tree &);
    Tree(const Tree &);
    void removeElem(int);
    void inOrder() const;
    void preOrder() const;
    void postOrder() const;
    void insertNode(int);
    void createTreeRandomly();
    void createTreeManually();
    void deleteTree();
    void print_Tree() const;
    void deleteDuplicates();
    int height() const;
    void floor_by_floor() const;
    void copy(const Tree &);
    void addElements();
    ~Tree();
};

#endif
