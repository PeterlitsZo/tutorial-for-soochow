#include <bits/stdc++.h>
using namespace std;
using ll=long long;

constexpr int MOD = 1e9 + 7;
constexpr int LEN = 12;
pair<char, int> OP[LEN];

int n, times_mark, add_mark, ans;

int ANS[1<<LEN][2];

int get_res(int i, int cur_op) {
    if(ANS[i][cur_op] != 0x3f3f3f3f)
        return ANS[i][cur_op];
    // 乘法的话，单位元是 1，不然是 0。
    int get = (cur_op == 1 ? 1 : 0);
    for(int j = 0; j < 12; j++) {
        if((i >> j) & 1) {
            if (cur_op == 1) get = (get * 1ll * OP[j].second) %MOD;
            else get = (get + OP[j].second) % MOD;
        }
    }
    return ANS[i][cur_op] = get;
}

// cur_op: 1 -> times, 0 -> add.
// state: 1 -> able ok to use, 0 -> unable.
void dfs(int bef, int state, int cur_op) {
    // state == 0 -> leaf node
    if(!state) {
        ans = min(ans, bef);
        return;
    }
    // Times. So choose a subset to times.
    if (cur_op == 1) {
        int aim = state & times_mark;
        if(!aim) { /* nothing to choose */ return; }
        for(int i = aim; i; i = (i - 1) & aim) {
            dfs(bef * 1ll * get_res(i, cur_op) % MOD, state & ~i, !cur_op);
        }
    // Add. So choose a subset to add.
    } else {
        int aim = state & add_mark;
        if(!aim) { /* nothing to choose */ return; }
        for(int i = aim; i; i = (i - 1) & aim) {
            dfs((bef + get_res(i, cur_op)) % MOD, state & ~i, !cur_op);
        }
    }
}

int main(){
    int t; scanf("%d", &t);
    while(t--) {
        // 初始化 ANS。
        memset(ANS, 0x3f, sizeof ANS);
        ans = 0x3f3f3f3f;

        // 读入并处理加操作和乘操作的掩码。
        int x; scanf("%d%d", &n, &x);

        times_mark = 0;
        add_mark = 0;
        for(int i = 0; i < n; i++){
            scanf(" %c%d", &OP[i].first, &OP[i].second);
            if(OP[i].first == '*') times_mark |= (1 << i);
            else add_mark |= (1 << i);
        }

        // 朴素无华的搜索
        dfs(x, (1 << n) - 1, 1);
        dfs(x, (1 << n) - 1, 0);
        printf("%d\n", ans);
    }
    return 0;
}
