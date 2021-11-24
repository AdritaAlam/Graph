#include <bits/stdc++.h>
using namespace std;

int no_of_vertices;
int adj[100][100];
int mat[100][100]; // Original

void printPathLength(int pathlength)
{

    cout << "Printing Path of Length " << pathlength << endl;

    for (int i = 1; i <= no_of_vertices; i++)
    {
        for (int j = 1; j <= no_of_vertices; j++)
        {
            if (adj[i][j])
                cout << i << " to " << j << endl;
        }
        cout << endl;
    }
    cout << endl;
}

void printOriginalMatrix()
{
    // Print
    cout << "-----------" << endl;
    for (int i = 1; i <= no_of_vertices; i++)
    {
        for (int j = 1; j <= no_of_vertices; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------" << endl;
}

void printMatrix()
{
    // Print
    cout << "-----------" << endl;
    for (int i = 1; i <= no_of_vertices; i++)
    {
        for (int j = 1; j <= no_of_vertices; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-----------" << endl;
}

int intermediate_helper(int row, int column)
{
    int sum = 0;
    for (int i = 1; i <= no_of_vertices; i++)
    {
        sum += adj[row][i] * mat[i][column];
    }
    return sum;
}

void Multiplication()
{

    int multiplied[no_of_vertices + 1][no_of_vertices + 1];
    memset(multiplied, 0, sizeof(multiplied));

    for (int i = 1; i <= no_of_vertices; i++)
    {
        for (int j = 1; j <= no_of_vertices; j++)
        {
            multiplied[i][j] = intermediate_helper(i, j);
        }
    }
    // printMatrix();
    // Replacing Adjaceny Matrix with Multiplied New Matrix
    for (int i = 1; i <= no_of_vertices; i++)
    {
        for (int j = 1; j <= no_of_vertices; j++)
        {
            adj[i][j] = multiplied[i][j];
        }
    }
    printMatrix();
}

void printAdjacentNodes(int node, int totalVertices)
{
    cout << "Adjacent of Node " << node << ": ";
    for (int i = 1; i <= totalVertices; i++)
    {
        if (adj[node][i] == 1)
            cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

int main()
{
    cin >> no_of_vertices;

    for (int i = 1; i <= no_of_vertices; i++)
    {
        for (int j = 1; j <= no_of_vertices; j++)
        {
            cin >> adj[i][j];
            mat[i][j] = adj[i][j];
        }
        printAdjacentNodes(i, no_of_vertices);
    }



    // Finding Path of Length 2
    for (int i = 1; i < no_of_vertices; i++)
    {
        Multiplication();
        printPathLength(i + 1);
    }


}