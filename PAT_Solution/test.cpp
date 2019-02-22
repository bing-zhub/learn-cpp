#include <bits/stdc++.h>
using namespace std;

template<typename Key, typename Value>
class BST{
private:
	struct Node{
		Key key;
		Value value;
		Node *left;
		Node *right;
		
		Node(Key key, Value value){
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}
	};
	
	Node *root;
	int count;
public:
	BST(){
		root = NULL;
		count = 0;
	}
	
	~BST(){
		
	}
	
	int size(){
		return count;
	}
	
	bool isEmpty(){
		return count == 0;
	}
	
	void insert(Key key, Value value){
		root = insert(root, key, value);
	}
	
	bool contain(Key key){
		return contain(root, key);
	}
	
	Value* search(Key key){
		return search(root, key);
	}

private:
	Node* insert(Node *node, Key key, Value value){
		if(node == NULL){
			count ++;
			return new Node(key, value);
		}
		
		if(key = node->key){
			node->value = value;
		}else if(key > node->key){
			insert(node->right, key, value);
		}else {
			insert(node->left, key, value);
		}
		return node;
	}
	
	bool contain(Node* node, Key key){
		if(node == NULL)
			return false;
		
		if(node-> key == key)
			return true;
		else if(node->key > key)
			return contain(node->left, key);
		else 
			return contain(node->right, key);
	}
	
	Value* search(Node* node, Key key){
		if(node==NULL)
			return NULL;
			
		if(key == node->key)
			return &(node->value);
			
		else if(key > node->key)
			return search(node->right, key);
		else
			return search(node-left, key);
	}	
};

int main(){
	
	return 0;
}
