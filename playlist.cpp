#include "playlist.h"
#include <iostream>
#include <fstream>
using namespace std;

Playlist::Playlist() {}

Playlist::Playlist(string name) {
    this->name = name;
}

void Playlist::setName(string name) {
    this->name = name;
}

string Playlist::getName() const {
    return name;
}

void Playlist::addSong(const Song& song) {
    songs.push_back(song);
}

void Playlist::removeSong(int index) {
    if (index >= 1 && index <= songs.size()) {
        songs.erase(songs.begin() + (index - 1));
        cout << "Song removed from playlist.\n";
    }
    else {
        cout << "Invalid song number.\n";
    }
}

void Playlist::showSongs() const {
    if (songs.empty()) {
        cout << "Playlist is empty.\n";
    }
    else {
        cout << "\nPlaylist: " << name << endl;
        for (int i = 0; i < songs.size(); i++) {
            cout << "\nSong #" << i + 1 << endl;
            songs[i].printInfo();
        }
    }
}

void Playlist::saveToFile(const string& filename) const {
    ofstream outFile(filename);
    for (const Song& s : songs) {
        outFile << s.getName() << ";" << s.getSinger() << ";" << s.getYear() << ";" << s.getGenre() << endl;
    }
    outFile.close();
}

void Playlist::loadFromFile(const string& filename) {
    songs.clear();
    ifstream inFile(filename);
    string name, singer, genre, line;
    int year;
    while (getline(inFile, line)) {
        size_t p1 = line.find(';');
        size_t p2 = line.find(';', p1 + 1);
        size_t p3 = line.find(';', p2 + 1);
        if (p1 == string::npos || p2 == string::npos || p3 == string::npos) continue;
        name = line.substr(0, p1);
        singer = line.substr(p1 + 1, p2 - p1 - 1);
        year = stoi(line.substr(p2 + 1, p3 - p2 - 1));
        genre = line.substr(p3 + 1);
        songs.push_back(Song(name, singer, year, genre));
    }
    inFile.close();
}

