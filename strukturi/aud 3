#include <iostream>
using namespace std;

struct kompleksen_broj{
    float realen;
    float imaginaren;

    float sobiranje1 (kompleksen_broj drug){
        int realen_zbir=realen+drug.realen;
        return realen_zbir;
    }
    float sobiranje2(kompleksen_broj drug){
        int imaginaren_zbir=imaginaren+drug.imaginaren;
        return imaginaren_zbir;
    }
};

void read(kompleksen_broj &broj){
    cin>>broj.realen>>broj.imaginaren;
}

void print(kompleksen_broj broj){
    cout<<broj.realen;
    if(broj.imaginaren>=0) cout<<" + "<<broj.imaginaren<<"i"<<endl;
    else cout<<" "<<broj.imaginaren<<"i"<<endl;

}

int main() {
    kompleksen_broj a,b;
    read(a);
    read(b);
    print(a);
    print(b);
    if( a.sobiranje2(b)>=0){
        cout<<a.sobiranje1(b)<<" + "<<a.sobiranje2(b)<<"i"<<endl;
    }
    else
        cout<<a.sobiranje1(b)<<" "<<a.sobiranje2(b)<<"i"<<endl;


    return 0;
}
