#ifndef BST_H
#define BST_H

#include <string>

using namespace std;

class Node {
private:
	int ID;
	int priority;
	string name;
	string time;
	string description;

	Node* left;
	Node* right;
public:
	void setID(int id) { ID = id; }
	void setPRI(int PRI) { priority = PRI; }
	void setName(string n) { name = n; }
	void setTime(string t) { time = t; }
	void setDesc(string desc) { description = desc; }
	void setLeft(Node* l) { left = l; }
	void setRight(Node* r) { right = r; }

	int getID() const { return ID; }
	int getPRI() const { return priority; }
	string getName() const { return name; }
	string getTime() const { return time; }
	string getDesc() const { return description; }
	Node* getLeft() { return left; }
	Node* getRight() { return right; }
};

class BST {
private:
	Node* getSuccessor(Node* curr);
public:
	Node* newNode(int id, int PRI, string name, string time, string desc);
	Node* insert(Node* root, Node* node);
	Node* search(Node* root, int id);
	Node* delNode(Node* root, int id);
	void preorder(Node* node);
};


#endif // !BST_H
