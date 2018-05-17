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
const int MAX = 501;
int x, y, z;
bool vis[MAX][MAX];
char arr[MAX][MAX];
bool valid(int i, int j)
{
	return i >= 0 && i < x && j >= 0 && j < y;
}
void flood_fill(int i, int j)
{
	if (!valid(i, j) || arr[i][j] == '#' || vis[i][j])
		return;
	vis[i][j] = 1;
	flood_fill(i + 1, j);
	flood_fill(i - 1, j);
	flood_fill(i, j + 1);
	flood_fill(i, j - 1);
	if (z)
		arr[i][j] = 'X', z--;
}
int main() {

	fast();
	cin >> x >> y >> z;
	rep(i, x)
	{
		rep(j, y)
			cin >> arr[i][j];
	}
	rep(i, x)
	{
		rep(j, y)
		{
			cin >> arr[i][j];
			if (!vis[i][j] && arr[i][j] == '.')
				flood_fill(i, j);
		}
	}
	rep(i, x)
	{
		rep(j, y)
			cout << arr[i][j];
		cout << endl;
	}
	return 0;
}
