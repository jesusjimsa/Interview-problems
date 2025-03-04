/*
    There are n teams numbered from `0` to `n - 1` in a tournament; each team is also a node in a **DAG**.

    You are given the integer `n` and a **0-indexed** 2D integer array `edges` of length `m` representing the **DAG**,
    where `edges[i] = [ui, vi]` indicates that there is a directed edge from team `ui` to team `vi` in the graph.

    A directed edge from `a` to `b` in the graph means that team `a` is **stronger** than team `b` and team `b` is
    **weaker** than team `a`.

    Team `a` will be the **champion** of the tournament if there is no team `b` that is **stronger** than team `a`.

    Return *the team that will be the **champion** of the tournament if there is a **unique** champion, otherwise,
    return* `-1`.

    ### Notes

    * A **cycle** is a series of nodes `a1, a2, ..., an, an+1` such that node `a1` is the same node as node `an+1`, the
    nodes `a1, a2, ..., an` are distinct, and there is a directed edge from the node `ai` to node `ai+1` for every `i`
    in the range `[1, n]`.
    * A **DAG** is a directed graph that does not have any `cycle`.
    

    ## Example 1:

    ![](https://assets.leetcode.com/uploads/2023/10/19/graph-3.png)
    ```
    Input: n = 3, edges = [[0,1],[1,2]]
    Output: 0
    Explanation: Team 1 is weaker than team 0. Team 2 is weaker than team 1. So the champion is team 0.
    ```

    ## Example 2:

    ![](https://assets.leetcode.com/uploads/2023/10/19/graph-4.png)
    ```
    Input: n = 4, edges = [[0,2],[1,3],[1,2]]
    Output: -1
    Explanation: Team 2 is weaker than team 0 and team 1. Team 3 is weaker than team 1. But team 1 and team 0 are not
    weaker than any other teams. So the answer is -1.
    ```

    ## Constraints:

    * `1 <= n <= 100`
    * `m == edges.length`
    * `0 <= m <= n * (n - 1) / 2`
    * `edges[i].length == 2`
    * `0 <= edge[i][j] <= n - 1`
    * `edges[i][0] != edges[i][1]`
    * The input is generated such that if team `a` is stronger than team `b`, team `b` is not stronger than team `a`.
    * The input is generated such that if team `a` is stronger than team `b` and team `b` is stronger than team `c`,
    * then team `a` is stronger than team `c`.
*/

#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        set<int> winners;
        set<int> losers;
        set<int> all_teams;

        // If there is only 1 team, they win automatically
        if (n == 1) {
            return 0;
        }

        for (int i = 0; i < edges.size(); i++) {
            const int stronger = edges[i][0];
            const int weaker = edges[i][1];
            all_teams.insert(edges[i][0]);
            all_teams.insert(edges[i][1]);
            losers.insert(weaker); // Teams on position 0 will never win the league, other team is superior

            // If the team was in the winners list, it is removed from there
            if (winners.find(weaker) != winners.end()) {
                winners.erase(weaker);
            }

            // If the team is not in the losers list, it means that no other team is stronger so far
            if (losers.find(stronger) == losers.end()) {
                winners.insert(stronger);
            }
        }

        if (winners.size() != 1 || all_teams.size() != n) {
            return -1;
        }

        return *winners.begin();
    }
};

int main(int argc, char const *argv[]) {
    Solution sol;
    vector<vector<int>> test1 = {{0, 1}, {1, 2}};
    vector<vector<int>> test2 = {{0, 2}, {1, 3}, {1, 2}};
    vector<vector<int>> test3 = {{1, 3}, {2, 1}};

    cout << "Test 1: Winner is " << sol.findChampion(3, test1) << endl;
    cout << "Test 2: Winner is " << sol.findChampion(4, test2) << endl;
    cout << "Test 3: Winner is " << sol.findChampion(4, test3) << endl;

    return 0;
}
