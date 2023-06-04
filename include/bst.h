// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <algorithm>

template < typename T >
class BST
{
private:
	struct Node
	{
		T word;
		int count;
		Node* left;
		Node* right;
	};
	Node* root;
	Node* Search(Node* root, T word) {
		if (root == nullptr) return 0;
		else if (root->word == word)
			return root->count;
		else if (word < root->word) return search(root->left, word);
		else return search(root->right, word);
	}
	Node* addNode(Node* root, T word) {
		if (root == nullptr) {
			root = new Node;
			root-> word = word;
			root-> count = 1;
			root-> left = root-> right = nullptr;
		}
		else if (root-> word > word) {
			root-> left = addNode(root-> left, word);
		}
		else if (root-> word < word) {
			root-> right = addNode(root-> right, word);
		}
		else
			root-> count++;
		return root;
	}
	int Depth(Node* root) {
		if (root == nullptr) return 0;
		else
			return std::max(Depth(root->left), Depth(root->right)) + 1;
	}
public:
	BST() : root(nullptr) {}
	void addword(T word) {
		root = addNode(root, word);
	}
	int depth() {
		return Depth(root) - 1;
	}
	int search(T word) {
		Node* temp = Search(root, word);
		return (temp) ? temp->count : 0;
	}
};

#endif  // INCLUDE_BST_H_
