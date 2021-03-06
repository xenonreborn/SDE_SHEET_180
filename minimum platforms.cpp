/*
Given arrival and departure times of all trains that reach a railway station. Find the minimum number of platforms required for the railway station so that no train is kept waiting.
Consider that all the trains arrive on the same day and leave on the same day. Arrival and departure time can never be the same for a train but we can have arrival time of one train equal to departure time of the other. At any given instance of time, same platform can not be used for both departure of a train and arrival of another train. In such cases, we need different platforms.


Example 1:

Input: n = 6 
arr[] = {0900, 0940, 0950, 1100, 1500, 1800}
dep[] = {0910, 1200, 1120, 1130, 1900, 2000}
Output: 3
Explanation: 
Minimum 3 platforms are required to 
safely arrive and depart all trains.
Example 2:

Input: n = 3
arr[] = {0900, 1100, 1235}
dep[] = {1000, 1200, 1240}
Output: 1
Explanation: Only 1 platform is required to 
safely manage the arrival and departure 
of all trains. 

Your Task:
You don't need to read input or print anything. Your task is to complete the function findPlatform() which takes the array arr[] (denoting the arrival times), array dep[] (denoting the departure times) and the size of the array as inputs and returns the minimum number of platforms required at the railway station such that no train waits.

Note: Time intervals are in the 24-hour format(HHMM) , where the first two characters represent hour (between 00 to 23 ) and the last two characters represent minutes (this may be > 59).


Expected Time Complexity: O(nLogn)
Expected Auxiliary Space: O(n)


Constraints:
1 ≤ n ≤ 50000
0000 ≤ A[i] ≤ D[i] ≤ 2359
*/

//optimal approach - Create a 'count' variable = 0. Sort the arrival array and the departure array. Now initialize two pointers 'i' and 'j' to 0. Iterate until either 'i' reachers array end or 'j'.
//If arrival[i] <= departure[j], move 'i' pointer forward by 1 and increase 'count' by 1. Else, move 'j' pointer forward by 1 and decrease 'count' by 1. In each iteration,
//compare if count is greater than maximum, if yes, update maximum = count. Finally return maximum.
//Time - O(2NlogN) + O(2N), 2NlogN for sorting the arrival and departure array, and 2N for traversing throug the sorted arrival and departure array.
//Space - O(1)

    int findPlatform(int arr[], int dep[], int n){
    	sort(arr,arr+n);
    	sort(dep,dep+n);
    	int i = 0, j = 0, count = 0, max1 = 0;
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        i++;
    	        count++;
    	    }
    	    else{
    	        j++;
    	        count--;
    	    }
    	    if(count > max1)
    	        max1 = count;
    	}
    	return max1;
    }
