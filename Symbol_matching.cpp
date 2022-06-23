#include <iostream>
#define Maxsize 10

typedef  struct {
    char data[Maxsize];
    int top;
}SqStack;

void InitStack(SqStack &S){
    S.top = 0;
}
bool StackEmpty(SqStack S){
    if(S.top == 0)return true;
    return false;
}
bool Push(SqStack &S,char a){
    if(S.top>Maxsize)return false;
    else {
        S.data[S.top] = a;
        S.top += 1;
        return true;
    }
}
bool Pop(SqStack &S,char& b){
    if(S.top==0) return false;
    else{
        b = S.data[S.top-1];
        S.top -= 1;
        return true;
    }

}

bool bracketCheck(char str[],int length){
    SqStack S;
    InitStack(S);
    for(int i = 0;i<length;i++){
        if(str[i]=='(' || str[i]=='[' || str[i]=='{'){
            Push(S,str[i]);
        }
        else {
            if (StackEmpty(S))
                return false;

            char topElem;
            Pop(S, topElem);
            if (str[i] == ')' && topElem != '(')
                return false;
            if (str[i] == ']' && topElem != '[')
                return false;
            if (str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return StackEmpty(S);
}
int main() {
    char str[] = {'{','(','(',')',')','[',']','}'};
    //char str[] = {'{','(','(',')',']','[',']','}'};
    bool boolFlag = bracketCheck(str,8);
    printf("%d",boolFlag);
}
