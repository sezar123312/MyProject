#include "user.h"

User::User() {}

User::User(string username, string password) {
    this->username = username;
    this->password = password;
}

void User::setUsername(string username) {
    this->username = username;
}

void User::setPassword(string password) {
    this->password = password;
}

string User::getUsername() {
    return username;
}

string User::getPassword() {
    return password;
}

bool User::login(string inputUsername, string inputPassword) {
    return (username == inputUsername && password == inputPassword);
}

Admin::Admin() {}

Admin::Admin(string username, string password) : User(username, password) {}
