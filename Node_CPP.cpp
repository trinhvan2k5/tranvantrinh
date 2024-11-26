#ifndef NODE_CPP
#define NODE_CPP
#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
using namespace std;
class Node{
	private:
		char ch;
		int freq;
		Node *left;
		Node *right;
	public:
		Node(char character, int frequency, Node* l=nullptr, Node* r=nullptr);
		char getChar() const;
		int getFreq() const;
		Node* getLeft() const;
		Node* getRight() const;
		
		bool isLeaf() const;
		
		friend class Huffman;
};
Node::Node(char character, int frequency, Node* l, Node* r):ch(character), freq(frequency), left(l), right(r){}
char Node::getChar() const{
	return ch;
}
int Node::getFreq() const{
	return freq;
}
Node* Node::getLeft() const{
	return left;
}
Node* Node::getRight() const{
	return right;
}
bool Node::isLeaf() const{
	return left==nullptr && right==nullptr;
}
#endif
