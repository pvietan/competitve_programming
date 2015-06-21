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

int m;
char s[1000005], res[1000005];
ll F[105];

bool isCharacter(char x) {
    return x>='A' && x <='Z';
}

void solve1() {
    int i, cot = 0;
    for (i = 0; i < m; ++i)
    if (!isCharacter(s[i])) break;
    for (int j = i; j < m; ++j)
        cot = cot*10+s[j]-'0';
    m = i;
    ll row = F[m-1]+1;
    for (int i = 0; i < m; ++i)
        if (i != m-1) row += (s[i]-'A')*(F[m-i-1]-F[m-i-2]);
        else row += s[i]-'A';
    printf("R%I64dC%I64d\n",(ll)cot,(ll)row);
}

void solve2() {
    int row = 0, cot = 0; bool b = false;
    for (int i = 1; i < m; ++i) {
        if (s[i]=='C') b = true;
        else {
            if (!b) cot = cot*10+s[i]-'0';
            else row = row*10+s[i]-'0';
        }
    }
    int n; ll tmp;
    for (int i = 1; i <= 100; ++i)
        if (F[i] >= row) {
            n = i;
            for (int i = 0; i < n; ++i)
                res[i]='A';
            tmp = F[n-1]+1;
            break;
        }
    for (int i = 0; i < n-1; ++i)
    for (char j = 'Z'; j >= 'A'; --j)
    if (tmp+(j-'A')*(F[n-i-1]-F[n-i-2]) <= row) {
        tmp += (j-'A')*(F[n-i-1]-F[n-i-2]);
        res[i] = j;
        break;
    }
    res[n-1] = row-tmp+'A';
    for (int i = 0; i < n; ++i)
        printf("%c",res[i]);
    printf("%d\n",cot);
}

bool check() {
    int i, j;
    for (i = m-1; i >= 0; --i)
        if (isCharacter(s[i])) break;
    for (j = i; j >= 0; --j)
        if (!isCharacter(s[j])) break;
    if (j < 0) return true;
    return false;
}

int main() {
    int n;
	freopen("input.txt","r",stdin);
    scanf("%d\n",&n);
    F[1] = 26;
    for (int i = 2; F[i-1] <= 1000000; ++i) {
        F[i] = F[i-1];
        ll tich = 1;
        for (int j = 0; j < i; ++j)
            tich *= 26;
        F[i] += tich;
    }
    while (n--) {
        scanf("%s\n",s);
        m = strlen(s);
        if (check()) solve1();
        else solve2();
    }
	return 0;
}
