#include "iostream"
#include "cstring"
using namespace std;

class QuizAttempt{
protected:
    char indeks[6];
public:
    QuizAttempt(char *indeks=""){
        strcpy(this->indeks,indeks);
    }
    virtual double score()=0;
    virtual void print()=0;
//  bool operator>=(QuizAttempt q){} ne mozhe
    bool operator>=(QuizAttempt *q){
        return score()>=q->score();
    }
};

class Quiz{
    
};

class MCQuizAttempt:public QuizAttempt{
private:
    char tocni[11];
    char odgovori[11];
public:
    MCQuizAttempt(char *indeks="", char *tocni="", char *odgovori=""): QuizAttempt(indeks){
        strcpy(this->tocni,tocni);
        strcpy(this->odgovori,odgovori);
    }
    void print(){
        cout<<"MCQUIZATTEMOPT"<<endl;
    }
    double score(){
        double poeni=0;
        for (int i = 0; i < strlen(tocni); ++i) {
            if(tocni[i]==odgovori[i])
                poeni+=1;
            else
                poeni-=0.25;
        }
    }
};

class TFQuizAttempt:public QuizAttempt{
private:
    bool tocni[10];
    bool odgovori[10];
public:
    TFQuizAttempt(char *indeks="", bool *tocni=0, bool *odgovori=0): QuizAttempt(indeks){
        for (int i = 0; i < 10; ++i) {
            this->tocni[i]=tocni[i];
            this->odgovori[i]=odgovori[i];
        }   
    }
    void print(){
        cout<<"MCQUIZATTEMOPT"<<endl;
    }
    double score(){
        double poeni=0;
        for (int i = 0; i <10 ; ++i) {
            if(tocni[i]==odgovori[i])
                poeni+=1;
            else
                poeni-=0.5;
        }
    }
    
};
double Average(QuizAttempt **niza){
    double sum=0;
    int polozheni=0;
    for (int i = 0; i < ; ++i) {
        
    }
}
int main(){
    
    return 0;
}
