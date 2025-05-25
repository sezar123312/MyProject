#ifndef SONG_H
#define SONG_H

#include <string>
using namespace std;

class Song {
private:
    string name;
    string singer;
    int year;
    string genre;

public:
    Song();
    Song(string name, string singer, int year, string genre);
    void setName(string name);
    void setSinger(string singer);
    void setYear(int year);
    void setGenre(string genre);
    string getName() const;
    string getSinger() const;
    int getYear() const;
    string getGenre() const;
    void printInfo() const;
};

#endif
