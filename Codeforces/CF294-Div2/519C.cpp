#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

int n, m;

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&m);
    int res = 0;
    while (n && m) {
        res++;
        if (n >= m) {
            n -= 2;
            m--;
        }
        else {
            n--;
            m -= 2;
        }
    }
    if (n < 0 || m < 0) res--;
    cout << res << endl;
	return 0;
}
