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

int main() {
	freopen("input.txt","r",stdin);
	int w = 0, b = 0;
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            char x;
            scanf("%c",&x);
            if (x >= 'a') {
                if (x=='q') b += 9;
                else if (x=='r') b += 5;
                else if (x=='b'||x=='n') b += 3;
                else if (x=='p') b += 1;
            }
            else {
                if (x=='Q') w += 9;
                else if (x=='R') w += 5;
                else if (x=='B'||x=='N') w += 3;
                else if (x=='P') w += 1;
            }
        }
        scanf("\n");
    }
    if (w < b) cout << "Black";
    else if (w==b) cout << "Draw";
    else cout << "White";
	return 0;
}
