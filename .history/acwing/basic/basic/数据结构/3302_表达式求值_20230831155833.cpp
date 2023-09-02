#include<bits/stdc++.h>
using namespace std;

// 双栈，一个操作数栈，一个运算符栈；
stack<int> num;
stack<char> op;
string func;
int res;

int count() {
    char op_ = op.top();
    op.pop();
    int num1 = num.top();
    num.pop();
    int num2 = num.top();
    num.pop();
    switch(op_) {
        case '+': res = num1 + num2;
            break; 
        case '-': res = num2 - num1; // 注意顺序
            break;
        case '*': res = num1 * num2;
            break;
        case '/': res = num2 / num1;  // 注意顺序
            break;
    } 
    num.push(res);
    if(op.top() == '(')
        op.pop();
}

int main() {
    cin >> func;
    for(int i=0; i<func.length(); i++) {
        if(func[i] == ')') {
            count();
            printf("res:%d\n",res);
        }
        else if(func[i] == '(')
            op.push('(');
        else if(func[i] >= '0' && func[i] <= '9'){ // 又不可能一直是个位数
            string snum = "";
            while(func[i] >= '0' && func[i] <= '9'){
                num += func[i];
            }
            if(op.top() == '*' || op.top() == '/')
                count();
        }
        else 
            op.push(func[i]);
    }
    while(num.size() > 1){ // while, not if
        count();
    }
    printf("%d", res);
}

