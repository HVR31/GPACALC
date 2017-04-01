#ifndef GPA_h
#define GPA_h
#include <string>

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
    double gpa_calc();//takes in number of classes variable and asks user the units for each class and expected grade to calculate final gpa
    double input_grade_transition(string x);//classes countdown uses this function in order to take in user's string input and converts it to number counterpart(EX:A-->4)
    double check_number_good(int x);//primariljy used for checking the user input for number of units for a class and make sure its not negative
    
    private:
    string name_student;
    string name_school;
    int number_of_classes;
};

#endif
