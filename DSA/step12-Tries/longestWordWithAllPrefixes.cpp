struct Node {
    Node *links[26];
    bool flag;
    
    bool containsKey(char c) {
        return links[c - 'a'] != NULL;
    }
    
    void put(char c, Node* node) {
        links[c- 'a'] = node;
    }
    
    void setEnd() {
        flag = true;
    }
    
    bool isEnd() {
        return flag;
    }
    
    Node* get(char c) {
        return links[c - 'a'];
    }
};

class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool searchString(string word) {
        Node* node = root;
        for (int i = 0; i < word.size(); i++) {
            if (!node->containsKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd();
    }
};

class Solution {
public:
    string longestValidWord(vector<string>& words) {
        // code here
        Trie tr;
        sort(words.begin(), words.end());
        for (string s: words) {
            tr.insert(s);
        }
        bool f = true;
        string ans = "";
        for (string s: words) {
            f= true;
            for (int i = 1; i < s.size(); i++) {
                if (!tr.searchString(s.substr(0, i))) {
                    f= false;
                    break;
                }
            }
            if (f  && (ans.size() < s.size())) {
                ans = s;
            }
        }
        return ans;
    }
};







