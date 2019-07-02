#include <bits/stdc++.h>
using namespace std;

class trie {
private:
    bool endOfNode;
    int counter;
    trie* children[26];
public:
    trie() {
        //this->endOfNode = endOfNode;
        counter = 1;
        for(int i = 0; i<26; i++) {
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
    int getCounter() {
    return this->counter;
    }
    void increaseCounter() {
        counter++;
    }

    void insert(trie* root, string data) {
        int index;

        for(int i = 0; i<data.size(); ++i) {
            index = data[i] - 'a';
            if(root->children[index] == nullptr) {
                root->children[index] = new trie();
                root = root->children[index];
            }
            else {
                root = root->children[index];
                root->increaseCounter();
            }
        }
        /*if(root->getEndOfNode() == true) { //Handling duplicate
            while(root->children[26] != nullptr) {
                root = root->children[26];
            }
            root->children[26] = new trie(true);
        }*/
        //root->endIt();
    }

    int search(trie* root, string data) {
        int index,ans = 0;
        for(int i = 0; i<data.size(); ++i) {
            index = data[i] - 'a';
            if(root->children[index] == nullptr) {
                return 0;
            }
            root = root->children[index];
        }
        return root->getCounter();
        //return getCount(root,ans);
    }
    /*int getCount(trie* node,int& count) {
        if(node == nullptr) {
            return count;
        }
        if(node->getEndOfNode() == true) {
            count += node->getCounter();
        }
        for(int i = 0; i<26; i++) {
            getCount(node->children[i],count);
        }
        return count;
    }*/
   /* void deleteIt(trie* root, string data) {
        if(root == nullptr) {
            return ;
        }
        int index;
        for(int i = 0; i<data.size(); i++) {
            index = data[i] - 'a';
            if(root->children[index] == nullptr) {
                return ;
            }
            root = root->children[index];
        }
        root->omitEnd();
    }*/
};
int main()
{
    trie root;
    int n,q;
    char str[1000007];
    scanf("%d%d",&n,&q);
    for(int i = 0; i<n; i++) {
        scanf("%s",str);
        root.insert(&root,str);
    }
    for(int i = 0; i<q; i++) {
        scanf("%s",str);
        printf("%d\n",root.search(&root,str));
    }
    return 0;
}

/**
To handle duplicate input, int counter in trie node is required. For each insert
operation, while traversing counter value for each node is incremented. Finally,
in search operation, the last node's counter value stores sum of all successors.
*/
