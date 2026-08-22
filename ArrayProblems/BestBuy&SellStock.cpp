#include <iostream>
using namespace std;
class Solution {
public:
    // In this problem : we are asked to maximize our stock profit such that we
    // have to buy stock on one day and then sell the stock on another day in
    // the future
    // Constraints are:
    //   1. buy and sell happen on different day
    //   2. sell must happen on future day(the buy day must come before the sell
    //   day.)

    // To gain Maximal Profit,we can think what we do in real life? we want to
    // buy thing in a cheap price and sell it in expensive price same rule
    // applies here but be careful,we can't find the min and max element in this
    // situation or in this circumstance like e.g: [7,1,6,3,4] the minimum
    // element is 1 while maximum element is 7 but we can't sell a stock in
    // previous/old/past day or buy a stock in next/future day(minimum price +
    // maximum price because the maximum might occur before the minimum.) now
    // ,imagine each and every day(price[i] the ith day) as selling day and
    // think at the current ith day whether if today could be the selling day of
    // stock what would be the best day to buy(bestBuy) that stock in the
    // past/previous day?

    // Actual Idea:-
    // "If today is the selling day, what is the cheapest price I could have
    // bought at before today?"

    // profit today = today’s price - cheapest previous price
    //  maximum answer = maximum of all those profits

    // bestBuy = cheapest past price
    // mp = best profit so far

    // TC:O(n) , SC:O(1)
    int maxProfit(vector<int>& prices) {
        int mp = 0, bestBuy = prices[0];
        // start the iteration by 1 as for 0th index element there would be no
        // bestBuy or -1th day where i could buy a stock in the previous old day
        // as negative indexing doesn't exists in C++ array
        for (int i = 1; i < prices.size(); i++) {
            // check should we gain a profit by selling stock today or should we
            // sell a stock or not?
            // bestBuy => the minimum price seen so far among all previous days.
            // mp => the maximum profit found so far.
            // this is the best profit you could make by selling today.
            if (prices[i] > bestBuy) { // selling  price at ith day > buy
                                       // price(we can gain profit)
                mp = max(mp, prices[i] - bestBuy);
            }

            // check whether today (current day) could be bestBuy day for the
            // future selling day or not if so update
            // updates the cheapest possible buy price for future days.
            bestBuy = min(bestBuy, prices[i]);
        }
        return mp;
    }
};

int main(){

}