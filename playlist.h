#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "song.h"
using namespace std;

class Playlist {
private:
    string name;
    vector<Song> songs;

public:
    Playlist();
    Playlist(string name);
    void setName(string name);
    string getName() const;
    void addSong(const Song& song);
    void removeSong(int index);
    void showSongs() const;
    void saveToFile(const string& filename) const;
    void loadFromFile(const string& filename);
};

#endif
