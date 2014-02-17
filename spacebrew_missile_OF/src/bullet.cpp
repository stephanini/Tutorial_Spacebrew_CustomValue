//
//  bullet.cpp
//  spacebrew_missile_2
//
//  Created by Bernardo Santos Schorr on 2/13/14.
//
//

#include "bullet.h"

void Bullet::setup( ofVec2f _vel ) {
    
    pos.set (ofGetWindowWidth()/2, ofGetWindowHeight()/2);
    vel = _vel;
    
}

void Bullet::update() {
    
    pos += vel;
    
}

void Bullet::draw() {
        ofCircle(pos, 5);
}