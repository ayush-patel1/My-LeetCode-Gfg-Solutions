class Node {
public:
    vector<Node*> child;
    bool flg;

    Node() {
        child.resize(26, nullptr);
        flg = false;
    }
};

class MagicDictionary {
    Node* root;

    bool dfs(Node* node, string &s, int pos, bool changed) {
        if (!node) return false;

        if (pos == s.size())
            return changed && node->flg;

        int idx = s[pos] - 'a';

        // Use the same character
        if (node->child[idx] && dfs(node->child[idx], s, pos + 1, changed))
            return true;

        // Change one character (only once)
        if (!changed) {
            for (int i = 0; i < 26; i++) {
                if (i == idx || !node->child[i]) continue;
                if (dfs(node->child[i], s, pos + 1, true))
                    return true;
            }
        }

        return false;
    }

public:
    MagicDictionary() {
        root = new Node();
    }

    void buildDict(vector<string> dictionary) {
        for (auto &s : dictionary) {
            Node* tmp = root;
            for (char ch : s) {
                int idx = ch - 'a';
                if (!tmp->child[idx])
                    tmp->child[idx] = new Node();
                tmp = tmp->child[idx];
            }
            tmp->flg = true;
        }
    }

    bool search(string searchWord) {
        return dfs(root, searchWord, 0, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */