#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <set>
using namespace std;

class PageReplacementFIFO {
private:
    int frameCount; // Number of frames in memory
    set<int> frames; // Vector to store frames
    queue<int> pageQueue; // Queue to store page order
    unordered_map<int, bool> pageMap; // Map to check if page is in memory

public:
    PageReplacementFIFO(int frameCount) {
        this->frameCount = frameCount;
    }

    // Function to simulate FIFO page replacement
    void pageFaults(const vector<int>& pageReferences) {
        int pageFaults = 0;

        for (int page : pageReferences) {
            cout << "Page Reference: " << page << " -> ";

            // If the page is not in memory
            if (pageMap.find(page) == pageMap.end()) {
                pageFaults++;
                if (frames.size() < frameCount) {
                    // Add the page to the memory
                    frames.insert(page);
                    pageMap[page] = true;
                } else {
                    // Replace the oldest page
                    int oldPage = pageQueue.front();
                    frames.erase(oldPage) ;
                    pageQueue.pop();
                    // Remove the old page from memory
                    pageMap[oldPage] = false;
                    
                    // Add the new page to memory
                    frames.insert(page);
                    pageMap[page] = true;
                }
            }

            // Print current memory state
            printMemoryState();
            
            // Add page to the queue (to track order for FIFO)
            pageQueue.push(page);
        }

        cout << "Total Page Faults: " << pageFaults << endl;
    }

    // Function to print current memory state
    void printMemoryState() {
        cout << "Memory State: ";
        for (int i : frames) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    // Hardcoded page references and frame count
    vector<int> pageReferences = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int frameCount = 3;

    PageReplacementFIFO fifo(frameCount);
    fifo.pageFaults(pageReferences);

    return 0;
}
/*

eduling\memory management\" ; if ($?) { g++ FIFO.cpp -o FIFO } ; if ($?) { .\FIFO }
Page Reference: 7 -> Memory State: 7 
Page Reference: 0 -> Memory State: 0 7
Page Reference: 1 -> Memory State: 0 1 7
Page Reference: 2 -> Memory State: 0 1 2
Page Reference: 0 -> Memory State: 0 1 2
Page Reference: 3 -> Memory State: 1 2 3
Page Reference: 0 -> Memory State: 1 2 3
Page Reference: 4 -> Memory State: 2 3 4
Page Reference: 2 -> Memory State: 2 3 4
Page Reference: 3 -> Memory State: 2 3 4
Total Page Faults: 6
*/