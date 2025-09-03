// 5. Implement the LIS code for any given array.

#include <bits/stdc++.h> //All header file.
using namespace std;

int main()
{
    int n;
    cin >> n; // Input size of the array.

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i]; // Input array elements.

    int LIS[n];   // LIS[i] will store the length of LIS ending at i
    int Track[n]; // Track[i] will store previous index in LIS

    memset(Track, -1, sizeof(Track));

    // Initialize LIS lengths to 1.
    for (int i = 0; i < n; i++)
        LIS[i] = 1;

    // Compute LIS for each position
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            // If previous element is smaller and gives longer subsequence
            if (arr[j] < arr[i] && LIS[i] < LIS[j] + 1)
            {
                LIS[i] = LIS[j] + 1; // Update LIS length
                Track[i] = j;        // Store previous index for reconstruction
            }
        }
    }


    // Find maximum LIS length and ending index
    int max = 0, ind = -1;
    for (int i = 0; i < n; i++)
    {
        if (LIS[i] > max)
        {
            max = LIS[i];
            ind = i;
        }
    }
    

    // Print LIS Length
    cout << "LIS Length = " << max << endl;

    // Reconstruct LIS using Track array
    vector <int> ans;
    while (ind != -1)
    {
        ans.push_back(arr[ind]);
        ind = Track[ind]; // Move to previous index
    }

    // Print the LIS in correct order
    cout << "Subsequence = ";
    for (int i = ans.size() - 1; i >= 0; i--)
    {
        cout << ans[i] << " ";
    }
       
    cout << endl;

    return 0;
}
