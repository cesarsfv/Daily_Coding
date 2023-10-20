class TreeNode:
    def __init__(self, value):
        self.value = value
        self.left = None
        self.right = None

def countUnivalSubtrees(root):
    if root is None:
        return 0, True

    left_count, is_left_unival = countUnivalSubtrees(root.left)
    right_count, is_right_unival = countUnivalSubtrees(root.right)

    if is_left_unival and is_right_unival:
        if (root.left and root.left.value == root.value) or root.left is None:
            if (root.right and root.right.value == root.value) or root.right is None:
                return 1 + left_count + right_count, True

    return left_count + right_count, False

# Exemplo de uso:
# Construindo uma árvore do exemplo fornecido
root = TreeNode(0)
root.left = TreeNode(1)
root.right = TreeNode(0)
root.right.left = TreeNode(1)
root.right.right = TreeNode(0)
root.right.left.left = TreeNode(1)
root.right.left.right = TreeNode(1)

count, _ = countUnivalSubtrees(root)
print("Número de subárvores unival:", count)
