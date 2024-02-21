#include "Item.hpp"

int Item::totalRevenue = 0;
int Item::totalItems = 0;

Item::Item() : stock(0), price(0), sold(0), serialNum(totalItems + 1) {
    totalItems++;
}

Item::Item(int stock, int price) : stock(stock), price(price), sold(0), serialNum(totalItems + 1) {
    totalItems++;
}

Item::Item(const Item& other) : stock(other.stock), price(other.price), sold(other.sold), serialNum(totalItems + 1) {
    totalItems++;
}

Item::~Item() {}

int Item::getSerialNum() const {
    return this->serialNum;
}

int Item::getSold() const {
    return this->sold;
}

int Item::getPrice() const {
    return this->price;
}

void Item::addStock(int addedStock) {
    if (addedStock > 0) {
        this->stock += addedStock;
    }
}

void Item::sell(int soldStock) {
    if(soldStock > this->stock) {
        totalRevenue += this->stock * this->price;
        this->sold += this->stock;
        this->stock = 0;
    }
    else {
        totalRevenue += soldStock * this->price;
        this->sold += soldStock;
        this->stock -= soldStock;
    }
}

void Item::setPrice(int newPrice) {
    this->price = newPrice;
}