#include <vector>
#include <string>
#include <iostream>
#include "heap.hpp"
using namespace std;

// Function prototype declarations
void generateHuffmanCodes(HuffmanNode* root, string code, vector<char>& chars, vector<string>& huffmanCodes);
void codeString(string& input);

HuffmanNode* buildHuffmanTree(string &input){
    string chars = "abcdefghijklmnopqrstuvwxyz ";
    int frequency[27] = {0};  // Initialize all frequencies to 0

    // Count character frequencies
    for (char ch: input){
        if (ch == ' ') frequency[26]++;
        else if (ch >= 'a' && ch <= 'z') 
            frequency[ch - 'a']++;
    }

    MinHeap minHeap;

    // Create Huffman nodes for characters with non-zero frequency
    for(int i = 0; i < 27; i++){
        if (frequency[i] != 0){
            minHeap.push(new HuffmanNode(chars[i], frequency[i]));
        }
    }

    // Build Huffman tree
    while(minHeap.size() > 1){
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        HuffmanNode* internalNode = new HuffmanNode('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        minHeap.push(internalNode);
    }

    return minHeap.top();
}

void generateHuffmanCodes(HuffmanNode* root, string code, vector<char>& chars, vector<string>& huffmanCodes){
    if (root){
        if(!root->left && !root->right){
            chars.push_back(root->character);
            huffmanCodes.push_back(code);
        }

        if (root->left)
            generateHuffmanCodes(root->left, code + "0", chars, huffmanCodes);
        if (root->right)
            generateHuffmanCodes(root->right, code + "1", chars, huffmanCodes);
    }
}

void codeString(string& input){
    HuffmanNode* root = buildHuffmanTree(input);

    vector<char> chars;
    vector<string> huffmanCodes;

    generateHuffmanCodes(root, "", chars, huffmanCodes);

    cout << "Huffman Codes:\n";
    for (size_t i = 0; i < chars.size(); i++) {
        cout << chars[i] << ": " << huffmanCodes[i] << "\n";
    }

    cout << "Encoded String:\n";
    for (char ch: input){
        for(size_t i = 0; i < chars.size(); i++){
            if(ch == chars[i]){
                cout << huffmanCodes[i];
                break;
            }
        }
    }
    cout << '\n';
}

// Main function
int main() {
    string text = "hello world";
    cout << "Input Text: " << text << "\n\n";
    codeString(text);
    return 0;
}