#include <bits/stdc++.h>
using namespace std;

int fx[]= {-1,-1,-1, 0,0, 1,1,1};
int fy[]= {-1, 0, 1,-1,1,-1,0,1};
int counter,ct;

char** construct(char **a,int R,int C);
void destruct(char **a,int R,int C);
void DFS(char** a,int R,int C,int r,int c,int pr,int pc,string path,char* word,int index,int n,int visited[60][60]);
bool valid(char **a,int R,int C,int r,int c,int pr,int pc,char* word,int index,int visited[60][60]);
void search(char**a,int R,int C,char* word,int n,int visited[60][60]);

int main()
{
    int R,C;
    char word[]= {'A','B','C','D','E','F','G','H','I','K','L','M','N','O','P',
                  'Q','R','S','T','U','V','W','X','Y','Z'
                 };

    while(cin>>R>>C)
    {
        if(R==0 && C==0)
        {
            break ;
        }
        ++ct;
        char **a;
        int visited[60][60];
        for(int i=0; i<=R; i++)
        {
            for(int j=0; j<=C; j++)
            {
                visited[i][j]=0;
            }
        }
        a=construct(a,R,C);

        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                cin>>a[i][j];
            }
        }

//    for(int i=0; i<R; i++)
//    {
//        for(int j=0; j<C; j++)
//        {
//            cout<<a[i][j];
//        }
//        cout<<endl;
//    }
        search(a,R,C,word,sizeof(word),visited);
        cout<<"Case "<<ct<<": "<<counter+1<<endl;
        destruct(a,R,C);
        counter=0;
    }
    return 0;
}

char**  construct(char **a,int R,int C)
{
    a=new char*[R];
    for(int i=0; i<R; i++)
    {
        a[i]=new char[C];
    }
    return a;
}
void destruct(char **a,int R,int C)
{
    for(int i=0; i<R; i++)
    {
        delete [] a[i];
    }
    delete [] a;
}

void search(char**a,int R,int C,char* word,int n,int visited[60][60])
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(a[i][j]==word[0])
            {
                DFS(a,R,C,i,j,-1,-1,"",word,0,n,visited);
            }
        }
    }
}
void DFS(char** a,int R,int C,int r,int c,int pr,int pc,string path,char* word,int index,int n,int visited[60][60])
{
    if(index>n || a[r][c]!=word[index])
    {
        return ;
    }
    if(index>counter)
    {
        counter=index;
    }
    /*{
        stringstream ss,ss2;
        ss<<r;
        ss2<<c;
        path+=string(1,word[index])+"( "+ss.str()+","+ss2.str()+" )";
        cout<<path<<endl;
    }*/
    for(int i=0; i<8; i++)
    {
        if(valid(a,R,C,r+fx[i],c+fy[i],pr,pc,word,index,visited))
        {
            visited[r][c]=1;
            DFS(a,R,C,r+fx[i],c+fy[i],r,c,path,word,index+1,n,visited);
        }
    }
}

bool valid(char** a,int R,int C,int r,int c,int pr,int pc,char *word,int index,int visited[60][60])
{
    if(((r>=0 && r<R) && (c>=0 && c<C) && !(r==pc && c==pc))==0)
    {
        return false;
    }
    if(a[r][c]==word[index+1] && (visited[r][c]==0))
    {
        return true;
    }
return false;
}
