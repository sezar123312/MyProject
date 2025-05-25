#include "song.h"
#include "song.h"
#include <iostream>
using namespace std;

Song::Song() {}

Song::Song(string name, string singer, int year, string genre) {
    this->name = name;
    this->singer = singer;
    this->year = year;
    this->genre = genre;
}

void Song::setName(string name) {
    this->name = name;
}

void Song::setSinger(string singer) {
    this->singer = singer;
}

void Song::setYear(int year) {
    this->year = year;
}

void Song::setGenre(string genre) {
    this->genre = genre;
}

string Song::getName() const {
    return name;
}

string Song::getSinger() const {
    return singer;
}

int Song::getYear() const {
    return year;
}

string Song::getGenre() const {
    return genre;
}

void Song::printInfo() const {
    cout << "Name: " << name << endl;
    cout << "Singer: " << singer << endl;
    cout << "Year: " << year << endl;
    cout << "Genre: " << genre << endl;
}
