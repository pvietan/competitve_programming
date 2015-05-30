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

string s1, s2;
char a;
map <char,int> F;

int main() {
	freopen("input.txt","r",stdin);
    scanf("%c\n",&a);
    cin >> s1 >> s2;
    F['6'] = 1; F['7'] = 2;
    F['8'] = 3;
    F['9'] = 4;
    F['T'] = 5;
    F['J'] = 6;
    F['Q'] = 7;
    F['K'] = 8;
    F['A'] = 9;
    if (s1[1] == s2[1]) {
        if (F[s1[0]] > F[s2[0]]) printf("YES\n");
        else printf("NO\n");
    }
    else if (s1[1]==a) printf("YES\n");
    else if (s2[1]==a) printf("NO\n");
    else printf("NO\n");
	return 0;
}
