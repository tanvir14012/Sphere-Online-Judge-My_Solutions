#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
bool visited[1000009];
int main()
{

    int f,s,d,up,down,count = 0,temp;
    queue<int> q;
    unordered_map<int,int>parent;
    scanf("%d%d%d%d%d",&f,&s,&d,&up,&down);
    bool flag;
    q.push(s);
    parent[s] = -1;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        visited[temp] = true;
        if(temp == d)
        {
            count = 0;
            flag = false;
            if(parent.empty())
            {
                cout<<0<<endl;
                break;
            }
            while(parent[temp] != -1)
            {
                count++;
                temp = parent[temp];
                if(temp == 0)
                {
                    flag = true;
                    break;
                }
            }

            if(flag == false){cout<<count<<endl;
            break;}
        }

        if((temp + up) <=f && visited[temp+up]==false)
        {

                q.push(temp + up);
                visited[temp+up] = true;
                parent[temp+up] = temp;

        }
         if((temp-down)>0 && visited[temp-down]==false)
        {

                q.push(temp-down);
                visited[temp-down] = true;
                parent[temp-down] = temp;
        }

    }
    if(flag)
    {
        cout<<"use the stairs"<<endl;
    }


    return 0;
}
/** if you set visited[f],you get WA. visited[10000000] helps to handle corner case like "visited[values > f]". **/
