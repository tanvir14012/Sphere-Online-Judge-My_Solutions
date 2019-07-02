#include <bits/stdc++.h>
using namespace std;

class trie {
private:
    bool endOfNode;
    trie* children[10];
public:
    trie(bool endOfNode) {
        this->endOfNode = endOfNode;
        for(int i = 0; i<10; i++) {
            children[i] = nullptr;
        }
    }
    bool getEndOfNode() {
        return endOfNode;
    }
    void endIt() {
        this->endOfNode = true;
    }
    void omitEnd() {
        endOfNode = false;
    }

    void insert(trie* root, string data) {
        int index;

        for(int i = 0; i<data.size(); ++i) {
            index = data[i] - '0';
            if(root->children[index] == nullptr) {
                root->children[index] = new trie(false);
                root = root->children[index];
            }
            else {
                root = root->children[index];
            }
        }
        root->endIt();
    }

    bool search(trie* root, string data) {
        int index;
        for(int i = 0; i<data.size(); ++i) {
            index = data[i] - '0';
            if(root->children[index] == nullptr) {
                return false;
            }
            else if(root->children[index]->endOfNode == true) {
                return true;
            }
            root = root->children[index];
        }
        return true;
    }
};
int main()
{
    trie* root;
    bool ans;
    int t,n;
    char str[10];
    scanf("%d",&t);
    while(t--) {
        root = new trie(false);
       scanf("%d",&n);
       ans = true;
       for(int i = 0; i<n; i++) {
        scanf("%s",str);
        if(root->search(root,str) == true){
            ans = false;
        }
        root->insert(root,str);
       }
       ans ? printf("YES\n") : printf("NO\n");
        delete root;
    }

    return 0;
}/**
simple trie implementation, a new number will cause (root->children[index] == nullptr)
to be true, and (root->children[index]->endOfNode == false, for any digit) to be true
 that's it.
**/
