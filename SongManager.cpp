#include "SongManager.h"
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void SongManager::addSong(const Song& song) {
    songs.push_back(song);
}

void SongManager::showAllSongs() {
    if (songs.empty()) {
        cout << "No songs in the list." << endl;
    }
    else {
        for (int i = 0; i < songs.size(); i++) {
            cout << "\nSong #" << i + 1 << endl;
            songs[i].printInfo();
        }
    }
}

void SongManager::deleteSong(int index) {
    if (index < 1 || index > songs.size()) {
        cout << "Invalid song number!" << endl;
        return;
    }
    songs.erase(songs.begin() + (index - 1));
    cout << "Song deleted successfully." << endl;
}

void SongManager::searchByName(const string& name) {
    bool found = false;
    for (Song s : songs) {
        if (s.getName() == name) {
            s.printInfo();
            found = true;
        }
    }
    if (!found)
        cout << "No song found with that name." << endl;
}

void SongManager::searchBySinger(const string& singer) {
    bool found = false;
    for (Song s : songs) {
        if (s.getSinger() == singer) {
            s.printInfo();
            found = true;
        }
    }
    if (!found)
        cout << "No song found by that singer." << endl;
}

void SongManager::searchByGenre(const string& genre) {
    bool found = false;
    for (Song s : songs) {
        if (s.getGenre() == genre) {
            s.printInfo();
            found = true;
        }
    }
    if (!found)
        cout << "No song found with that genre." << endl;
}

void SongManager::searchByYear(int year) {
    bool found = false;
    for (Song s : songs) {
        if (s.getYear() == year) {
            s.printInfo();
            found = true;
        }
    }
    if (!found)
        cout << "No song found from that year." << endl;
}

void SongManager::sortByName() {
    sort(songs.begin(), songs.end(), [](const Song& a, const Song& b) {
        return a.getName() < b.getName();
        });
    cout << "Songs sorted by name." << endl;
}

Song SongManager::getSong(int index) const {
    if (index >= 0 && index < songs.size()) {
        return songs[index];
    }
    return Song();
}

void SongManager::saveToFile(const string& filename) {
    ofstream outFile(filename);
    for (Song s : songs) {
        outFile << s.getName() << ";" << s.getSinger() << ";" << s.getYear() << ";" << s.getGenre() << endl;
    }
    outFile.close();
}

void SongManager::loadFromFile(const string& filename) {
    songs.clear();
    ifstream inFile(filename);
    string name, singer, genre, line;
    int year;
    while (getline(inFile, line)) {
        size_t pos1 = line.find(';');
        size_t pos2 = line.find(';', pos1 + 1);
        size_t pos3 = line.find(';', pos2 + 1);
        if (pos1 == string::npos || pos2 == string::npos || pos3 == string::npos)
            continue;
        name = line.substr(0, pos1);
        singer = line.substr(pos1 + 1, pos2 - pos1 - 1);
        year = stoi(line.substr(pos2 + 1, pos3 - pos2 - 1));
        genre = line.substr(pos3 + 1);
        songs.push_back(Song(name, singer, year, genre));
    }
    inFile.close();
}
