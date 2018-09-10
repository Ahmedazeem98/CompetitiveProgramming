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
int main()
{
	fast();
	string s, ss;
	while (cin >> s >> ss)
	{
		reverse(all(s));
		reverse(all(ss));
		if (sz > ss.size())
			swap(s, ss);
		int arr[501];
		rep(i, 501)
			arr[i] = 0;
		int re = 0, f;
		for (int i = 0; i < sz; i++)
		{
			for (int j = 0; j < ss.size(); j++)
			{
				int a = s[i] - '0', b = ss[j] - '0', c = 0;
				arr[i + j] += (a*b);
			}
		}
		for (int i = 0; i < 501; i++)
		{
			arr[i + 1] += arr[i] / 10;
			arr[i] %= 10;	
		}
		int idx = -1;
		for (int i = 500; i >= 0; i--)
		{
			if (arr[i] != 0)
			{
				idx = i;
				break;
			}
		}
		if (idx == -1)
			cout << "0\n";
		else
		{
			for (int i = idx; i >= 0; i--)
				cout << arr[i];
			cout << "\n";
		}
	}
	return 0;
}
