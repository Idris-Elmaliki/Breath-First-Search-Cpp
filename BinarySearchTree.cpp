#include <iostream>
#include <queue>

class Node {
public: 
    int data; 
    Node* left; 
    Node* right; 

    Node(const int& data) 
    : data(data){
        left = nullptr; 
        right = nullptr; 
    }
};

class BinarySearchTree {
    Node* root; 

public:
    BinarySearchTree() { 
        root = nullptr; 
    }

    bool insert(const int &data) {
        Node* newNode = new Node(data); 

        if(root == nullptr) {
            root = newNode; 
            return true; 
        }
        
        Node* temp = root; 

        while(true) {
            if(newNode->data == temp->data)
                return false; 
            
            if(newNode->data < temp->data) {
                if(temp->left == nullptr) {
                    temp->left = newNode; 
                    break; 
                }
                temp = temp->left;  
            }
            else {
                if(temp->right == nullptr) {
                    temp->right = newNode; 
                    break; 
                }
            
                temp = temp->right;
            }
        }
    
        return true; 
    }

    bool Contains(const int &data) {
        Node* temp = root; 

        while(temp != nullptr) {
            if(data < temp->data) {
                temp = temp->left; 
            }
            else if(data > temp->data) {
                temp = temp->right; 
            }
            else {
                return true; 
            }
        }

        return false; 
    }

    void BreathFirstSearch() {
        std::queue<Node*> myQueue;
        myQueue.push(root);

        while(myQueue.size() > 0) {
            Node* currentNode = myQueue.front(); 
            myQueue.pop(); 

            std::cout << currentNode->data << '\n'; 

            if(currentNode->left != nullptr) {
                myQueue.push(currentNode->left); 
            }
            if(currentNode->right != nullptr) {
                myQueue.push(currentNode->right); 
            }
        } 
    }

    ~BinarySearchTree() {
        std::queue<Node*> deleteQueue; 
        deleteQueue.push(root); 

        while(deleteQueue.size() > 0) {
            Node* currentNode = deleteQueue.front(); 
            deleteQueue.pop(); 

            if(currentNode->left != nullptr) {
                deleteQueue.push(currentNode->left); 
            }
            if(currentNode->right != nullptr) {
                deleteQueue.push(currentNode->right); 
            }

            delete currentNode; 
        }
    }
};
