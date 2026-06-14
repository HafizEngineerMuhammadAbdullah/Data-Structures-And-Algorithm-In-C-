class Solution {
public:
    // TC:O(nlogk) , SC:O(k)
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        // In this question,we have to maintain kth those co-ordinate points(say
        // (x,y)) which are closest(near) to origin(0,0) in the two dimensional
        // rectangular system called X-Y plane.

        // closest means that those co-ordinate points whose distance from
        // origin(0,0) is lesser than other points

        // so here we use Max Heap Priority Queue DS to tackle this problem &
        // solve it.since the default behaviour of priority queue is Max-Heap
        // means the largest element  comes at the top of PQ so with the help of
        // this property ,we will maintain k closest points to origin in
        // priority queue & discard(remove/eliminate/delete) the larger(greater)
        // points among the points stored in PQ because this is the something
        // that we don't want since we want to store only those points in PQ
        // whose distance is lesser than other co-ordinate points, so in this
        // way we can maintain the k Closest Points to origin

        // create a PQ
        priority_queue<pair<double, int>>
            pq; //(distance value,idx(row idx of point))

        // Maintain a max-heap of size k containing the closest points seen so
        // far. If the heap exceeds size k, remove the farthest point.

        // scan the points vector & find out the Euclidean distance for each
        // co-ordinate points using Euclidean distance formula
        for (int x = 0; x < points.size(); x++) { // TC:O(nlogk)
            // determine Euclidean Distance Between (two points) coming as
            // co-ordinate point say (x,y) from points 2d vector & origin(0,0)
            // using Euclidean Formula sqrt((x1 - x2)^2 + (y1-y2)^2)
            double distance = sqrt(pow(points[x][0], 2) + pow(points[x][1], 2));
            pq.push({distance, x});
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // push the k closest points into the vector
        while (!pq.empty()) { // TC:O(k)
            res.push_back(
                points[pq.top().second]); // insert the points row which is
                                          // actually a co-ordinate point
            pq.pop();
        }

        return res;
    }
};