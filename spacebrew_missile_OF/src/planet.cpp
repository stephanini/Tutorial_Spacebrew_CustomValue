//
//  planet.cpp
//  spacebrew_missileGame
//
//  Created by Bernardo Santos Schorr on 2/13/14.
//
//

#include "planet.h"

void Planet::setup(float _initVel, ofImage &_explosion) {
    
    lifeCount = 255;
    diam = ofRandom(50, 150);
    initVel = _initVel;
    
    int bornPlace = floor (ofRandom(4));
    
    if (bornPlace == 0) {
        pos.x = -diam/2;
        pos.y = ofRandom(ofGetWindowHeight() * 0.25, ofGetWindowHeight() * 0.75);
        vel.x = ofRandom(1, initVel);
        vel.y = ofRandom(-initVel, initVel);
    }
    
    if (bornPlace == 1) {
        pos.x = ofGetWindowWidth()+diam/2;
        pos.y = ofRandom(ofGetWindowHeight() * 0.25, ofGetWindowHeight() * 0.75);
        vel.x = ofRandom(-1, -initVel);
        vel.y = ofRandom(-initVel, initVel);    }
    
    if (bornPlace == 2) {
        pos.y = -diam/2;
        pos.x = ofRandom(ofGetWindowWidth() * 0.25, ofGetWindowWidth() * 0.75);
        vel.y = ofRandom(1, initVel);
        vel.x = ofRandom(-initVel, initVel);    }
    
    if (bornPlace == 3) {
        pos.y = ofGetWindowHeight() + diam/2;
        pos.x = ofRandom(ofGetWindowWidth() * 0.25, ofGetWindowWidth() * 0.75);
        vel.y = ofRandom(-1, -initVel);
        vel.x = ofRandom(-initVel, initVel);    }
    
    explosion = &_explosion;
    
    
    
}

void Planet::update() {
    
    if (!isExploded) {
        pos += vel;
    } else {
        lifeCount -= 3;
    }
    
    if (pos.x < -diam/2) pos.x = ofGetWindowWidth() +  diam/2;
    if (pos.x > ofGetWindowWidth() +  diam/2) pos.x = -diam/2;
    
    if (pos.y < -diam/2) pos.y = ofGetWindowHeight() +  diam/2;
    if (pos.y > ofGetWindowHeight() +  diam/2) pos.y = -diam/2;
    
}

void Planet::draw(ofImage &planet) {
    
    ofPushMatrix(); {
        
        ofTranslate(pos);
        
        if (!isExploded ) {
            planet.draw(0, 0, diam, diam);
        } else {
            ofSetColor(255, lifeCount);
            explosion->draw(0, 0, diam, diam);
        }
        
        ofSetColor(255);
        
    }ofPopMatrix();
    
}