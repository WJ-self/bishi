//排列数字
#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 10;
int path[N];

int dfs(int u) { // 层次
    if (u==n) { //遍历完成
        for (int i=0; i<n; i++) {
            printf("%d ", path[i]);
        }
        cout << endl;
        return 0;
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}