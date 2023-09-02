#include<bits/stdc++.h>
using namespace std;
int n;
const int N = 20;
char st[N][N];
int path[N];
bool col[N], dg[N], udg[N];

void dfs(int u) { //第u行
    if (u == n) {
        for(int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                printf("%c", st[i][j]);
            }
            cout << endl;
        }
    }
    int x = u;
    for (int y=0; y<n; y++) { // 每一列
        if(!col[y] && !dg[y-x+n] && !udg[y+x]) { //可以放棋子
            st[x][y] = 'Q';
            col[y] = dg[y-x+n] = udg[y+x] = true; //不能放了
            dfs(x+1);
            //恢复现场
            col[y] = dg[y-x+n] = udg[y+x] = false; 

        }

    }

}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++){
            st[i][j] = '.';
        }
    }
    dfs(0);
    return 0;
}