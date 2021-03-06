#include <bits/stdc++.h>
using namespace std;
// Question Link - https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1/

// You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.
// Input:
// N = 5
// arr[] = {1,2,3,4,5}
// Output: 6

// Method 1:
// TC-O(N^2) SC-O(1) : Brute force , check for each number from 1 to n in the array.

// Method 2:
// TC-O(N) SC-O(N) : Hashing
class Solution
{
public:
    int missingNumber(int arr[], int n)
    {
        unordered_set<int> s;
        for (int i = 0; i < n; i++)
            s.insert(arr[i]);

        int ans = 1;
        while (s.find(ans) != s.end())
            ans++;

        return ans;
    }
};

// Method 3 : TC - O(N *Log(N)), SC - O(1)
class Solution
{
public:
    int missingNumber(int arr[], int n)
    {
        sort(arr, arr + n);
        int minInt = 1;
        for (int i = 0; i < n; i++)
        {
            if (minInt == arr[i])
                minInt++;
        }
        return minInt;
    }
};

// Method 4 : TC - O(N), SC - O(1)
class Solution
{
public:
    void swap(int *a, int *b)
    {
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

    //Function to segregate negative and positive numbers.
    int segregate(int arr[], int n)
    {
        int j = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= 0)
            {
                swap(&arr[i], &arr[j]);
                j++;
            }
        }

        return j;
    }

    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n)
    {
        int s = n + 1;
        int j = segregate(arr, n);
        arr = arr + j;
        n -= j;
        for (int i = 0; i < n; i++)
        {
            if (abs(arr[i]) - 1 < n && arr[abs(arr[i]) - 1] > 0)
            {
                arr[abs(arr[i]) - 1] *= -1;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > 0)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};
