#include "ArtistUser.h"
#include <iostream>

int ArtistUser::num_of_artist = 0;

ArtistUser::ArtistUser(char* n) : User(n) {
    this->num_of_music_uploaded = 0;
    this->uploaded_music_list = new char*[100];
    num_of_artist++;
}

ArtistUser::ArtistUser(const ArtistUser& other) : User(other.name) {
    this->num_of_favourite_music = other.getNumOfFavouriteMusic();
    this->num_of_music_uploaded = other.num_of_music_uploaded;
    this->uploaded_music_list = new char*[100];    
    this->music_list = new char*[100];

    for (int i = 0; i < this->num_of_favourite_music; i++) {
        this->music_list[i] = new char[strlen(other.music_list[i])];
        strcpy(this->music_list[i], other.music_list[i]);
    }

    for (int i = 0; i < this->num_of_music_uploaded; i++) {
        this->uploaded_music_list[i] = new char[strlen(other.uploaded_music_list[i])];
        strcpy(this->uploaded_music_list[i], other.uploaded_music_list[i]);
    }
    num_of_artist++;
}

ArtistUser::~ArtistUser() {
    std::cout << "Artist user " << this->name << " deleted" << std::endl;
    for (int i = 0; i < this->num_of_music_uploaded; i++) {
        delete[] this->uploaded_music_list[i];
    }
    delete[] this->uploaded_music_list;
    // num_of_artist--;
 }

void ArtistUser::uploadMusic(char* music) {
    this->uploaded_music_list[this->num_of_music_uploaded] = new char[strlen(music)];
    strcpy(this->uploaded_music_list[this->num_of_music_uploaded], music);
    this->num_of_music_uploaded++;
}

void ArtistUser::deleteUploadedMusic(char* music) {
    int delIdx;
    for (int i = 0; i < this->num_of_music_uploaded; i++) {
        if (strcmp(this->uploaded_music_list[i], music) == 0) {
            delIdx = i;
            break;
        }
    }

    for (int i = delIdx; i < this->num_of_music_uploaded - 1; i++) {
        strcpy(this->uploaded_music_list[i], this->uploaded_music_list[i+1]);
    }

    delete[] this->uploaded_music_list[this->num_of_music_uploaded];
    this->num_of_music_uploaded--;
}

void ArtistUser::viewUploadedMusicList() const {
    if (this->num_of_music_uploaded == 0) {
        std::cout << "No music uploaded" << std::endl;
    }
    else {
        for (int i = 0; i < this->num_of_music_uploaded; i++) {
            std::cout << i+1 << ". " << this->uploaded_music_list[i] << std::endl;
        }
    }
}

int ArtistUser::getNumOfMusicUploaded() const {
    return this->num_of_music_uploaded;
}

int ArtistUser::getNumOfArtist() {
    return ArtistUser::num_of_artist;
}