class Solution {
public:
    void Union(unordered_map<string, string>& parent, string s, string s1) {
        if (parent.find(s) == parent.end() && parent.find(s1) == parent.end()) {
            parent[s] = " ";
            parent[s1] = s;
        }
        else {
            if (parent.find(s) != parent.end()) {
                if (parent[s] != " ") parent[s1] = parent[s];
                else parent[s1] = s;
            }
            else {
                if (parent[s1] != " ") parent[s] = parent[s1];
                else parent[s] = s1;
            }
        }
    }
    vector<string> backtracking(unordered_map<string, vector<string>>& child, string text) {
        vector<string> result, subresult;
        string str;
        unordered_map<string, vector<string>>::iterator itr1;
        int i, j, k, l;
        for (i=0; i<text.length(); ++i) {
            if (text[i] == ' ') {
                if (i != text.length()) subresult = backtracking(child, text.substr(i+1));
                if (child.find(text.substr(0, i)) != child.end()) {
                    str = text.substr(0, i);
                    for (k=0; k<subresult.size(); ++k)
                    {
                        for (l=0; l<child[text.substr(0, i)].size(); ++l)
                            result.push_back(child[str][l] + " " + subresult[k]);
                    }
                }
                for (k=0; k<subresult.size(); ++k)
                    result.push_back(text.substr(0, i+1) + subresult[k]);
                break;
            }
        }
        if (i == text.length()) {
            if (child.find(text) != child.end()) {
                for (l=0; l<child[text].size(); ++l)
                    result.push_back(child[text][l]);
            }
            result.push_back(text);
        }
        return result;
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        vector<string> result;
        unordered_map<string, string> parent;
        unordered_map<string, vector<string>> child;
        result.push_back(text);
        int i, n = synonyms.size(), j, k, l, len;
        string str, newtext;
        if (n==0) return result;
        for (i=0, j=0; i<=text.length(); ++i) {
            if (text[i] == ' ' || i==text.length()) {
                parent[text.substr(j, i-j)] = " ";
                j = i+1;
            }
        }
        for (i=0; i<n; ++i) {
            Union(parent, synonyms[i][0], synonyms[i][1]);
        }
        unordered_map<string, string>::iterator mapitr;
        for (mapitr=parent.begin(); mapitr!=parent.end(); ++mapitr) {
            if (mapitr->first != mapitr->second) {
                if (mapitr->second != " ") child[mapitr->second].push_back(mapitr->first);
            }
        }
        result = backtracking(child, text);
        sort(result.begin(), result.end());
        return result;
    }
};