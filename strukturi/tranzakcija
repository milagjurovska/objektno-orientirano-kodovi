#include <iostream>
using namespace std;

struct Transaction{
    int id_num;
    int sum;
    int provizija;
    bool plakjanje;
};

void read1(Transaction& tranzakcija){
    cin>>tranzakcija.id_num>>tranzakcija.sum>>tranzakcija.provizija>>tranzakcija.plakjanje;
}

int main() {
    Transaction tranzakcija;
    int n; bool proverka=false;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        read1(tranzakcija);
        if(tranzakcija.plakjanje==1){
            proverka=true;
            cout<<tranzakcija.id_num<<" "<<tranzakcija.sum+tranzakcija.provizija<<endl;
        }
    }
    if(proverka==false){
        cout<<"No credit card transaction"<<endl;
    }

    return 0;
}
