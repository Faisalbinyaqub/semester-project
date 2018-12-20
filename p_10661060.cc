//Headers inclusion
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

template <class var>

void print(var textline){
    cout << textline;
}

//Structure defining

struct course {
    int level;
    string subjects[10];
};

struct record{
    int semester;
    int credit_hr;
    string course_name;
    int mark;
    string grade;
};


class person
{
    public:
        person()
        {

            status = "null";
        }
        //setter functions for student
        void setName(string val){
            name = val;
        }

        void setStatus(string val){
            status = val;
        }

        void setAge(int val){
            age = val;
        }

        void setID(int val){
            object_id = val;
        }

        void setIndex(int val){
            index = val;
        }

        void setResidence(string val){
            residence = val;
        }

        void listItems(vector <string> arrayVar){
            int len = arrayVar.size();
            for (int i=0;i<len;i++){
                print(arrayVar[i]);
                if ((i+1)%3 == 0){
                    print("\n");
                }else{
                    print("\t\t");
                }
            }
        }


        //getter functions for student
        string getName(){
            return name;
        }

        string getStatus(){
            return status;
        }

        int getAge(){
            return age;
        }

        string getResidence(){
            return residence;
        }

        string getType(){
            return "person";
        }

        int getID(){
            return object_id;
        }

        int getIndex(){
            return index;
        }

        void getInfo(){
            cout << "\nname       : " << getName() << "\nage        : " << getAge() << "\nperson ID    : " << getID() <<endl;
        }

    private:
        string name;
        int age;
        int index;
        int object_id;
        string status;
        string residence;
};


struct student{
    person details;
    float schoolfees;
    int level;
    string course;
    string department;
    vector<string> subjects;
    vector<record> academic_records;
};

struct staff{
    person details;
    string job;
    string department;
    vector<string> subjects;
};


// functions prototypes
void addStudent(),editStudent(),manageStudent(),GpaCalc(student obj);
void addStaff(),editStaff(),manageStaff(),GpaCalc(student obj);
string lower(string line),gradeCalc(double score);

student Stu_Container[10000];
staff Sta_Container[10000];


int stu_base_id=10111000;
int sta_base_id=11110000;
int stu_count = 0;
int sta_count = 0;
string str;int num;

int main()
{
    cout<<"\n \t\t\t ***************************************** \n";
     cout<<"\n \t\t\t FAISO SCHOOL MANAGEMENT SYSTEM \n";

     cout<<"\n \t\t\t ***************************************** \n";
     cout << "\n\n";
    string option;

    while (true){
     cout << "\n \t\t\t 1. STUDENTS INFORMATION ";
     cout << "\n \t\t\t 2. STAFFS INFORMATION ";
     cout << "\n \t\t\t 0. EXIT PROGRAM ";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice :=> ";
     cin >> str;
       if (str == "1"){
            system("cls");//Clear screen

      while (true){
                cout<<"\n \t\t\t STUDENT INFORMATION SYSTEM \n";
     cout<<"\n \t\t\t ***************************************** \n";
     cout << "\n\n";
     cout << "\n \t\t\t 1. Add Students ";
     cout << "\n \t\t\t 2. Edit Student Records";
     cout << "\n \t\t\t 3. Manage Records";
     cout << "\n \t\t\t 0. Exit Program";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice :=> ";
                cin >> option;
                if (option == "1"){
                system("cls");//Clear screen
                    addStudent();
                }
                else if (option == "2"){
                    system("cls");//Clear screen
                    editStudent();
                }
                else if (option == "3"){
                    system("cls");//Clear screen
                    manageStudent();
                }
                else if (option == "0"){
                    system("cls");//Clear screen=
                    break;
                    system("cls");//Clear screen
                }
                cin.clear();
            }

        }
        else if (str == "2"){
                system("cls");//Clear screen
            cout<<"\n \t\t\t STAFF INFORMATION SYSTEM \n";
     cout<<"\n \t\t\t ***************************************** \n";
            while (true){

     cout << "\n\n";
     cout << "\n \t\t\t 1. Add Staffs ";
     cout << "\n \t\t\t 2. Edit Staff Records";
     cout << "\n \t\t\t 3. Manage Records";
     cout << "\n \t\t\t 0. Exit Program";
     cout << "\n\n";
     cout << "\t\t\t Select Your Choice :=> ";

                cin >> option;
                if (option == "1"){
                    system("cls");//Clear screen
                    addStaff();
                }
                else if (option == "2"){
                    editStaff();
                }
                else if (option == "3"){
                    manageStaff();
                }
                else if (option == "0"){
                    break;
                }
                cin.clear();
            }
        }
        else if (str == "0"){
            system("cls");
                cout << "\n\n";
              cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE";
              cout << "\n\n";
            break;
        }
    }
    return 0;
}


