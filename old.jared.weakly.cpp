#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

bool hashedTable[1009] = {false} ;
int tableSize = 1009 ;
int key = rand()%tableSize;

unsigned long long linear = 0, prime = 0, amtRandom = 0;

void clearHashTable( bool hashArray[] )
{
    for( int i; i < tableSize ; i++ )
        hashArray[i] = false;
}

void generateTable( bool hashArray[], int percentage )
{

    int value = rand()%tableSize;

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

void linearProbingMethod( bool hashArray[] )
{
    int insertion = rand()%tableSize;

        while (hashArray[insertion] == true)
        {
            if(insertion < tableSize)
                insertion++;
            else 
            {
                insertion = 0;
            }

            linear++;
        }
        hashArray[insertion] = true;
}

void primeProbingMethod( bool hashArray[] )
{
    int insertion = rand()%tableSize;

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

void randomProbingMethod(  bool hashArray[] )
{
    int insertion, startInsertion;
    insertion = startInsertion = rand()%tableSize;

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

    for (int i = 10; i <= 90; i+=5)
    {

        for (int j = 0; j < 1000; j++ )
        {
            clearHashTable( hashedTable );
            generateTable( hashedTable, i );
            for ( int k = 0; k < 1000; k ++ )
            {
                linearProbingMethod( hashedTable );
//                primeProbingMethod( hashedTable);
//                randomProbingMethod( hashedTable );
            }
        }
        std::cout<< "Average probes for alpha = " << i << std::endl;
        std::cout<< "Linear: " << linear/1000000.0 << std::endl;
        std::cout<< "Random: " << amtRandom/1000000.0 << std::endl;
        std::cout<< "Prime: " << prime/1000000.0 << std::endl << std::endl;
    }
}
