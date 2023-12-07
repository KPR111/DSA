// #define KPR_111


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
#define sum(v)                accumulate(all(v),0ll)
#define endl                  "\n"
#define inf                   (1LL<<30)


#ifdef KPR_111
#include "debug.h"
#else
#define deb(...)
#endif


const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
ll fact[N], inv[N], invfact[N];
void factInverse() {
        fact[0] = inv[1] = fact[1] = invfact[0] = invfact[1] = 1;
        for (long long i = 2; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = MOD - (inv[MOD % i] * (MOD / i) % MOD);
        invfact[i] = (inv[i] * invfact[i - 1]) % MOD;
    }
}


ll mul(int x, int y) {
    return (1LL * x * y) % MOD;
}

ll nCr(int n, int r) {
        if (r > n)
        return 0;
    return mul(mul(fact[n], invfact[r]), invfact[n - r]);
}


const int Number = 1e6 + 5;
vector<int> primes;
bool prime[Number];
void seive(){
    mem(prime, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= Number; i++){
        if(prime[i]){
            for(int j = i * i; j <= Number; j += i){
                prime[j] = false;
            }
        }
    }
    for(int i = 2; i <= Number; i++){
        if(prime[i]) primes.pb(i);
    }
}

int binpow(int x, int y)
{
    int z = 1;
    while(y)
    {
        if(y & 1) z = mul(z, x);
        x = mul(x, x);
        y >>= 1;
    }
    return z;
}


// if O(n^2) is not working go for nlogn and if not working think about n*31



void solve(){
    int n,m;
    cin>>n>>m;
    vector<string>v(n);
    rep(i,n)cin>>v[i];
    vector<vector<int>> vis(n,vector<int> (m,0));
    // vector<vector<pair<int,int>>> par(n,vector<pair<int,int>> (m,0));
    map<pair<int,int>,pair<int,int>> par;
    pair<int,int> orginal;
    queue<pair<pair<int,int>,int>> q;
    rep(i,n)
        rep(j,m){
            if(v[i][j]=='A')vis[i][j]=1,par[{i,j}]={-1,-1},orginal={i,j};
            if(v[i][j]=='M')q.push({{i,j},1}),vis[i][j]=1;
        }

    q.push({orginal,0});    

    vector<int> dx={1,-1,0,0};
    vector<int> dy={0,0,1,-1};
    pair<int,int> p={-1,-1};
    while(!q.empty()){

        auto it=q.front();
        q.pop();

        int x=it.f.f;
        int y=it.f.s;
        int who=it.s;

        if(who){
            //monster as source
            
            for(int i=0;i<4;i++){
                int nrw=x+dx[i];
                int ncl=y+dy[i];

                if(nrw>=0 && nrw<n && ncl>=0 && ncl<m && v[nrw][ncl]=='.' && !vis[nrw][ncl] ){
                    vis[nrw][ncl]=1;
                    q.push({{nrw,ncl},1});
                }
            }
        }
        else{
            bool cansurvive=0;
            //Player as source
            
            for(int i=0;i<4;i++){
                int nrw=x+dx[i];
                int ncl=y+dy[i];

                if(nrw<0 || nrw>=n || ncl <0 || ncl>=m ){
                    // p={nrw,ncl};
                    par[{nrw,ncl}]={x,y};
                    p.f=nrw;
                    p.s=ncl;
                    // cout<<"flkdjfklsdf";
                    break;
                }

                if(nrw>=0 && nrw<n && ncl>=0 && ncl<m && v[nrw][ncl]=='.' && !vis[nrw][ncl] ){
                    vis[nrw][ncl]=1;
                    par[{nrw,ncl}]={x,y};
                    deb(x,y,par[{nrw,ncl}],nrw,ncl,par[{x,y}]);
                    q.push({{nrw,ncl},0});
                    cansurvive=1;
                }
            }

        }
    }

    // cout<<p.f<<" "<<p.s<<endl;
    string s;
    if(p.f==-1)NO;
    else{
        YES;
        
        int ct=0;

        p=par[p];

        while(p!=orginal){
                ct++;
            auto present=p;
            auto parent=par[p];
            deb(p,parent);
            if(parent.f==-1)break;
            if(present.f-parent.f>0)s+='D';
            else if(present.f-parent.f<0)s+='U';
            else if(present.s-parent.s>0)s+='R';
            else if(present.s-parent.s<0)s+='L';
            p=par[p];
        }
        cout<<ct<<endl;
        
        reverse(all(s));
        cout<<s<<endl;
    }

    


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