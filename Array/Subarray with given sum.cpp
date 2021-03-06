#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1

Given an unsorted array A of size N that contains only non-negative integers, find a continuous sub-array which adds to a given number S.
Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4

Method 1:
TC - O(N^2) , SC - O(1)
*/
class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        long long curr_sum = 0;
        int start = 0;
        for (int i = 0; i < n; i++)
        {
            curr_sum = arr[i];
            for (int j = i + 1; j <= n; j++)
            {
                if (curr_sum == s)
                    return {i + 1, j};
                if (curr_sum > s || j == n)
                    break;
                curr_sum += arr[j];
            }
        }
        return {-1};
    }
};
/*
Method 2:
TC - O(N) , SC - O(1)
*/
class Solution
{
public:
    vector<int> subarraySum(int a[], int n, long long s)
    {
        int sum = 0, i = 0, j = 0;
        while ((i < n) && (j <= n))
        {
            if (sum < s)
            {
                sum += a[j];
                j++;
            }
            else if (sum > s)
            {
                sum -= a[i];
                i++;
            }
            else if (sum == s)
            {
                return {i + 1, j};
                break;
            }
        }
        return {-1};
    }
};
