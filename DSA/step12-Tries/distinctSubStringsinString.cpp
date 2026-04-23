struct Node{
    Node* links[26];
    bool flag;
    
    bool containsKey(char c) {
        return links[c - 'a'] != NULL;
    }
    
    void put(char c, Node* node) {
        links[c - 'a'] = node;
    }
    
    Node* get(char c) {
        return links[c - 'a'];
    }
    
    void setEnd() {
        flag = true;
    }
    
    bool isEnd() {
        return flag;
    }
};

// class Trie {
// private:
//     Node* root;
// public:
//     Trie() {
//         root = new Node();
//     }
    
//     void insert(string word) {
//         Node* node = root;
//         for (int i = 0; i < word.size(); i++) {
//             if (!(node->containsKey(word[i]))) {
//                 node->put(word[i], new Node());
//             }
//             node = node->get(word[i]);
//         }
//         node->setEnd();
//     }
    
//     bool searchString(string word) {
//         Node* node = root;
//         for (int i = 0; i < word.size(); i++) {
//             if (!node->containsKey(word[i])) return false;
//             node = node->get(word[i]);
//         }
//         return node->isEnd();
//     }
// };

class Solution {
  public:
    int countSubs(string& s) {
        // code here
        Node* root = new Node();
        int ans = 0;
        Node* node;
        for (int i = 0; i < s.size(); i++) {
            node = root;
            for (int j = i; j < s.size(); j++) {
                if (!node->containsKey(s[j])) {
                    node->put(s[j], new Node());
                    ans++;
                }
                node = node->get(s[j]);
            }
        }
        return ans;
    }
    
};