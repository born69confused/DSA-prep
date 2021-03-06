#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1/#

Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.

Input:
    N = 2
    A[] = {1, 10}
Output: 1

Method 1:
TC - O(N^2) , SC - O(1)
*/
class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n)
    {

        int res = -1;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (arr[j] >= arr[i] && res < (j - i))
                    res = j - i;
            }
        }
        return res;
    }
};
/*
Method 2:
TC - O(N) , SC - O(N)
*/
class Solution
{
public:
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n)
    {
        int small_on_left[n];
        int large_on_right[n];
        int min_el = arr[0];
        int max_el = arr[n - 1];
        int res = -1;
        for (int i = 0; i < n; i++)
        {
            if (min_el > arr[i])
                min_el = arr[i];
            small_on_left[i] = min_el;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (max_el < arr[i])
                max_el = arr[i];
            large_on_right[i] = max_el;
        }
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (small_on_left[i] <= large_on_right[j])
            {
                res = max(res, j - i);
                j++;
            }
            else
                i++;
        }
        return res;
    }
};