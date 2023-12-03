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

ll g(int h,int w,int n,vector<vector<ll>> pf){

        if(h<=n && w<=n)return pf[h][w];

        ll hq=h/n,wq=w/n;
        ll hr=h%n,wr=w%n;

        ll ans=0;

        ans+=g(n,n,n,pf)*(hq*wq);
        ans+=g(n,wr,n,pf)*hq;
        ans+=g(hr,n,n,pf)*wq;
        ans+=g(hr,wr,n,pf);

        return ans;

}

void solve(){
        int n;
        cin>>n;
        int q;
        cin>>q;

        vector<vector<char>> v(n,vector<char>(n) );

        rep(i,n){
                rep(j,n)
                        cin>>v[i][j];
        }

        vector<vector<ll>> pf(n+3,vector<ll> (n+3,0));

        fo(i,1,n+1){
                fo(j,1,n+1){

                        pf[i][j]=pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1]+(v[i-1][j-1]=='B')*1ll;
                }
        }

        deb(pf);

        while(q--){

                int a,b,c,d;
                cin>>a>>b>>c>>d;
                
                cout<<g(c+1,d+1,n,pf)-g(a,d+1,n,pf)-g(c+1,b,n,pf)+g(a,b,n,pf)<<endl;
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