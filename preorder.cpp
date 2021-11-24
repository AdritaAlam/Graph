#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100;
int BST[4 * SIZE];

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

// preorder

void PreOrderDFS(int par)
{

    if (BST[par] == -1)
        return;

    cout << BST[par] << " ";

    PreOrderDFS(2 * par);

    PreOrderDFS(2 * par + 1);

    BST[par] = -1;
}

int main()
{

    memset(BST, -1, sizeof(BST));
    int no_of_nodes;
    cin >> no_of_nodes;

    int input;

    for (int i = 1; i <= no_of_nodes; i++)
    {
        cin >> input;
        BST[i] = input;
    }
    cout << "Preorder Traversal" << endl;
    PreOrderDFS(1);
}