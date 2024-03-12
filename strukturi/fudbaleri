#include <iostream>
using namespace std;

struct Footballplayer{
    char ime_igrach[50];
    int broj_dres;
    int broj_golovi;
};

struct Footballteam{
    char ime[50];
    Footballplayer igrachi[11];
};

void best_team(Footballteam* teams,int n){
    int indeks=0,maks=-1,sum;
    for (int i = 0; i < n; ++i) {
        sum=0;
        for (int j = 0; j < 11; ++j) {
            sum+=teams[i].igrachi[j].broj_golovi;
        }
        if(maks<sum){
            maks=sum;
            indeks=i;
        }
    }
    cout<<"Najdobar tim e "<<teams[indeks].ime<<endl;
}

int main() {
    int n;
    cin>>n;
    Footballteam tim[50];
    for (int i = 0; i < n; ++i) {
        cin>>tim[i].ime;
        for (int j = 0; j < 11; ++j) {
            cin>>tim[i].igrachi[j].ime_igrach>>tim[i].igrachi[j].broj_dres>>tim[i].igrachi[j].broj_golovi;
        }
    }
    best_team(tim,n);

    return 0;
}
