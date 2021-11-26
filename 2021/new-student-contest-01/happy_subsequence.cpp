#include<bits/stdc++.h>
using namespace std;


const int maxn = 1e4 + 5;
char s[maxn], p[] = {'C', 'a', 'r', 'o', 'l'};
int main() {
    scanf("%s", s + 1);
    int n = strlen(s + 1), cur = 0;
    for (int i = 1; i <= n; ++i) {
        if (s[i] == p[cur]) {
            ++cur;
            if (cur == 5) break;
        }
    }
    if (cur == 5) printf("Happy");
    else printf("Emmm");
    return 0;
}
