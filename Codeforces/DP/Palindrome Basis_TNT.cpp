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

vi palin;
int reverse(int n)
{
    int r=0;
    while(n>0)
    {
        r=r*10+n%10;
        n/=10;
    }
    return r;
}
bool palindrome(int n)
{
    return (reverse(n)==n); 
}

int dp[40003][500];
int m=1e9+7;
int solve(int i,int j,int n){
	if(i==0)return 1;
	if(i<0||j>=palin.sz)return 0;

	if(dp[i][j]!=-1)
		return dp[i][j];

	int ans=0;
	(ans+=solve(i,j+1,n))%=m;
	(ans+=solve(i-palin[j],j,n))%=m;

	return dp[i][j]= ans;
}
// void solve(){
// 	int n=40000;
// 	// cin>>n;
// 	// cout<<solve(n,0,n)<<endl;

// 	rep(i,palin.sz+1){
// 		dp[0][i]=1;
// 	}

// 	for(int i=1;i<=n;i++){
// 		dp[i][0]=0;
// 		for(int j=palin.sz-1;j>=0;j--){
// 			dp[i][j]=dp[i][j+1]%m;
// 			if(i-palin[j]>=0){
// 				(dp[i][j]+=dp[i-palin[j]][j])%=m;
// 			}
// 		}
// 	}
// 	// cout<<dp[n][0]<<endl;
// }

int32_t main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	fo(i,1,40001){
		if(palindrome(i))palin.pb(i);
	}
	mem(dp,-1);
	// solve();
	int ans=solve(40000,0,40000);
	int tt = 1;
	cin >> tt;
	for(int t = 0; t < tt; t++) {
		//cout << "Case #" << t+1 << ": ";
		//cout << endl;
		int n;
		cin>>n;
		cout<<dp[n][0]<<endl;
		#ifdef KPR_111
			cout << "__________________________" << endl;
		#endif
	}
}