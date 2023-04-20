#include <iostream>
using namespace std;

int main() {
   int arr[] = {10, 20, 30, 40, 50};
   int n = sizeof(arr)/sizeof(arr[0]);
   int largest = arr[0];

   for(int i = 1; i < n; i++) {
      if(largest < arr[i])
         largest = arr[i];
   }

   cout << "Largest element in the array is " << largest << endl;
   return 0;
}
