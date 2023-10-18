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


// const int mod = 1e9 + 7;
// inline int mul(int x, int y) {
// 	return (ll)x * y % mod;
// }


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


int n,m,b,mod;
vi v;

// int DP[502][502][502]
int dp[2][502][502];
// Optimizing the above dp memory ...
//Ideas here for space optimzation of DP to dp
// observations we need to definetly remove one of the p , lineno ,bugs
// we can remove p directly since we only need the present p and next p+1 
// ie present and previous 2D dp  so we can do this Iterative dp as show below
int solve(int p,int lineno,int bugs){

	if(lineno>m)return 0;
	if(bugs>b)return 0;
	if(p==n){
		if(lineno==m) return bugs<=b;
		return 0;
	}

	int& ans=dp[p][lineno][bugs];
	if(~ans)
		return ans;
	
	ans=0;

	int nt=solve(p+1,lineno,bugs);
	int t=solve(p,lineno+1,bugs+v[p]);

	(ans+=nt)%=mod;
	(ans+=t)%=mod;
	return (ans)%mod;

}
void solve(){

	mem(dp,0);
	cin>>n>>m>>b>>mod;
	v.resize(n);
	rep(i,n)cin>>v[i];

	// cout<<solve(0,0,0)%mod<<endl;
	rep(i,b+1){
		dp[n&1][m][i]=1;
	}

	for(int i=n-1;i>=0;i--){
		for(int j=m;j>=0;j--){
			for(int k=b;k>=0;k--){
				dp[i&1][j][k]=dp[(i+1)&1][j][k]%mod;
				if(j+1<=m && k+v[i]<=b)
					(dp[i&1][j][k]+=dp[i&1][j+1][k+v[i]])%=mod;
			}
		}
	}

	cout<<dp[0][0][0]<<endl;
	
	
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