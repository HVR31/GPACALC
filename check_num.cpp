#include<iostream>
#include<cmath>
#include<complex>
#include<iomanip>
#include<limits>
//#include<stdexcept>
#include"check_num.h"

using namespace std;

int check_number(int x){
     while(x<=0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"you entered an invalid input try again\n";
        cin>>x;
        }
}