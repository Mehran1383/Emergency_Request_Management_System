#include <iostream>

#include "heap.h"
#include "BST.h"

#define BLUE "\033[1;34m"
#define RESET "\033[1;0m"

int main()
{
	Heap heap;
	BST tree;
	Node* root = nullptr;
	string command;
	unsigned int pos, _pos;
	int id, pri;
	string time, name, desc;

	cout << "Press -h or --help to see the valid commands" << endl;

	while (1) {
		cout << BLUE <<"root:~$" << RESET;
		getline(cin, command);
		
		if (command == "-h" || command == "--help") {
			cout << "add <id> <priority> <name> <time> <description>" << endl;
			cout << "process" << endl;
			cout << "search <id>" << endl;
			cout << "update <id> <new priority>" << endl;
			cout << "list : heap array" << endl;
			cout << "list -t : preorder traversal of BST" << endl;
			cout << "exit" << endl;
		}
		else if (command.substr(0, 3) == "add") {
			pos = 4;

			pos = command.find(" ", pos);
			id = stoi(command.substr(4, pos - 4));
			_pos = ++pos;

			pos = command.find(" ", pos);
			pri = stoi(command.substr(_pos, pos - _pos));
			_pos = ++pos;

			pos = command.find(" ", pos);
			name = command.substr(_pos, pos - _pos);
			_pos = ++pos;

			pos = command.find(" ", pos);
			time = command.substr(_pos, pos - _pos);
			_pos = ++pos;

			pos = command.find(" ", pos);
			desc = command.substr(_pos, pos - _pos);

			root = tree.insert(root, tree.newNode(id, pri, name, time, desc));
			heap.insert(id, pri);
		}
		else if (command == "process") {
			HeapNode node = heap.extractMax();
			root = tree.delNode(root, node.getID());
		}
		else if (command.substr(0, 6) == "search") {
			pos = 7;

			pos = command.find(" ", pos);
			id = stoi(command.substr(7, pos - 7));

			Node* node = tree.search(root, id);

			cout << "ID" << "          " << node->getID() << endl;;
			cout << "Priority" << "    " << node->getPRI() << endl;
			cout << "Name" << "        " << node->getName() << endl;
			cout << "Time" << "	       " << node->getTime() << endl;
			cout << "Description" << " " << node->getDesc() << endl;
		}
		else if (command.substr(0, 6) == "update") {
			pos = 7;

			pos = command.find(" ", pos);
			id = stoi(command.substr(7, pos - 7));
			_pos = ++pos;

			pos = command.find(" ", pos);
			pri = stoi(command.substr(_pos, pos - _pos));

			heap.updateNode(id, pri);
		}
		else if (command == "list") {
			heap.printHeap();
		}
		else if (command == "list -t") {
			tree.preorder(root);
			cout << endl;
		}
		else if (command == "exit")
			break;
		else
			cout << "command not found" << endl;
	}

	return 0;
}