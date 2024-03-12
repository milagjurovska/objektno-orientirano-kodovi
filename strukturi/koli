#include <iostream>
using namespace std;

struct Engine{
    int horsepower;
    int torque;
};

struct Car{
    char ime[50];
    int god;
    Engine e;
};

void print(int n, struct Car kola[]){
    int indeks;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if(kola[j].e.horsepower>kola[j+1].e.horsepower) {
                int temp = kola[j+1].e.horsepower;
                kola[j+1].e.horsepower=kola[j].e.horsepower;
                kola[j].e.horsepower=temp;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if(kola[0].e.torque<kola[1].e.torque)
            indeks=1;
        else
            indeks=0;
    }
    cout<<"Manufacturer: "<<kola[indeks].ime<<endl;
    cout<<"Horsepower: "<<kola[indeks].e.horsepower<<endl;
    cout<<"Torque: "<<kola[indeks].e.torque<<endl;
}

void read1(Car& kola){
    cin>>kola.ime>>kola.god>>kola.e.horsepower>>kola.e.torque;
}

int main() {
    Engine e;
    Car kola[50];
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        read1(kola[i]);
    }
    print(n, kola);

    return 0;
}
