using namespace std;
#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
public:
  static int countRotations(const vector<int>& arr) {

    if(arr[0] < arr[arr.size() - 1]) return 0;

    int low = 0;
    int high = arr.size() - 1;

    while(low <= high){

        int mid = low + (high - low)/2;

        if( arr[0] < arr[mid] && arr[mid+1] < arr[arr.size() - 1]) return  mid + 1;

        if(arr[low] < arr[mid]) {
            low = mid - 1;
        }else{
            high = mid + 1;
        }
    }

    return 0;

  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) 
      << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) 
      << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;

    return 0;

}