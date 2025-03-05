#include<iostream>
using namespace std;

const int nm = 101;
int i, n, cnt, queen[nm][nm];
bool col[nm], dia1[nm], dia2[nm];

void Print_Result();
bool Can_Place_Queen(int, int, const int);
void Place_Queen(int);

int main()
{
    cin >> n;
    for(int i = 1; i <= 2 * n; i++)
    {
        col[i] = true;
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
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
            cout << queen[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

bool Can_Place_Queen(int i, int j, const int n)
{
    if(col[j] == true && dia1[i - j + n] == true && dia2[i + j - 1] == true)
        return true;
    return false;
}
void Place_Queen(int i)
{
    for(int j = 1; j <= n; j++)
    {
        if(Can_Place_Queen(i, j, n))
        {
            queen[i][j] = i;
            col[j] = false;
            dia1[i - j + n] = false;
            dia2[i + j - 1] = false;
            if(i == n)Print_Result();
            else Place_Queen(i + 1);
            queen[i][j] = 0;
            col[j] = true;
            dia1[i - j + n] = true;
            dia2[i + j - 1] = true;
        }
    }
}
