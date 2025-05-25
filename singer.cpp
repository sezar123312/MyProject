#include "singer.h"
#include "singer.h"
#include <iostream>
using namespace std;

Singer::Singer() {}

Singer::Singer(string name, int albumCount) {
    this->name = name;
    this->albumCount = albumCount;
}

void Singer::addSong(const Song& song) {
    songs.push_back(song);
}

string Singer::getName() const {
    return name;
}

void Singer::showInfo() const {
    cout << "\n--- Singer Page ---\n";
    cout << "Name: " << name << endl;
    cout << "Albums: " << albumCount << endl;
    cout << "Total Songs: " << songs.size() << endl;
    cout << "\nSongs by " << name << ":" << endl;
    for (int i = 0; i < songs.size(); i++) {
        cout << "\nSong #" << i + 1 << endl;
        songs[i].printInfo();
    }
}
