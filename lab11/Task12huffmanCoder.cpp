#include <vector>
#include <string>
#include <iostream>
#include "heap.hpp"
using namespace std;


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

// Function to return the encoded string in binary format
string codeString(string& input, HuffmanNode* root) {
    vector<char> chars;            // Vector to store unique characters from the input
    vector<string> huffmanCodes;   // Vector to store corresponding Huffman codes
    vector<int> frequencies;       // Vector to store frequencies of the characters

    // Generate the Huffman codes, characters, and their frequencies using the Huffman tree
    generateHuffmanCodes(root, "", chars, frequencies, huffmanCodes);

    // Display the generated Huffman codes and their respective frequencies
    cout << "Huffman Codes:\n";
    for (size_t i = 0; i < chars.size(); i++) {
        cout << chars[i] << ": "
             << "Frequency = " << frequencies[i]
             << ", Code = " << huffmanCodes[i] << "\n";
    }

    string encodedText = ""; // String to store the final encoded text

    // Iterate through each character in the input string
    for (char ch : input) {
        // Find the Huffman code corresponding to the current character
        for (size_t i = 0; i < chars.size(); i++) {
            if (ch == chars[i]) {
                encodedText += huffmanCodes[i]; // Append the code to the encoded text
                break; // Exit the loop once the character is found
            }
        }
    }

    return encodedText; // Return the complete encoded string
}

//function to decode binary to string 
string decode(string codedText, HuffmanNode* root) {
    string decodedText = "";
    HuffmanNode* currentNode = root;

    for (char bit : codedText) {
        // Traverse the tree based on the current bit
        if (bit == '0') {
            currentNode = currentNode->left;
        } else if (bit == '1') {
            currentNode = currentNode->right;
        }

        // If a leaf node is reached, append the character to the decoded text
        if (!currentNode->left && !currentNode->right) {
            decodedText += currentNode->character;
            currentNode = root; // Restart traversal for the next character
        }
    }

    return decodedText;
}


// Main function to demonstrate Huffman coding
int main() {
    string text = "hello world";  // Input text
    HuffmanNode* root =  buildHuffmanTree(text);
    cout << "Input Text: " << text << "\n\n";
    string codedText = codeString(text,root);  // Perform Huffman encoding
    cout<<"\nEncoded Text:"<<codedText<<"\n\n";

    cout<<"Decoded Text: " << decode(codedText,root)<<"\n" ;
    return 0;
}
