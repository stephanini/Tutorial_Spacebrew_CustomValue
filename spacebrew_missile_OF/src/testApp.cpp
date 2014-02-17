#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    //Setting the text that will be written
    ofTrueTypeFont::setGlobalDpi(72);
	pixelMix.loadFont("pixelmix.ttf", 28, true, true);
	pixelMix.setLineHeight(28.0f);
	pixelMix.setLetterSpacing(1.037);
    
    //Setting up Spacebrew
    Spacebrew::Config config;
    config.clientName = "bernardoOF";
    config.addSubscribe("ofPoint", "point2d");
    
    spacebrew.connect( Spacebrew::SPACEBREW_CLOUD, config );
    ofAddListener(spacebrew.onMessageEvent, this, &testApp::onSpacebrewMessage);
    
    //Setting up initial variables for the game itself
    ofSetVerticalSync(true);
    cannon.loadImage("cannon.png");
    bkg.loadImage("bkg.jpg");
    explosion.loadImage("explosion.png");
    earth.loadImage("earth.png");
    deathStar.loadImage("death_star.png");
    
    width = ofGetWindowWidth();
    height = ofGetWindowHeight();
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    //populating the Vectors with the Earths and Death Stars
    for (int i = 0; i < 10; i++) {
        Planet tempEarth;
        tempEarth.setup(2, explosion);
        
        Planet tempDeath;
        tempDeath.setup(2, explosion);
        
        earthUnits.push_back(tempEarth);
        deathUnits.push_back(tempDeath);
        
    }
    
    //setting the isFinished to FALSE
    isFinished = false;
    
}

//--------------------------------------------------------------
void testApp::update(){
    
    if (!isFinished) {
    
        for (int i = 0; i < earthUnits.size(); i++) {
            earthUnits[i].update();
            
            if (earthUnits[i].lifeCount < 0) {
                earthUnits.erase(earthUnits.begin()+i);
            } else {
                
                for (int j = 0; j < bulletList.size(); j++) {
                    if ( ofDist(bulletList[j].pos.x, bulletList[j].pos.y, earthUnits[i].pos.x, earthUnits[i].pos.y) < earthUnits[i].diam * 0.5) {
                        earthUnits[i].isExploded = true;
                        bulletList.erase(bulletList.begin() + j);
                    }
                }
            }
        }
        
        for (int i = 0; i < deathUnits.size(); i++) {
            deathUnits[i].update();
            
            if (deathUnits[i].lifeCount < 0) {
                deathUnits.erase(deathUnits.begin()+i);
            } else {
                
                for (int j = 0; j < bulletList.size(); j++) {
                    if ( ofDist(bulletList[j].pos.x, bulletList[j].pos.y, deathUnits[i].pos.x, deathUnits[i].pos.y) < deathUnits[i].diam * 0.5) {
                        deathUnits[i].isExploded = true;
                        bulletList.erase(bulletList.begin() + j);
                    }
                }
            }
        }
        
        for (int i = 0; i < bulletList.size(); i++) {
            bulletList[i].update();
        }
        
        if (deathUnits.size() <= 0) isFinished = true;
        
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    ofPushMatrix(); {
        
        
        ofTranslate(width/2, height/2);
        
        bkg.draw(0, 0);
        
        ofRotate(-angle);
        cannon.draw(0, 0, 300, 300);
        
        
    }ofPopMatrix();
    
    for (int i = 0; i < earthUnits.size(); i++) {
        earthUnits[i].draw(earth);
    }
    
    for (int i = 0; i < deathUnits.size(); i++) {
        deathUnits[i].draw(deathStar);
    }
    
    for (int i = 0; i < bulletList.size(); i++) {
        bulletList[i].draw();
    }
    
    ofSetColor(255);
    pixelMix.drawString("EARTH:" + ofToString( earthUnits.size()) , 30, 40);
    pixelMix.drawString("DEATH STAR:" + ofToString( deathUnits.size()) , 30, 80);
    pixelMix.drawString("BALANCE:" + ofToString( int (earthUnits.size()) - int(deathUnits.size())) , 30, 120);
    
    if (isFinished) {
        ofSetColor(0, 200);
        ofRect(width/2, height/2, width, height);
        
        ofSetColor(255);
        pixelMix.drawString("GAME OVER", width/3, 320);
        pixelMix.drawString("YOUR BALANCE IS " + ofToString( int (earthUnits.size()) - int(deathUnits.size())), width/3, 380);
    }
    
}

//--------------------------------------------------------------
void testApp::onSpacebrewMessage( Spacebrew::Message & m ){
    if ( m.type == "point2d"){
        Json::Value  pointJSON;
        Json::Reader reader;
        reader.parse(m.value, pointJSON);
        
        if ( !pointJSON["state"].asBool() ) {
            initFlick.set(pointJSON["x"].asInt(), pointJSON["y"].asInt());
        }
        
        if ( pointJSON["state"].asBool() ) {
            cannonDirection = ofVec2f(pointJSON["x"].asInt(), pointJSON["y"].asInt()) - initFlick;
            angle = cannonDirection.angle(ofVec2f(1, 0));
            
            Bullet tempBullet;
            tempBullet.setup(cannonDirection * 0.1);
            bulletList.push_back(tempBullet);
            if (bulletList.size() > 5) {
                bulletList.erase(bulletList.begin());
            }
        }
    }
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}
