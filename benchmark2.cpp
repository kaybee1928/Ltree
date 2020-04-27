/*
* * * * * * * * * * * * * * * * * * *
*       Author : Ganzaki            *
*                                   *
*       language : c++              *
*                                   *
* * * * * * * * * * * * * * * * * * *
*/
#include <bits/stdc++.h>
#include "ltree"
#include <chrono> 
#define FOR(i,j,k) for(ll i=j;i<k;i++)
#define FOR1(i,j,k) for(ll i=j;i<=k;i++)
#define FOR2(i,j,k) for(ll i=j;i>=k;i--)
#define FILL(a,i) memset(a,i,sizeof(a))
#define db(i) printf("lol %d \n",i)
#define el '\n'
#define dbg(...) do{\
    fprintf(stderr,"%s - %d (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
#define MOD 10000000007


using namespace std;


using ll = long long;
using ul = unsigned long;
using str = std::string;
using ld = long double;
using ii = pair<ll,ll>;
using vs = std::vector<str>;
using vi = std::vector<int>;
using vll = std::vector<ll>;
using vc = std::vector<char>;
using mii = std::map<int,int>;
using msi = std::map<string,int>;
void desperate_optimization(int precision){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}




struct LOL{
    ksb::LTree<int> *a;
    bool operator()(int _a, int _b){
        cout<<el;
        return _a < _b;
    }
};




int main()
{
    ll n ;

    cout<<"For n = ";
    cin>>n;
    list<ll> l(n);
    for(auto itr = l.begin(); itr != l.end(); ++itr){
        *itr = rand()%1024;
    }
    ksb::LTree<ll> a(l.begin(), l.end());

    cout<<"Jumping to all elements "<<el; 
    auto start = chrono::high_resolution_clock::now();
    FOR(i,0,l.size()){
        ll t = i;
        auto xx = l.begin();
        while(t--) ++xx;
    }
    auto end = chrono::high_resolution_clock::now(); 
    double tt =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 

    tt *= 1e-9; 
    cout<<"List : "<<tt<<el;
    start = chrono::high_resolution_clock::now();
    FOR(i,0,a.size()){
        auto xx = (a.begin()+i);
    }
    end = chrono::high_resolution_clock::now(); 
    tt =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 

    tt *= 1e-9; 
    cout<<"LTree : "<<tt<<el;

    return 0;
}
