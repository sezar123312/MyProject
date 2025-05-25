#include <iostream>
#include <vector>
#include "song.h"
#include "user.h"
#include "SongManager.h"
#include "playlist.h"
#include "singer.h"
using namespace std;

int main() {
    Admin admin("admin", "1234");
    string username, password;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    if (!admin.login(username, password)) {
        cout << "Login failed." << endl;
        return 0;
    }

    SongManager manager;
    manager.loadFromFile("songs.txt");

    Playlist userPlaylist(username + "_playlist");
    userPlaylist.loadFromFile(username + "_playlist.txt");

    vector<Singer> singers;
    auto addSongToSinger = [&](const Song& s) {
        for (Singer& singer : singers) {
            if (singer.getName() == s.getSinger()) {
                singer.addSong(s);
                return;
            }
        }
        Singer newSinger(s.getSinger(), 1);
        newSinger.addSong(s);
        singers.push_back(newSinger);
        };

    for (int i = 0; i < 100; i++) {
        Song s = manager.getSong(i);
        if (s.getName() == "") break;
        addSongToSinger(s);
    }

    int option;
    while (true) {
        cout << "\n--- MENU ---\n";
        cout << "1. Show All Songs\n";
        cout << "2. Add New Song\n";
        cout << "3. Auto Play\n";
        cout << "4. Show My Playlist\n";
        cout << "5. Add Song to My Playlist\n";
        cout << "6. Remove Song from My Playlist\n";
        cout << "7. Show Singer Page\n";
        cout << "8. Edit Song\n";
        cout << "0. Exit\n";
        cout << "Choose option: ";
        cin >> option;

        if (option == 1) {
            manager.showAllSongs();
        }
        else if (option == 2) {
            string name, singerName, genre;
            int year;
            cin.ignore();
            cout << "Enter song name: ";
            getline(cin, name);
            cout << "Enter singer: ";
            getline(cin, singerName);
            cout << "Enter year: ";
            cin >> year;
            cin.ignore();
            cout << "Enter genre: ";
            getline(cin, genre);
            Song s(name, singerName, year, genre);
            manager.addSong(s);
            manager.saveToFile("songs.txt");
            addSongToSinger(s);
            cout << "Song added and saved.\n";
        }
        else if (option == 3) {
            for (int i = 0; i < 100; i++) {
                Song s = manager.getSong(i);
                if (s.getName() == "") break;
                cout << "\nNow Playing:\n";
                s.printInfo();
                cout << "Press Enter to play next...";
                cin.ignore();
                cin.get();
            }
        }
        else if (option == 4) {
            userPlaylist.showSongs();
        }
        else if (option == 5) {
            manager.showAllSongs();
            int index;
            cout << "Enter song number to add to your playlist: ";
            cin >> index;
            userPlaylist.addSong(manager.getSong(index - 1));
            userPlaylist.saveToFile(username + "_playlist.txt");
        }
        else if (option == 6) {
            userPlaylist.showSongs();
            int index;
            cout << "Enter song number to remove: ";
            cin >> index;
            userPlaylist.removeSong(index);
            userPlaylist.saveToFile(username + "_playlist.txt");
        }
        else if (option == 7) {
            cin.ignore();
            string targetSinger;
            cout << "Enter singer name: ";
            getline(cin, targetSinger);
            bool found = false;
            for (Singer& s : singers) {
                if (s.getName() == targetSinger) {
                    s.showInfo();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Singer not found.\n";
        }
        else if (option == 8) {
            manager.showAllSongs();
            int index;
            cout << "Enter song number to edit: ";
            cin >> index;
            Song s = manager.getSong(index - 1);
            if (s.getName() == "") {
                cout << "Invalid song.\n";
            }
            else {
                string newName, newSinger, newGenre;
                int newYear;
                cin.ignore();
                cout << "Enter new name (current: " << s.getName() << "): ";
                getline(cin, newName);
                cout << "Enter new singer (current: " << s.getSinger() << "): ";
                getline(cin, newSinger);
                cout << "Enter new year (current: " << s.getYear() << "): ";
                cin >> newYear;
                cin.ignore();
                cout << "Enter new genre (current: " << s.getGenre() << "): ";
                getline(cin, newGenre);
                s.setName(newName);
                s.setSinger(newSinger);
                s.setYear(newYear);
                s.setGenre(newGenre);
                manager.deleteSong(index);
                manager.addSong(s);
                manager.saveToFile("songs.txt");
                cout << "Song updated.\n";
            }
        }
        else if (option == 0) {
            break;
        }
        else {
            cout << "Invalid choice.\n";
        }
    }
    return 0;
}
