class Node{
public:
    vector<Node*> child;
    bool flg;
    Node(){
        child.assign(26, NULL);
        flg = false;
    }
};

class Trie{
public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void add(string s){
        Node* t = root;
        for(auto ch : s){
            if(!t->child[ch - 'a']){
                t->child[ch - 'a'] = new Node();
            }
            t = t->child[ch - 'a'];
        }
        t->flg = true;
    }

    bool dfs(string &w, int i, Node* t){
        if(i == w.size()) return t->flg;

        if(w[i] == '.'){
            for(int j = 0; j < 26; j++){
                if(t->child[j] && dfs(w, i + 1, t->child[j]))
                    return true;
            }
            return false;
        }
        else{
            if(!t->child[w[i] - 'a']) return false;
            return dfs(w, i + 1, t->child[w[i] - 'a']);
        }
    }

    bool search(string &word){
        return dfs(word, 0, root);
    }
};

class WordDictionary {
public:
    Trie t;

    WordDictionary() {}

    void addWord(string word) {
        t.add(word);
    }
    
    bool search(string word) {
        return t.search(word);
    }
};
/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */