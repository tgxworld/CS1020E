#include <string>
#include "Pancake.h"

using namespace std;

Pancake::Pancake() {
  this->_topSweet = false;
  this->_btmSweet = false;
  this->_orientate = "up";
}

void Pancake::setTopSweet() {
  this->_topSweet = true;
}

void Pancake::setBtmSweet() {
  this->_btmSweet = true;
}

string Pancake::getOrientation() {
  return this->_orientate;
}

void Pancake::toggleOrientation() {
  if(this->_orientate == "up") {
    this->_orientate = "down";
  } else {
    this->_orientate = "up";
  }
}

bool Pancake::getBtmSweet() {
  return this->_btmSweet;
}

bool Pancake::getTopSweet() {
  return this->_topSweet;
}

void Pancake::setOrientationSweet() {
  if(this->_orientate == "up") {
    this->setTopSweet();
  } else if(this->_orientate == "down") {
    this->setBtmSweet();
  }
}

void Pancake::setReverseOrientationSweet() {
  if(this->_orientate == "up") {
    this->setBtmSweet();
  } else if(this->_orientate == "down") {
    this->setTopSweet();
  }
}

