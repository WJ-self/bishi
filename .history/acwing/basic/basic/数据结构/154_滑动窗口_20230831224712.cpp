#include<bits/stdc++.h>
using namespace std;

const int N = 1e6+10;
int q[N], a[N]; // save index

int main() {
    int n,k;
    cin >> n >> k;
    int h=0, t=-1; //head, tail
    // 维护最小值
    for (int i=0; i<n; i++) {
        cin >> a[i];
        while(h<=t && a[q[t]] >= a[i]) t--; //剔除队尾更大更老的元素
        q[++t] = i; //将新元素插入队尾
        if(q[h] < i-k+1) h++; //检查队头是否滑出了窗口
        if(i >= k-1) printf("%d ", a[q[h]]); //输出队头最小值
    }
    cout << endl;
    // 维护最大值
    h=0, t=-1; //head, tail
    for (int i=0; i<n; i++) {
        while(t!=-1 && a[q[t]] <= a[i]) t--; //剔除队尾更小更老的元素
        q[++t] = i; //将新元素插入队尾
        if(q[h] < i-k+1) h++; //检查队头是否滑出了窗口
        if(i >= k-1) printf("%d ", a[q[h]]); //输出队头最小值
    }
}