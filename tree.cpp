#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include "tree.h"

using namespace std;

ostream &operator<<(ostream &output, const Tree &T)
{
    T.print_Tree();

    return output;
}

istream &operator>>(istream &input, Tree &T)
{
    T.addElements();

    return input;
}

Tree::Tree()
{
    rootPtr = NULL;
}

Tree::~Tree()
{
    deleteTree_helper(rootPtr);
}

Tree::Tree(const Tree &original)
{
    if (rootPtr != NULL)
        deleteTree_helper(rootPtr);

    rootPtr = NULL;
    copy_helper(original.rootPtr);
}

void Tree::addElements()
{
    int choice;
    printf("How to add elements to the tree? (1 - Manually / 2 - Random): ");
    do
    {
        scanf("%d", &choice);
        if ((choice != 1) && (choice != 2))
            printf("Enter 1 or 2: ");

    } while ((choice != 1) && (choice != 2));

    switch (choice)
    {
    case 1:
        createTreeManually();
        break;
    case 2:
        createTreeRandomly();
        break;
    }
}

Tree &Tree::operator=(const Tree &rightTree)
{
    if (rootPtr != NULL)
        deleteTree_helper(rootPtr);
    rootPtr = NULL;
    copy_helper(rightTree.rootPtr);
    return *this;
}

void Tree::insertNode(int value)
{
    insertNode_helper(&rootPtr, value);
}

void Tree::insertNode_helper(TreeNode **treePtr, int value)
{
    if (*treePtr == NULL)
    {
        *treePtr = new TreeNode;
        if (*treePtr != NULL)
        {
            (*treePtr)->data = value;
            (*treePtr)->leftPtr = NULL;
            (*treePtr)->rightPtr = NULL;
        }
        else
            cout << value << " not inserted. No memory available. \n";
    }
    else if (value < (*treePtr)->data)
        insertNode_helper(&((*treePtr)->leftPtr), value);
    else if (value >= (*treePtr)->data)
        insertNode_helper(&((*treePtr)->rightPtr), value);
}

void Tree::createTreeRandomly()
{
    createTreeRandomly_helper(&rootPtr);
}

void Tree::createTreeRandomly_helper(TreeNode **treePtr)
{
    srand(time(NULL));

    int count, item, from, to;
    cout.setf(ios::fixed);

    cout << "How much numbers do you want to place in tree? : ";
    cin >> count;
    cout << "Random range from ... to ... : ";
    cin >> from >> to;

    cout << "The numbers being placed in the tree are: \n";
    for (int i = 1; i <= count; i++)
    {
        item = rand() % (abs(from - to) + 1) + min(from, to);
        cout << setw(5) << item;
        insertNode_helper(treePtr, item);
    }
    cout << endl;
}

void Tree::createTreeManually()
{
    createTreeManually_helper(&rootPtr);
}

void Tree::createTreeManually_helper(TreeNode **treePtr)
{
    int count, item;
    cout.setf(ios::fixed);
    cout << "How much numbers do you want to place in tree? : ";
    cin >> count;

    for (int i = 1; i <= count; i++)
    {
        cout << "Enter " << i << " number: ";
        cin >> item;
        insertNode_helper(treePtr, item);
    }
}

void Tree::inOrder() const
{
    inOrder_helper(rootPtr);
}

void Tree::inOrder_helper(TreeNode *treePtr) const
{
    if (treePtr != NULL)
    {
        inOrder_helper(treePtr->leftPtr);
        cout << setw(5) << treePtr->data;
        inOrder_helper(treePtr->rightPtr);
    }
}

void Tree::preOrder() const
{
    preOrder_helper(rootPtr);
}

void Tree::preOrder_helper(TreeNode *treePtr) const
{
    if (treePtr != NULL)
    {
        cout << setw(5) << treePtr->data;
        preOrder_helper(treePtr->leftPtr);
        preOrder_helper(treePtr->rightPtr);
    }
}

void Tree::postOrder() const
{
    postOrder_helper(rootPtr);
}

void Tree::postOrder_helper(TreeNode *treePtr) const
{
    if (treePtr != NULL)
    {
        postOrder_helper(treePtr->leftPtr);
        postOrder_helper(treePtr->rightPtr);
        cout << setw(5) << treePtr->data;
    }
}

void Tree::deleteTree()
{
    deleteTree_helper(rootPtr);
    rootPtr = NULL;
}
void Tree::deleteTree_helper(TreeNode *&treePtr)
{
    if (treePtr != 0)
    {
        deleteTree_helper(treePtr->leftPtr);
        deleteTree_helper(treePtr->rightPtr);

        delete treePtr;
    }
}

