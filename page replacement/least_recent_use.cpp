#include <bits/stdc++.h>

using namespace std;

class LRUPageReplacement {
private:
    int frameCount; // Number of frames in memory
    list<int> pageList; // Doubly linked list to store pages in order of use
    unordered_map<int, list<int>::iterator> pageMap; // Map to track page positions in the list

public:
    LRUPageReplacement(int frameCount) {
        this->frameCount = frameCount;
    }

    // Function to simulate LRU page replacement
    void pageFaults(const vector<int>& pageReferences) {
        int pageFaults = 0;

        for (int page : pageReferences) {
            cout << "Page Reference: " << page << " -> ";

            // If the page is already in memory (recently used)
            if (pageMap.find(page) != pageMap.end()) {
                // Move the page to the front of the list (most recently used)
                pageList.erase(pageMap[page]);
                pageList.push_front(page);
                pageMap[page] = pageList.begin();
            } else {
                pageFaults++;

                // If there is space in memory
                if (pageList.size() < frameCount) {
                    pageList.push_front(page);
                    pageMap[page] = pageList.begin();
                } else {
                    // If memory is full, remove the least recently used page
                    int lruPage = pageList.back();
                    pageList.pop_back();
                    pageMap.erase(lruPage);

                    // Add the new page to the front (most recently used)
                    pageList.push_front(page);
                    pageMap[page] = pageList.begin();
                }
            }

            // Print current memory state
            printMemoryState();
        }

        cout << "Total Page Faults: " << pageFaults << endl;
    }

    // Function to print current memory state
    void printMemoryState() {
        cout << "Memory State: ";
        for (int page : pageList) {
            cout << page << " ";
        }
        cout << endl;
    }
};

int main() {
    // Hardcoded page references and frame count
    vector<int> pageReferences = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3};
    int frameCount = 3;

    LRUPageReplacement lru(frameCount);
    lru.pageFaults(pageReferences);

    return 0;
}
/*
Page Reference: 7 -> Memory State: 7
Page Reference: 0 -> Memory State: 0 7
Page Reference: 1 -> Memory State: 1 0 7
Page Reference: 2 -> Memory State: 2 1 0
Page Reference: 0 -> Memory State: 0 2 1
Page Reference: 3 -> Memory State: 3 0 2
Page Reference: 0 -> Memory State: 0 3 2
Page Reference: 4 -> Memory State: 4 0 3
Page Reference: 2 -> Memory State: 2 4 0
Page Reference: 3 -> Memory State: 3 2 4
Total Page Faults: 8
*/ 
