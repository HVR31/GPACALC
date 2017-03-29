#include<iostream>
#include<cmath>
#include<complex>
#include<iomanip>
#include<limits>
#include<stdexcept>

using namespace std;

class GPA{
    public:
    GPA();//default constructor()
    GPA(string name_student,string name_school,int number_of_classes);
    //all set functions
    void set_student_Name(string name);
    void set_school_name(string scho_name);
    void set_number_of_classes(int n);
    //all getter functions
    string get_student() const;
    string get_school() const;
    int get_number_of_classes() const;
    //other memeber functions
    double classes_countdown();
    double input_grade_transition(string x);
    double check_number_good(int x);

    private:
    string name_student;
    string name_school;
    int number_of_classes;
};

GPA::GPA(){}

GPA::GPA(string name_student,string name_school,int number_of_classes):
name_student(name_student),name_school(name_school),number_of_classes(number_of_classes){}

void GPA::set_student_Name(string name){
    name_student=name;
}

string GPA::get_student() const{
    return name_student;
}

void GPA::set_school_name(string scho_name){
    name_school=scho_name;
}

string GPA::get_school() const{
    return name_school;
}

void GPA::set_number_of_classes(int n){
    number_of_classes=n;
}

int GPA::get_number_of_classes() const{
    return number_of_classes;
}


double GPA::classes_countdown(){
    double total_units_completed_semester;
    while(number_of_classes>0){

        double final_grade;
        int units_for_one_class;
        string letter_grade;

        cout<<"how many units is class #"<<number_of_classes<<endl;
        cin>>units_for_one_class;
       //The precedding while loop checks user input to validate if it is not a negative,zero or
        while(check_number_good(units_for_one_class)==false){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"you entered an invalid input try again\n";
        cin>>units_for_one_class;
        check_number_good(units_for_one_class);
        }

        total_units_completed_semester= total_units_completed_semester+units_for_one_class;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"what grade do you plan to recieve for class # "<<number_of_classes<<endl<<"Enter A,A-,B+,B,..etc?";
        cin>>letter_grade;
        //the preceding while loop checks to see if user entered a letter character and that the  letter entered was in range of a-f
        //by passing it through input grde transition function,-1 indicates user input error
        while(input_grade_transition(letter_grade)==-1){

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"you did not enter a letter that was valid,try again\n";
            cin>>letter_grade;
            input_grade_transition(letter_grade);
        }

        double units_after_multiplier=units_for_one_class*input_grade_transition(letter_grade); //calculates the unit for the class and multiplies it by multiplier depending on grade
        final_grade=final_grade+units_after_multiplier;
        number_of_classes--;//decrement value of loop by 1
        //when number of classes=0 then function will exit with a return value of final_grade
        if(number_of_classes==0){

            return (final_grade/total_units_completed_semester);
        }
    }
}

double GPA::check_number_good(int x){
     if(x<=0||x>20){
         return false;
     }else
     return x;
}


double GPA::input_grade_transition(string x){
     //alters string value of x into its numeric counterpart
    double y=0;
    if(x=="A"||x=="a"){
        y=4.0;

    }else if(x=="A-"||x=="a-"){
        y=3.67;

    }else if(x=="B+"||x=="b+"){
        y=3.33;

    }else if(x=="B"||x=="b"){
        y=3.00;

    }else if(x=="B-"||x=="b-"){
        y=2.67;

    }else if(x=="C+"||x=="c+"){
        y=2.33;

    }else if(x=="C"||x=="c"){
        y=2.0;

    }else if(x=="C-"||x=="c-"){
        y=1.67;

    }else if(x=="D+"||x=="d+"){
        y=1.33;

    }else if(x=="D"||x=="d"){
        y=1.00;

    }else if(x=="D-"||x=="d-"){
        y=0.67;

    }else if(x=="F"||x=="f"){
        y=0;

    }else{
        return -1;//-1 indicates that x wasnt a letter from A-F range

    }
    return y;

}

int check_number(int x){
     while(x<=0){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout<<"you entered an invalid input try again\n";
        cin>>x;
        }
}

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

    cout<<"your GPA:"<<foo.classes_countdown()<<endl;

}
