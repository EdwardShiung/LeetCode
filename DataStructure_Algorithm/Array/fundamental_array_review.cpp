#include<iostream>
using namespace std;

void fundamentalArray();


int main(){

    fundamentalArray();



}


void fundamentalArray(){
    

    int array[2][3] = {
        {0,1,2},
        {3,4,5}
    };


    // Print first element address
    cout << "array:\t\t\t"<< array << endl;
    cout << "&array:\t\t\t"<< &array << endl;
    cout<< "&array[0][0]:\t\t" << &array[0][0] << endl;


    // Hexadecimal to decimal
    cout << "array\t\t\t" << (long)array << endl;
    cout << "&array:\t\t\t" << (long)&array << endl;
    cout << "&array[0][0]:\t\t" << (long)&array[0][0] << endl;


    


}


