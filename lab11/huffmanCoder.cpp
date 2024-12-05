#include <vector>
#include <string>
#include <iostream>
#include "heap.hpp"
using namespace std;

// Function prototype declarations
void generateHuffmanCodes(HuffmanNode* root, string code, vector<char>& chars, vector<string>& huffmanCodes);
void codeString(string& input);

// Function to build the Huffman Tree from the input string
HuffmanNode* buildHuffmanTree(string &input) {
    // List of characters supported (a-z and space)
    string chars = "abcdefghijklmnopqrstuvwxyz ";
    int frequency[27] = {0};  // Initialize all character frequencies to 0

    // Count the frequency of each character in the input string
    for (char ch: input) {
        if (ch == ' ') frequency[26]++;  // Space maps to the 27th position
        else if (ch >= 'a' && ch <= 'z') 
            frequency[ch - 'a']++;  // Map 'a' to index 0, 'b' to 1, etc.
    }

    MinHeap minHeap;

    // Create Huffman nodes for all characters with non-zero frequency
    for(int i = 0; i < 27; i++) {
        if (frequency[i] != 0) {
            minHeap.push(new HuffmanNode(chars[i], frequency[i]));
        }
    }

    // Build the Huffman Tree by combining the smallest frequency nodes
    while(minHeap.size() > 1) {
        // Extract the two nodes with the smallest frequency
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();

        // Create a new internal node combining these two nodes
        HuffmanNode* internalNode = new HuffmanNode('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;

        // Push the new internal node back into the min-heap
        minHeap.push(internalNode);
    }

    // The remaining node in the heap is the root of the Huffman Tree
    return minHeap.top();
}

// Function to generate Huffman codes from the tree
void generateHuffmanCodes(HuffmanNode* root, string code, vector<char>& chars, vector<int>& frequencies, vector<string>& huffmanCodes) {
    if (root) {
        // If this is a leaf node, store its character, frequency, and Huffman code
        if (!root->left && !root->right) {
            chars.push_back(root->character);
            frequencies.push_back(root->frequency);
            huffmanCodes.push_back(code);
        }

        // Recursively generate codes for the left and right subtrees
        if (root->left)
            generateHuffmanCodes(root->left, code + "0", chars, frequencies, huffmanCodes);
        if (root->right)
            generateHuffmanCodes(root->right, code + "1", chars, frequencies, huffmanCodes);
    }
}

// Function to encode the input string using Huffman coding
void codeString(string& input) {
    // Build the Huffman Tree from the input string
    HuffmanNode* root = buildHuffmanTree(input);

    vector<char> chars;  // List of unique characters
    vector<string> huffmanCodes;  // Corresponding Huffman codes
    vector<int> frequencies;  // Frequencies of the characters

    // Traverse the tree to collect the characters, codes, and frequencies
    generateHuffmanCodes(root, "", chars, frequencies, huffmanCodes);

    // Print the Huffman codes along with the character frequencies
    cout << "Huffman Codes:\n";
    for (size_t i = 0; i < chars.size(); i++) {
        cout << chars[i] << ": " 
             << "Frequency = " << frequencies[i] 
             << ", Code = " << huffmanCodes[i] << "\n";
    }

    // Encode the input string using the generated Huffman codes
    cout << "Encoded String:\n";
    for (char ch: input) {
        // Find the Huffman code for each character in the input string
        for (size_t i = 0; i < chars.size(); i++) {
            if (ch == chars[i]) {
                cout << huffmanCodes[i];
                break;
            }
        }
    }
    cout << '\n';
}


// Main function to demonstrate Huffman coding
int main() {
    string text = "hello world";  // Input text
    cout << "Input Text: " << text << "\n\n";
    codeString(text);  // Perform Huffman encoding
    return 0;
}
