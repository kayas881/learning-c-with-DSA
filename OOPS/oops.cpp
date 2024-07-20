#include <iostream>
#include <string>

using namespace std;

//encapsulation is wrapping properties and member function
// into an single capsule/single unit called class
class Teacher {
    //properties /attributes
    private:
     double salary;  //data hiding
    public:
    string name;
    string dept;
    string subject;
   
   //non-parameterized Constructor
//    Teacher(){
//     dept = "electronics and telecommunication";
//    }
   //parameterized constructor
      Teacher(string name, string dept, string subject, double salary){
        //this-> is a pointer to point on object property
        this->name = name;
        this->dept = dept;
        this->subject = subject;
        this->salary =salary;
       }
    //methods/member functions
    void changeDept(string newDept){
        dept = newDept;   
    }

    // setter function
    void setSalary(double s){
        salary = s;
    }

    //getter function
    double getSalary(){
        return salary;
    }

    void getInfo(){
        cout<< "name : " << name << endl;
        cout<< "subject : " << subject << endl;
        cout<< "dept :"<< dept<<endl;
    }
    
};

class Student {
public:
    string name;
    // made a pointer of cgpa
    double* cgpaPtr;

    Student(string name, double cgpa){
        this->name = name;
        //allocated a new/dynamic memory in heap for the pointer
        cgpaPtr = new double;
        // stored cgpa in that memory
        *cgpaPtr = cgpa;
        

    }
    //shallow copy constructor
    // Student(Student &obj){
    //     this->name = obj.name;
    //     this->cgpaPtr = obj.cgpaPtr;
    // }
    // // deep copy constructor
    //     Student(Student &obj){
    //     this->name = obj.name;
    //     //allocated another new memory because we dont wanna change our original memeory
    //     cgpaPtr = new double; 
    //     *cgpaPtr = *obj.cgpaPtr;
    // }

    ~Student(){
        cout<<"hello i am destructor"<<endl;
        delete cgpaPtr; // deleting dynamic memory
    }

    void getInfo(){
        cout<<"name :"<< name<<endl;
        cout<<"Cgpa :"<< *cgpaPtr<<endl;
    }
} ;
//Inheritance 
class Person{
public:
     string name;
     int age;

    //  Person(string name, int age){
    //     this->name = name;
    //     this->age = age;
    //  }  
    Person(){
        cout<<"Parent Constructor is generated first"<<endl;
    };
        ~Person(){
        cout<<"i am a parent destructor"<<endl;
    }
};
// inherited name and age from person to student2
class Student2 : public Person{
public:
    int rollno;

    void getInfo(){
        cout<<"name : " <<name << endl;
        cout<<"age : " <<age << endl;
        cout<<"rollno : " <<rollno << endl;
    }

    Student2(string name, int age, int rollno){
        cout<<"Child constructor is created after parent constructor so that it can inherit name and age";
        this->name = name;
        this->age = age;
        this->rollno = rollno;

    }
    // in destructor the destructor happens in child class first then parent class
    ~Student2(){
        cout<<"i am a child destructor"<<endl;
    }
    
};


// polymorphism is when a object takes different forms and behaves different ways based on the context
class Print{
public:

// function overloading is an example of compile time polymorphism 
    void show(int x){
        cout<<"int : "<<x<<endl;
    }
        void show(char ch){
        cout<<"character : "<<ch<<endl;
    }

};
// function overwriting is an example of run time poilymorphism
class Par{
public:
   void getInfo(){
        cout<<"Parent class....."<<endl;
    }
};

class Child : public Par {
public:
    void getInfo(){
        cout<<"child class....."<<endl;
    }
    
};
int main(){
    // //object
    // Teacher t1("kayas","electronics and telecommunication","DCOM", 20000);
    // //default copy constrctor;
    // Teacher t2(t1);

    // //t1.getInfo();
    // t2.getInfo();

    // Student2 s1("kayas",19,2103070);
    // s1.getInfo();  

    Child c1;
    c1.getInfo();
    return 0;
}