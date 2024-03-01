#include "PremiumUser.h"
#include <iostream>

PremiumUser::PremiumUser(char* n) : User(n) {
    this->active = true;
    this->num_of_music_downloaded = 0;
}

PremiumUser::PremiumUser(const PremiumUser& other) : User(other.name) {
    this->num_of_music_downloaded = other.num_of_music_downloaded;
    this->active = other.active;
    this->num_of_favourite_music = other.getNumOfFavouriteMusic();
    this->music_list = new char*[100];
    for (int i = 0; i < this->num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }
    // std::cout << "Premium User Copied" << std::endl;
}

PremiumUser::~PremiumUser() {
    // std::cout << "Premium user " << this->name << " deleted" << std::endl;
}

void PremiumUser::downloadMusic(char* music) {
    if (!this->active) {
        std::cout << "Activate premium account to download music" << std::endl;
    }
    else {
        this->num_of_music_downloaded++;
        std::cout << "Music Downloaded: " << music << std::endl;
    }
}

void PremiumUser::inactivatePremium() {
    this->active = false;
}

void PremiumUser::activatePremium() {
    this->active = true;
}

int PremiumUser::getNumOfMusicDownloaded() const {
    return this->num_of_music_downloaded;
}

bool PremiumUser::getPremiumStatus() const {
    return this->active;
}