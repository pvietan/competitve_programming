#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <unordered_map>

using namespace std;

#define pb push_back
#define sz(a) (int)a.size()
#define fs first
#define sc second

typedef long long ll;
typedef pair<int,int> ii;

int res[200005][2], b[100005], a[100005], n, ptr[100005], k;
bool B[100005];
unordered_map <int,int> F;
vector <int> adj[100005];

void change(int & tmp, int x) {
    if (tmp==x) return;
    swap(a[tmp],a[x]);
    swap(tmp,x);
    k++;
    res[k][0] = tmp; res[k][1] = x;
    adj[F[a[x]]].pb(x);
}

bool check(int x) {
    for (; x; x /= 10) if (x%10!=4 && x%10!=7) return false;
    return true;
}

int main() {
    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    bool f = true;
    for (int i = 1; i <= n; ++i)
    if (a[i] != b[i]) {
        f = false;
        break;
    }
    if (f) {
        printf("0");
        return 0;
    }
    int tmp = -1;
    for (int i = 1; i <= n; ++i)
    if (check(a[i])) {
        tmp = i;
        break;
    }
    if (tmp == -1) {
        printf("-1");
        return 0;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (i==1 || b[i] != b[i-1]) F[b[i]] = ++cnt;
        else F[b[i]] = F[b[i-1]];
    }
    for (int i = 1; i <= n; ++i)
        adj[F[a[i]]].pb(i);
    for (int i = n; i > 0; --i) {
        if (b[i]==a[tmp]) continue;
        if (b[i] == a[i]) {
            B[i] = true;
            continue;
        }
        int x;
        for (;;) {
            x = adj[F[b[i]]][ptr[F[b[i]]]++];
            if (a[x] == b[i] && !B[x]) break;
        }
        change(tmp,i);
        change(tmp,x);
        B[i] = true;
    }
    printf("%d\n",k);
    for (int i = 1; i <= k; ++i)
        printf("%d %d\n",res[i][0],res[i][1]);
    return 0;
}
