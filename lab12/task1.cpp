class directAddressing{
    public:
        int hashTable[100] = {-1} 

        void insertKeyValuePair(int value){
            int key = value%100;
            if (hashTable[key]!=-1) hashTable[key] = value; 
        }

        void searchValue(int value){
            int key = value%100;
            cout<< (value == hashTable[key]) ? "" ;
        }
}