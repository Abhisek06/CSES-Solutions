#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
#define ll long long int
#define pb push_back
#define pf push_front
#define pob pop_back
#define pof pop_front
#define debug1(x) cout<<#x<<" "<<x<<endl;
#define debug2(x,y) cout<<#x<<" "<<x<<"   "<<#y<<" "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" "<<x<<"   "<<#y<<" "<<y<<"   "<<#z<<" "<<z<<endl;
#define present(c,x) ((c).find(x) != (c).end())
#define null NULL
#define mp make_pair
#define sz(x)	(ll)x.size()
#define fi first
#define se second
#define boost ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define inf 1e18
#define flush fflush(stdout);
//#define endl '\n'
//unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
//shuffle (foo.begin(), foo.end(), std::default_random_engine(seed));
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<ll, null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
ll modpower(ll a,ll b,ll c)
{
	ll res=1;
	while(b)
	{
		if(b&1LL)
			res=(res*a)%c;
		a=(a*a)%c;
		b>>=1;
	}
	return res;
}
//-------------------------------Template--Above-----------------------------------------------
int n,m;
char arr[1001][1001];
bool visited[1001][1001];
bool valid(int r,int c){
    if(r<1 or r>n or c<1 or c>m or arr[r][c]=='#')
        return false;
    if(visited[r][c])
        return false;
    return true;
}
void dfs(int row,int col){
    visited[row][col]=true;
    if(valid(row-1,col))
        dfs(row-1,col);
    if(valid(row+1,col))
        dfs(row+1,col);
    if(valid(row,col-1))
        dfs(row,col-1);
    if(valid(row,col+1))
        dfs(row,col+1);
}
int main()
{
	boost
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            char c;
            cin>>c;
            arr[i][j]=c;
        }
	}
	int count=0;
	for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!visited[i][j] and arr[i][j]=='.'){
               // debug2(i,j)
                count++;
                dfs(i,j);
            }
        }
	}
	cout<<count<<endl;
	return 0;
}
