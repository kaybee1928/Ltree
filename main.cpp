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
        a->printData();
        cout<<el;
        return _a < _b;
    }
};




int main()
{
    ksb::LTree<int> a(1000, 0);
    //db(1);
    //*a.begin()=1;
    for (int i = 0; i < 1000; ++i)
    {
        a[i] = i;
    }
    //a.printData();
    // for (int i = 0; i <= 10000; ++i){
    //     //cout<<i<<el;
    //     auto itr = a.end();
    //     ll j = 0;
    //     ll k = a.end() - (a.begin() + i);
    //     //cout<<k<<el;
    //     while(k>=0) {++j;--itr;k--;}
    //     //if(i!=(10000 - j)) cout<<i<<" "<<j<<" lol "<<el;
    //     if(i!=0) if(i - 1 != (*itr)) cout<<"BBlol "<<(*itr)<<el;
    // }
    // for (int i = 0; i < 10000; ++i)
    // {
    //     cout<<a[i]<<" ";
    // }
    // cout<<(a.end() - (a.begin() + 5000))<<el;
    // cout<<(a.end() == (a.begin() + 10000))<<el;
    // for(int i = 0; i < 10000; ++i){
    //     for(int j = 0; j <=i; ++j){
    //         cerr<<i<<" "<<j<<el;
    //         if(i-j>=0){
    //             if(i-j != ((a.end()-j) - (a.end()-i)))
    //                 cout<<"Wasted \n";
    //         }
    //     }
    // }
    //cout<<ttt(1,2)<<el;
    //std::iter_swap(a.begin(), a.begin()+50);
    //a.printData();
    auto start = chrono::high_resolution_clock::now();
    //sort(a.begin(), a.end());
    // reverse(a.begin(), a.end());
    auto end = chrono::high_resolution_clock::now(); 
    // db(2);
    // while(itr!=a.end()){
    //     cout<<(*itr)<<" ";
    //     ++itr;
    // }
    // for (int i = 0; i < 1000000; ++i)
    // {
    //     cout<<(*(itr + i))<<" ";
    // }
    auto itr = a.begin();
    while(itr!=a.end()){
        cerr<<(*itr)<<" ";
        ++itr;
    }
    cout<<el;
    double tt =  
      chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 

    tt *= 1e-9; 
    cout<<tt<<el;
    // cout<<((a.begin() + 2) < (a.begin() + 10))<<el;
    // cout<<((a.begin() + 12) < (a.begin() + 10))<<el;
    return 0;
}
