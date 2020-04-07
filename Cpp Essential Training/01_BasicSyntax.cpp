#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    // inline comment
    
    /*
     Multiline comment
     */
    
    int simple_number = 10;
    const double pi = 3.14;
    
    simple_number = 1;
    
    cout << simple_number << endl << pi << endl;
    
    int *ip; // pointer for integer value
    ip = &simple_number; // link to the variable address
    
    cout << "*ip links to " << *ip << ", ip address is " << ip << endl;
    
    // create reference to int value
    // have to be initialized immediately
    int &number_ref = simple_number;
    cout << "simple_number = " << simple_number << ", number_ref = " << number_ref << endl;
    
    simple_number = 999;
    cout << "simple_number = " << simple_number << ", number_ref = " << number_ref << endl;
    
    number_ref = 615; // will affect simple_number value
    cout << "simple_number = " << simple_number << ", number_ref = " << number_ref << endl;
    
    int &another_ref = number_ref; // reference could also connect to another ref
    another_ref = 0;
    cout << "simple_number = " << simple_number << ", number_ref = " << number_ref << ", another_ref = " << another_ref << endl;
    
    int arr[5];
    arr[0] = 10; 
    arr[1] = 20;
    
    int *arr_pointer = arr; // point to the first array item
    cout << *(++arr_pointer) << endl; // inscease pointer to refer second item
    
    // print memory addresses of the increased pointers
    cout << arr_pointer << " " << arr_pointer + 1 << " " << arr_pointer + 2 << endl;
    
    // insert code here...
    cout << "Hello, World 1!\n";
    return 0;
}
