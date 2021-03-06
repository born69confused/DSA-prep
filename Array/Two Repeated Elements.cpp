#include <bits/stdc++.h>
using namespace std;
/*
Question Link - https://practice.geeksforgeeks.org/problems/two-repeated-elements-1587115621/1/#

You are given an array of N+2 integer elements. All elements of the array are in range 1 to N. Also, all elements occur once except two numbers which occur twice. Find the two repeating numbers.

Input:
    N = 4
    array[] = {1,2,1,3,4,3}
Output: 1 3

Method 1:
TC - O(N) , SC - O(N)
*/
class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        vector<int> res;
        int freq[n] = {0};
        for (int i = 0; i < n + 2; i++)
        {
            if (freq[arr[i] - 1] == 0)
                freq[arr[i] - 1]++;
            else
                res.push_back(arr[i]);
        }
        return res;
    }
};
/*
Method 2:
TC - O(N) , SC - O(1) (Modifying the original array.)
*/
class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        vector<int> res;
        for (int i = 0; i < n + 2; i++)
        {
            if (arr[abs(arr[i]) - 1] > 0)
            {
                arr[abs(arr[i]) - 1] *= -1;
            }
            else
                res.push_back(abs(arr[i]));
        }
        return res;
    }
};
/*
Method 3:
TC - O(N) , SC - O(1) (No modification in the array.)
*/
class Solution
{
public:
    // Function to find two repeated elements.
    vector<int> twoRepeated(int arr[], int n)
    {
        vector<int> res;
        int x = 0, y = 0, Xor = arr[0];
        for (int i = 1; i < n + 2; i++)
        {
            Xor = Xor ^ arr[i];
            if (i <= n)
                Xor = Xor ^ i;
        }

        // Xor will now contain the xor of the two repeated elements.
        int set_bit = Xor & ~(Xor - 1);
        // finding the rightmost setbits in the Xor value.
        for (int i = 0; i < n + 2; i++)
        {
            if (arr[i] & set_bit)
                x = x ^ arr[i];
            else
                y = y ^ arr[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (i & set_bit)
                x = x ^ i;
            else
                y = y ^ i;
        }
        /*Determining order of answer*/
        int count_x = 0, count_y = 0;
        for (int i = 0; i < n + 2; i++)
        {
            if (arr[i] == x)
                count_x++;
            if (arr[i] == y)
                count_y++;
            if (count_x == 2)
            {
                return {x, y};
            }
            if (count_y == 2)
            {
                return {y, x};
            }
        }
        return {1, 1};
    }
};
