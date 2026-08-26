#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Given:-
// we are given n vertical lines(n vertical bar) height in the form of vector of integer
// Finds the maximum water area formed by any two vertical lines.
// OR Return the maximum amount of water container can store
// Solution :-
// since we know that container is made up of three combination of lines, two vertical lines calles as left and right boundary and x-axis 
// connect these two vertical lines
// simply pick two vertical lines to form a container
// in the Brute Force Approach,we have to find all the possible containers and correspondingly find it's area(currArea) then match that area with the global variable (maximumArea)  to determine the maximum area of container water can store.
// To simplify the above sentence, we have to find all the possible two distinct vertical lines(known as left and right boundary) sunch that they can store the maximum amount of water from all of the containers
// Time Complexity: O(n^2)
// Space Complexity: O(1) auxiliary space



left                         right
  ↓                            ↓
  |                            |
  |      taller wall           |
  |      |                  |  |
  |      |                  |  |
  |______|__________________|__|

       shorter wall controls water
long long maxArea(const vector<int>& heights) {
    // global variable that track the maximum amount(area) of water container(|___|) can store
	long long maximumArea = 0;

    // pick the left boundary
	for (int left = 0; left < static_cast<int>(heights.size()); left++) {
        // pick the right boundary
		for (int right = left + 1; right < static_cast<int>(heights.size()); right++) {
            // now,we have formed a container with the help of left and right boundary
            // now ,find the width of the container
			long long width = right - left;
            // now ,find the height of the container ,here however we should think that minimum of the two vertical lines(two boundaries) should be taken as height otherwise water would be overflow
            // the shorter wall determines how high the water can rise.,otherwise the water would spill over it.
			long long height = min(heights[left], heights[right]);
            // find the current Area of the selected container 
            long long currArea = width * height;
            // find the maxArea from the possible whole container
			maximumArea = max(maximumArea, currArea);
		}
	}

	return maximumArea;
}

int main() {
	cout << "\n \t \t \t \t \t \t Program to Find the Container With Most Water Using Brute Force Approach\n";
	cout << "\n \t \t \t \t \t \t============================================================================\n";

	int n;
	cout << "Enter the number of heights: ";
	cin >> n;

	if (n < 0) {
		cout << "The number of heights cannot be negative.\n";
		return 1;
	}

	vector<int> heights(n);
	cout << "Enter the heights: ";
	for (int& height : heights) {
		cin >> height;
	}

	cout << "Maximum water area: " << maxArea(heights) << '\n';
	return 0;
}
