#include <bits/stdc++.h>
using namespace std;
///spoj ELEVTRBL try 2.cpp is also accepted
bool visited[10000000];
class value
{
    int stair,button_click;
public:
    value()
    {
        stair = button_click = 0 ;
    }
    value(int x,int y)
    {
        stair =x;
        button_click = y;
    }
    int getStair()
    {
        return stair;
    }
    int getButton()
    {
        return button_click;
    }
};
int main()
{

    int f,s,d,up,down,count = 0,temp;
    queue<value*> q;
    unordered_map<int,int>parent;
    scanf("%d%d%d%d%d",&f,&s,&d,&up,&down);
    bool flag = true;

    value v(s,0);
    q.push(&v);
    while(!q.empty())
    {
        value *temp = q.front();
        q.pop();
        visited[temp->getStair()] = true;
        if(temp->getStair() == d)
        {
            flag = false;
            cout<<temp->getButton()<<endl;
            break;

        }

        if((temp->getStair() + up) <=f && visited[temp->getStair()+up]==false)
        {

                q.push(new value(temp->getStair() + up, temp->getButton()+1));
                visited[temp->getStair() + up] = true;

        }
         if((temp->getStair() - down) > 0 && visited[temp->getStair() - down] == false)
        {

                q.push(new value(temp->getStair()-down,temp->getButton() + 1));
                visited[temp->getStair() - down] = true;
        }

    }
    if(flag)
    {
        cout<<"use the stairs"<<endl;
    }


    return 0;
}
/** if you set visited[f],you get WA. visited[10000000] helps to handle corner case like "visited[values > f]". **/
