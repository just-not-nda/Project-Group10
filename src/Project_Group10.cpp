#include<iostream>
using namespace std;

const int nm = 20;
int N, cnt, queen[nm];
bool col[nm], dia1[2 * nm], dia2[2 * nm];

void Print_Result();
bool Can_Place_Queen(int, int);
void Place_Queen(int);

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        col[i] = true;
    for (int i = 1; i <= 2 * N; i++)
    {
        dia1[i] = true;
        dia2[i] = true;
    }
    Place_Queen(1);
    cout << "=> Total number of ways to place queens: " << cnt;
    return 0;
}

void Print_Result()
{
    cnt++;
    cout << "Way " << cnt << ":" << endl;
    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
            if(queen[i] == j)
                cout << i << " ";
            else
                cout << "0 ";
        cout << endl;
    }
    cout << endl;
}

bool Can_Place_Queen(int i, int j)
{
    return col[j] && dia1[i - j + N] && dia2[i + j - 1];
}
void Place_Queen(int i)
{
    for(int j = 1; j <= N; j++)
    {
        if(Can_Place_Queen(i, j))
        {
            queen[i] = j;
            col[j] = dia1[i - j + N] = dia2[i + j - 1] = false;
            if(i == N)
                Print_Result();
            else
                Place_Queen(i + 1);

            col[j] = dia1[i - j + N] = dia2[i + j - 1] = true;
        }
    }
}