void addStudent(){


    cin.clear();
     system("cls");//Clear screen
    cout<<"\n \t\t\t ADDING NEW STUDENT  \n";
     cout<<"\n \t\t\t ***************************************** \n";
    student temp;
    print("\n \t\t\t Assigned Student ID : ");print(stu_base_id+stu_count);
    temp.details.setID(stu_base_id+stu_count);temp.details.setIndex(stu_count);stu_count++;
    string str;int num;
    print("\n \t\t\t Enter Students Name : ");
    cin.ignore();getline(cin, str);cin.clear();
    temp.details.setName(str);
    print("\n \t\t\tEnter Students Age : ");
    cin >> num;
    while (cin.fail()){
        print("\n \t\t\t( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    temp.details.setAge(num);

    print("\n \t\t\tEnter Department Name : ");
    cin >> str;
    temp.department = str;

    print("\n \t\t\t Enter Students Course : ");
    cin >> str;
    temp.course = str;

    print("\n \t\t\tEnter Students Level  : ");
    cin >> num;
    while (cin.fail()){
        print("\n \t\t\t( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    while (num != 100 && num != 200 && num != 300 && num != 400){
        print("\n \t\t\t( invalid ) Enter Level  : ");
        cin >> num;
        while (cin.fail()){
            print("\n \t\t\t( invalid ) Try Again : ");
            cin.clear();cin.ignore();cin >> num;
        }
    }
    temp.level = num;
    //set controls
    print("\n \t\t\tEnter Students School Fees : ");
    cin >> num;
    while (cin.fail()){
        print("\n \t\t\t( invalid ) Try Again  : ");
        cin.clear();cin.ignore();cin >> num;
    }
    temp.schoolfees = num;

    //pushing to array
    Stu_Container[temp.details.getIndex()] = temp;

    print("\n \t\t\tDo you want to add another student? (y/n) : ");
    cin >> str;
    if (str == "y"){
            system("cls");//Clear screen
        addStudent();
    }
    else{
        system("cls");//Clear screen
    }

};

void editStudent(){
//search student
int pass = 1;
system("cls");
print("\n \t\t\t( edit ) Enter students ID or 0 to leave : ");
int stu_id;
cin >> stu_id;
while (cin.fail()){
    print("\n \t\t\t( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> stu_id;
}
if (stu_id != 0){
        system("cls");//Clear screen

    stu_id -= stu_base_id;
    //controls
    while (stu_id < 0 || stu_id >= stu_count){
        system("cls");//Clear screen
        print("\n \t\t\t( invalid ) Enter Students ID or 0 to leave : ");
        cin >> stu_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n \t\t\t( invalid ) Enter valid student ID : ");
            cin >> stu_id;
        }
        if(stu_id != 0){
            system("cls");//Clear screen
            stu_id -= stu_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
            system("cls");
        //found student
        print("\n \t\t\t Student Found\n");
        student obj = Stu_Container[stu_id];
        //editing student
        //list option for edit...eg name ,age etc.
        while (true){
            print("\n \t\t\t 1.name \n \t\t\t 2. age \n \t\t\t 3. level \n \t\t\t 4. course \n \t\t\t 5. department \n \t\t\t 6. student subjects \n \t\t\t 7. residence \n0. exit\n");
            print("\n \t\t\t What do you want to edit : ");
            string edit;
            cin >> edit;
            if (edit == "1"){

                print("\n \t\t\tStudents name : ");print(obj.details.getName());
                print("\n \t\t\tChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
            }
            else if (edit == "2"){
                print("\n \t\t\tStudents age : ");print(obj.details.getAge());
                print("\\n \t\t\tChange to : ");
                cin >> num;
                while (cin.fail()){
                    print("\n \t\t\t( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                obj.details.setAge(num);
            }
            else if (edit == "3"){
                print("\n \t\t\tStudents level : ");print(obj.level);
                print("\\n \t\t\tChange to : ");
                cin >> num;
                while (cin.fail()){
                    print("\n \t\t\t( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                while (num != 100 && num != 200 && num != 300 && num != 400){
                    print("\n \t\t\tChange to 100,200,300 or 400 : ");
                    cin >> num;
                    while (cin.fail()){
                        print("\n \t\t\t( invalid ) Try Again : ");
                        cin.clear();cin.ignore();cin >> num;
                    }
                }
                obj.level = num;
            }
            else if (edit == "4"){
                print("\n \t\t\tStudents course : ");print(obj.course);
                cin.ignore();getline(cin, str);cin.clear();
                obj.course = str;
            }
            else if (edit == "5"){
                print("\n \t\t\tStudents Department : ");print(obj.department);
                print("\\n \t\t\tChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.department = str;
            }
            else if (edit == "6"){
                print("\n \t\t\t Students subject : \n");//list obj.subjects;
                while (true){
                    print(" \n \t\t\t1. add subject \n \t\t\t2. remove subject \n \t\t\t0. exit\n");
                    print("select an option : ");
                    cin >> str;
                    if (str == "1"){
                        cin.ignore();
                        while (true){
                            print("\n \t\t\tenter subject to add or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(str);
                               record _new;
                               _new.course_name = str;
                               _new.mark = -1;
                               obj.academic_records.push_back(_new);
                            }
                        }

                    }
                    else if (str == "2"){
                        cin.ignore();
                        while (true){
                            print("\n \t\t\t enter subject to remove or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                                int len = obj.subjects.size();
                                for (int i=0;i<len;i++){
                                    if (lower(obj.subjects[i]) == lower(str)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        obj.academic_records.erase(obj.academic_records.begin()+i);
                                        print("\nSubject successfully removed ...");
                                        break;
                                    }
                                    if (i == len-1){
                                        print("\n \t\t\t cant find subject index ...\n");
                                    }
                                }
                            }
                        }
                    }else if (str == "0"){
                        break;
                    }
                }

            }
            else if (edit == "7"){
                print("\n \t\t\tnStudents Residence : ");print(obj.details.getResidence());
                print("\n \t\t\t Change to : ");
                cin.ignore();getline(cin, str);cin.clear();
                cin.clear();obj.details.setResidence(str);
            }
            else if (edit == "0"){
                //commit changes and push
                Stu_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStudent(){
    system("cls");
    //search student
int pass = 1;
print("\n \t\t\t( manage )Enter students ID or 0 to leave : ");
int stu_id;
cin >> stu_id;
while (cin.fail()){
    print("\n \t\t\t( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> stu_id;
}
if (stu_id != 0){
system("cls");
    stu_id -= stu_base_id;
    //controls
    while (stu_id < 0 || stu_id >= stu_count){
        print("\n \t\t\t( invalid ) Enter Students ID or 0 to leave : ");
        cin >> stu_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n \t\t\t( invalid ) Enter valid student ID : ");
            cin >> stu_id;
        }
        if(stu_id != 0){
                system("cls");
            stu_id -= stu_base_id;
        }
        else{
            pass = 0;
            break;

        }
    }

    if (pass == 1){
            system("cls");
        //found student
        print("\n \t\t\tStudent Found\n");
        student obj = Stu_Container[stu_id];
        //editing student
        while (true){
            print("\n \t\t\t1. enter students score \n \t\t\t2. show academic records \n \t\t\t3. remove student \n \t\t\t0. exit\n");
            print("\n \t\t\tWhat do you want to do : ");
            string manage;
            cin >> manage;
            if (manage == "1"){
                int len = obj.subjects.size();
                print("  \n \t\t\tEnter the semester? (1,2) : ");
                cin >> num;
                while (num != 1 && num != 2){
                    print(" \n \t\t\tEnter the semester? (1,2) : ");
                    cin >> num;
                }
                for (int i=0;i<len;i++){
                    if (obj.academic_records[i].mark == -1){
                        print("\n \t\t\t\nSubject :\t");print(obj.academic_records[i].course_name);
                        print("\n \t\t\t Do you want to record marks for this subject : ");
                        cin >> str;str = lower(str);
                        while (str != "y" && str != "n"){
                            print("\n \t\t\t please choose 'y' or 'n'");
                            cin >> str;
                            str = lower(str);
                        }
                        if (str == "y"){
                            int credit_h;
                            print("\n \t\t\t Credit Hour(s)\t:\t");
                            cin >> credit_h;
                            while (0 > credit_h || credit_h > 3){
                                print("\n \t\t\t(invalid) Credit Hour(s)\t:\t");
                                cin >> credit_h;
                            }
                            int score;
                            print(" \n \t\t\tEnter Mark\t:\t");
                            cin >> score;
                            while (0 > score || score >100){
                                print("(invalid) Enter Mark\t:\t");
                                cin >> score;
                            }
                            obj.academic_records[i].mark = score;
                            obj.academic_records[i].credit_hr = score;
                            obj.academic_records[i].semester = num;
                            obj.academic_records[i].grade = gradeCalc(score);
                        }
                    }
                }
                Stu_Container[obj.details.getIndex()] = obj;
            }
            else if (manage == "2"){
                int len = obj.subjects.size();

                print("\n \t\t\t********************************************************************************************");
                print("\n \t\t\t Name : ");print(obj.details.getName());print("\tDepartment : ");print(obj.department);
                print("\n \t\t\t Course : ");print(obj.course);print("\tLevel : ");print(obj.level);print("\tGPA :\t");GpaCalc(obj);
                print("\n \t\t\t********************************************************************************************");

                for (int i=0;i<len;i++){
                    if (obj.academic_records[i].mark != -1){
                        print("\n\n \t\t\t Subject :\t");print(obj.academic_records[i].course_name);
                        print(" \t\t\t\tMark :\t");print(obj.academic_records[i].mark);
                        print(" \t\t\t\tGrade :\t");print(obj.academic_records[i].grade);
                    }
                    else{
                        print("\n\n \t\t\tSubject :\t");print(obj.academic_records[i].course_name);
                        print(" \t\t\t\tMark :\t");print("**N/A**");
                        print(" \t\t\t\tGrade :\t");print("**N/A**");
                    }
                }
                print("\n\n \t\t\t============================================================================================");
                print("\n \t\t\t############################################################################################");
            }
            else if (manage == "3"){
                     system("cls");//Clear screen
                print("\n \t\t\t Are you sure you want to remove student? (y/n) : ");
                cin >> str;str = lower(str);
                while (str != "y" && str != "n"){
                    print("\n \t\t\t please choose 'y' or 'n'");
                    cin >> str;
                    str = lower(str);
                }
                if (str == "y"){
                    obj.details.setStatus("removed");
                    Stu_Container[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                //commit changes and push
                Stu_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};

void addStaff(){
    system("cls");
    //add student detail....read class and struct
    cin.clear();
   cout<<"\n \t\t\t ADD NEW STAFF  \n";
     cout<<"\n \t\t\t ***************************************** \n";
    staff temp;
    print("\n\n \t\t\tAssigned Staff ID : ");print(sta_base_id+sta_count);
    temp.details.setID(sta_base_id+sta_count);temp.details.setIndex(sta_count);sta_count++;
    string str;int num;
    print("\n \t\t\tEnter Staff Name : ");
    cin.ignore();getline(cin, str);cin.clear();
    temp.details.setName(str);
    print("\n \t\t\tEnter Staff Age : ");
    cin >> num;
    while (cin.fail()){
        print("\n \t\t\t( invalid ) Try Again : ");
        cin.clear();cin.ignore();cin >> num;
    }
    temp.details.setAge(num);
    //list department for student to choose from
    print("\n \t\t\tEnter Department Name : ");
    cin >> str;
    temp.department = str;

    print("\n \t\t\tEnter Staffs Job : ");
    cin >> str;
    temp.job = str;



    Sta_Container[temp.details.getIndex()] = temp;

    print("\n \t\t\tDo you want to add another staff? (y/n) : ");
    cin >> str;

    if (str == "y"){
            system("cls");//Clear screen
        addStaff();
    }
    else{
        system("cls");//Clear screen

    }

};

void editStaff(){
    system("cls");
//search student
int pass = 1;
print("\n \t\t\t( edit ) Enter Staffs ID or 0 to leave : ");
int sta_id;
cin >> sta_id;
while (cin.fail()){
    print("\n \t\t\t( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> sta_id;
}
if (sta_id != 0){
    sta_id -= sta_base_id;
    //controls
    while (sta_id < 0 || sta_id >= stu_count){
        print("\n \t\t\t( invalid ) Enter Staffs ID or 0 to leave : ");
        cin >> sta_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n \t\t\t( invalid ) Enter valid Staff ID : ");
            cin >> sta_id;
        }
        if(sta_id != 0){
            sta_id -= sta_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
            system("cls");
        //found student
        print("\n \t\t\tStaff Found\n");
        staff obj = Sta_Container[sta_id];

        while (true){
            print("\n\n \t\t\t1. name \n \t\t\t2. age \n \t\t\t3. department \n \t\t\t4. staff subjects \n \t\t\t5. residence \n \t\t\t0. exit\n");
            print("\nWhat do you want to edit : ");
            string edit;
            cin >> edit;
            if (edit == "1"){
                print("\n \t\t\tStaffs name : ");print(obj.details.getName());
                print("\n\n \t\t\tChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
            }
            else if (edit == "2"){
                print("\n\n \t\t\tnChange to : ");
                cin >> num;
                while (cin.fail()){
                    print("\n \t\t\t( invalid ) Try Again : ");
                    cin.clear();cin.ignore();cin >> num;
                }
                obj.details.setAge(num);
            }
            else if (edit == "3"){
                print("\n \t\t\tStaffs Department : ");print(obj.department);
                print("\n\n \t\t\tChange to : ");
                cin.ignore();getline(cin, str);cin.clear();
                obj.department = str;
            }
            else if (edit == "4"){
                print("\n\n\n \t\t\tStaffs subject : \n");//list obj.subjects;
                while (true){
                    print("  \t\t\t1. add subject \n \t\t\t. remove subject \n \t\t\t 0. exit\n");
                    print(" \t\t\t select an option : ");
                    cin >> str;
                    if (str == "1"){
                        cin.ignore();
                        while (true){
                            print("\n \t\t\t enter subject to add or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                               obj.subjects.push_back(str);
                            }
                        }

                    }
                    else if (str == "2"){
                        cin.ignore();
                        while (true){
                            print("\n \t\t\t enter subject to remove or use 0 to leave : ");
                            getline(cin, str);
                            if (str == "0"){
                                break;
                            }
                            else{
                                int len = obj.subjects.size();
                                for (int i=0;i<len;i++){
                                    if (lower(obj.subjects[i]) == lower(str)){
                                        obj.subjects.erase(obj.subjects.begin()+i);
                                        print("\n \t\t\t Subject successfully removed ...");
                                        break;
                                    }
                                    if (i == len-1){
                                        print("\n \t\t\tcant find subject index ...\n");
                                    }
                                }
                            }
                        }
                    }else if (str == "0"){
                        break;
                    }
                }
            }
            else if (edit == "5"){
                print("\n \t\t\t Staffs Residence : ");print(obj.details.getResidence());
                print("\n\n \t\t\t Change to : ");
                cin.ignore();getline(cin, str);cin.clear();
                cin.clear();obj.details.setResidence(str);
            }
            else if (edit == "0"){
                //commit changes and push
                Sta_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}

};

void manageStaff(){

    system("cls");
    //search student
int pass = 1;
print("\n \t\t\t( manage )Enter Staffs ID or 0 to leave : ");
int sta_id;
cin >> sta_id;
while (cin.fail()){
    print("\n \t\t\t( invalid ) Try Again : ");
    cin.clear();cin.ignore();cin >> sta_id;
}
if (sta_id != 0){
    sta_id -= sta_base_id;
    //controls
    while (sta_id < 0 || sta_id >= sta_count){
        print("\n \t\t\t( invalid ) Enter Staff ID or 0 to leave : ");
        cin >> sta_id;
        while (cin.fail()){
            cin.clear();cin.ignore();
            print("\n \t\t\t ( invalid ) Enter valid staff ID : ");
            cin >> sta_id;
        }
        if(sta_id != 0){
            sta_id -= sta_base_id;
        }
        else{
            pass = 0;
            break;
        }
    }

    if (pass == 1){
        //found student
        print("\n \t\t\t Staff Found\n");
        staff obj = Sta_Container[sta_id];
        //editing student
        while (true){
            print("\n\n \t\t\t 1. remove staff \n0. exit\n");
            print("\nWhat do you want to do : ");
            string manage;
            cin >> manage;
            if (manage == "1"){
                print("\n \t\t\t Are you sure you want to remove staff? (y/n) : ");
                cin >> str;str = lower(str);
                while (str != "y" && str != "n"){
                    print("\n \t\t\t please choose 'y' or 'n'");
                    cin >> str;
                    str = lower(str);
                }
                if (str == "y"){
                    obj.details.setStatus("removed");
                    Sta_Container[obj.details.getIndex()] = obj;
                }
            }
            else if (manage == "0"){
                //commit changes and push
                Sta_Container[obj.details.getIndex()] = obj;
                break;
            }
        }
    }
}
};


string lower(string line){
    string LOWER = "abcdefghijklmnopqrstuvwxyz";
    string UPPER = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string ret_lower = "";
    int len = line.length();
    for (int i=0;i<len;i++){//boy
        for (int j=0;j<26;j++){
            if (line[i] == UPPER[j]){
                ret_lower += LOWER[j];
                break;
            }
            else if (j == 25){
                ret_lower += line[i];
            }
        }

    }
    return ret_lower;
}


string gradeCalc(double score){
    if (79 < score && score <= 100){
        return "A";
    }
    else if(74 < score && score <= 79){
        return "B+";
    }
    else if(69 < score && score <= 74){
        return "B";
    }
    else if(64 < score && score <= 69){
        return "C+";
    }
    else if(59 < score && score <= 64){
        return "C";
    }
    else if(54 < score && score <= 59){
        return "D+";
    }
    else if(49 < score && score <= 54){
        return "D";
    }
    else if(44 < score && score <= 49){
        return "E";
    }
    else if(-1 < score && score <= 44){
        return "F";
    }
    else{
        return "invalid mark";
    }
}


float getGpaScore(string grade){
    if (grade == "A"){
        return 4.0;
    }
    else if (grade == "B+"){
        return 3.5;
    }
    else if (grade == "B"){
        return 3.0;
    }
    else if (grade == "C+"){
        return 2.5;
    }
    else if (grade == "C"){
        return 2.0;
    }
    else if (grade == "D+"){
        return 1.5;
    }
    else if (grade == "D"){
        return 1.0;
    }
    else if (grade == "E"){
        return 0.5;
    }
    else if (grade == "F"){
        return 0.0;
    }
    return -1;
}

void GpaCalc(student obj){
    float gpa = 0.0;int tch=0;bool empty_score = false;
    int len = obj.academic_records.size();
    vector<record> temp_record = obj.academic_records;
    for (int i=0;i<len;i++){
        if (temp_record[i].mark == -1){
            empty_score = true;
            cout << "**N/A**";
            break;
        }
        else{
            tch += temp_record[i].credit_hr;
            gpa += getGpaScore(temp_record[i].grade)*temp_record[i].credit_hr;
        }
    }
    if (empty_score == false){
        if (len != 0){
            cout << gpa/tch;
        }
        else{
            cout << "**N/A**";
        }
    }
}
