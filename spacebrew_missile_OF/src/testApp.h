#pragma once

#include "ofMain.h"
#include "planet.h"
#include "bullet.h"
#include "ofxSpacebrew.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    //setup spacebrew
    Spacebrew::Connection spacebrew;
    void onSpacebrewMessage( Spacebrew::Message & m );
    
    //Font used in game
    ofTrueTypeFont pixelMix;
    
    //All image objects
    ofImage cannon;
    ofImage bkg;
    
    ofImage earth;
    ofImage deathStar;
    ofImage explosion;
    
    //variables to hold window width and height
    int width, height;
    
    //containers for each of the elements
    vector<Planet> earthUnits;
    vector<Planet> deathUnits;
    vector<Bullet> bulletList;

    //boolean to verify if game is finished
    bool isFinished;
    
    //variables to control the cannon
    ofVec2f initFlick;
    ofVec2f cannonDirection;
    float angle;
    
    
		
};
