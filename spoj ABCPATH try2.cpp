#include <bits/stdc++.h>
using namespace std;

int fx[]= {-1,-1,-1, 0,0, 1,1,1};
int fy[]= {-1, 0, 1,-1,1,-1,0,1};
int counter,ct;
int visited[60][60];
char a[60][60];


void DFS(int R,int C,int r,int c,int depth);
bool valid(int R,int C,int r,int c,char ch);
void search(int R,int C);

int main()
{
    int R,C;

    while(cin>>R>>C)
    {
        if(R==0 && C==0)
        {
            break ;
        }
        ++ct;

        for(int i=0; i<R; i++)
        {
            for(int j=0; j<C; j++)
            {
                cin>>a[i][j];
                visited[i][j]=0;
            }
        }

        search(R,C);
        cout<<"Case "<<ct<<": "<<counter<<endl;

        counter=0;

    }
    return 0;
}



void search(int R,int C)
{
    for(int i=0; i<R; i++)
    {
        for(int j=0; j<C; j++)
        {
            if(a[i][j]=='A')
            {
                visited[i][j]=1;
                DFS(R,C,i,j,1);
            }
        }
    }
}
void DFS(int R,int C,int r,int c,int depth)
{

    if(depth>counter)
    {
        counter=depth;
    }

    for(int i=0; i<8; i++)
    {
        if(valid(R,C,r+fx[i],c+fy[i],a[r][c]))

        {
        if(a[r+fx[i]][c+fy[i]]==a[r][c]+1)
        {

                visited[r+fx[i]][c+fy[i]]=1;
                DFS(R,C,r+fx[i],c+fy[i],depth+1);
            }
        }
    }
}

bool valid(int R,int C,int r,int c,char ch)
{
    if(((r>=0 && r<R) && (c>=0 && c<C))&& !visited[r][c])
    {
        return true;
    }
    return false;
}

