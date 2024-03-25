#include <iostream>
#include "cstring"
using namespace std;

class Achievement{
private:
    char name[50];
    char description[200];
    static int totalUserAchievements;
public:
    Achievement(){}
    Achievement(char* name, char* description){
        strcpy(this->name, name);
        strcpy(this->description,description);
    }
    Achievement(const Achievement &a){
        strcpy(this->name, a.name);
        strcpy(this->description,a.description);
    }
    ~Achievement(){}
    void print(){
        cout<<"Ime: "<<name<<endl;
        cout<<"Opis: "<<description<<endl;
    }
    static void incgrementTotalUserAchievements(){
        totalUserAchievements++;
    }
    friend class UserProfile;
};
int Achievement::totalUserAchievements=0;

class UserProfile{
private:
    char name[100];
    Achievement achievements[50];
    int n=0;
public:
    UserProfile(){}
    UserProfile(char *name){
        strcpy(this->name, name);
    }
    void print(){
        cout<<"Ime: "<<name<<endl;
        cout<<"Postignuvanja: "<<achievements<<endl;
    }
    void addAchievement(const Achievement& achievement){
        achievements[n++]=achievement;
        Achievement::totalUserAchievements++;
    }
};

int main(){

    return 0;
}
