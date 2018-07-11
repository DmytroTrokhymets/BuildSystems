
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <map>

void generateNumbers(const int & maxCountNumbers,  std::map< int, int > & allNumbers)
{
    for(int i = 0; i < maxCountNumbers; i++) {
        int rnd = std::rand() % 10;
        allNumbers[rnd]++;
    }
}

void printHistogram(std::map< int, int > & allNumbers)
{
    for(auto it = allNumbers.cbegin(); it != allNumbers.cend(); ++it) {
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

    const int maxCountNumbers = 10;
    std::map< int, int > allNumbers;

    generateNumbers(maxCountNumbers, allNumbers);

    printHistogram(allNumbers);

    std::cin.get();
    return EXIT_SUCCESS;
}
