#include "student.h"
#include <iostream>
int main(){
    load_from_file();

    welcome();

    while(true){
        Categories();

        cout << "\nDo you want to continue? (1 = yes / 0 = no): ";
        int c;
        cin >> c;

        if(c == 0){
            save_to_file();
            break;
        }
    }

    return 0;
}