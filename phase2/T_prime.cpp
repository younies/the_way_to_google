//This T-Prime problem
//http://codeforces.com/problemset/problem/230/B

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


#define ll long long

bool check(long long n )
{
    /*long long sn = (long long) sqrt(n);
    int c = 0;
    //cerr << sn << endl;
    for (long long i = 2 ; i <= n/2 ; ++i)
    {
        if(n%i==0) c++;
        for(long long j = i*i ; j <= n/2 ; j = j * i)
        {
            if(n%j == 0)    c++;
            if(c > 1)
                return false;
        }
        
    }
    if(c == 1)
        return true;
    return false;
     */
    int c = 0;
    for (int i = 2; i * i  <= n; ++i){
        while (n%i == 0) {
            n/=i;
            c++;
           // cerr << c << endl;
        }
    }
    
    if (c == 2) {
        return true;
    }
    return false;
}


vector<ll> buildPrimes(ll num)
{
    vector<int> primes(num + 1, 1);
    
    for (ll i = 2;  i <= num; ++i)
    {
        if(primes[i] == 1)
            for (ll j = i*i; j <=num; j += i)
            {
                primes[j] = 0;
            }
    }
    
    vector<ll> ret;
    
    for (ll i = 2 ; i <= num; ++i)
    {
        if(primes[i] == 1)
            ret.push_back(i * i);
    }
    
    
    return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    
    long long n ;
    cin >> n  ;
    
    ll num = 1000000000000;
    num = sqrt(num);
    
    vector<ll> Tprimes = buildPrimes(num);
    
    
    
    for (int i= 0 ; i < n ; ++i) {
        
    
    long long temp;
    cin >> temp;
    if(binary_search(Tprimes.begin(), Tprimes.end() , temp))
        cout << "YES\n";
    else
        cout << "NO\n";
    }
    return 0 ;   
}