#include <bits/stdc++.h>
using namespace std;
#define MAXS 1000000
#define MAXC 62
#define MAXW 1000

int g[MAXS][MAXC];
int f[MAXS];
bitset<MAXW> out[MAXS];
bitset<MAXW>ans;

class AhoCorasick
{
private:
    int n;
    char text[MAXS];

    void input()
    {
        char str[2000];
        memset(g,-1,sizeof g);
        memset(f,0,sizeof f);
        int state = 1,currState = 0,index = 0;
        scanf("%s%d",text,&n);
        for(int i = 0; i<n; i++)
        {
            scanf("%s",str);
            ///Building a trie, each new node gets the next number as node-name.
            currState = 0;

            for(int j = 0; str[j]; j++)
            {
                index = getIndex(str[j]);
                if(g[currState][index] == -1)
                {
                    g[currState][index] = state++;
                }
                currState = g[currState][index];
            }
            out[currState].set(i);
            ///stores whether i'th indexed string of arr, ends at state 'currState' or not. Thus adding the string to output by using 1 bit, hhh very memory efficient.

        }
    }
    void buildMachine()
    {
        ///Failure function
        queue<int>q;
        int s,fail;
        for(int i = 0; i<MAXC; i++)
        {
            if(g[0][i] != -1)
            {
                f[g[0][i]] = 0; ///here, depth is 1
                q.push(g[0][i]);
            }
            else
            {
                g[0][i] = 0; ///Necessary in failure alg below, non-existing char back to state 0. To stop infinite loop at line 68.
            }
        }
        while(! q.empty())
        {
            s = q.front();
            q.pop();
            for(int i= 0; i<MAXC; i++)
            {
                if(g[s][i] != -1)
                {
                    q.push(g[s][i]);
                    fail = f[s]; ///here is the perfect place to calculate failure of g[s][i],cuz here 'state:s' is (depth-1) state of 'state:g[s][i]'.
                    while(g[fail][i] == -1)
                    {
                        fail = f[fail];
                    }
                    fail = g[fail][i];
                    f[g[s][i]] = fail;
                    out[g[s][i]] |= out[fail]; ///merging output of the node & it's failure node.
                    ///Read the paper of aho-corasick,published in 1975.
                }
            }
        }
    }
    int nextState(int s, char ch)
    {
        int index = getIndex(ch);
        while(g[s][index] == -1)   ///If non-existing state, use failure function to support automaton.
        {
            s = f[s];
        }
        return g[s][index];
    }
    int getIndex(char ch)
    {
        if(ch >= '0' && ch <= '9')
        {
            return ch - '0';
        }
        else if (ch >= 'A' && ch <= 'Z') {
            return (ch - 'A') + 10;
        }
        else {
            return (ch-'a') + 36;
        }
    }
public:
    AhoCorasick() {}
    void search()
    {
        input();
        buildMachine();
        int state = 0;
        for(int i = 0; text[i]; i++)
        {
            state = nextState(state,text[i]); /// traverse the trie state/node for the text
            if(out[state].count() > 0) /// if the state has at least one output
            {
                ans |= out[state];
            }
        }
        for(int i = 0; i<n; i++)
        {
            if(ans.test(i))
            {
                printf("Y\n");
            }
            else
            {
                printf("N\n");
            }
        }
    }
};

int main()
{
    AhoCorasick alg;
    alg.search();


    return 0;
}
