#include <iostream>
#include <cctype>
#include <string>
#include <vector>
using namespace std;

bool lesspriority(char,char);
void push(char );
void pop();
vector<char>inf,pof;
char stk[500];
int i,j,top=0;



int main()
{
    int a,t=0;
    string str;
    cin>>a;
    a++;
    while(a--)
    {
        getline(cin,str);
        for(auto ch:str)
        {
            switch(ch)
            {
            case ' ':
                break;
            case '(':
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                push(ch);
                break;
            case ')':
                pop();
                break;

            default:
                pof.push_back(ch);
                break;
            }
        }
        while(top>0)
        {
            pof.push_back(stk[--top]);
        }
        for(auto au:pof)
            cout<<au;
        cout<<endl;
    pof.clear();
    inf.clear();
    }
    return 0;
}
bool lesspriority(char ch,char ts)
{
    if(ts=='(')
    {
        return false;
    }
    int pv1,pv2,t;
    char op[]= {'+','-','*','/','^','('};
    int pr[]= {0,0,1,1,2,3};

    for( t=0; t!=5; ++t)
    {
        if(op[t]==ch)
        {
            pv1=pr[t];
        }
    }
    for( t=0; t!=5; ++t)
    {
        if(op[t]==ts)
        {
            pv2=pr[t];
        }
    }
    if(pv1<pv2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(char ch)
{
    if(top==0)
    {
        stk[top++]=ch;
    }
    else
    {
        if(ch!='(')
        {
            while(lesspriority(ch,stk[top-1])==true && top>0)
            {
                pof.push_back(stk[--top]);
            }
        }
        stk[top++]=ch;
    }
}

void pop(void)
{

    while(stk[--top] !='(')
    {
        pof.push_back(stk[top]);
    }
}
