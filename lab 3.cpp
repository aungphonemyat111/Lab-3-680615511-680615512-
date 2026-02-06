#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <random>

using namespace std;



// Time Complexity: O(N) - Linear pass to sum elements
int getSum(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 0);
}

// Time Complexity: O(N) - Linear pass to find max
int getMax(const vector<int>& v) {
    return *max_element(v.begin(), v.end());
}

// Time Complexity: O(N) - Linear pass to find min
int getMin(const vector<int>& v) {
    return *min_element(v.begin(), v.end());
}

//  Complexity: O(N) -  linear
double getMean(const vector<int>& v) {
    return (double)getSum(v) / v.size();
}

// Time Complexity: O(N log N) - Sorting is required
double getMedian(vector<int> v) {
    sort(v.begin(), v.end());
    size_t n = v.size();
    if (n % 2 == 0) return (v[n/2 - 1] + v[n/2]) / 2.0;
    return v[n/2];
}

// Time Complexity: O(N) - 
int getMode(const vector<int>& v) {
    map<int, int> counts;
    for (int x : v) counts[x]++;
    int mode = v[0], maxCount = 0;
    for (auto const& [val, count] : counts) {
        if (count > maxCount) {
            maxCount = count;
            mode = val;
        }
    }
    return mode;
}

// Time Complexity: O(N) - Max and Min are linear
int getRange(const vector<int>& v) {
    return getMax(v) - getMin(v);
}

// Time Complexity: O(N) - Single pass check
int countEvens(const vector<int>& v) {
    int count = 0;
    for(int x : v) if(x % 2 == 0) count++;
    return count;
}

// Time Complexity: O(N) - Derived from total size and evens
int countOdds(const vector<int>& v) {
    return v.size() - countEvens(v);
}

// Time Complexity: O(N) - Calculates variance in linear time
double getStandardDeviation(const vector<int>& v) {
    double mean = getMean(v);
    double sq_sum = 0;
    for (int x : v) sq_sum += pow(x - mean, 2);
    return sqrt(sq_sum / v.size());
}

// Time Complexity: O(N log N) - Sort and then print
void printSorted(vector<int> v) {
    sort(v.begin(), v.end());
    for (int x : v) cout << x << " ";
    cout << endl;
}

// Time Complexity: O(N log N) - Requires sorting
void printQuartiles(vector<int> v) {
    sort(v.begin(), v.end());
    size_t n = v.size();
    cout << "Q1: " << v[n * 0.25] 
         << ", Q2 (Median): " << getMedian(v) 
         << ", Q3: " << v[n * 0.75] << endl;
}

int main() {
    // Random number generation
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> sizeDist(50, 150);
    uniform_int_distribution<> valDist(0, 100);

    // Vector 
    int n = sizeDist(gen);
    vector<int> data;
    for (int i = 0; i < n; ++i) {
        data.push_back(valDist(gen));
    }

    // Results 
    cout << "--- Vector Statistics ---" << endl;
    cout << "Number of elements: " << data.size() << endl;
    cout << "Sum: " << getSum(data) << endl;
    cout << "Highest: " << getMax(data) << endl;
    cout << "Lowest: " << getMin(data) << endl;
    cout << "Mean: " << getMean(data) << endl;
    cout << "Median: " << getMedian(data) << endl;
    cout << "Mode: " << getMode(data) << endl;
    cout << "Range: " << getRange(data) << endl;
    cout << "Evens: " << countEvens(data) << endl;
    cout << "Odds: " << countOdds(data) << endl;
    cout << "Std Dev: " << getStandardDeviation(data) << endl;
    
    cout << "\nSorted Order:" << endl;
    printSorted(data);
    
    cout << "\nQuartiles:" << endl;
    printQuartiles(data);

    return 0;
}