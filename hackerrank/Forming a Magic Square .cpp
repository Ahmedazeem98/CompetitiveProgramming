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
using namespace std;
typedef long long ll;
const  double PI = 3.141592654;
#define rep(i,x) for(int(i)=0;(i)<(ll)(x);(i)++)
#define all(s)      (s).begin(),(s).end()
#define allv(v)      (v).begin(),(v).end()
#define allvr(v)      (v).rbegin(),(v).rend()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
int dx[] = { 0, 0, -1, 1, -1, 1, -1, 1 };
int dy[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
//x = atoill(s.c_str())
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
vector<int>vv = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int arr1[3][3];
map<int, vector<vector<int>>>mp;
int sol = 0, tt;
bool If_magic()
{
	int sum = 0;
	set<int>st;
	for (int ii = 0; ii < 3; ii++)
	{
		sum = 0;
		for (int jj = 0; jj < 3; jj++)
		{
			sum += arr1[ii][jj];
		}
		st.insert(sum);
	}
	for (int ii = 0; ii < 3; ii++)
	{
		sum = 0;
		for (int jj = 0; jj < 3; jj++)
		{
			sum += arr1[jj][ii];
		}
		st.insert(sum);
	}
	st.insert((arr1[0][0] + arr1[1][1] + arr1[2][2]));
	st.insert((arr1[0][2] + arr1[1][1] + arr1[2][0]));
	if (st.size() == 1)
		return 1;
	else
		return 0;
}
void solve(vector<int>vv)
{
	int arr[3][3];
	set<int>st;
	int sum = 0, f = 0, ff = 3;
	for (int ii = 0; ii < 3; ii++)
	{
		for (int jj = f, g = 0; jj < ff; g++, jj++)
		{
			arr[ii][g] = vv[jj];
		}
		f += 3, ff += 3;
	}
	for (int ii = 0; ii < 3; ii++)
	{
		sum = 0;
		for (int jj = 0; jj < 3; jj++)
		{
			sum += arr[ii][jj];
		}
		st.insert(sum);
	}
	for (int ii = 0; ii < 3; ii++)
	{
		sum = 0;
		for (int jj = 0; jj < 3; jj++)
		{
			sum += arr[jj][ii];
		}
		st.insert(sum);
	}
	st.insert((arr[0][0] + arr[1][1] + arr[2][2]));
	st.insert((arr[0][2] + arr[1][1] + arr[2][0]));
	int n = 0, nn = 3;
	if (st.size() == 1)
	{
		for (int k = 0; k < 3; k++)
		{
			vector<int>b(vv.begin() + n, vv.begin() + nn);
			mp[sol].push_back(b);
			n += 3, nn += 3;
		}
		sol++;
	}
}
void generate()
{
	do
	{
		for (int h = 0; h < 3; h++)
		{
			solve(vv);
		}
	} while (next_permutation(allv(vv)));
}
int main()
{
	fast();
	rep(i, 3)
	{
		rep(j, 3)
			cin >> arr1[i][j];
	}
	if (If_magic())
	{
		cout << 0 << endl;
		return 0;
	}
	generate();
	int mn = 1000;
	for (auto e : mp)
	{
		int dif = 0;
		rep(i, 3)
		{
			rep(j, 3)
			{
				dif += abs(arr1[i][j] - e.second[i][j]);
			}
		}
		if (dif != 0)
			mn = min(mn, dif);
	}
	cout << mn << endl;
	return 0;
}
