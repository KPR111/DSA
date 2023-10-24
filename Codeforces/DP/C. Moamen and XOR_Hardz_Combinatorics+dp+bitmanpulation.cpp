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
#define sum(v)                accumulate(all(v),0ll)
#define endl                  "\n"
#define inf                   (1LL<<30)


const int N = 2e5 + 10;
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


#ifdef KPR_111
#include "debug.h"
#else
#define deb(...)
#endif


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

int n,k;
    ll cnteven=0;
    ll pow_2=1;


ll dp[200005][2];
ll solve(int i,int equal){

    if(i<0)
        return 1;
    // cout<<i<<endl;
    ll &ans=dp[i][equal];
    if(~ans)
        return ans;
    ans=0;

    if(n&1){
        //odd
        //And>=Xor
        if(!equal)
            (ans+=mul(pow_2,solve(i-1,0)))%=MOD;
        else {
        //even no of ones 0,0
            (ans+=mul(cnteven,solve(i-1,1)))%=MOD;
        //all one 1,1
            (ans+=solve(i-1,1))%=MOD;
        }
    }
    else if (!(n&1)){
        if(!equal)
            (ans+=mul(pow_2,solve(i-1,0)))%=MOD;
        else{
            //even no of ones 0,0
            (ans+=mul(cnteven,solve(i-1,1)))%=MOD;
            //all one 1,0
            (ans+=solve(i-1,0))%=MOD;
        }
    }

    return ans;
}

void solve(){
    mem(dp,-1);
    cin>>n>>k;
    pow_2=1;
    cnteven=0;
    for(int i=0;i<n;i++){
        pow_2=mul(pow_2,2);
        if(i%2==0)
            (cnteven+=nCr(n,i))%=MOD;
    }
    // cout<<pow_2<<" "<<cnteven<<endl;
    cout<<solve(k-1,1)<<endl;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    factInverse();
    for(int t = 0; t < tt; t++) {
        //cout << "Case #" << t+1 << ": ";
        solve();
        //cout << endl;
        #ifdef KPR_111
            cout << "__________________________" << endl;
        #endif
    }
}