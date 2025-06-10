#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// Function to find the page to be replaced
int predict(vector<int> &pages, vector<int> &frames, int index) {
    int farthest = index;
    int res = -1;

    for (int i = 0; i < frames.size(); i++) {
        int j;
        for (j = index; j < pages.size(); j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        // If the page is never used again
        if (j == pages.size()) {
            return i;
        }
    }

    return (res == -1) ? 0 : res;
}

int optimalPageReplacement(vector<int> pages, int capacity) {
    vector<int> frames;
    int pageFaults = 0;

    for (int i = 0; i < pages.size(); i++) {
        int page = pages[i];

        // If page is already in memory
        if (find(frames.begin(), frames.end(), page) != frames.end()) {
            continue;
        }

        // If there's space in memory
        if (frames.size() < capacity) {
            frames.push_back(page);
        } else {
            int pos = predict(pages, frames, i + 1);
            frames[pos] = page;
        }

        pageFaults++;
    }

    return pageFaults;
}

int main() {
    int n, capacity;

    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter page reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter frame capacity: ";
    cin >> capacity;

    int faults = optimalPageReplacement(pages, capacity);
    cout << "Total Page Faults: " << faults << endl;

    return 0;
}
