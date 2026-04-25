#include "student.h"
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<student> students;
#include <fstream>

void welcome(){
    cout << "=====================================\n";
    cout << "         Student Management System\n";
    cout << "=====================================\n\n";
}

void Categories(){
cout << "1  - Add New Student\n";
cout << "2  - Update Student Information\n";
cout << "3  - Delete Student\n";
cout << "4  - Search for Student\n";
cout << "5  - Sort All Students\n";
cout << "6  - Display All Students\n";
cout << "7  - Show Top Student\n";
cout << "8  - Sort Students by Grades\n";
cout << "9  - Calculate Student Average grade\n";

cout << "\n=====================================\n";
cout << "Enter your choice: ";
int choice;
while (!(cin>>choice))
{
    cin.clear();
    cin.ignore(1000,'\n');
    cout << "Invalid input, try again: ";
}

switch (choice){
    case 1:{
        student new_student;
        cout<<"\n";
        cout<<"enter student data\n";
        cout<<"name: ";
        cin.ignore();
        getline(cin, new_student.name);
        cout<<"Id: ";
        cin >> new_student.id;
        cout<<"grades: ";
        for(int i=0 ; i< 5 ; i++){
            cin>>new_student.subject[i];
        }
        add(new_student);
        break;
    }
    case 2:{
        int ID;
        cin >>ID;
        update_student(ID);
        break;
    }
    case 3 :{
        cout<<"\n";
        cout<<"Enter the ID student you want to delete\n";
        int ID;
        cin >>ID;
        remove(ID);
        break;
    }

    case 4 :{
        cout<<"\n";
        cout<<"Enter the ID student you want to search\n";
        int ID;
        cin >> ID;
        int index = search(ID);
        if(index == -1){
            cout<<"this student is not found\n";
        }
        else{
            cout<<"this student is found\n";
        }
        break;
    }

    case 5 :{
        cout<<"\n";
        if(students.empty()){
            cout<<"There are no students on the list. You must add students first.\n";
        }
        else {
            sort_students();
            cout<<"They have been sorted successfully.\n";
            cout<<"If you want to view them in order, Enter: 1, or if you want to finish, Enter : 0\n";
            int c;
            cin >> c;
            if(c==1){
                display_all_students();
            }
        }
        break;
    }
    case 6:{
        cout<<"\n";
        if (students.empty()){
            cout << "There are no students on the list. You must add students first.\n";
        }
        else {
            display_all_students();
        }
        break;
    }
    case 7:{
        cout<<"\n";
        if(students.empty()){
            cout<<"There are no students on the list. You must add students first.\n";
        }
        else{
            show_top();
        }
        break;
    }
    case 8:{
        cout<<"\n";
        if (students.empty()){
            cout << "There are no students on the list. You must add students first.\n";
        }
        else{
            cout<<"Here is a list of students ranked by their grades.\n";
            cout<<"\n";
            sort_by_grades();
            display_all_students();
        }
        break;
    }
    case 9:{
        cout<<"\n";
        cout<<"Enter the ID student you want to Calculate Average grades\n";
        int ID ; 
        cin >> ID;
        Calculate_Student_Average_grade(ID);
    }
}

}

void add(student s){
    if(check(s)){
        students.push_back(s);
        cout<<"Added successfully\n";
        return;
    }
    cout<<"Add failed, try again\n";
}

bool check(student s){
    if(s.name==" " || s.id<0) return 0;

    for(int i=0 ; i<5 ; i++){
        if(s.subject[i]<0) return 0;
    }
    if(search(s.id)!=-1) return 0;
    return 1;
}

void update_student(int ID){
    int index = search(ID);

    if(index == -1){
        cout << "Student not found\n";
        return;
    }

    cout << "1 - Update name\n";
    cout << "2 - Update grades\n";
    cout << "3 - Update both\n";

    int choice;
    cin >> choice;
    if(choice == 1 || choice == 3){
        cout << "Enter new name: ";
        getline(cin, students[index].name);
    }

    if(choice == 2 || choice == 3){
        cout << "Enter new grades:\n";
        for(int i = 0; i < 5; i++){
            cin >> students[index].subject[i];
        }
    }

    cout << "Updated successfully\n";
}

int search(int ID){
    for(int i=0 ; i<students.size() ; i++){
        if(ID==students[i].id){
            return i;
        }
    }
    return -1;
}

void sort_students(){
    sort(students.begin() , students.end() ,[](student a , student b){return a.id<b.id;});
}

void remove(int ID){
    int index = search(ID);
    if(index==-1){
        cout << "Error, the student is not on the list to be deleted\n";
        return ;
    }
    for(int i= index ; i<students.size()-1 ; i++){
        students[i]=students[i+1];
    }
    students.pop_back();
    cout<<"The operation was completed successfully\n";
}

void display_one_student(int index){
    cout<<"name: "<<students[index].name<<" ID: "<<students[index].id<<"\n";
    cout<<"grades : ";
    for(int i=0 ; i< 5 ; i++){
        cout<<students[index].subject[i]<<" ";
    }
    cout<<"\n";
}

void display_all_students(){
    sort_students();
    for(int i=0 ; i<students.size() ; i++){
        display_one_student(i);
    }
}

double total_grades(student s){
    double sum=0;
    for(auto i : s.subject){
        sum+=i;
    }
    return sum;
}

void sort_by_grades(){
    sort(students.begin() , students.end() , 
        [](student a , student b){return total_grades(a)>total_grades(b);});
}

void show_top(){
    sort_by_grades();
    int cnt=0;
    for(int i=0 ;  cnt<10 && i<students.size() ; i++){
        cout<<i+1<<" place goes to the "<<students[i].name<<" whith ID : "<<students[i].id<<" and total grades : " <<total_grades(students[i])<<"\n";
        cnt++;
    }
}

void Calculate_Student_Average_grade(int ID){
    int index = search(ID);
    if(index == -1){
        cout<<"Error, this student is not found\n";
        return ;
    }
    double av=0;
    for(int i=0 ; i<5 ; i++){
        av+=students[index].subject[i];
    }
    cout<<"Average grades of student :"<<students[index].name<<"/ ID:"<<students[index].id<<" is "<<av/5<<"\n";
}

void save_to_file(){
    ofstream file("students.txt");

    for(auto s : students){
        file << s.id << "\n";
        file << s.name << "\n";

        for(int i = 0; i < 5; i++){
            file << s.subject[i] << " ";
        }
        file << "\n";
    }

    file.close();
    cout << "Data saved successfully\n";
}


void load_from_file(){
    ifstream file("students.txt");

    if(!file){
        cout << "No file found\n";
        return;
    }

    students.clear();

    while(true){
        student s;

        if(!(file >> s.id)) break;

        file.ignore();
        getline(file, s.name);

        for(int i = 0; i < 5; i++){
            file >> s.subject[i];
        }

        students.push_back(s);
    }

    file.close();
    cout << "Data loaded successfully\n";
}