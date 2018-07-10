#====================================================================
# Сonstructing a histogram of the input data set                    =
#							       	    =
# Created by Dmytro Trokhymets				            =
# 10.06.2018							    =
#====================================================================

#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>


/*
*====================================================
* Function generate @maxCountNumbers random numbers =
* and inserting in vector                           =
*====================================================
*/
void generateNumbers(const int & maxCountNumbers, std::vector< std::pair<int, int> > & allNumber)
{
    for(int i = 0; i < maxCountNumbers; i++)
    {
        int rnd = std::rand() % 10; // [0..9]

        auto resultFind = std::find_if(allNumber.begin(), allNumber.end(), [=] (std::pair<int,int> p) {return p.first == rnd;} );

        // if random number absent, then insert in vector
        if(resultFind == allNumber.end()) {
              allNumber.emplace_back(std::make_pair(rnd, 1));
        }
        else  resultFind->second++;  // increment number of occurrences
    }
}

void printHistogram(std::vector< std::pair<int, int> > & allNumber)
{
    for(auto it = allNumber.cbegin(); it != allNumber.cend(); ++it)
    {
        std::cout << it->first << ':';
        for(int i = 0; i < it->second; i++) {
            std::cout << '*' << ' ';
        }
    std::cout << std::endl;
    }
}

int main(int argc, char *argv[])
{
    std::srand(static_cast<unsigned int>(std::time(0)));

    const int maxCountNumbers = 20;
    // first element vector ist generation random number
    // second element number of occurrences
    std::vector< std::pair<int,int> > allNumber;

   generateNumbers(maxCountNumbers, allNumber);
   std::sort(allNumber.begin(), allNumber.end(), [](std::pair<int, int> p1, std::pair<int, int> p2) { return p1.first < p2.first; });
   printHistogram(allNumber);

   std::cin.get();
   return EXIT_SUCCESS;
}


