class PrefixTree {
public:
    PrefixTree* children[26]{};
    char val;
    bool endsWith = false;
    
    PrefixTree() {}
    
    void insert(string word) {
        PrefixTree* curr = this;
        for (char ch : word) {
            PrefixTree* node = curr->children[ch-'a'];
            if(node == nullptr) {
                node = new PrefixTree();
                node->val = ch;
                curr->children[ch-'a'] = node;
            }
            curr = node;
        }
        curr->endsWith = true;
    }
    
    bool search(string word) {
        PrefixTree* curr = this;
        for (char ch : word) {
            PrefixTree* node = curr->children[ch-'a'];
            if (node==nullptr || node->val != ch) {
                return false;
            }
            curr = node;
        }
        return curr->endsWith;
    }
    
    bool startsWith(string prefix) {
        PrefixTree* curr = this;
        for (char ch : prefix) {
            PrefixTree* node = curr->children[ch-'a'];
            if (node==nullptr || node->val != ch) {
                return false;
            }
            curr = node;
        }
        return true;
    }
};
