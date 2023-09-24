#include<bits/stdc++.h>
using namespace std;

const int N = 310;
int v[N],s[N]; // v:各个重量，s:前缀和
int dp[N][N];// dp[i][j]: 区间i->j的最小合并代价
int n;

int main(){
    cin>>n;
    memset(dp, 0x3f, sizeof dp);
    for (int i=1; i<=n; i++) {
        cin >> v[i];
        s[i] = s[i-1]+v[i];
    }

    for(int len = 1; len<=n; len++) {
        for (int i = 1; i<=n; i++) {
            int j = i+len-1;

            if(i == j) {
                dp[i][j] = 0;
                break;
            }

            for(int k=i; k<=j; k++) {
                dp[i][j] = min(dp[i][k] + dp[k+1][j] + s[j]-s[i-1], dp[i][j]);
            }
        }
    }
}