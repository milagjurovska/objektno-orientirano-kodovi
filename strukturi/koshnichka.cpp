#include <iostream>
using namespace std;

struct Item{
    char ime[50];
    int cena;
};

struct ShoppingCart{
    int id;
    int broj;
    Item produkti[50];
};

void average(struct ShoppingCart koshna[], int broj){
    int najmalasuma=0;
    for (int i = 0; i < broj; ++i) {

    }
}

void read1(Item& produkt){
    cin>>produkt.ime>>produkt.cena;
}

void read2(ShoppingCart& koshna){
    cin>>koshna.id>>koshna.broj;
}

int main() {
    Item produkt;
    ShoppingCart koshna[100];
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        read2(koshna[i]);
        for (int j = 0; j < koshna[i].broj; ++j) {
            read1(koshna.produkti[j]);
        }

    }
    average(koshna,n);

    highest();
    return 0;
}
