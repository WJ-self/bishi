#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int e[N]; // node value at k-1
int ne[N]; // next node index
int head=-1, idx=0; // head node, usable node index (the k-th)

void add_to_head(int x) {
    e[idx] = x, ne[idx] = head, head = idx, idx++;
}