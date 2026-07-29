class Node {
public:
    vector<Node*> child;
    bool flg;

    Node() {
        child.resize(26, NULL);
        flg = false;
    }
};

class Trie {
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* tmp = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!tmp->child[idx])
                tmp->child[idx] = new Node();
            tmp = tmp->child[idx];
        }
        tmp->flg = true;
    }

    bool search(string word) {
        Node* tmp = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (!tmp->child[idx]) return false;
            tmp = tmp->child[idx];
        }
        return tmp->flg;
    }

    bool startsWith(string prefix) {
        Node* tmp = root;
        for (char ch : prefix) {
            int idx = ch - 'a';
            if (!tmp->child[idx]) return false;
            tmp = tmp->child[idx];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */