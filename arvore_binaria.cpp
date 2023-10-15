/* Dada a raiz de uma árvore binária, implemente serialize(root), que serializa a árvore em uma string, e deserialize(s), que desserializa a string de volta na árvore.

Por exemplo, dada a seguinte class Node

class Node:
     def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
O seguinte teste deve passar:

node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'     */


#include <iostream>
#include <sstream>
#include <string>
#include <queue>

class TreeNode {
public:
    std::string val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(std::string val) : val(val), left(nullptr), right(nullptr) {}
};

class TreeSerializer {
public:
    // Serializa a árvore em uma string
    std::string serialize(TreeNode* root) {
        if (!root)
            return "null";
        
        std::string result = root->val + " ";
        result += serialize(root->left) + " ";
        result += serialize(root->right);
        return result;
    }

    // Desserializa a string de volta para a árvore
    TreeNode* deserialize(std::istringstream& iss) {
        std::string val;
        iss >> val;
        if (val == "null")
            return nullptr;
        
        TreeNode* root = new TreeNode(val);
        root->left = deserialize(iss);
        root->right = deserialize(iss);
        
        return root;
    }
};

int main() {
    TreeNode* node = new TreeNode("root");
    node->left = new TreeNode("left");
    node->left->left = new TreeNode("left.left");
    node->right = new TreeNode("right");

    TreeSerializer serializer;
    std::string serialized = serializer.serialize(node);
    std::istringstream iss(serialized);
    TreeNode* deserialized = serializer.deserialize(iss);

    // Verifica se a desserialização funcionou corretamente
    if (deserialized && deserialized->left && deserialized->left->left && deserialized->left->left->val == "left.left") {
        std::cout << "Teste passou!" << std::endl;
    } else {
        std::cout << "Teste falhou!" << std::endl;
    }

    return 0;
}
