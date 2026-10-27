
#include <iostream>
using namespace std;

int n;
int graph[20][20];
int path[20];

// Check if vertex is already in path
bool IS_SAFE(int v, int pos)
{
    // Check connection with previous vertex
    if (graph[path[pos - 1]][v] == 0)
        return false;

    // Check if vertex is already visited
    for (int i = 0; i < pos; i++)
    {
        if (path[i] == v)
            return false;
    }

    return true;
}

// Solve using Backtracking
bool Solve(int pos)
{
    // All vertices are included
    if (pos == n)
    {
        if (graph[path[n - 1]][path[0]] == 1)
        {
            cout << "Hamiltonian Cycle: ";

            for (int i = 0; i < n; i++)
                cout << path[i] << " ";

            cout << path[0] << endl;
            return true;
        }

        return false;
    }

    // Try remaining vertices
    for (int v = 1; v < n; v++)
    {
        if (IS_SAFE(v, pos))
        {
            path[pos] = v;

            if (Solve(pos + 1) == true)
                return true;

            // Backtracking
            path[pos] = -1;
        }
    }

    return false;
}

// Hamiltonian function
void Hamiltonian()
{
    path[0] = 0;

    for (int i = 1; i < n; i++)
        path[i] = -1;

    if (Solve(1) == false)
        cout << "No Hamiltonian Cycle exists." << endl;
}

int main()
{
    cout << "Enter number of vertices: ";
    cin >> n;

    if (n < 3 || n > 20)
    {
        cout << "Enter vertices between 3 and 20.";
        return 0;
    }

    cout << "Enter adjacency matrix:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }

    Hamiltonian();

    return 0;
}