int Tree::height() const
{
    return height_helper(rootPtr);
}

int Tree::height_helper(TreeNode *treePtr) const
{
    if (treePtr == NULL)
        return 0;

    else
        return 1 + max(height_helper(treePtr->leftPtr), height_helper(treePtr->rightPtr));
}

void Tree::print_Tree() const
{
    print_helper(rootPtr);
}

void Tree::print_helper(TreeNode *treePtr, int indent) const
{
    if (treePtr != NULL)
    {
        if (treePtr->rightPtr)
            print_helper(treePtr->rightPtr, indent + 4);

        if (indent)
            std::cout << std::setw(indent) << ' ';

        if (treePtr->rightPtr)
            std::cout << " /\n"
                      << std::setw(indent) << ' ';

        std::cout << treePtr->data << "\n ";

        if (treePtr->leftPtr)
        {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            print_helper(treePtr->leftPtr, indent + 4);
        }
    }
}

void Tree::floor_by_floor() const
{
    floor_by_floor_helper(rootPtr);
}

void Tree::floor_by_floor_helper(TreeNode *treePtr) const
{
    int count = 0;
    for (int i = 1; i <= height_helper(treePtr); i++)
    {
        cout << i << " floor: ";
        postOrder_floor(treePtr, count, i);
        cout << endl;
    }
    cout << endl;
}

void Tree::postOrder_floor(TreeNode *treePtr, int count, int i) const
{
    if (treePtr != NULL)
    {
        postOrder_floor(treePtr->leftPtr, ++count, i);
        if (i == count)
        {
            cout << treePtr->data << " ";
        }
        count--;
        postOrder_floor(treePtr->rightPtr, ++count, i);
    }
}

void Tree::copy(Tree const &original)
{
    if (rootPtr != NULL)
        deleteTree_helper(rootPtr);

    rootPtr = NULL;
    copy_helper(original.rootPtr);
}

void Tree::copy_helper(TreeNode const *treePtr)
{
    if (treePtr != NULL)
    {
        insertNode_helper(&rootPtr, treePtr->data);
        copy_helper(treePtr->leftPtr);
        copy_helper(treePtr->rightPtr);
    }
}

TreeNode *Tree::findMaximumKey(TreeNode *ptr)
{
    while (ptr->rightPtr != nullptr)
    {
        ptr = ptr->rightPtr;
    }
    return ptr;
}

void Tree::removeElem(int data)
{
    removeElem_helper(rootPtr, data);
}

void Tree::removeElem_helper(TreeNode *&treePtr, int value)
{

    if (treePtr == nullptr)
    {
        return;
    }

    if (value < treePtr->data)
    {
        removeElem_helper(treePtr->leftPtr, value);
    }

    else if (value > treePtr->data)
    {
        removeElem_helper(treePtr->rightPtr, value);
    }

    else
    {
        if (treePtr->leftPtr == nullptr && treePtr->rightPtr == nullptr)
        {
            delete treePtr;
            treePtr = nullptr;
        }

        else if (treePtr->leftPtr && treePtr->rightPtr)
        {
            TreeNode *predecessor = findMaximumKey(treePtr->leftPtr);

            treePtr->data = predecessor->data;

            removeElem_helper(treePtr->leftPtr, predecessor->data);
        }

        else
        {
            TreeNode *child = (treePtr->leftPtr) ? treePtr->leftPtr : treePtr->rightPtr;
            TreeNode *curr = treePtr;

            treePtr = child;

            delete curr;
        }
    }
}

void Tree::deleteDuplicates()
{
    deleteDuplicates_helper(&rootPtr);
}

void Tree::deleteDuplicates_helper(TreeNode **treePtr)
{
    flag = 0;
    if ((*treePtr) != NULL)
    {
        check_dup((*treePtr), (*treePtr)->data);
        if (flag > 1)
        {
            for (int i = 1; i < flag; i++)
                removeElem((*treePtr)->data);
        }
        flag = 0;

        deleteDuplicates_helper(&((*treePtr)->leftPtr));
        deleteDuplicates_helper(&((*treePtr)->rightPtr));
    }
}

void Tree::check_dup(TreeNode *treePtr, int value)
{
    if (treePtr != NULL)
    {
        check_dup(treePtr->leftPtr, value);

        if (treePtr->data == value)
            flag++;

        check_dup(treePtr->rightPtr, value);
    }
}
