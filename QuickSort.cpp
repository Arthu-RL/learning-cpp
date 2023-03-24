#include <iostream>
#include <vector>

using namespace std;

void swap_elements(int &i, int &j){
    int temp;
    temp = i;
    i = j;
    j = temp;
}

int partition(vector<int> &vet, int l, int r){
    int pivot = vet[r];
    int i = l;

    for(int j = l; j < r; j++){
        if (vet[j] < pivot){
            swap_elements(vet[i], vet[j]);
            i++;
        }
    }

    swap_elements(vet[i], vet[r]);
    return i;
}

void quicksort(vector<int> &vet, int l, int r){
    if (l < r){
        int p = partition(vet, l, r);
        quicksort(vet, l, p-1);
        quicksort(vet, p+1, r);
    }
}

int main(){
    vector<int> vec = {5, 2, 9, 1, 5, 6, 9, 10, 7};

    quicksort(vec, 0, vec.size()-1);

    cout << "\n";
    for(auto v : vec){
        cout << v << " ";
    }
    cout << "\n";

    return 0;
}