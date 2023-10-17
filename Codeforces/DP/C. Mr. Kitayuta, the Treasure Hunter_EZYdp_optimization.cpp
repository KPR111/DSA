//#define KPR_111


#include<bits/stdc++.h>
using namespace std;


using ll= long long;
typedef pair<ll, ll>          pll;
typedef vector<ll>            vll;
typedef vector<pll>           vpll;
typedef vector<string>        vs;
typedef unordered_map<ll,ll>  umll;
typedef map<ll,ll>            mll;
#define pb                    push_back
#define eb                    emplace_back
#define sz                    size()
#define maxpq                 priority_queue<int>
#define minpq                 priority_queue<int, vector<int>, greater<int> >
#define f                     first
#define s                     second
#define vi                    vector<int>
#define vvi                   vector<vi>
#define vb                    vector<bool>
#define pii                   pair<int,int>
#define vpi                   vector<pii>
#define vvb                   vector<vb>
#define YES                   cout << "YES" << "\n"
#define NO                    cout << "NO" << "\n"
#define prDouble(x)           cout << fixed << setprecision(10) << x
#define ispowoftwo(n)         (!(n & (n-1)))
#define fo(i,m,n)             for(ll i=(ll)(m);i<(ll)(n);i++)
#define rep(i,n)              fo(i,0,n)
#define rl(i,n,m)             for(int i=n;i>=m;i--)
#define all(v)                v.begin(),v.end()
#define uniq(v)               (v).erase(unique(all(v)),(v).end()) //if you sort it and use you get uniqe elements
#define mem(a, b)             memset(a, (b), sizeof(a))
#define ct(x,v)               count(v.begin(),v.end(),x)
#define mxe(v)                *max_element(v.begin(),v.end())
#define mne(v)                *min_element(v.begin(),v.end())
#define endl                  "\n"
#define inf                   (1LL<<30)


#ifdef KPR_111
#include "debug.h"
#else
#define deb(...)
#endif




int n,d;
vi v;
int m;




// map<pair<int,int>,int> dp;
// If you use maps in place of array gives you tle , using maps is highly risy and time limit is also 1 second ,ie restricted
int dp[30003][500];
// map<int,int> mp;
vi gems;


int solve(int i,int jL){

    if(i>m||jL==0){
        return 0;
    }

    int mjeL=jL-d+250;// jL<d if I decrease ie l to l-1 jL
    //Observation is mjeL ie maximum jump extra length is always <246
    // 245*244/2==30000 nearly so max mjeL can not be more than 250 and -250 
    // so use mjeL as dp variable
    if(dp[i][mjeL]!=-1)return dp[i][mjeL];

    int ans=-1e9;

    if(i==0)
        return ans=max(ans,gems[i]+solve(i+jL,jL));
    else{
        if(jL>0)ans=max(ans,gems[i]+solve(i+jL-1,jL-1));
        ans=max(ans,gems[i]+solve(i+jL,jL));
        ans=max(ans,gems[i]+solve(i+jL+1,jL+1));
    }

    return dp[i][mjeL]=ans;
}
void solve(){
    mem(dp,-1);
    cin>>n>>d;
    v.resize(n);
    gems.resize(30001,0);
    rep(i,n)cin>>v[i];
    rep(i,n)gems[v[i]]++;
    m=*max_element(all(v));

    cout<< solve(0,d)<<endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    // cin >> tt;
    for(int t = 0; t < tt; t++) {
        //cout << "Case #" << t+1 << ": ";
        solve();
        //cout << endl;
        #ifdef KPR_111
            cout << "__________________________" << endl;
        #endif
    }
}    