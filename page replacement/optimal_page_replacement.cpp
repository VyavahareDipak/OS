#include <bits/stdc++.h>
using namespace std;


class OptimalPageReplacement {
private:
    int frameCount; // Number of frames in memory

public:
    OptimalPageReplacement(int frameCount) {
        this->frameCount = frameCount;
    }

    // Function to simulate Optimal page replacement
    void pageFaults(const vector<int>& pageReferences) {
        int pageFaults = 0;
        vector<int> frames; // To store pages in memory

        for (int i = 0; i < pageReferences.size(); i++) {
            int page = pageReferences[i];
            cout << "Page Reference: " << page << " -> ";

            // If the page is already in memory (no page fault)
            if (find(frames.begin(), frames.end(), page) != frames.end()) {
                printMemoryState(frames);
                continue;
            }

            pageFaults++;

            // If there is space in memory, add the new page
            if (frames.size() < frameCount) {
                frames.push_back(page);
            } else {
                // Memory is full, find the page to replace using OPT
                int farthest = -1;
                int pageToReplace = -1;

                // Find the page to replace
                for (int j = 0; j < frames.size(); j++) {
                    int frame = frames[j];
                    auto it = find(pageReferences.begin() + i, pageReferences.end(), frame);
                    if (it == pageReferences.end()) {
                        pageToReplace = frame;
                        break;
                    } else {
                        if (it - pageReferences.begin() > farthest) {
                            farthest = it - pageReferences.begin();
                            pageToReplace = frame;
                        }
                    }
                }

                // Replace the farthest page
                for (int j = 0; j < frames.size(); j++) {
                    if (frames[j] == pageToReplace) {
                        frames[j] = page;
                        break;
                    }
                }
            }

            // Print current memory state
            printMemoryState(frames);
        }

        cout << "Total Page Faults: " << pageFaults << endl;
    }

    // Function to print current memory state
    void printMemoryState(const vector<int>& frames) {
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

    OptimalPageReplacement opt(frameCount);
    opt.pageFaults(pageReferences);

    return 0;
}

/*
Page Reference: 7 -> Memory State: 7 
Page Reference: 0 -> Memory State: 7 0
Page Reference: 1 -> Memory State: 7 0 1
Page Reference: 2 -> Memory State: 2 0 1
Page Reference: 0 -> Memory State: 2 0 1
Page Reference: 3 -> Memory State: 2 0 3
Page Reference: 0 -> Memory State: 2 0 3
Page Reference: 4 -> Memory State: 2 4 3
Page Reference: 2 -> Memory State: 2 4 3
Page Reference: 3 -> Memory State: 2 4 3
Total Page Faults: 6
*/
