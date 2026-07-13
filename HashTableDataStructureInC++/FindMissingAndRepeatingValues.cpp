class Solution {
public:
    // Time Complexity = O(n²) ✅
    // Space Complexity = O(n²) ✅
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        // ans vector stores the repeating value(say a) as well as the missing
        // value(say b) as final answer => [a,b] == [repeating value,missing
        // value]
        vector<int> ans;
        // To findout(track) the Repeating Value(duplicate value) in the range
        // [1,n^2], we use Unordered_Set so create an unordered set
        unordered_set<int> s;
        int a, b;
        long long expSum = 0, actualSum = 0;
        int n = grid.size();

       // Traverse the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                // compute actual sum i.e. sum of all elements of grid
                actualSum += grid[i][j];
                // track either element a already exist in set or not,if exists
                // means it is a repeated value
                if (s.find(grid[i][j]) != s.end()) {
                    a = grid[i][j];
                    ans.push_back(a); // repeating value
                } else {
                    // else insert element in the set
                    s.insert(grid[i][j]);
                }
            }
        }
        // compute expSum i.e. sum of the elements(numbers) in the range [1, n^2]
        expSum = ((n * n) * (n * n + 1)) / 2;
        // Calculate 'b' => missing value
        // actualSum = expectedSum − missing + repeated
        // Re-arranging => missing = expectedSum + repeated − actualSum
        b = expSum + a - actualSum;
        ans.push_back(b); // missing value
        return ans;
    }
};