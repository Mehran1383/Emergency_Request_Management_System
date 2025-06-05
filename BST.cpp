#include <iostream>

#include "BST.h"

Node* BST::newNode(int id, int PRI, string name, string time, string desc)
{
	Node* temp = new Node();

	temp->setID(id);
	temp->setPRI(PRI);
	temp->setName(name);
	temp->setTime(time);
	temp->setDesc(desc);
	temp->setRight(NULL);
	temp->setLeft(NULL);

	return temp;
}
Node* BST::insert(Node* root, Node* node) 
{
	if (root == NULL) {
		root = node;
	}
	else if (node->getID() < root->getID())
		root->setLeft(insert(root->getLeft(), node));
	else
		root->setRight(insert(root->getRight(), node));

	return root;
}

void BST::preorder(Node* node) 
{
	if (node != NULL) {
		std::cout << node->getID() << " ";
		preorder(node->getLeft());
		preorder(node->getRight());
	}
}

Node* BST::search(Node* root, int id) 
{
	if (root == NULL)
		return NULL;
	if (id == root->getID()) {
		return root;
	}
	else if (id < root->getID()) {
		search(root->getLeft(), id);
	}
	else if (id > root->getID()) {
		search(root->getRight(), id);
	}
	else
		return NULL;
}

Node* BST::getSuccessor(Node* curr) 
{
    curr = curr->getRight();
    while (curr != nullptr && curr->getLeft() != nullptr)
        curr = curr->getLeft();
    return curr;
}

Node* BST::delNode(Node* root, int id) 
{
    if (root == nullptr)
        return 0;

	if (root->getID() > id)
		root->setLeft(delNode(root->getLeft(), id));
	else if (root->getID() < id)
		root->setRight(delNode(root->getRight(), id));
    else {
        // Cases when root has 0 children
        // or only right child
        if (root->getLeft() == nullptr) {
            Node* temp = root->getRight();
            delete root;
            return temp;
        }
        // When root has only left child
        if (root->getRight() == nullptr) {
            Node* temp = root->getLeft();
            delete root;
            return temp;
        }
        // When both children are present
        Node* succ = getSuccessor(root);
        root = succ;
		root->setRight(delNode(root->getRight(), succ->getID()));
    }
    return root;
}

