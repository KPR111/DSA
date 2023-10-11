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


vi primes={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};

vector<int> v;
int mod=1e9+7;
vector<int> ways(100005);
int dp[71][1<<19];

void init(){
    memset(dp,-1,sizeof(dp));
    ways[0]=1;
    for(int i=1;i<100003;i++){
        ways[i]=(ways[i-1]*2)%mod;
    }

}

int solve(int i,int bitmask){

    if(i==71){
        if(bitmask==0)return 1;
        return 0;
    }

    if(dp[i][bitmask]!=-1)
        return dp[i][bitmask];

    if(v[i]==0)return solve(i+1,bitmask);

    ll noofways=ways[v[i]-1];

    ll ans=0;


    //Observations are we need to play on the freq on the number as number are from 1 to 70 only
    //so for the array of n same numbers , we get 2power n-1 odd len subsequence and 2power n-1 even
    // len subsequence so ie the reason init() function is doing 
    // If that particular subsequence with even length will definetly make a perfect square so we are
    // not selecting any of the prime number in that so bitmask is sent as it as
    // In case of odd frequency subsequeces we need to definetly elimate all the even times repeated one
    // only one number remains , in 2n+1 2n aldready makes a perfect square so that extra only should
    // be added in the prime numbers bitmasking
    
    //selecting even frequency
    (ans+=noofways*(solve(i+1,bitmask)))%=mod;

    //selecting odd frequency
    int temp=i;
    int nbitmask=bitmask;
    int prime=0;
    while(temp>1){
        if(temp%primes[prime]==0){
            nbitmask^=(1<<prime);
            temp/=primes[prime];
        }
        else prime++;
    }

    (ans+=noofways*(solve(i+1,nbitmask)))%=mod;

    return dp[i][bitmask]=ans;
}
void solve(){
    init();
    int n;
    cin>>n;
    v.resize(71,0);

    rep(i,n){
        int x;cin>>x;v[x]++;
    }

    cout<< solve(1,0)-1<<endl;
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