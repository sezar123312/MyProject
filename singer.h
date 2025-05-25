#ifndef SINGER_H
#define SINGER_H

#include <string>
#include <vector>
#include "song.h"
using namespace std;

class Singer {
private:
    string name;
    int albumCount;
    vector<Song> songs;

public:
    Singer();
    Singer(string name, int albumCount);
    void addSong(const Song& song);
    void showInfo() const;
    string getName() const;
};

#endif
