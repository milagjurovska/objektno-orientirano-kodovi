#include <iostream>
using namespace std;

struct date{
    int godina;
    int mesec;
    int den;

    int sporedi(date drug){
        if(godina>drug.godina) return 1;
        else if(godina<drug.godina) return -1;
        else{
            if(mesec>drug.mesec) return 1;
            else if(mesec<drug.mesec) return -1;
            else{
                if(den>drug.den) return 1;
                else if (den<drug.den) return -1;
                else
                    return 0;
            }
        }
    }

    int razlika_na_denovi(date drug){
        int denovi=den-drug.den+(mesec-drug.mesec)*30+(godina-drug.godina)*365;
        return denovi;
    }
};

void read(date &datum){
    cin>>datum.den>>datum.mesec>>datum.godina;
}

void print(date datum){
    cout<<datum.den<<"."<<datum.mesec<<"."<<datum.godina<<endl;
}

int main() {
    date date1;
    date date2;
    read(date1);
    read(date2);
    print(date1);
    print (date2);

    int rezultat=date1.sporedi(date2);
    if(rezultat==1){
        cout<<"razlikata e "<<date1.razlika_na_denovi(date2)<<endl;
    }
    else if(rezultat==-1){
        cout<<"razlikata e "<<date2.razlika_na_denovi(date1)<<endl;
    }
    else{
        cout<<"datumite se ednakvi"<<endl;
    }

    return 0;
}
