#ifndef HUFFMAN_CPP
#define HUFFMAN_CPP
#include "Node_CPP.cpp"
#include <vector>
#include <queue>
using namespace std;
class Huffman{
	private:
		void encode(Node* root, const string& str, unordered_map<char, string> &huffmanCode);
		void decode(Node* root, int& index, const string& str);
	public:
		void buildHuffmanTree(const string& text);
};
struct Compare{
	bool operator()(Node* l, Node* r){
		return l->getFreq() > r->getFreq();
	}
};
void Huffman::encode(Node* root, const string& str, unordered_map<char, string> &huffmanCode){
	if(root==nullptr){
		return;
	}
	if(root->isLeaf()){
		huffmanCode[root->getChar()] = (str != "") ? str: "1";
	}
	encode(root->getLeft(),str + "0", huffmanCode);
	encode(root->getRight(),str + "1", huffmanCode);
}
void Huffman::decode(Node* root, int& index, const string& str){
	if(root == nullptr){
		return;
	}
	if(root->isLeaf()){
		cout<<root->getChar();
		return;
	}
	index++;
	if(str[index] == '0'){
		decode(root->getLeft(), index, str);
	}else{
		decode(root->getRight(), index, str);
	}
}
void Huffman::buildHuffmanTree(const string& text){
	if(text.empty()){
		return;
	}
	unordered_map<char, int> freq;
	for(char ch : text){
		freq[ch]++;
	}
	priority_queue<Node*, vector<Node*>, Compare> pq;
	for(const auto& pair : freq){
		pq.push(new Node(pair.first, pair.second));
	}
	while(pq.size() != 1){
		Node* left = pq.top(); pq.pop();
		Node* right = pq.top(); pq.pop();
		int sum = left->getFreq() + right->getFreq();
		pq.push(new Node('\0', sum, left, right));
	}
	Node* root = pq.top();
	unordered_map<char, string> huffmanCode;
	encode(root, "", huffmanCode);
	cout<<"cac ma huffman la: \n"<<endl;
	for(const auto& pair : huffmanCode){
		cout<<pair.first<<" "<<pair.second<<"\n";
		
	}
	string str;
	for(char ch : text){
		str +=huffmanCode[ch];
	}
	cout<<"\nChuoi duoc ma hoa la: \n"<<str<<"\n";
	cout<<"\nChuoi dc gia ma la: \n";
	int index = -1;
	while(index < (int)str.size() - 1){
		decode(root, index, str);
	}
	cout<<endl;
}

#endif
