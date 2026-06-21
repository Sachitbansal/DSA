class DisjointSet {
    vector<int> rank, parent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;

        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int upu = findUPar(u);
        int upv = findUPar(v);

        if (upu == upv) return;

        if (rank[upu] < rank[upv]) {
            parent[upu] = upv;
        }
        else if (rank[upu] > rank[upv]) {
            parent[upv] = upu;
        }
        else {
            parent[upv] = upu;
            rank[upu]++;
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        unordered_map<string, int> mailToId;
        unordered_map<string, string> mailToName;

        int id = 0;

        // assign id to every email
        for (auto &acc : accounts) {

            string name = acc[0];

            for (int i = 1; i < acc.size(); i++) {

                string mail = acc[i];

                if (mailToId.find(mail) == mailToId.end()) {
                    mailToId[mail] = id++;
                }

                mailToName[mail] = name;
            }
        }

        DisjointSet ds(id);

        // union emails in same account
        for (auto &acc : accounts) {

            int firstMailId = mailToId[acc[1]];

            for (int i = 2; i < acc.size(); i++) {
                ds.unionByRank(firstMailId, mailToId[acc[i]]);
            }
        }

        // group emails by parent
        unordered_map<int, vector<string>> groups;

        for (auto &it : mailToId) {

            string mail = it.first;
            int node = it.second;

            int par = ds.findUPar(node);

            groups[par].push_back(mail);
        }

        vector<vector<string>> ans;

        for (auto &g : groups) {

            vector<string> emails = g.second;

            sort(emails.begin(), emails.end());

            string name = mailToName[emails[0]];

            emails.insert(emails.begin(), name);

            ans.push_back(emails);
        }

        return ans;
    }
};