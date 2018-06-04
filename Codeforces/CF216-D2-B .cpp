#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <unordered_map>
using namespace std;
typedef long long ll;
const  double PI = 3.141592654;
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
#define all(s)      (s).begin(),(s).end()
#define allv(v)      (v).begin(),(v).end()
#define allr(v)      (v).rbegin(),(v).rend()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
int dx[] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[] = { 1, -1, 0, 0, -1, 1, 1, -1 };
void fast()
{
#ifndef ONLINE_JUDGE

/*
	**    ** ** **    *********   ** ** **
	**    **          **     **   **
	**    **          *********   **
	**    **          **          **
	**    ** ** **    **          ** ** **
*/
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int n, e;
vector<vector<int>>adj(100);
vector<vector<int>>cc;
vector<int>v;
bool vis[100];
map<int, int>mp;
map<int, int>mp1;
bool cycle = 0;
void dfs(int node , int p)
{
	if (!vis[node])
		v.push_back(node);
	if (vis[node])
	{
		cycle = 1;
		return;
	}
	vis[node] = 1;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int ch = adj[node][i];
		if (ch != p)
			dfs(ch, node);
	}
}
int main()
{
	fast();
	cin >> n >> e;
	int ans = 0;
	while (e--)
	{
		int a, b;
		cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int>free;
	rep(i, n)
	{
		if (!vis[i])
		{
			v.clear();
			cycle = 0;
			dfs(i, -1);
			if (v.size())
			{
				if (v.size() & 1 && cycle)
					ans += 1;
			}
		}
	}
	if ((n - ans) & 1)
		ans++;
	cout << ans;
	return 0;
}
