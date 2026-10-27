
#include <iostream>
#include <cmath>
using namespace std;

int N;
int board[20];

// Check whether queen can be placed
bool IS_SAFE(int row, int col)
{
    for (int i = 1; i < row; i++)
    {
        // Check same column
        if (board[i] == col)
            return false;

        // Check diagonal
        if (abs(board[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

// Print the chessboard
void PRINT_BOARD()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// N-Queen using Backtracking
void NQUEEN(int row)
{
    if (row > N)
    {
        PRINT_BOARD();
        return;
    }

    for (int col = 1; col <= N; col++)
    {
        if (IS_SAFE(row, col))
        {
            board[row] = col;

            NQUEEN(row + 1);

            board[row] = 0;
        }
    }
}

int main()
{
    cout << "Enter number of queens: ";
    cin >> N;

    if (N < 1 || N > 19)
    {
        cout << "Enter N between 1 and 19.";
        return 0;
    }

    NQUEEN(1);

    return 0;
}
