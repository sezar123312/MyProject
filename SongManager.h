#ifndef SONG_MANAGER_H
#define SONG_MANAGER_H

#include <vector>
#include <string>
#include "song.h"
using namespace std;

class SongManager {
private:
    vector<Song> songs;

public:
    void addSong(const Song& song);
    void showAllSongs();
    void deleteSong(int index);
    void searchByName(const string& name);
    void searchBySinger(const string& singer);
    void searchByGenre(const string& genre);
    void searchByYear(int year);
    void sortByName();
    Song getSong(int index) const;
    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
};

#endif
