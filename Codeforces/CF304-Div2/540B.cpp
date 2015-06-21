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

int a[1005], n, k, p, x, y, sum, sum2;
bool f[1005];

int main() {
	freopen("input.txt","r",stdin);
    scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    for (int i = 1; i <= k; ++i) {
        scanf("%d",&a[i]);
        sum += a[i];
    }
    sort(a+1,a+k+1);
    for (int i = 1; i <= k; ++i) {
        f[a[i]] = true;
        if (a[i] < y) continue;
        if (max(0,n/2-i+1)+max(0,n/2-k+i) > n-k) continue;
        int sum2 = x-sum-max(0,n/2-i+1), tmp2 = max(0,n/2-k+i);
        if (a[i]*tmp2 <= sum2) {
            for (int j = 1; j <= max(0,n/2-i+1); ++j) printf("1 ");
            for (int j = 1; j <= tmp2; ++j) printf("%d ",a[i]);
            return 0;
        }
    }
    for (int i = y; i <= p; ++i) {
        if (f[i]) continue;
        int cnt1 = 0, cnt2 = 0;
        for (int j = 1; j <= k; ++j) {
            cnt1 += (a[j] <= i);
            cnt2 += (a[j] >= i);
        }
        if (max(0,n/2-cnt1) + max(0,n/2-cnt2)+1 > n-k) continue;
        int sum2 = x-sum-max(0,n/2-cnt1), tmp2 = max(0,n/2-cnt2);
        if ((ll)i*tmp2 <= sum2-i) {
            for (int i = 1; i <= max(0,n/2-cnt1); ++i) printf("1 ");
            for (int j = 1; j <= tmp2; ++j) printf("%d ",i);
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1");
	return 0;
}
