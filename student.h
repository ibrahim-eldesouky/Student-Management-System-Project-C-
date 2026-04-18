#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
using namespace std;

struct student{
    string name;
    long long id;
    double grade;
    bool operator==(const student & other) const{
        return (name == other.name &&
                id == other.id &&
                grade == other.grade);
    }
};

vector<student>v;
void add(student s);
bool check(student s);
void display();
void sort();
int search(student s);
void update(student s , long long d , double g);
void remove(student s);
void sortbygrades();
void showtop();
double average();

#endif