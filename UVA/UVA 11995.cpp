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
	int x;
	while (cin >> x && x != EOF)
	{
		stack<int>st;
		priority_queue<int>pr;
		queue<int>q;
		int qu = 1, sta = 1, pri = 1;
		rep(i, x)
		{
			int a, b;
			cin >> a >> b;
			if (a == 1)
			{
				if (qu)
					q.push(b);
				if (pri)
					pr.push(b);
				if (sta)
					st.push(b);
			}
			else
			{
				if (sta)
				{
					if (st.size() == 0 || st.top() != b)
						sta = 0;
					else
						st.pop();
				}
				if (pri)
				{

					if (pr.size() == 0 || pr.top() != b)
						pri = 0;
					else
						pr.pop();
				}
				if (qu)
				{
					if (q.size() == 0 || q.front() != b)
						qu = 0;
					else
						q.pop();
				}
			}
		}
		if (qu + pri + sta > 1)
			cout << "not sure" << endl;
		else if (qu + pri + sta == 0)
			cout << "impossible" << endl;
		else
		{
			if (qu)
				cout << "queue" << endl;
			else if (sta)
				cout << "stack" << endl;
			else if (pri)
				cout << "priority queue" << endl;
		}
	}
	return 0;
}
