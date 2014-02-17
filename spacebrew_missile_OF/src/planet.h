//
//  planet.h
//  spacebrew_missileGame
//
//  Created by Bernardo Santos Schorr on 2/13/14.
//
//

#pragma once

#include "ofMain.h"

class Planet {
public:
    void setup(float _initVel, ofImage &_explosion);
    void update();
    void draw(ofImage &planet);
    
    float diam;
    float initVel;
    
    ofVec2f pos;
    ofVec2f vel;
    
    bool isExploded;
    
    ofImage * explosion;
    
    int lifeCount;
    
};