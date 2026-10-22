
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Job {
public:
    int idx;
    int deadline;
    int profit;

    Job(int idx, int deadline, int profit) {
        this->idx = idx;
        this->deadline = deadline;
        this->profit = profit;
    }
};

int maxProfit(vector<pair<int, int>> pairs) {
    int n = pairs.size();
    vector<Job> jobs;

    for (int i = 0; i < n; i++) {
        jobs.emplace_back(i, pairs[i].first, pairs[i].second);
    }

    // Sort jobs by decreasing profit
    sort(jobs.begin(), jobs.end(),
         [](const Job &a, const Job &b) {
             return a.profit > b.profit;
         });

    // Find maximum deadline
    int maxDeadline = 0;
    for (const Job &job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // -1 means the slot is empty
    vector<int> slots(maxDeadline + 1, -1);

    int profit = 0;

    for (const Job &job : jobs) {
        // Find the latest available slot
        for (int t = min(job.deadline, maxDeadline); t >= 1; t--) {
            if (slots[t] == -1) {
                slots[t] = job.idx;
                profit += job.profit;

                cout << "Selected job " << job.idx
                     << " in slot " << t << endl;
                break;
            }
        }
    }

    cout << "Max Profit => " << profit << endl;
    return profit;
}

int main() {
    int n = 4;

    vector<pair<int, int>> jobs(n);
    jobs[0] = make_pair(4, 20);
    jobs[1] = make_pair(1, 10);
    jobs[2] = make_pair(1, 40);
    jobs[3] = make_pair(1, 30);

    maxProfit(jobs);

    return 0;
}
