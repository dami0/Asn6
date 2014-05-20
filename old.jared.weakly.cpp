#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

bool hashedTable[1009] = {false} ;
int tableSize = 1009;
unsigned long long linear = 0, prime = 0, amtRandom = 0;

void clearHashTable( bool hashArray[] )
{
    for( int i; i < tableSize ; i++ )
        hashArray[i] = false;
}

void generateTable( bool hashArray[], int percentage, int &key )
{

    int value = key;
    int bound = ceil( tableSize * ( percentage/100.0 ) );
    int prime = 17;



    for(int i = 0; i < bound ; i++)
    {
        while( hashArray[value] == true )
        {
            value=(value*prime)%tableSize ;
        }
        hashArray[value] = true;
    }
}

void linearProbingMethod( bool hashArray[] , int & key)
{
    int insertion = key;
    int tries = 0;

        while (hashArray[insertion] == true)
        {
            if(insertion < tableSize)
                insertion++;
            else 
            {
                insertion = 0;
            }

            linear++;
            tries++;
        }
        hashArray[insertion] = true;
}

void primeProbingMethod( bool hashArray[] ,int & key)
{
    int insertion = key;

    if( hashArray[insertion] == false )
    {
        hashArray[insertion] = true;
        prime+=1;
    }

    else
    {
        while ( hashArray[insertion] == true )
        {
            insertion = (insertion + 39) % tableSize;
            prime+=1;
        }
        hashArray[insertion] = true;
    }
}

void randomProbingMethod(  bool hashArray[] ,int & key)
{
    int insertion, startInsertion;
    insertion = startInsertion = key;

    while ( hashArray[insertion] == false )
    {
        if( hashArray[insertion] == false )
        {
            hashArray[insertion] = true;
            amtRandom+=1;
            break;
        }
        else
        {
            insertion = ( key + 1 ) % 30;
            amtRandom+=1;
        }
    }
}

int main()
{
    srand(time(0));

    int key;
    key = rand()%tableSize;

//clearHashTable( hashedTable );
//generateTable( hashedTable, 90, key);
//
// for( int i = 0; i<1000; i++)
//     std::cout << hashedTable[i] << std::endl;
//

    for (int i = 10; i <= 90; i+=5)
    {

        for (int j = 0; j < 1000; j++ )
        {
            clearHashTable( hashedTable );
            std::cout << j << std::endl;
            generateTable(hashedTable, i, key);
            for ( int k = 0; k < 1000; k ++ )
            {
                linearProbingMethod( hashedTable, key );
//                primeProbingMethod( hashedTable, key );
//                randomProbingMethod( hashedTable, key );
            }
        }
        std::cout<< "Average probes for alpha = " << i << std::endl;
        std::cout<< "Linear: " << linear/1000000.0 << std::endl;
        std::cout<< "Random: " << amtRandom/1000000.0 << std::endl;
        std::cout<< "Prime: " << prime/1000000.0 << std::endl << std::endl;
    }
}
