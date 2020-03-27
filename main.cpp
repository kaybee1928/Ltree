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
#define MOD 1000000007


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




int main()
{
    ksb::LTree<int> a(100, 0);
    //db(1);
    for (int i = 0; i < 100; ++i)
    {
        a[i] = a[i] = rand()%1024;
    }
    // for (int i = 0; i < 100; ++i)
    // {
    //     cout<<a[i]<<" ";
    // }
    ksb::LTree<int>::iterator::value_type c = 0;
    cout<<c<<el;
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    auto itr = a.begin();
    // db(2);
    while(itr!=a.end()){
        cout<<(*itr)<<" ";
        ++itr;
    }
    cout<<el;
    return 0;
}
