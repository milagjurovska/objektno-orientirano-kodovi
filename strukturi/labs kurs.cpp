#include <iostream>
#include "cstring"
using namespace std;

struct Course{
    char ime[50];
    int kod;
    int broj_studenti;
};

struct Student{
    char ime[50];
    int indeks;
    int broj;
    int niza[50];
};

char* get_most_popular_course(struct Course courses[],int num_courses){
    int maks=0;
    char* popularen=nullptr;
    for (int i = 0; i < num_courses; ++i) {
        if(maks<courses[i].broj_studenti){
            maks=courses[i].broj_studenti;
                popularen=courses[i].ime;
        }
    }
    return popularen;
}

void read1(Student& student1, Course kurs[],int broj){
    cin>>student1.ime>>student1.indeks>>student1.broj;
    for (int i = 0; i < student1.broj; ++i) {
        cin>>student1.niza[i];
        for (int j = 0; j < broj; ++j) {
            if(kurs[j].kod==student1.niza[i])
                kurs[j].broj_studenti++;
        }
    }
}

void read2(Course& kurs){
    cin>>kurs.ime>>kurs.kod;
    kurs.broj_studenti=0;
}

int main() {
    Student student1[50];
    Course kurs[50];
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; ++i) {
        read2(kurs[i]);
    }
    for (int i = 0; i < n; ++i) {
        read1(student1[i], kurs,m);
    }

    cout<<"Najpopilaren kurs e "<<get_most_popular_course(kurs,m)<<endl;

    return 0;
}
