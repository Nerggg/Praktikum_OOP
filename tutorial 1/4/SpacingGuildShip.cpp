#include <iostream>
#include "SpacingGuildShip.hpp"

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;

SpacingGuildShip::SpacingGuildShip() : passengerCount(0), guildNavigatorCount(3), maxPassengerCap(50), spiceStock(50), serialNum(producedShips + 1) {
    this->operatingGuildNavigator = this->guildNavigatorCount;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : serialNum(producedShips + 1), maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount) {
    this->passengerCount = 0;
    this->spiceStock = spiceStock;
    this->operatingGuildNavigator = this->guildNavigatorCount;
    producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& other) : maxPassengerCap(other.maxPassengerCap), passengerCount(other.passengerCount), guildNavigatorCount(other.guildNavigatorCount), spiceStock(other.spiceStock), serialNum(producedShips + 1) {
    this->operatingGuildNavigator = this->guildNavigatorCount;
    producedShips++; 
}

SpacingGuildShip::~SpacingGuildShip() {}

int SpacingGuildShip::getShipSerialNum() const {
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const {
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance) {
    totalGuildTravel += (distance / (E * E * this->operatingGuildNavigator));
    this->operatingGuildNavigator--;
}

void SpacingGuildShip::boarding(int addedPassengers) {
    if (this->passengerCount + addedPassengers > this->maxPassengerCap) {
        this->passengerCount = this->maxPassengerCap;
    }
    else {
        this->passengerCount += addedPassengers;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers) {
    if (this->passengerCount - droppedPassengers < 0) {
        this->passengerCount = 0;
    }
    else {
        this->passengerCount -= droppedPassengers;
    }
}

void SpacingGuildShip::refreshNavigator(int n) {
    if (n > 0){
        if (spiceStock >= n * GUILD_NAVIGATOR_SPICE_DOSE){
            operatingGuildNavigator += n;
            spiceStock -= n * GUILD_NAVIGATOR_SPICE_DOSE;
        }
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice) {
    this->spiceStock += addedSpice;