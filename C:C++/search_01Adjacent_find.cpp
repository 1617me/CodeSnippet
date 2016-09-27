#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> v1{0, 1, 2, 4, 5, 5, 6, 7, 9, 9};
    auti i1 = ajacent_find(v1.begin(), vi1.end());
    if(i1 == v1.end()){
	cout << "no matching adjacent elements\n"<< endl;
    }
    else {
	cout << "the first adjacent pair of equal elements at: "
	    << distance(v1.begin(), i1) << endl;
    }

    auto v2 = adjacent(v1.begin(), v1.end(), greater<int>());
    if (v2 == v1.end()){
	cout << "there is no matching adjacent element in accending order\n";
    }
    else {
	cout << "the last:"
	    << distance(v1.begin(), v2) << endl;
    }
}
