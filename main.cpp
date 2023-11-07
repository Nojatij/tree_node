#include <iostream>
#include <ctime>
#include "tree.h"
using namespace std;

void instructions();

int main()
{
    srand(time(NULL));
    Tree Tree, copyTree;
    int choice;
    Tree.addElements();

    do
    {
        instructions();
        cin >> choice;
        switch (choice)
        {
        case 1:
            Tree.addElements();
            break;
        case 2:
            cout << Tree;
            break;
        case 3:
            cout << endl
                 << "In order traversal: ";
            Tree.inOrder();
            cout << endl << endl;
            break;
        case 4:
            cout << endl
                 << "Pre order traversal: ";
            Tree.preOrder();
            cout << endl << endl;
            break;
        case 5:
            cout << endl
                 << "Post order traversal: ";
            Tree.postOrder();
            cout << endl << endl;
            break;
        case 6:
            cout << endl << "Input the element to be deleted: ";
            int element;
            cin >> element;
            Tree.removeElem(element);
            cout << Tree;
            break;
        case 7:
            Tree.deleteTree();
            cout << "The tree has been deleted!" << endl;
            break;
        case 8:
            Tree.deleteDuplicates();
            cout << "The tree with no duplicates: " << endl << Tree;
            break;
        case 9:
            cout << endl << "Tree height: " << Tree.height()<< endl << endl;
            break;
        case 10:
            Tree.floor_by_floor();
            break;
        case 11:
            copyTree = Tree;
            cout << "Copied tree: " << endl << Tree;
            break;
        }

    } while (choice != 12);
}

void instructions()
{
    cout << "Choose:" << endl
         << "1 - Add elements into the tree" << endl
         << "2 - Print tree" << endl
         << "3 - In order traversal" << endl
         << "4 - Pre order traversal" << endl
         << "5 - Post order traversal" << endl
         << "6 - Remove element" << endl
         << "7 - Remove tree " << endl
         << "8 - Delete dublicates" << endl
         << "9 - Tree height" << endl
         << "10 - Floor-by-floor traversal" << endl
         << "11 - Copy the tree" << endl
         << "12 - Finish" << endl
         << "?- ";
}
