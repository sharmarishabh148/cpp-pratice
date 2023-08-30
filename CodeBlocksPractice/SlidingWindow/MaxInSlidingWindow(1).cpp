#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <deque>

// function to clean up the window
void CleanUp(int i, std::deque<int>& currentWindow, const std::vector<int>& nums) {
    // remove all the indexes from currentWindow whose corresponding values
    // are smaller than or equal to the current element
    while (!currentWindow.empty() && nums[i] >= nums[currentWindow.back()]) {
        currentWindow.pop_back();
    }
}

// function to find the maximum in all possible windows
std::vector<int> FindMaxSlidingWindow(const std::vector<int>& nums, int w) {
    // if the input array is empty, return an empty array
    if (nums.empty()) {
        return {};
    }

    // initializing variables
    std::vector<int> output;
    std::deque<int> currentWindow;

    // if window size is greater than the array size, set the window size to the array size
    if (w > nums.size()) {
        w = nums.size();
    }

    // iterate over the first w elements
    for (int i = 0; i < w; ++i) {
        // for every element, remove the previous smaller elements from currentWindow
        CleanUp(i, currentWindow, nums);

        // append the index of the current element to currentWindow
        currentWindow.push_back(i);
    }

    // appending the maximum element of the current window to the output list
    output.push_back(nums[currentWindow[0]]);

    // iterate over the remaining input list
    for (int i = w; i < nums.size(); ++i) {
        // for every element, remove the previous smaller elements from currentWindow
        CleanUp(i, currentWindow, nums);

        // remove first index from the currentWindow if it has fallen out of the current window
        if (!currentWindow.empty() && currentWindow[0] <= (i - w)) {
            currentWindow.pop_front();
        }

        // append the index of the current element to currentWindow
        currentWindow.push_back(i);

        // adding the maximum element of the current window to the output list
        output.push_back(nums[currentWindow[0]]);
    }

    // return the array containing output
    return output;
}

// driver code
int main() {
    std::vector<int> windowSizes = {3, 3, 3, 3, 2, 4, 3, 2, 3, 18};
    std::vector<std::vector<int>> numsList = {
        {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}/*,
        {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
        {10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
        {1, 5, 8, 10, 10, 10, 12, 14, 15, 19, 19, 19, 17, 14, 13, 12, 12, 12, 14, 18, 22, 26, 26, 26, 28, 29, 30},
        {10, 6, 9, -3, 23, -1, 34, 56, 67, -1, -4, -8, -2, 9, 10, 34, 67},
        {4, 5, 6, 1, 2, 3},
        {9, 5, 3, 1, 6, 3},
        {2, 4, 6, 8, 10, 12, 14, 16},
        {-1, -1, -2, -4, -6, -7},
        {4, 4, 4, 4, 4, 4}*/
    };

    for (int i = 0; i < numsList.size(); i++) {
        std::cout << i + 1 << ".\tInput array:\t";
        std::cout << "[";
        std::copy(numsList[i].begin(), numsList[i].end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "]" << std::endl;
        std::cout << "\tWindow size:\t" << windowSizes[i] << std::endl;
        std::vector<int> output = FindMaxSlidingWindow(numsList[i], windowSizes[i]);
        std::cout << "\n\tMaximum in each sliding window:\t";
        std::cout << "[";
        std::copy(output.begin(), output.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << "]" << std::endl;
        std::cout << std::string(100, '-') << "\n";
    }
}
