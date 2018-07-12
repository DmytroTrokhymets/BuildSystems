
#include "staticlibrary.h"
#include <cassert>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    int countValues = 10;
    assert(countValues > 0);

    int *allValues = new int[countValues];
        for(int i = 0; i < countValues; i++) { 
        allValues[i] = rand() % 10;
        PrintStar(allValues[i]);
    }

    delete [] allValues;

  std::cin.get();

}


