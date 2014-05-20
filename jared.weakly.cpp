#include <iostream>

class HashValue
{
    private:
        int key;
        int value;

    public:
        HashValue ( int key, int value ) 
        {
            this->key = key;
            this->value = value;
        }

        int getKey() 
        {
            return key;
        }

        int getValue() 
        {
            return value;
        }
};

const int tableSize = 1009;

class LinearHash
{
    private:
        HashValue **table;

    public:
        LinearHash()
        {
            table = new HashValue*[tableSize];
            for ( int i = 0; i < tableSize; i++ )
                table[i] = NULL;
        }

        int get(int key) 
        {
            int hash = (key % tableSize);
            while ( table[hash] != NULL && table[hash]->getKey() != key )
                hash = (hash + 1) % tableSize;
            if ( table[hash] == NULL )
                return -1;
            else
                return table[hash]->getValue();
        }

        void put(int key, int value) 
        {
            int hash = (key % tableSize);
            while (table[hash] != NULL && table[hash]->getKey() != key)
                hash = (hash + 1) % tableSize;
            if (table[hash] != NULL)
                delete table[hash];
            table[hash] = new HashValue(key, value);
        }     
};

int main ()
{
    int key = 30; int shit = 25;
    HashValue a(key,shit);
}
