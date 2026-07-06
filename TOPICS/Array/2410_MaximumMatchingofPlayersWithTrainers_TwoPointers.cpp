// Runtime: 24ms, beats: 89.00%
class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int count, i, j;

        count = i = j = 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        while (i < players.size() && j < trainers.size()) {
            if (players[i] <= trainers[j]) {
                count++;
                i++;
            }
            j++;
        }
        return count;
    }
};
