#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int d1;
    int m1;
    int y1;
    cin >> d1 >> m1 >> y1;
    int d2;
    int m2;
    int y2;
    cin >> d2 >> m2 >> y2;
    
    long long fine = 0;
    
    if(y2 < y1)
        {
        fine = (y1 - y2) * 10000;
    }
    
    else if(m2 < m1 && y1 == y2)
        {
        fine = (m1 - m2) * 500;
    }
    
    else if(d2 < d1 && m1 == m2 &&  y1 == y2)
        {
        fine = (d1 - d2) * 15;
    }
    
    cout << fine << endl;
    
    return 0;
}
