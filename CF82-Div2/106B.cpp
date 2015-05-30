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

int a[105], b[105], c[105], d[105], n;
bool F[105];

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i)
        scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
    for (int i = 1; i <= n; ++i) {
        bool t = false;
        for (int j = 1; j <= n; ++j)
        if (a[i]<a[j]&&b[i]<b[j]&&c[i]<c[j]) {
            t = true;
            break;
        }
        F[i] = t;
    }
    int mn = 999999999, tmp = -1;
    for (int i = 1; i <= n; ++i)
    if (!F[i] && mn > d[i]) {
        mn = d[i];
        tmp = i;
    }
    cout << tmp << endl;
	return 0;
}
