#include <iostream>
using namespace std;

const int SIZE = 9;
int sudoku[SIZE][SIZE];
bool markRow[9][9];
bool markCol[9][9];
bool markMatrix[3][3][9];
int count = 0;

void readSudoku(int sudoku[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> sudoku[i][j];
        }
    }
}

void printResult()
{
    cout<<endl;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout<<sudoku[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Try(int i, int j)
{
    if (i < 9 && j < 9)
    {
        if (sudoku[i][j] == 0)
        {
            for (int z = 1; z <= 9; z++)
            {
                if (!markRow[i][z - 1] && !markCol[j][z - 1] && !markMatrix[i / 3][j / 3][z - 1])
                {
                    markRow[i][z - 1] = true;
                    markCol[j][z - 1] = true;
                    markMatrix[i / 3][j / 3][z - 1] = true;
                    sudoku[i][j] = z;
                    Try(i, j + 1);
                    markRow[i][z - 1] = false;
                    markCol[j][z - 1] = false;
                    markMatrix[i / 3][j / 3][z - 1] = false;
                    sudoku[i][j] = 0;
                }
            }
        }
        else
            Try(i, j + 1);
    }
    else if (i < 9 && j >= 9)
    {
        Try(i + 1, 0);
    }
    else
    {
        ::count++;
        // printResult();
    }
}

int main()
{
    readSudoku(sudoku);
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (sudoku[i][j] != 0)
            {
                int num = sudoku[i][j];
                markRow[i][num - 1] = true;
                markCol[j][num - 1] = true;
                markMatrix[i / 3][j / 3][num - 1] = true;
            }
        }
    }
    Try(0,0);
    cout<<::count<<endl;
    return 0;
}