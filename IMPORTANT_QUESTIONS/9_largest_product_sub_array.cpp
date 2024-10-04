#include <iostream>
#include <limits>
using namespace std;

int largest_product_sub_array_brute_force(int arr[], int n) {
    int max = INT8_MIN;

    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++){
            int currProd = 1;
            for (int k=i; k<=j; k++) {
                currProd *= arr[k];
            }
            if (max < currProd) {
                max = currProd;
            }
        }
    }

    return max;
}

int largest_product_sub_array_slightly_optimized(int arr[], int n) {
    int max = INT8_MIN;

    for (int i=0; i<n; i++) {
        int prod = 1;
        for (int j=i; j<n; j++) {
            prod = prod*arr[j];
            if (max < prod) {
                max = prod;
            }
        }
    }

    return max;
}

int largest_product_sub_array_best(int arr[], int n) {
    int result = INT8_MIN;
    int maxProd = arr[0];
    int minProd = arr[0];

    for (int i=1; i<n; i++) {
        int curr = arr[i];

        int temp = max(curr, max(maxProd*curr, minProd*curr));
        minProd = min(curr, min(maxProd*curr, minProd*curr));
        maxProd = temp;

        result = max(maxProd, result);
    }

    return result;

}

int main() {
    int arr[] = {2, 3, -2, 4};
    int n = sizeof(arr) / sizeof(int);
    
    cout << "Largest Product of sub array : " << largest_product_sub_array_brute_force(arr, n) << endl;
    cout << "Largest Product of sub array : " << largest_product_sub_array_slightly_optimized(arr, n) << endl;
    cout << "Largest Product of sub array : " << largest_product_sub_array_best(arr, n) << endl;

    return 0;
}