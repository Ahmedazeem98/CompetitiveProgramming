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
int xx[] = { -1, 0, 0,};
int yy[] = { 0, -1, 1 };
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
int x, y, a, b;
char arr[9][9];
bool vis[9][9];
string s = "IEHOVA";
vector<string>ans;
bool test = 0;
bool valid(int i, int j)
{
	return i >= 0 && i < x && j >= 0 && j < y;
}
void dfs(int i, int j, string des)
{
	if (vis[i][j] || !valid(i, j))
		return;
	vis[i][j] = 1;
	if (des != "null" && test == 0)
		ans.push_back(des);
	if (arr[i][j] == '#')
	{
		test = 1;
		return;
	}
	for (int k = 0; k < 3; k++)
	{
		int tox = i + xx[k];
		int toy = j + yy[k];
		if (s.find(arr[tox][toy]) != -1 || arr[tox][toy] == '#' && valid(tox,toy))
		{
			if (k == 0)
				dfs(tox, toy, "forth");
			else if (k == 1)
				dfs(tox, toy, "left");
			else
				dfs(tox, toy, "right");
		}
	}
	vis[i][j] = 0;
}
int main()
{
	fast();
	int t;
	cin >> t;
	while (t--)
	{
		test = 0;
		cin >> x >> y;
		rep(i, x)
		{
			rep(j, y)
			{
				cin >> arr[i][j], vis[i][j] = 0;
				if (arr[i][j] == '@')
					a = i, b = j;
			}
		}
		dfs(a, b, "null");
		rep(i, ans.size())
		{
			if (i != ans.size() - 1)
				cout << ans[i] << " ";
			else
				cout << ans[i] << endl;
		}
		ans.clear();
	}
	return 0;
}
