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
#define allr(v)      (v).rbegin(),(v).rend()
#define pb          push_back
#define sz          s.size()
#define ssz          ss.size()
#define vz          v.size()
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
//x = atoi(s.c_str())
void fast()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL), cout.tie(NULL);
}
int main()
{
	fast();
	queue<string>q;
	map<string, int>mp;
	int idx = 1, r = 5;
	for (char i = 'a'; i <= 'z'; i++)
	{
		string s;
		s += i;
		q.push(s);
	}
	string ss;
	while (!q.empty())
	{
		ss = q.front();
		q.pop();
		mp[ss] = idx++;
		if (ssz != 5)
		{

			for (char i = ss[ssz - 1] + 1; i <= 'z'; i++)
				q.push(ss + i);
		}
	}
	string f;
	while (cin >> f)
	{
		auto e = mp.find(f);
		if (e!=mp.end())
			cout << mp[f] << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}
