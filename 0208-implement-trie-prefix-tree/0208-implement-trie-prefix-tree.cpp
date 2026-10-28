class Trie {
private:
    struct Node {
        Node* children[26]{};
        bool isEnd = false;
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->children[idx] == nullptr)
                node->children[idx] = new Node();

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        Node* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (node->children[idx] == nullptr)
                return false;

            node = node->children[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (node->children[idx] == nullptr)
                return false;

            node = node->children[idx];
        }

        return true;
    }
};
