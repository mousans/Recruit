#include<vector>
#include<iostream>
#include<stack>

using namespace std;

bool judge(char s){
    if(s == '+' || s == '-' || s == '*' || s == '/' || s == '(' || s == ')'){
        return true;
    }
    return false;
}

bool compare(char a,char b){
    if( a == '('){
        return false;
    }
   if( b == '+' || b == '-'){
       return true;
   }
    if( a == '*' || a == '/'){
        return true;
    }
    return false;
}
void pushOp(vector<string>& expression,char op){
    string tp;
    tp.push_back(op);
    expression.push_back(tp);
    return;
}
bool isNum(char a){
    if(a>'0'-1 && a<'9+1'){
        return true;
    }
    return false;
}
/**
 * 
 * 将中缀表达式转为后缀表达式 
 * 规则:
 * 1.遇到数字直接输出
 * 2.遇到(直接入栈
 * 3.遇到)将符号栈输出知道(
 * 4.对于其他符号,碰到优先级大于等于它的都输出,然后自己入栈
 * 
 * */
vector<string> midToAfter(string s){
    vector<string> expression;
    stack<char> ops;
    for (int i = 0; i < s.length();i++){
        if(judge(s[i])){
            switch(s[i]){
                case '(':
                    ops.push('(');
                    break;
                case ')':
                    while(!ops.empty() && ops.top() != '('){
                        pushOp(expression, ops.top());
                        ops.pop();
                    }
                    ops.pop();
                    break;
                default:
                    while(!ops.empty() && compare(ops.top(),s[i])){
                        pushOp(expression, ops.top());
                        ops.pop();
                    }
                    ops.push(s[i]);
                    break;
            }
        }else if(isNum(s[i])){
            int l = i;
            while (i<s.length()&&isNum(s[i]))
            {
                i++;
            }
            expression.push_back(s.substr(l, i - l));
            i--;
        }
    }
    while(!ops.empty()){
        pushOp(expression, ops.top());
        ops.pop();
    }
    return expression;
}

int changeToNum(string s){
    int res = 0;
    for (int i = 0; i < s.length();i++){
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

/**
 * 计算后缀表达式
 * */


int calculate(vector<string>& expression){
    stack<int> nums;
    for (int i = 0; i < expression.size();i++){
        if(judge(expression[i][0])){
            switch(expression[i][0]){
                case '+':
                    int r = nums.top();
                    nums.pop();
                    int l = nums.top();
                    nums.pop();
                    nums.push(l + r);
                    break;
                case '-':
                    int r = nums.top();
                    nums.pop();
                    int l = nums.top();
                    nums.pop();
                    nums.push(l - r);
                    break;
                case '*':
                    int r = nums.top();
                    nums.pop();
                    int l = nums.top();
                    nums.pop();
                    nums.push(l * r);
                    break;
                case '/':
                    int r = nums.top();
                    nums.pop();
                    int l = nums.top();
                    nums.pop();
                    nums.push(l / r);
                    break;
                default:
                    break;
            }
        }else{
            nums.push(changeToNum(expression[i]));
        }
    }
    return nums.top();
}
int main(){

}