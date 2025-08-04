#include <iostream>
#include <map>
#include <string>

using namespace std;

struct Node {
    map<char, Node*> children;
};

class SuffixTree {
public:
    Node* root;

    SuffixTree() {
        root = new Node();
    }

    void insertSuffix(const string& suffix) {
        Node* current = root;
        for (char c : suffix) {
            if (current->children.count(c) == 0)
                current->children[c] = new Node();
            current = current->children[c];
        }
    }

    void build(const string& text) {
        for (size_t i = 0; i < text.size(); ++i) {
            insertSuffix(text.substr(i));
        }
    }

    void print(Node* node, string prefix = "") {
		for (auto& pair : node->children) {
			char ch = pair.first;
			Node* child = pair.second;
			cout << prefix << ch << endl;
			print(child, prefix + "  ");
		}

    }

    void display() {
        print(root);
    }
};

int main() {
    string text;
    cout << "Digite a string (ex: BANANA): ";
    cin >> text;
    text += "$"; // simbolo final

    SuffixTree tree;
    tree.build(text);

    cout << "\nÁrvore de Sufixos:\n";
    tree.display();

    return 0;
}
