/* Nama : Putri Nabila
   Kelas : A
   NPM : 140810180007
   Tanggal 08 Maret 2020
   Deskripsi : studi kasus 1  "algoritma Pencarian Nilai Maksimal"
*/


#include <iostream>
using namespace std;

#define N 10
int CariMaks(int x[]){
    int maks = x[0];
    for(int i = 1; i < N; i++){
        if(x[i] > maks)
            maks = x[i];
    }
    return maks;
}

int main(){
    int x[N] = {5,6,1000,9,7,15,40,6,10,300};
    cout << "Nilai maksimal adalah "<<CariMaks(x);
}

