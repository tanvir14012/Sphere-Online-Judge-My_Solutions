#include <bits/stdc++.h>
using namespace std;
int it;
list<char> topDown(char x[], char y[], int i, int j) {
		list<char> sb;
		if (i == strlen(x) || j == strlen(y)) {
			if (i == strlen(x)) {
				it = j;
				while (it < strlen(y)) {
					sb.push_back(y[it]);
					it++;
				}
				return sb;
			} else if (j == strlen(y)) {
				it = i;
				while (it < strlen(x)) {
					sb.push_back(x[it]);
					it++;
				}
				return sb;
			}
			else {
				return sb;
			}
		} else if (x[i] == y[j]) {

			sb = topDown(x, y, i + 1, j + 1);
			sb.push_front(x[i]);
			return sb;
		} else {
			list<char> sb1 = topDown(x, y, i + 1, j);
			sb1.push_front( x[i]);
			list<char> sb2 = topDown(x, y, i, j+1);
			sb2.push_front( y[j]);
			//System.out.println("fk : " + sb1 + " ;" + sb2);
			return sb1.size() < sb2.size() ? sb1 : sb2;
		}
	}
int main()
{
    char x[102],y[102];
    list<char> a;
    list<char>::iterator it;
    while(scanf("%s%s",x,y) == 2) {
        a = topDown(x,y,0,0);
        for(it = a.begin(); it != a.end(); it++){
        printf("%c",*it);
        }
        printf("\n");
    }
    return 0;
}


