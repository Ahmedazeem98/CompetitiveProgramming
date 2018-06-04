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
int x, ans;
char arr[100][100];
bool vis[100][100];
set<char>st;
bool valid(int i, int j)
{
	return i >= 0 && i < x && j >= 0 && j < x;
}
void dfs(int i, int j)
{
	if (!valid(i, j) || arr[i][j] == '.')
		return;
	vis[i][j] = 1;
	st.insert(arr[i][j]);
	rep(k, 3)
	{
		int tox = i + dx[k];
		int toy = j + dy[k];
		if (!vis[tox][toy])
			dfs(tox, toy);
	}
}
int main()
{
	fast();
	int t;
	cin >> t;
	rep(f, t)
	{
		ans = 0;
		cout << "Case " << f + 1 << ": ";
		cin >> x;
		rep(i, x)
		{
			rep(j, x)
				cin >> arr[i][j], vis[i][j] = 0;
		}
		rep(i, x)
		{
			rep(j, x)
			{
				if (arr[i][j] != '.' && !vis[i][j])
				{
					dfs(i, j);
					if (st.size() == 2 || (st.size() == 1 && *st.begin() == 'x'))
						ans++;
					st.clear();
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
