
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

// -------------------- Q1: Count Occurrences --------------------
int findFirstOccurrence(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result = mid;
            high = mid - 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int findLastOccurrence(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            result = mid;
            low = mid + 1;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

void question1() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target;
    cout << "Enter target to count: ";
    cin >> target;
    int first = findFirstOccurrence(nums, target);
    if (first == -1) cout << "Occurrences: 0\n";
    else {
        int last = findLastOccurrence(nums, target);
        cout << "Occurrences of " << target << ": " << last - first + 1 << endl;
    }
}

// -------------------- Q2: Find Min in Rotated Sorted Array --------------------
void question2() {
    vector<int> nums = {4, 5, 6, 7, 1, 2, 3};
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[high]) low = mid + 1;
        else high = mid;
    }
    cout << "Minimum element is: " << nums[low] << endl;
}

// -------------------- Q3: Search in Bitonic Array --------------------
int findPeak(const vector<int>& A) {
    int low = 0, high = A.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (A[mid] < A[mid + 1]) low = mid + 1;
        else high = mid;
    }
    return low;
}

int binarySearchAsc(const vector<int>& A, int low, int high, int B) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == B) return mid;
        else if (A[mid] < B) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int binarySearchDesc(const vector<int>& A, int low, int high, int B) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == B) return mid;
        else if (A[mid] > B) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

void question3() {
    vector<int> A = {1, 3, 8, 12, 9, 5, 2};
    int B;
    cout << "Enter element to search in bitonic array: ";
    cin >> B;
    int peak = findPeak(A);
    int idx = binarySearchAsc(A, 0, peak, B);
    if (idx == -1)
        idx = binarySearchDesc(A, peak + 1, A.size() - 1, B);
    if (idx != -1)
        cout << "Element " << B << " found at index " << idx << endl;
    else
        cout << "Element " << B << " not found" << endl;
}

// -------------------- Q4: Max Sawblade Height (Eko) --------------------
bool canCutWood(const vector<int>& A, int H, int B) {
    long long totalWood = 0;
    for (int height : A)
        if (height > H) totalWood += (height - H);
    return totalWood >= B;
}

void question4() {
    vector<int> A = {20, 15, 10, 17};
    int B;
    cout << "Enter required wood amount: ";
    cin >> B;
    int low = 0, high = *max_element(A.begin(), A.end());
    int result = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canCutWood(A, mid, B)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Maximum height of sawblade: " << result << endl;
}

// -------------------- Q5: Search Insert Position --------------------
int searchInsert(const vector<int>& A, int B) {
    int low = 0, high = A.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (A[mid] == B) return mid;
        else if (A[mid] < B) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

void question5() {
    vector<int> A = {1, 3, 5, 6};
    int B;
    cout << "Enter number to find insert position: ";
    cin >> B;
    cout << "Insert position: " << searchInsert(A, B) << endl;
}

// -------------------- Q6: Search in Matrix --------------------
void question6() {
    vector<vector<int>> A = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int B;
    cout << "Enter number to search: ";
    cin >> B;
    int n = A.size(), m = A[0].size();
    int low = 0, high = n * m - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        int val = A[mid / m][mid % m];
        if (val == B) {
            cout << "Found\n";
            return;
        } else if (val < B) low = mid + 1;
        else high = mid - 1;
    }
    cout << "Not Found\n";
}

// -------------------- Q7: Monk and Nice Strings --------------------
void question7() {
    int N;
    cout << "Enter number of strings: ";
    cin >> N;
    vector<string> A(N + 1);
    for (int i = 1; i <= N; ++i) cin >> A[i];
    for (int i = 1; i <= N; ++i) {
        int niceness = 0;
        for (int j = 1; j < i; ++j)
            if (A[j] < A[i]) ++niceness;
        cout << niceness << endl;
    }
}

// -------------------- Q8: Monk and Sorting Algorithm --------------------
int getChunkWeight(const string &numStr, int i) {
    int weight = 0, start = 5 * (i - 1);
    for (int j = start; j < start + 5; ++j) {
        int pos = numStr.length() - 1 - j;
        int digit = (pos >= 0) ? numStr[pos] - '0' : 0;
        weight = weight * 10 + digit;
    }
    return weight;
}

void question8() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];
    int i = 1;
    while (true) {
        bool allZero = true;
        for (auto &str : arr) {
            if (getChunkWeight(str, i) != 0) {
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
    for (auto &str : arr) cout << str << endl;
}

// -------------------- Q10: Monk and Suffix Sort --------------------
void question10() {
    string S;
    int k;
    cout << "Enter string and k: ";
    cin >> S >> k;
    vector<string> suffixes;
    for (int i = 0; i < S.length(); ++i) suffixes.push_back(S.substr(i));
    sort(suffixes.begin(), suffixes.end());
    if (k <= suffixes.size()) cout << suffixes[k - 1] << endl;
    else cout << "Invalid value of k\n";
}


// -------------------- Q9: Monk Being Monitor --------------------
void question9() {
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
    for (auto &entry : freq) {
        uniqueHeights.push_back(entry.first);
    }

    sort(uniqueHeights.begin(), uniqueHeights.end(), greater<int>());

    int maxDiff = -1;
    for (int i = 0; i < uniqueHeights.size(); ++i) {
        for (int j = i + 1; j < uniqueHeights.size(); ++j) {
            int h1 = uniqueHeights[i];
            int h2 = uniqueHeights[j];
            int diff = freq[h1] - freq[h2];
            if (diff > maxDiff && diff > 0) maxDiff = diff;
        }
    }
    cout << maxDiff << endl;
}


// -------------------- Main --------------------
int main() {
    cout << "Choose question number (1 to 9): ";
    int choice;
    cin >> choice;
    switch (choice) {
        case 1: question1(); break;
        case 2: question2(); break;
        case 3: question3(); break;
        case 4: question4(); break;
        case 5: question5(); break;
        case 6: question6(); break;
        case 7: question7(); break;
        case 8: question8(); break;
        case 9: question9(); break;
        case 10: question10(); break;
        default: cout << "Invalid choice!\n";
    }
    return 0;
}
