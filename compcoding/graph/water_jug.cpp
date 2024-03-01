#include <iostream>
#include <set>
#include <queue>
#include <vector>

using namespace std;

bool solve(int capA, int capB, int target) {
    set<pair<int,int>> vis;
    queue<pair<int,int>> q;

    vis.insert({0,0});
    q.push({0,0});

    while(!q.empty()) {
        int filledA = q.front().first;
        int filledB = q.front().second;

        // cout<<"("<<filledA<<", "<<filledB<<")\n";
        q.pop();

        if(filledA == target || filledB == target)    return true;

        vector<pair<int,int>> moves = {
            {0,filledB},{filledA,0},
            {capA,filledB},{filledA,capB},
            {min(filledA + filledB, capA), max(0, filledB - (capA - filledA))}, // filledB - capA + filledA
            {max(0, filledA - (capB - filledB)), min(filledB + filledA, capB)}
        };

        for(auto move: moves) {
            int newA = move.first;
            int newB = move.second;

            if(vis.find({ newA, newB }) == vis.end()) {
                vis.insert({ newA, newB });
                q.push({ newA, newB });
            }
        }
    }

    return false;
}

int main() {
    int cap1 = 3, cap2 = 5, target = 42;

    cout<<solve(cap1, cap2, target);
}