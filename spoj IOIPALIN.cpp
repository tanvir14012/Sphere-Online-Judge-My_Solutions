#include <bits/stdc++.h>
using namespace std;
int T[5002][3];
inline int get(int count, int val){
		count = count + 3 + val;
		if(count >= 3)
		{count -= 3;}
		return count;
	}
 int bottomUp(string& str, int n) {
	     int count = 0;
		for (int l = 1; l < n; l++) {
			count = (count < 2)?count+1 : 0;
			for (int i = 0; i < n; i++) {
				if (i+l < str.length() && str[i] == str[i + l]) {
					if (i + 1 < str.length() && l - 2 >= 0) {
						T[i][count] = T[i + 1][get(count,-2)];
					}
				} else {
					if (i + l < str.length() && l - 1 >= 0) {
						T[i][count] = 1 + min(T[i][get(count,-1)], T[(i + 1)][get(count,-1)]);
					}
				}
			}
		}
		return T[0][count];
	}

int main()
{
    int n;
    string s;
    cin>>n>>s;
    printf("%d\n",bottomUp(s,n));
    return 0;
}
