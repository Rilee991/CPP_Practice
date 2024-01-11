// C++ program for weighted job scheduling using Naive Recursive Method
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// A job has start time, finish time and profit.
struct Job
{
	int start, finish, profit;
};

// A utility function that is used for sorting events
// according to finish time
bool jobComparator(Job s1, Job s2)
{
	return (s1.finish < s2.finish);
}

// Find the latest job (in sorted array) that doesn't
// conflict with the job[i]. If there is no compatible job,
// then it returns -1.
int latestNonConflict(Job arr[], int i)
{
	for (int j=i-1; j>=0; j--)
	{
		if (arr[j].finish <= arr[i-1].start)
			return j;
	}
	return -1;
}

// A recursive function that returns the maximum possible
// profit from given array of jobs. The array of jobs must
// be sorted according to finish time.
int findMaxProfitRec(Job arr[], int n)
{
	// Base case
	if (n == 1) return arr[n-1].profit;

	// Find profit when current job is included
	int inclProf = arr[n-1].profit;
	int i = latestNonConflict(arr, n);
	if (i != -1)
	inclProf += findMaxProfitRec(arr, i+1);

	// Find profit when current job is excluded
	int exclProf = findMaxProfitRec(arr, n-1);

	return max(inclProf, exclProf);
}

// The main function that returns the maximum possible
// profit from given array of jobs
int findMaxProfit(Job arr[], int n)
{
	// Sort jobs according to finish time
	sort(arr, arr+n, jobComparator);

	return findMaxProfitRec(arr, n);
}

bool cmp(Job j1, Job j2) {
    return j1.start < j2.start;
}

int solve(Job arr[], int n, int i, int e, vector<int> &dp) {
    if(i == n)  return 0;

    if(dp[i] != -1) return dp[i];

    int w1 = e <= arr[i].start ? solve(arr, n, i+1, arr[i].finish, dp) + arr[i].profit : 0;
    int w2 = solve(arr, n, i+1, e, dp);

    return dp[i] = max(w1, w2);
}

int findMaxProfit2(Job arr[], int n) {
    sort(arr, arr+n, cmp);
    vector<int> dp(n, -1);
    return solve(arr, n, 0, 0, dp);
}

// Driver program
int main()
{
	Job arr[] = {{3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200}};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "The optimal profit is " << findMaxProfit2(arr, n);
	return 0;
}
