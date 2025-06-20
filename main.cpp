
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// -------------------- Question 1: Matrix Search --------------------
void question1() {
    vector<vector<int>> A = {
        {1, 3, 5},
        {7, 9, 11},
        {13, 15, 17}
    };
    int B;
    cout << "Enter element to search: ";
    cin >> B;
    int n = A.size(), m = A[0].size();
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int val = A[mid / m][mid % m];
        if (val == B) {
            cout << "Found\n";
            return;
        }
        if (val < B) low = mid + 1;
        else high = mid - 1;
    }
    cout << "Not Found\n";
}

// -------------------- Question 2: Monk and Nice Strings --------------------
void question2() {
    int N;
    cout << "Enter number of strings: ";
    cin >> N;
    vector<string> A(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) {
        int nice = 0;
        for (int j = 1; j < i; ++j)
            if (A[j] < A[i]) ++nice;
        cout << nice << endl;
    }
}

// -------------------- Question 3: Monk and Sorting Algorithm --------------------
int getChunkWeight(const string &numStr, int i) {
    int weight = 0;
    int start = 5 * (i - 1);
    for (int j = start; j < start + 5; ++j) {
        int pos = numStr.length() - 1 - j;
        int digit = (pos >= 0) ? numStr[pos] - '0' : 0;
        weight = weight * 10 + digit;
    }
    return weight;
}

void question3() {
    int n;
    cout << "Enter number of numbers: ";
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    int i = 1;
    while (true) {
        vector<pair<int, int>> weights;
        for (int j = 0; j < n; ++j) {
            int weight = getChunkWeight(arr[j], i);
            weights.push_back({weight, j});
        }

        bool allZero = true;
        for (auto &w : weights) {
            if (w.first != 0) {
                allZero = false;
                break;
            }
        }
        if (allZero) break;

        stable_sort(arr.begin(), arr.end(), [&](const string &a, const string &b) {
            return getChunkWeight(a, i) < getChunkWeight(b, i);
        });
        i++;
    }

    for (const auto &num : arr) cout << num << endl;
}

// -------------------- Question 4: Monk being Monitor --------------------
void question4() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    vector<int> heights(n);
    unordered_map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
        freq[heights[i]]++;
    }
    vector<int> uniqueHeights;
    for (auto &entry : freq) uniqueHeights.push_back(entry.first);
    sort(uniqueHeights.begin(), uniqueHeights.end(), greater<int>());

    int maxDiff = -1;
    for (int i = 0; i < uniqueHeights.size(); ++i) {
        for (int j = i + 1; j < uniqueHeights.size(); ++j) {
            int h1 = uniqueHeights[i], h2 = uniqueHeights[j];
            int diff = freq[h1] - freq[h2];
            if (diff > maxDiff && diff > 0) maxDiff = diff;
        }
    }
    cout << maxDiff << endl;
}

// -------------------- Question 5: Monk and Suffix Sort --------------------
void question5() {
    string S;
    int k;
    cout << "Enter string: ";
    cin >> S;
    cout << "Enter k: ";
    cin >> k;
    vector<string> suffixes;
    for (int i = 0; i < S.length(); ++i) suffixes.push_back(S.substr(i));
    sort(suffixes.begin(), suffixes.end());
    if (k <= suffixes.size()) cout << suffixes[k - 1] << endl;
    else cout << "Invalid value of k\n";
}

// -------------------- Main Menu --------------------
int main() {
    int choice;
    cout << "Choose question number to run (1-5): ";
    cin >> choice;
    switch (choice) {
        case 1: question1(); break;
        case 2: question2(); break;
        case 3: question3(); break;
        case 4: question4(); break;
        case 5: question5(); break;
        default: cout << "Invalid choice!\n";
    }
    return 0;
}
