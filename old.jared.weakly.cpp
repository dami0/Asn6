#include <iostream>
#include <ctime>
#include <cmath>
#include <cstdlib>

int tableSize = 1009 ;

long long linear = 0, prime = 0, amtRandom = 0;

void clearHashTable( bool hashArray[] )
{
    for( int i = 0 ; i < tableSize ; i++ )
        hashArray[i] = false;
}

void generateTable( bool hashArray[], int percentage )
{

    int value = rand()%tableSize;

    int bound = ceil( tableSize * ( percentage/100.0 ) );
    int prime = 17;

    for(int i = 0; i < bound ; i++)
    {
        if ( hashArray[value] == false)
        {
            hashArray[value] = true;
            value=(value*prime)%tableSize;
            break;
        }
        else
            value=(value*prime)%tableSize;
    }
}

void linearProbingMethod( bool hashArray[] )
{
    int insertion = rand()%tableSize;

    for ( int i = 0; i < tableSize ; i++ )
    {
        if ( hashArray[insertion] == false )
        {
            hashArray[insertion] = true;
            insertion=(insertion+1)%tableSize; /* right? */
            break;
        }
        else 
        {
            insertion=(insertion+1)%tableSize;
            linear++;
        }
    }
}

void primeProbingMethod( bool hashArray[] )
{
    int insertion = rand()%tableSize;

    for ( int i = 0; i < tableSize ; i++ )
    {
        if ( hashArray[insertion] == false )
        {
            hashArray[insertion] = true;
            break;
        }
        else 
        {
            insertion=(insertion*39)%tableSize;
            prime++;
        }
    }
}

void randomProbingMethod(  bool hashArray[] )
{
    int insertion, startInsertion;
    insertion = startInsertion = rand()%tableSize;

    for ( int i = 0; i < tableSize ; i++ )
    {
        if ( hashArray[insertion] == false )
        {
            hashArray[insertion] = true;
            break;
        }
        else 
        {
            insertion=(startInsertion +1)%30;
            amtRandom++;
        }
    }
}

int main()
{
srand(time(NULL));
bool hashedTable[1009] = {false} ;


    for (int i = 10; i <= 90; i+=5)
    {

        for (int j = 0; j < 1000; j++ )
        {
            clearHashTable( hashedTable );
            generateTable( hashedTable, i );
            for ( int k = 0; k < 1000; k ++ )
            {
                linearProbingMethod( hashedTable );
                primeProbingMethod( hashedTable);
                randomProbingMethod( hashedTable );
            }
        }
        std::cout<< "Average probes for alpha = " << i << std::endl;
        std::cout<< "Linear: " << linear/1000000.0 << std::endl;
        std::cout<< "Random: " << amtRandom/1000000.0 << std::endl;
        std::cout<< "Prime: " << prime/1000000.0 << std::endl << std::endl;
    }
}
