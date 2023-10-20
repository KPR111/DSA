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

int n,k;
vi a;
vi cold;
vi hot;

ll dp[2][5001][2];
ll solve(int i,int laststored,int cpu){

	// cout<<i<<" "<<laststored<<" "<<cpu<<endl;
	if(i==n)
		return 0;

	ll &ans=dp[i][laststored][cpu];
	if(~ans)
		return ans;

	ans=0;
	if(i>0 && a[i]==a[i-1]){
		ans=solve(i+1,laststored,cpu)+hot[a[i]-1];
	}
	else if(i>0 && a[i]==laststored){
		ans=solve(i+1,a[i-1],!cpu)+hot[a[i]-1];
	}
	else 
		ans=min(solve(i+1,laststored,cpu)+cold[a[i]-1],solve(i+1,a[i-1],!cpu)+cold[a[i]-1]);

	return ans;
}

void solve(){
	mem(dp,0);
	cin>>n>>k;
	a.resize(n);
	cold.resize(k);
	hot.resize(k);
	rep(i,n)cin>>a[i];
	rep(i,k)cin>>cold[i];
	rep(i,k)cin>>hot[i];
	// cout<<solve(1,0,0)+cold[a[0]-1]<<endl;

	for(int i=n-1;i>=1;i--){
		for(int c1=k;c1>=0;c1--){
			for(int c2=1;c2>=0;c2--){
				ll ans=1e18;
				if(i>0 && a[i]==a[i-1]){
					ans=dp[(i+1)&1][c1][c2] +hot[a[i]-1];
				}
				else if(i>0 && a[i]==c1){
					ans=dp[(i+1)&1][a[i-1]][!c2]+hot[a[i]-1];
				}
				else 
					ans=min( dp[(i+1)&1][c1][c2] +cold[a[i]-1],dp[(i+1)&1][a[i-1]][!c2]+cold[a[i]-1]);
				dp[i&1][c1][c2]=ans;
			}
		}
	}

	cout<<dp[1][0][0]+cold[a[0]-1]<<endl;
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