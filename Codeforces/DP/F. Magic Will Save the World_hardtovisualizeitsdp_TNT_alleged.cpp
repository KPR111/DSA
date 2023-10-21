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


const int mod = 1e9 + 7;
inline int mul(int x, int y) {
    return (ll)x * y % mod;
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

int searchforanswer(vi x, int n, int k) {
    int ans = 0;
    for (int a = n; a >= 1; a /= 2) {
        while ( x[ans+a] <= k) ans += a;
    }
    return ans;
}

int w,f;
int n;
vi s;

int dp[2][1000001];
// bool solve(int i,int sum){

//     if(i>=n){
//         cout<<sum<<endl;
//         return dp[i][sum]= true;
//     }

//     if(dp[i][sum]!=-1)return dp[i][sum];
//     int nt=solve(i+1,sum);
//     int t=solve(i+1,sum+s[i]);

//     return dp[i][sum]=t|nt;
// }

bool check(int mid){
    // for(int i=0;i<=sum(s);i++){
    //     if(dp[0][i]){
    //         if((w*1ll)*mid>=i && (f*1ll)*mid>=sum(s)-i || (w*1ll)*mid>=sum(s)-i && (f*1ll)*mid>=i)return true;
    //     }
    // }
    // return false;
    for(int i=max(0,int(sum(s)-f*mid));i<=w*mid;i++){
        if(dp[0][i])return true;
    }
    return false;
}

void solve(){
    mem(dp,0);
    cin>>w>>f;
    cin>>n;
    s.resize(n);
    rep(i,n)cin>>s[i];
    // for(int i=0;i<=1000001;i++){
    //     dp[n&1][i]=1;
    // }
    // bool a=solve(0,0);
    int sum=sum(s);
    dp[n&1][sum]=1;
    for(int i=n-1;i>=0;i--){
        for(int j=sum;j>=0;j--){

            int nt=dp[(i+1)&1][j];
            int t=dp[(i+1)&1][j+s[i]];

            dp[i&1][j]=nt|t;
        }
    }
    // cout<<dp[0][13]<<endl;

    int ans=1e9;
    int lo=1,hi=1;
    // ffftttttttttttt
    while(!check(hi))hi*=2;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;

        if(check(mid))hi=mid-1;
        else lo=mid+1;
    }
    cout<<lo<<endl;

    // for(int i=0;i<=sum(s);i++){
    //     if(dp[0][i]){
    //         ans=min(ans,max((int)ceil((i*1.0)/w),(int)ceil((sum-i)*1.0)/f));
    //     }
    // }
    // cout<<ans<<endl;
    

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tt = 1;
    cin >> tt;
    for(int t = 0; t < tt; t++) {
        //cout << "Case #" << t+1 << ": ";
        solve();
        //cout << endl;
        #ifdef KPR_111
            cout << "__________________________" << endl;
        #endif
    }
}