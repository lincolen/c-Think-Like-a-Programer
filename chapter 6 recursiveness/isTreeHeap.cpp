
struct BinaryTreeNode {
	int value;
	BinaryTreeNode * right;
	BinaryTreeNode * left;
};
using  binaryTreeRoot = BinaryTreeNode * ;

isTreeHeap(binaryTreeRoot root) {
	if (root == nullptr)
		return true;

	bool IsHeap = true;
	if (root->right != nullptr) {
		IsHeap = (root->value > root->right->value && isTreeHeap(root->right))
	}
	if (root->left != nullptr) {
		IsHeap = (root->value > root->left->value && isTreeHeap(root->left))
	}
	return isHeap;
}

int main(){}