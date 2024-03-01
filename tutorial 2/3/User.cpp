#include "User.h"
#include <iostream>

int User::n_user = 0;

User::User(char* n) {
    // std::cout << "namanya " << n << std::endl;
    this->name = new char[strlen(n)];
    strcpy(this->name, n);
    this->num_of_favourite_music = 0;
    this->music_list = new char*[100];
    n_user++;
}

User::User(const User& u) {
    this->name = new char[strlen(u.getName())];
    strcpy(this->name, u.name);
    this->num_of_favourite_music = u.getNumOfFavouriteMusic();
    this->music_list = new char*[100];
    n_user++;

    for (int i = 0; i < u.num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(u.music_list[i])];
        strcpy(this->music_list[i], u.music_list[i]);
    }
}

User::~User() {
    std::cout << "User " << this->name << " deleted" << std::endl;
    delete[] this->name;
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        delete[] this->music_list[i];
    }
    delete [] this->music_list;
    // n_user--;
}

void User::addFavouriteMusic(char* music) {
    this->music_list[this->num_of_favourite_music] = new char[strlen(music)];
    strcpy(this->music_list[this->num_of_favourite_music], music);
    this->num_of_favourite_music++;
}

void User::deleteFavouriteMusic(char* music) {
    int delIdx;
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        if (strcmp(this->music_list[i], music) == 0) {
            delIdx = i;   
            break;
        }
    }

    for (int i = delIdx; i < this->num_of_favourite_music - 1; i++) {
        strcpy(this->music_list[i], this->music_list[i+1]);
    }

    delete[] this->music_list[this->num_of_favourite_music];
    this->num_of_favourite_music--;
}

void User::setName(char* name) {
    strcpy(this->name, name);
}

char* User::getName() const {
    return this->name;
}

int User::getNumOfFavouriteMusic() const {
    return this->num_of_favourite_music;
}

void User::viewMusicList() const {
    if (this->num_of_favourite_music == 0) {
        std::cout << "No music in your favourite list" << std::endl;
    }
    else {
        for (int i = 0; i < this->num_of_favourite_music; i++) {
            std::cout << i+1 << ". " << this->music_list[i] << std::endl;
        }
    }
}

int User::getNumOfUser() {
    return User::n_user;
}