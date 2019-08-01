#include<iostream>
#include<cassert>
#include<algorithm> // max()

using std::cin;
using std::cout;
using std::endl;

template<class T> class BinaryTree {
	
		
	public:	
		class Node{
			private:
				Node * right;
				Node * left;
				T element;
			public:
				Node();
				Node(T element);
				Node(const Node & origin);
				Node * getRight() const;
				Node * getLeft() const;
				T getElement() const;
				void setRight(Node * newRight);
				void setLeft(Node * newLeft);
				void setElement(T newElemnt);
		};
		using Tree = Node * ;

		BinaryTree();
		~BinaryTree();
		void addElement(T newElement);
		void printTree() const;
		T findMax() const;
	


	protected:
		Tree head;
		Tree getHead() const;
		void setHead(Tree tree);
		void _printTree(Tree tree) const;
		void deleteTree(Tree tree);
		T findMax(Tree tree) const;
};

void testTree() {
	BinaryTree<int> myTree;
	myTree.addElement(5);
	myTree.addElement(22);
	myTree.printTree();

	//test is search tree
	
}

//initilazier get set functions for Nodes
template<class T> BinaryTree<T>::Node::Node() {
	this->setRight(nullptr);
	this->setLeft(nullptr);
}
template<class T> BinaryTree<T>::Node::Node(T element) : Node(){
	this->setElement(element);
}
template<class T> BinaryTree<T>::Node::Node(const Node & origin){
	this->setElement(origin.getElement());
	this->setRight(origin.getRight());
	this->setLeft(origin.getLeft());
}
template<class T> typename BinaryTree<T>::Node* BinaryTree<T>::Node::getRight() const{
	return this->right;
}
template<class T> typename BinaryTree<T>::Node * BinaryTree<T>::Node::getLeft() const{
	return this->left;
}
template<class T> T BinaryTree<T>::Node::getElement() const{
	return this->element;
}
template<class T> void BinaryTree<T>::Node::setRight(Node * newRight){
	this->right = newRight;
}
template<class T> void BinaryTree<T>::Node::setLeft(Node * newLeft){
	this->left = newLeft;
}
template<class T> void BinaryTree<T>::Node::setElement(T newElement){
	this->element = newElement;
}


template<class T>  typename BinaryTree<T>::Tree BinaryTree<T>::getHead() const {
	return this->head;
}
template<class T> void BinaryTree<T>::setHead(BinaryTree<T>::Tree tree)  {
	this->head = tree;
}
template<class T> BinaryTree<T>::BinaryTree() {
	this->setHead(nullptr);
}
template<class T> void BinaryTree<T>::addElement(T newElement) {
	if (this->getHead() == nullptr) {
		this->setHead(new Node(newElement));
		return;
	}
	
	Node * node;
	Node * next = this->getHead();
	do {
		node = next;
		if (newElement < node->getElement()) {
			next = node->getLeft();
		}
		else if (newElement > node->getElement()) {
			next = node->getRight();
		}
		else {
			std::cerr << "element already exists";
			return;
		}
	} while (next != nullptr);

	if (newElement < node->getElement()) {
		node->setLeft(new Node(newElement));
	}
	else if (newElement > node->getElement()) {
		node->setRight(new Node(newElement));
	}
}
template<class T> void BinaryTree<T>::printTree() const {
	this->_printTree(this->getHead());
}
template<class T> void BinaryTree<T>::_printTree(BinaryTree<T>::Tree tree) const {
	if (tree == nullptr) return;

	cout << tree->getElement() << endl;
	_printTree(tree->getRight());
	_printTree(tree->getLeft());

}
template<class T> void BinaryTree<T>::deleteTree(Tree tree) {
	if (tree == nullptr)
		return;

	
	cout << "deleteing " << tree->getElement() << endl;
	deleteTree(tree->getRight());
	deleteTree(tree->getLeft());
	delete tree;
}
template<class T> BinaryTree<T>::~BinaryTree() {
	cout << "\ndeleting binary tree" << endl;
	deleteTree(this->getHead());
}

template<class T> T BinaryTree<T>::findMax() const {
	assert(!"Tree is empty" || this->getHead() == nullptr);

	return(_findMax(this->getHead));
}

template<class T> T BinaryTree<T>::findMax(Tree tree) const {

	
	T max = tree->getElement;
	if(tree->getLeft() != nullptr)
		max = max(max, findMax(tree->getLeft()));
	if(tree->getright() != nullptr)
		max = max(max, findMax(tree->getright()));
	return max;
}

bool isBinarySearchTree(BinaryTree<int>::Node *root) {
	if (root == nullptr)
	return true;

	bool isSearchTree = true;
	if (root->getLeft() != nullptr) {
		isSearchTree = (root->getElement() > root->getLeft()->getElement()) && isBinarySearchTree(root->getLeft());
	}
	if (root->getRight() != nullptr) {
		isSearchTree = 
			isSearchTree && 
			(root->getElement() < root->getRight()->getElement()) && 
			isBinarySearchTree(root->getRight());
	}

	return isSearchTree;
}

