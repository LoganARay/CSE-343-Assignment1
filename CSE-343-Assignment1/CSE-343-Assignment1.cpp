// CSE-343-Assignment1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <cmath>

#define UNDERLINE_ON "\033[4m"
#define UNDERLINE_OFF "\033[0m"
int* userMemoryAllocation(int* arr);

int main()
{
    int* arr = new int[100];
    int* idArr=userMemoryAllocation(arr);
    for (int i = 0; i < 100; i++) {
        std::cout << idArr[i]<< " ";
    }
   return 0;

}

int* userMemoryAllocation(int* arr) 
{
    srand(time(NULL));
    int processId = 0;
    int arrIndex = 0;
    int startingAddress = 2000;
    int maxSize = 100 * 160;
    std::cout << UNDERLINE_ON << "Process Id\tStarting Memory Address\tSize of the Process(MB)\tUnusedSpace(MB)" << UNDERLINE_ON << std::endl;
    while (startingAddress <= maxSize) {
        processId = processId + 1;
        int randNum = (rand() % 30) + 1;
        int processSize = randNum * 80;
        int resultingSize= startingAddress + processSize;
        if (resultingSize > maxSize) {
            return arr;
        }
        int numMemPages = static_cast<int>(std::ceil(((double)processSize / 160.0)));
        int unusedSpace = (numMemPages * 160) - processSize;
        std::cout << UNDERLINE_OFF << "   " << processId << "\t\t\t" << startingAddress << "\t\t\t" << processSize << "\t\t\t" << unusedSpace << std::endl;
        startingAddress = resultingSize;
        for (int i=0; i < numMemPages; i++) {
                arr[i+arrIndex] = processId;
        }
        arrIndex = arrIndex + numMemPages;
        startingAddress = resultingSize;
    }
    return arr;
}
