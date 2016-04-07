//This sor the array problem
//http://codeforces.com/problemset/problem/451/B

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <memory.h>
#include <fstream>
using namespace std;


pair<pair<long long, long long> , pair<long long, long long> > firstIndex(vector<long long> &numbers , vector<long long> &numbers2 )
{
    pair<long long, long long> ret;
    pair<long long, long long> ret2;
    int i ,n;
    
    ret.first = - 1;
    ret2.first = -1;
    for (i = 0 , n = (int)numbers.size(); i < n ; ++i)
    {
        if(numbers[i] != numbers2[i])
        {
            ret.first = i;
            ret.second = numbers[i];
            i++;
            break;
        }
    }
    
    
    for ( ;  i < n ; ++i)
    {
        if(ret.second == numbers2[i])
        {
            ret2.first = i ;
            ret2.second = numbers[i];
            break;
        }
    }
    
    return make_pair(ret, ret2);
    
}


bool check(vector<long long> &numbers , vector<long long> &numbers2, int i ,int  j)
{
    for ( int k = 0 , n = numbers2.size(); k <= (j - i)  ; ++k )
    {
        if(numbers[i + k] != numbers2[j - k])
            return false;
    }
    
    return true;
}

bool check2(vector<long long> &numbers , vector<long long> &numbers2, int i ,int  j)
{
    for ( int k = j+1 , n = (int)numbers2.size(); k < n  ; ++k )
    {
        if(numbers[k] != numbers2[k])
            return false;
    }
    
    return true;
}



int main(int argc, const char * argv[]) {
    // insert code here...
    
    long long n ;
    cin >> n  ;
    
    vector<long long> numbers(n);
    
    
    for (long long i = 0 ; i < n ; ++i)
    {
        cin >> numbers[i];
    }
    
    
    vector<long long> numbers2 = numbers;
    
    sort(numbers.begin(), numbers.end());
    
    pair<pair<long long, long long> , pair<long long, long long> > ineceis = firstIndex(numbers, numbers2);
    
    if (ineceis.first.first == -1)
    {
        cout << "yes\n1 1\n";
        return 0;
    }
    
    
    if(ineceis.second.first == -1)
    {
        cout << "no\n";
        return 0;
    }
    //cout << ineceis.second.first << endl;
    
    if(check(numbers, numbers2, ineceis.first.first, ineceis.second.first) && check2(numbers, numbers2, ineceis.first.first, ineceis.second.first))
    {
        cout << "yes\n";
        cout << ineceis.first.first+1 << " " << ineceis.second.first+1 << endl;
    }
    else
    {
        cout << "no\n" << endl;
    }
    
    
    return 0;
    
    
}
