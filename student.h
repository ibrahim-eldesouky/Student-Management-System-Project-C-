#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
using namespace std;

struct student{
    string name;
    int id;
    double subject[5]={};
};

extern vector<student> students;

void welcome();
void Categories();
void add(student s);
bool check(student s);
void update_student(int ID);
int search(int ID);
void sort_students();
void remove(int ID);
void display_one_student(int index);
void display_all_students();
double total_grades(student s);
void sort_by_grades();
void show_top();
void Calculate_Student_Average_grade(int ID);
void save_to_file();
void load_from_file();
#endif