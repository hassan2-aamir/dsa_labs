#include <vector>
#include <string>
#include <iostream>
#include "heap.hpp"
using namespace std;

// Build the Huffman Tree from input string
HuffmanNode* buildHuffmanTree(string &input) {
    string chars = "abcdefghijklmnopqrstuvwxyz ";
    int frequency[27] = {0}; // Array to count character frequencies

    // Count frequencies of each character in the input
    for (char ch : input) {
        if (ch == ' ')
            frequency[26]++;
        else if (ch >= 'a' && ch <= 'z')
            frequency[ch - 'a']++;
    }

    MinHeap minHeap;

    // Create a node for each character with non-zero frequency
    for (int i = 0; i < 27; i++) {
        if (frequency[i] != 0) {
            minHeap.push(new HuffmanNode(chars[i], frequency[i]));
        }
    }

    // Build the tree by combining nodes with the smallest frequencies
    while (minHeap.size() > 1) {
        HuffmanNode* left = minHeap.top(); minHeap.pop();
        HuffmanNode* right = minHeap.top(); minHeap.pop();
        HuffmanNode* internalNode = new HuffmanNode('\0', left->frequency + right->frequency);
        internalNode->left = left; internalNode->right = right;
        minHeap.push(internalNode);
    }

    return minHeap.top(); // Root of the Huffman Tree
}

// Generate Huffman codes for each character
void generateHuffmanCodes(HuffmanNode* root, string code, vector<char>& chars, vector<int>& frequencies, vector<string>& huffmanCodes) {
    if (root) {
        if (!root->left && !root->right) { // Leaf node
            chars.push_back(root->character);
            frequencies.push_back(root->frequency);
            huffmanCodes.push_back(code);
        }
        generateHuffmanCodes(root->left, code + "0", chars, frequencies, huffmanCodes);
        generateHuffmanCodes(root->right, code + "1", chars, frequencies, huffmanCodes);
    }
}

// Encode the input string using Huffman codes
string codeString(string& input, HuffmanNode* root) {
    vector<char> chars; vector<string> huffmanCodes; vector<int> frequencies;

    generateHuffmanCodes(root, "", chars, frequencies, huffmanCodes);

    // Print Huffman codes
    for (size_t i = 0; i < chars.size(); i++) {
        cout << chars[i] << ": Frequency = " << frequencies[i] << ", Code = " << huffmanCodes[i] << "\n";
    }

    // Build encoded string
    string encodedText = "";
    for (char ch : input) {
        for (size_t i = 0; i < chars.size(); i++) {
            if (ch == chars[i]) {
                encodedText += huffmanCodes[i];
                break;
            }
        }
    }
    return encodedText;
}

// Decode the encoded text using the Huffman Tree
string decode(string codedText, HuffmanNode* root) {
    string decodedText = "";
    HuffmanNode* currentNode = root;

    for (char bit : codedText) {
        currentNode = (bit == '0') ? currentNode->left : currentNode->right;
        if (!currentNode->left && !currentNode->right) { // Leaf node
            decodedText += currentNode->character;
            currentNode = root; // Restart for next character
        }
    }

    return decodedText;
}

// Calculate and display the compression ratio
void calculateCompressionRatio(string& input, string& encodedText) {
    int originalSize = input.size() * 8; // Original size in bits
    int compressedSize = encodedText.size(); // Encoded size in bits
    cout << "\nOriginal Size: " << originalSize << " bits\n";
    cout << "Compressed Size: " << compressedSize << " bits\n";
    cout << "Compression Ratio: " << ((float)originalSize / compressedSize) << "\n";
}

// Main function to test Huffman coding
int main() {
    vector<string> testCases = { // Input test cases
        "hello world",
        "this is a test of huffman encoding",
        "aaaaabbbbcccccdddddeeeee fffff",
        "my name is ali i am a student in class i like to play cricket football and basketball as well"
    };

    for (string& text : testCases) {
        cout << "Input Text: " << text << "\n\n";

        HuffmanNode* root = buildHuffmanTree(text); // Build tree
        string encodedText = codeString(text, root); // Encode text

        cout << "\nEncoded Text: " << encodedText << "\n";
        cout << "Decoded Text: " << decode(encodedText, root) << "\n"; // Decode text

        calculateCompressionRatio(text, encodedText); // Calculate compression ratio
        cout << "-----------------------------------\n";
    }

    return 0;
}
