#include <iostream>
using namespace std;

struct student{
    char ime[50];
    char prezime[50];
    int indeks;
    int poeni;
};

void read(student &student){
    cin>>student.ime>>student.prezime>>student.indeks;
    int a, b, c, d;
    cin>>a>>b>>c>>d;
    student.poeni=a+b+c+d;
}

void sortiranje(student student1[],int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-1; ++j) {
            if(student1[j].poeni<student1[j+1].poeni){
                student temp=student1[j];
                student1[j]=student1[j+1];
                student1[j+1]=temp;
            }
        }
    }
}

void print(student student1){
    cout<<student1.ime<<" "<<student1.prezime<<" "<<student1.indeks<<" "<<student1.poeni<<endl;
}

int main() {
    student student1[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        read(student1[i]);
    }
    sortiranje(student1,n);
    for (int i = 0; i < n; ++i) {
        print(student1[i]);
    }

    return 0;
}
