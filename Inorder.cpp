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

// bool visited_inorder[100];
void inorder(int par)
{
    // cout << "Parent : " << par << endl;
    // If left child exist, visit left child
    if ((BST[2 * par] == -1 && BST[2 * par + 1] == -1))
    {
        if (BST[par] != -1)
        {
            cout << BST[par] << " ";
            BST[par] = -1;
        }
        return;
    }
    cout << BST[par] << " ";
    inorder(2 * par);
    inorder(2 * par + 1);
}

void DFS(int par)
{
    if (BST[par] == -1)
    {
        return;
    }

    DFS(2 * par);

    if (BST[par] != -1)
    {
        cout << BST[par] << " ";
        BST[par] = -1;
    }

    DFS(2 * par + 1);

    if (BST[par] != -1)
    {
        cout << BST[par] << " ";
        BST[par] = -1;
    }
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
    cout << "Inorder Traversal" << endl;
    DFS(1);
}