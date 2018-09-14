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
#include <unordered_map>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include<cstdlib>
#include <utility>
#include <valarray>
#include <vector>
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
#define ssz          ss.size()
#define vz          v.size()
#define clr(v,val) memset(v,val,sizeof v)
//x = atoi(s.c_str())
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
ll fib(int n)
{
	return (((1 / sqrt(5))*(pow((1 + sqrt(5)) / 2, n)) - ((1 / sqrt(5))*(pow((1 - sqrt(5)) / 2, n)))));
}
void fast(){
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
bool isPrime(int x)
{
	if (x == 1)
		return 0;
	for (int j = 2; j*j <= x; j++)
	{
		if (x%j == 0)
			return 0;
	}
	return 1;
}
vector<int>top;
int vis[102];
int x, k;
void dfs(int node ,vector<int>adj[])
{
	if (vis[node])
		return;
	vis[node] = 1;
	rep(k, adj[node].size())
	{
		int ch = adj[node][k];
		if (!vis[ch])
			dfs(ch,adj);
	}
	top.push_back(node);
}
int main()
{
	fast();
	while (cin >> x >> k)
	{
		if (!x)
			break;
		vector<int>adj[102];
		rep(i, 102)
			vis[i] = 0;
		top.clear();
		rep(i, k)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
		}
		for (int i = 1; i <= x; i++)
		{
			if (!vis[i])
				dfs(i,adj);
		}
		cout << top[top.size()-1];
		for (int i = top.size()-2; i >= 0; i--)
			cout << " " << top[i];
		cout << "\n";
	}
	return 0;
}
