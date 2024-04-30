#include <iostream>
#include <cstring>
#include <string>
using namespace std;

// 27mi aok 28mi oop 1vi mat2
//cisto virtuelna funk ne presmetuva nishto
//od abstraktna klasa ne mozhe da instancirame objektn no mozhe da imame pokazhuvach koj pokazhuva kon nekoj od izvedenite klasi, abst klasa ima 1 virtual funk
//fiksno abstrakna klasa na 2kolok

class GeometriskoTelo{
protected:
    double visina;
public:
    GeometriskoTelo(double visina=0){
        this->visina=visina;
    }

    double getVisina() const {
        return visina;
    }
    virtual void pecati(){
        cout<<"Telo so visina "<<visina;
    }
     virtual double volumen()=0;//cisto virtuelna funkcii
};

class Cilindar: public GeometriskoTelo{
private:
    double r;
public:
    Cilindar(double visina=0, double r=0): GeometriskoTelo(visina){
        this->r=r;
    }
    void pecati(){
        GeometriskoTelo::pecati();
        cout<<", radius "<<r<<", volumen "<<volumen()<<endl;
    }
    double volumen(){
        return 3.14*r*r*visina;
    }
    double getR() const {
        return r;
    }
};
class Konus:public GeometriskoTelo{
private:
    double r;
public:
    Konus(double visina=0,double r=0): GeometriskoTelo(visina){
        this->r=r;
    }
    void pecati(){
        GeometriskoTelo::pecati();
        cout<<", radius "<<r<<", volumen "<<volumen()<<endl;
    }
    double volumen(){
        return 3.14*r*r*visina/3.0;
    }

    double getR() const {
        return r;
    }
};

class Kvadar:public GeometriskoTelo{
private:
    double a,b;
public:
    Kvadar(double visina=0,double a=0, double b=0): GeometriskoTelo(visina){
        this->a=a;
        this->b=b;
    }
    void pecati(){
        GeometriskoTelo::pecati();
        cout<<", strana a  "<<a<<", strana b  "<<b<<", volumen "<<volumen()<<endl;
    }
    double volumen(){
        return visina*a*b;
    }
};

void teloSoNajgolemVolumen(GeometriskoTelo *niza[], int n){
    double max=niza[0]->volumen(); int indeks=0;
    for (int i = 0; i < n; ++i) {
        if(niza[i]->volumen()>max){
            max=niza[i]->volumen();
            indeks=i;
        }
    }
    cout<<"Najgolem volumen e: "<<endl;
    niza[indeks]->pecati();
}

//zadolzhitelna za ispit
double getRadius(GeometriskoTelo *g){
    Cilindar *c=dynamic_cast<Cilindar*>(g);
    if(c){
        return c->getR();
    }
    Konus *k=dynamic_cast<Konus*>(g);
    if(k){
        return k->getR();
    }
    return -1;
}

int main(){
    // GeometriskoTelo m(s);  ne mozhe!!!
    // GeometriskoTelo *m; mozhe!!!!
    // Cilindar n(2,7) ne mozhe posho ne e pokriena volumen klasatra i pak i ovaa e abstrakna klasa
    int n;
    cin>>n;
    int type;
    GeometriskoTelo **niza=new GeometriskoTelo * [n];//pokazuvach kon dinamichko alocirana niza
    for (int i = 0; i < n; ++i) {
        cin>>type;
        if(type==1){
            double visina, r;
            cin>>visina>>r;
            niza[i]=new Cilindar(visina, r);
        }
        else if(type==2){
            double visina, r;
            cin>>visina>>r;
            niza[i]=new Konus(visina,r);
        }
        else if(type==3){
            double visina, a, b;
            cin>>visina>>a>>b;
            niza[i]=new Kvadar(visina,a,b);
        }
    }
    for (int i = 0; i < n; ++i) {
        niza[i]->pecati();
     }
    teloSoNajgolemVolumen(niza,n);
    //niza[0]->getR(); ne mozhe ja nema vo osnovnata klasa
    cout<<getRadius(niza[0]);
    return 0;
}
