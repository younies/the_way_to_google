#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool check(pair<int, int> pos  ,  vector<string> &text , vector<string> &pattern)
{
    int rows = (int)pattern.size();
    int cols = (int)pattern[0].size();
    for (int i = 0; i <   rows ; ++i)
    {
        for (int j = 0; j < cols; j++)
        {
            if(pattern[i][j] != text[i+pos.first][j + pos.second])
                return false;
        }
    }
    
    return true;
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int G_i = 0;G_i < R;G_i++){
            cin >> G[G_i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int P_i = 0;P_i < r;P_i++){
            cin >> P[P_i];
        }
        
        bool flag = false;
        
        for (int i =0 ; i < R -r +1; ++i)
        {
            for (int j =0 ; j < C -c +1; ++j)
            {
                pair<int, int> pos = make_pair(i, j);
                if(check( pos, G, P))
                {
                    flag = true;
                    break;
                }
                
            }
            if (flag) {
                break;
            }
        }
        if(flag)
            cout << "YES" <<endl;
        else
            cout << "NO" <<endl;
        
    }
    return 0;
}
