#include<iostream>
#include<cstring>
using namespace std;

class UserAlreadyExistsException {
//TODO
private:
    string ime;
public:
    UserAlreadyExistsException(string ime){
        this->ime=ime;
    }
    void print(){
        cout<<"User with username "<<ime<<" already exists!"<<endl;
    }
};

class UserNotFoundException {
//TODO
public:
    void print(){
        cout<<"User not found"<<endl;
    }
};

class FriendsLimitExceededException {
//TODO
public:
    void print() {
        cout << "Friends limit exceeded!" << endl;
    }
};

class User {
private:
    char username[50];
    int age;
    int friends;
    static int friendsLimit;
public:
    User(char *username = "", int age = 18) : age(age) {
        strcpy(this->username, username);
        friends = 0;
        friendsLimit=0;
    }

    friend ostream &operator<<(ostream &os, const User &user) {
        os << "Username: " << user.username << " Age: " << user.age << " # of friends: " << user.friends;
        return os;
    }

    User &operator++() {
        if(friends>=friendsLimit){
            throw FriendsLimitExceededException();
        }
        ++friends;
        return *this;
    }

    friend class SocialNetwork;

    const char *getUsername() const {
        return username;
    }

    static void setLimit(int friendsLimit);

};

int User::friendsLimit=3;

void User::setLimit(int friendsLimit) {
    User::friendsLimit = friendsLimit;
}

class SocialNetwork {
private:
    User *users;
    int n;
public:
    SocialNetwork() {
        n = 0;
        users = new User[n];
    }

    SocialNetwork &operator+=(User &u) {
        for (int i = 0; i < n; ++i) {
            if(strcmp(users[i].username,u.getUsername())==0)
                throw UserAlreadyExistsException(u.getUsername());
        }
        User *tmp = new User[n + 1];
        for (int i = 0; i < n; i++) {
            tmp[i] = users[i];
        }
        tmp[n++] = u;
        delete[] users;
        users = tmp;
        return *this;
    }

     void friendRequest(char *firstUsername, char *secondUsername) {
        int firstIndex = -1, secondIndex = -1;
        for (int i = 0; i < n; i++) {
            if (strcmp(users[i].username, firstUsername) == 0) {
                firstIndex = i;
            }
            if (strcmp(users[i].username, secondUsername) == 0) {
                secondIndex = i;
            }
        }

        if (firstIndex == -1 || secondIndex == -1) {
            throw UserNotFoundException();
        }

        try {
            ++users[firstIndex];
            ++users[secondIndex];
        } catch (FriendsLimitExceededException &e) {
            e.print();
        }
    }


    friend ostream &operator<<(ostream &os, const SocialNetwork &network) {
        os << "Users: " << endl;
        for (int i=0;i<network.n;i++) {
            os << network. users[i] << endl;
        }
        return os;
    }
};


int main() {
    SocialNetwork sn;
    int n;
    cin >> n;
    for (int i=0;i<n;i++){
        char username[50]; int age;
        cin >> username >> age;
        User u(username, age);
        try{
            sn += u;
        }catch(UserAlreadyExistsException &e){
            e.print();
        }
    }

    cout << "Registration of users " << endl;
    cout << sn << endl;
    cout << "Friend requests " << endl;

    int friendships;
    cin >> friendships;
    for (int i=0;i<friendships;i++){
        char username1[50], username2[50];
        cin >> username1 >> username2;
        try{
            sn.friendRequest(username1, username2);
        }
        catch(UserNotFoundException n){
            n.print();
        }

    }

    cout << sn << endl;

    cout << "CHANGE STATIC VALUE" << endl;

    int maxFriends;
    cin >> maxFriends;
    cin >> friendships;
    User::setLimit(maxFriends);
    for (int i=0;i<friendships;i++){
        char username1[50], username2[50];
        cin >> username1 >> username2;
        try{
            sn.friendRequest(username1, username2);
        }
        catch(UserNotFoundException n){
            n.print();
        }
    }
    cout << sn;
    return 0;
}
