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
int dx[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };
char arr[50][50];
bool vis[50][50];
int x, c;
bool valid(int i, int j)
{
	return i < x && j < x && i >= 0 && j >= 0;
}
void dfs(int i, int j)
{
	if (!valid(i, j) || vis[i][j] || arr[i][j] == '0')
		return;
	vis[i][j] = 1;
	for (int k = 0; k < 8; k++)
	{
		int tox = i + dx[k], toy = j + dy[k];
		if (arr[tox][toy] == '1')
			dfs(tox, toy);
	}
}
int main()
{
	fast();
	while (cin >> x)
	{
		int ans = 0;
		rep(i, x)
		{
			rep(j, x)
			{
				cin >> arr[i][j];
				vis[i][j] = 0;
			}
		}
		rep(i, x)
		{
			rep(j, x)
			{
				if (arr[i][j] == '1' && !vis[i][j])
				{
					ans++;
					dfs(i, j);
				}
			}
		}
		c++;
		cout << "Image number " << c << " contains " << ans << " war eagles.\n";
	}
	return 0;
}
