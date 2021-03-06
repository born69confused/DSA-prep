#include <bits/stdc++.h>
using namespace std;

// Question Link - https://practice.geeksforgeeks.org/problems/frequency-of-array-elements-1587115620/1/#

// Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can be absent from the array. Your task is to count the frequency of all elements from 1 to N.
// Note: The elements greater than N in the array can be ignored for counting.
// Input:
// N = 5
// arr[] = {2, 3, 2, 3, 5}
// P = 5
// Output: 0 2 2 0 1

// Method 1:
// TC - O(N) , SC - O(N)

class Solution
{
public:
    void frequencyCount(vector<int> &arr, int N, int P)
    {
        int a[N + 1] = {0};
        for (auto i : arr)
        {
            if (i <= N)
            {
                a[i]++;
            }
        }
        for (int i = 0; i < arr.size(); i++)
        {
            arr[i] = a[i + 1];
        }
    }
};

// Method 2:
// TC - O(N), SC - O(1)

class Solution
{
public:
    void frequencyCount(vector<int> &arr, int n, int P)
    {
        int max = P + 1;
        for (int i = 0; i < n; i++)
        {
            if ((arr[i]) % max <= n)
                arr[(arr[i] - 1) % max] += max;
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] /= max;
        }
    }
};