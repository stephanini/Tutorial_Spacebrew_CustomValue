//
//  bullet.h
//  spacebrew_missile_2
//
//  Created by Bernardo Santos Schorr on 2/13/14.
//
//

#pragma once

#include "ofMain.h"

class Bullet {
public:
    
    void setup ( ofVec2f _vel);
    void update ();
    void draw();
    
    ofVec2f pos, vel;
    
    
};
