class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> words(wordList.begin(), wordList.end());
        words.erase(beginWord);

        auto fin = words.find(endWord);
        if (fin == words.end()) return 0;
        while(!q.empty()) {
            int step = q.front().second;
            string word = q.front().first;
            q.pop();
            if (word == endWord) {return step;}
            int len = beginWord.length();

            for (int j = 0; j<len; j++) {
                char original = word[j];
                for (char i = 'a'; i<='z'; i++) {
                    word[j] = i;
                    if (words.find(word) != words.end()){
                        q.push({word, step+1});
                        words.erase(word);
                    }
                }
                word[j] = original;
            }
        }
        return 0;
    }
};
