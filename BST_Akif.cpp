#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
int BST[4 * SIZE];

int level[5] = {1, 2, 4, 8, 16};

bool searchlevel(int x)
{
    for (int i = 0; i < 5; i++)
    {
        if (level[i] == x)
            return true;
    }
    return false;
}
void printDash(int x)
{
    while (x--)
        cout << "-";
}

void printTreeStyle()
{
    int x = 16;
    for (int i = 1; i < 15; i++)
    {
        if (searchlevel(i))
        {
            printDash(x);
        }
        cout << BST[i] << " ";
        if (searchlevel(i))
        {
            printDash(x);
            cout << endl;

            x = x / 2;
        }
        printDash(x / 2);
    }
    cout << endl;
    cout << "-------" << endl;
}

void printTree()
{
    cout << "-------" << endl;
    for (int i = 1; i < 15; i++)
    {
        cout << BST[i] << " ";
    }
    cout << endl;
    cout << "-------" << endl;
}

void insertNode(int root, int item)
{
    if (BST[root] == item)
    {
        cout << endl;
        cout << "*** The item " << item << " already exist !" << endl;
        return;
    }
    if (BST[root] == 0)
    {
        BST[root] = item; // Parent inserted
    }
    else
    {
        if (item < BST[root])
            insertNode(2 * root, item);
        else
            insertNode((2 * root) + 1, item);
    }
}


int main()
{
    memset(BST, 0, sizeof(BST));
    insertNode(1, 10);
    insertNode(1, 2);
    insertNode(1, 8);
    insertNode(1, 1);
    insertNode(1, 3);
    insertNode(1, 7);
    insertNode(1, 9);

    printTreeStyle();
}