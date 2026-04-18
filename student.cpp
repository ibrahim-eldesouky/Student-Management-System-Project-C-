#include "student.h"
#include <iostream>
#include <vector>
using namespace std;

vector<student>v;

void add(student s){
    if(check(s)){
        v.push_back(s); 
    }
}


bool check(student s){
    if(s.name == " " || s.id <= 0 || s.grade<0) return 0;
    for(auto i : v){
        if(s == i){
            return 0;
        }
    }
    return 1;
}

void display(){
    sort();
    for(auto i : v){
        cout << i.name << " " << i.id << " " << i.grade<<"\n";
    }
}

void sort(){
    long long mn =1e18 , index; 
    for(int i=0 ; i<v.size() ; i++){  
        for(int j=i ; j<v.size() ; j++){
            if(v[j].id<mn){ 
                mn = v[j].id; 
                index = j;
            }
        }
        swap(v[i] , v[index]);
    }
}

int search(student s){
    for(int i=0 ; i<v.size() ; i++){
        if(s==v[i]){
            return i;
        }
    }
    return -1;
}

void update(student s , long long d , double g){
    int ser  = search(s);
    if(ser!=-1){
        v[ser].id = d;
        v[ser].grade = g;
    }
}

void remove(student s){
    int ser = search(s);
    for(int i = ser ; i<v.size()-1 ; i++){
        v[i]=v[i+1];
    }
    v.pop_back();
}

void sortbygrades(){
    double mx =-1e18 , index; 
    for(int i=0 ; i<v.size() ; i++){  
        for(int j=i ; j<v.size() ; j++){
            if(v[j].grade>mx){ 
                mx = v[j].grade; 
                index = j;
            }
        }
        swap(v[i] , v[index]);
    }
}

void showtop(){
    sortbygrades();
    for(int i=0 ; i<10 && i<v.size() ; i++){
        cout<<v[i].name << " " << v[i].id <<  " " << v[i].grade<<"\n";
    }
}

double average(){
    double sum =0 ;
    for(auto i : v){
        sum+=i.grade;
    }
    return sum/v.size();
}
