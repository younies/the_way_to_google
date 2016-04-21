#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int x[] = { -1 , 0 , 1 , 0};
int y[] = { 0 , 1 , 0 , -1 };


void fillo(vector<string> & result  ,  int row , int col , int n)
{
        if(row > 0 && row < n -1 && col > 0 && col < n -1)
        {
            for (int k = 0 ; k <  4 ; k++)
                if(result[row][col] <= result[row + x[k]][col + y[k]] )
                    return;
            result[row][col] = 'X';
        }
}


int main(){
    int n;
    cin >> n;
    vector<string> grid(n);
    for(int grid_i = 0;grid_i < n;grid_i++){
        cin >> grid[grid_i];
    }
    
    for (int i = 0 ; i < n ; ++i)
        for (int j = 0 ; j < n ; ++j)
            fillo(grid , i, j, n);
    
    for (int i = 0 ; i < n ; ++i)
        cout << grid[i] << endl;
    return 0;
}