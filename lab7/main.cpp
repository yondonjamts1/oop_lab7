//
//  main.cpp
//  lab7
//
//  Created by out on 11/1/17.
//  Copyright © 2017 Yondonjamts_G. All rights reserved.
//

/* Zumberel
 Yondonjamts
 Munkhchimeg*/

#include<iostream>
#include<string.h>
using namespace std;

class Student{
    
public:
    char *name;
    int course;
    
private:
    char *id;
    float GPA;
    
public:
    Student(){
        //char m[7];
        //strcpy(m,"unknown");
        name = new char[strlen("unknown")+1];
        strcpy(name,"unknown");
        course = 1;
        
        id = new char[strlen("unknown")+1];
        strcpy(id,"unknown");
        GPA = 0;
        
    }
    Student(char* m, int c1, char* num, float g){
        name = new char[strlen(m)+1];
        strcpy(name,m);
        course = c1;
        
        id = new char[strlen(num)+1];
        strcpy(id,num);
        GPA = g;
        
    }
    
    Student(Student &S){
        name = new char[strlen(S.name)+1];
        strcpy(name,S.name);
        course = S.course;
        
        id = new char[strlen(S.id)+1];
        strcpy(id,S.id);
        GPA = S.GPA;
        
    }
    ~Student(){
        
        delete []name;
        delete []id;
    }
    
    void setName(const char*);
    const char* getName();
    
    void setCourse(int);
    const int getCourse();
    
    void setId(const char*);
    const char* getId();
    
    void setGPA(float);
    const float getGPA();
    void print();
    
    bool greatThan(Student &);
    bool lessThan(Student &);
    
    bool before(Student &);
    bool after(Student &);
};

bool Student :: lessThan(Student &S)
{
    if(course > S.course) return true;
    else return false;
}

bool Student :: greatThan(Student &S)
{
    if(course < S.course) return true;
    else return false;
}

bool Student :: after(Student &S)
{
    if(strcmp(name,S.name) == 1) return true;
    else return false;
}

bool Student :: before(Student &S)
{
    if(strcmp(name,S.name) == -1) return true;
    else return false;
}
void Student :: setName(const char *name1)
{
    
    name = new char[strlen(name1) + 1];
    strcpy(name,name1);
}

const char* Student :: getName()
{
    return  name;
}

void Student :: setId(const char *id1)
{
    
    id = new char[strlen(id1) + 1];
    strcpy(id,id1);
}

const char* Student :: getId()
{
    return id;
}

void Student :: setCourse(int course1)
{
    course = course1;
}
const int Student :: getCourse()
{
    return course;
}

void Student :: setGPA(float GPA1)
{
    GPA = GPA1;
}
const float Student :: getGPA()
{
    return GPA;
}
void Student ::  print()
{
    cout <<"Ner : " <<name <<endl;
    cout <<"ID : " <<id <<endl;
    cout <<"course : " <<course <<endl;
    cout <<"GPA : "<<GPA <<endl;
}
int main(){
    int i,ku,n,m;
    
    cout << "Heden suragchiin medeelel oruulah ve : ";
    cin >> n;
    
    Student *a[n];
    
    char name[20];
    char id[20];
    float gol;
    
    
    for(i = 0; i < n; i++)
    {
        a[i] = new Student();
        cout << "\t" <<"Ner : ";
        cin >> name;
        a[i]->setName(name);
        
        cout << "\t" <<"course : ";
        cin >> ku;
        a[i] ->setCourse(ku);
        
        cout << "\t" <<"ID : ";
        cin >> name;
        a[i] ->setId(name);
        
        cout << "\t" <<"GPA : ";
        cin >> gol;
        a[i] ->setGPA(gol);
        
        cout<<endl<<endl;
    }
    m = n;
    while( m > 0)
    {
        for( i = 1; i < m; i++)
        {
            if(a[i-1]->lessThan(*a[i])){
                strcpy(name,a[i-1]->getName());
                strcpy(id,a[i-1]->getId());
                ku = a[i-1]->getCourse();
                gol = a[i-1]->getGPA();
                
                
                a[i-1]->setName(a[i]->getName());
                a[i-1]->setId(a[i]->getId());
                a[i-1]->setCourse(a[i]->getCourse());
                a[i-1]->setGPA(a[i]->getGPA());
                
                a[i]->setName(name);
                a[i]->setId(id);
                a[i]->setCourse(ku);
                a[i]->setGPA(gol);
                
            }
        }
        m--;
    }
    
    cout << "**************courseeer erembelev*************\n";
    for(i = 0; i < n; i++)
    {
        a[i] -> print();
        
    }
    m = n;
    while( m > 0)
    {
        for( i = 1; i < m; i++)
        {
            if(a[i-1]->after(*a[i])){
                strcpy(name,a[i-1]->getName());
                strcpy(id,a[i-1]->getId());
                ku = a[i-1]->getCourse();
                gol = a[i-1]->getGPA();
                
                
                a[i-1]->setName(a[i]->getName());
                a[i-1]->setId(a[i]->getId());
                a[i-1]->setCourse(a[i]->getCourse());
                a[i-1]->setGPA(a[i]->getGPA());
                
                a[i]->setName(name);
                a[i]->setId(id);
                a[i]->setCourse(ku);
                a[i]->setGPA(gol);
                
            }
        }
        m--;
    }
    cout << "**************Nereer erembelev*************\n";
    for(i = 0; i < n; i++)
    {
        a[i] -> print();
        
    }
    return 0;
}
