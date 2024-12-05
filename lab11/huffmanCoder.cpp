#include "heap.hpp"
#include <vector>
#include <string>
#include <iostream>
using namespace std;



HuffmanNode* buildHuffmanTree(string &input){
    string chars = "abcdefghijklmnopqrstuvwxyz "
    int frequecy[27];

    for (int i =0;i<27;i++){
        frequecy[i]=0;
    }

    for (char ch: input){
        if ch == ' ' frequency[26]++;
        else frequency[25+(static_cast<int>'z' - static_cast<int>ch)]++;
    }

    MinHeap minHeap;

    for(int i=0;i<27;i++){
        if (frequency[i]!=0){
            minHeap.push(new )
        }
    }
}