#include<iostream>
#include<cmath>
#include<complex>
#include<iomanip>
#include<limits>


using namespace std;

double check_number_good(double x){
    while(!(cin>>x)||x<0||x==0||x>4){
        if(!cin){
            cout<<"Not a valid number make sure you entered a numeric value\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else if(x<0||x==0||x>4){
            cout<<"you entered a negative number, or a zero, or number beyond range only non negative numbers accepted\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }else{
             
        }
        
    }
   return x;
    
}

int main(){
    
    string type_school;
    cout<<"Hello what is your current school level?(e.g. high school,college,etc...)\n";
    getline(cin,type_school);
    
    int number_of_classes=0;
    while((cout<<"hello there how many classes are you taking this term?\n"),!(cin>>number_of_classes)||number_of_classes==0){
        if(!cin){
        cout<<"**invalid number of classes entered must be numeric.**\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        else{
            cout<<" you are taking 0 classes?? then program is no longer needed then goodbye, if you made a mistake press actual number of classes"<<endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        
    }
    
    double final_grade=0;
    double total_units_completed_semester=0;
    
    
    while(number_of_classes>0){
        
        double units_for_one_class=0;
        double grade_multiplier=0;
        
        cout<<"how many units is class #"<<number_of_classes<<endl;
        cin>>units_for_one_class;
    
        total_units_completed_semester= total_units_completed_semester+units_for_one_class;
        
        
        cout<<"what grade do you plan to recieve for class # "<<number_of_classes<<endl<<"Enter 4 for A,3.67 for A-,3.33 for B+,3 for B,2.67 for B-,2.33 for C+,2 for C,1.67 for C-,1.33 for D+,1 for D,.67 for D-,0 for F?";
        cin>>grade_multiplier;
        cout<<"grade_multiplier"<<grade_multiplier;
       
        number_of_classes--;
        double units_after_multiplier=units_for_one_class*grade_multiplier; //calculates the unit for the class and multiplies it by multiplier depending on grade
        final_grade=final_grade+units_after_multiplier;
        cout<<"final_grade"<<final_grade;
        
    }
    
    cout<<"your gpa for this semester will be "<<final_grade/total_units_completed_semester<<endl;
   
    double total_units_completed_carrer=0;
    cout<<"how many units have you completed in your "<<type_school<<" career?\n";
    cin>>total_units_completed_carrer;
    double current_GPA=0;
    cout<<"what is your current GPA"<<endl;
    cin>>current_GPA;
    double units_multiplied=current_GPA*total_units_completed_carrer;
    double units_past_present=total_units_completed_carrer+total_units_completed_semester;
    units_multiplied=units_multiplied+final_grade;
    cout<<"your current gpa is a "<<current_GPA<<" it will change to "<<units_multiplied/units_past_present<<" at the semester's end"<<endl;
    

}