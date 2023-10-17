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


vi primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47, 53};
vi masks;
vi v;
int n;

int dp[100][1<<17];

int solve(int i,int bitmask){

    if(i==n)return 0;

    if(dp[i][bitmask]!=-1)
        return dp[i][bitmask];

    int ans=1e9;
    for(int j=1;j<54;j++){

        if((bitmask&masks[j])==0){
            ans=min(ans,abs(v[i]-j)+solve(i+1,bitmask|masks[j]));
        }
    }

    return dp[i][bitmask]=ans;
}

vi fa;
void traceroute(int i,int bitmask){
    if(i==n)return ;

    int ans=dp[i][bitmask];
    for(int j=1;j<54;j++){

        if((bitmask&masks[j])==0){
            if(ans==abs(v[i]-j)+solve(i+1,bitmask|masks[j])){
                fa.pb(j);
                traceroute(i+1,bitmask|masks[j]);
                return;
            }
        }
    }

    return ;
}

void solve(){
    mem(dp,-1);
    cin>>n;
    rep(i,n){
        int x;
        cin>>x;
        v.pb(x);
    }
    masks.resize(100);
    for(int i=1;i<60;i++){
        // int j=0;
        masks[i]=0;
        rep(j,primes.sz)
            if(i%primes[j]==0){
                masks[i]|=(1<<j);
            }
        // cout<<masks[i]<<endl;
    }

    int a=solve(0,0);
    // cout<<a<<endl;
    traceroute(0,0);
    rep(i,fa.sz){
        cout<<fa[i]<<" ";
    }
    cout<<endl;
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