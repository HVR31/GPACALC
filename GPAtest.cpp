#include<iostream>
#include<cmath>
#include<complex>
#include<iomanip>
#include<limits>
#include<stdexcept>
#include"GPA.h"
#include"check_num.h"

using namespace std;

int main(){
    string j,k;
    int x;
    
    GPA foo;
    cout<<"what is your name??"<<endl;
    getline(cin,j);
    foo.set_student_Name(j);
    cout<<"what is your school name??"<<endl;
    getline(cin,k);
    foo.set_school_name(k);
    cout<<"how many classes?"<<endl;
    cin>>x;
    
    foo.set_number_of_classes(check_number(x));
    
    cout<<foo.get_student()<<"'s GPA:"<<foo.gpa_calc()<<endl;
}

