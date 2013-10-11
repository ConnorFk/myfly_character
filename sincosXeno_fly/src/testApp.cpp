#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofSetVerticalSync(TRUE);
    ofEnableAlphaBlending();
    
    ofBackground(255);
    speed=0.003;
    sd = 0;
    ofSetFrameRate(60);
    
    //disable auto background
    ofSetBackgroundAuto(FALSE);

}

//--------------------------------------------------------------
void testApp::update(){
    
    float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
    float radius = 200+time*20;
    time+=speed;
    
    
    
    // set up the angle
    float dx = pos.x - prevPos.x;
    float dy = pos.y - prevPos.y;
    angle = atan2(dy, dx);
    prevPos=pos;
    
    if(sd == 2){
        ofSetColor(ofRandom(100,230), ofRandom(50,200), ofRandom(100,230));
        pos.x = xorig + radius * cos(time)*sin(time*5);  //create the modulation
        pos.y = yorig + radius * -sin(time);
    }else if(sd == 0 || sd == 3){
        ofSetColor(ofRandom(100,230), ofRandom(50,200), ofRandom(100,230));
        pos.x = (1-time) * pos.x + (time) * mouseX;
        pos.y = (1-time) * pos.y + (time) * mouseY;
    }else{
        ofSetColor(60);
        pos.x = xorig + radius * cos(time)*sin(time*5);  
        pos.y = yorig + radius * -sin(time);
    }
    ofNoFill();
    ofSetLineWidth(1);
}

//--------------------------------------------------------------
void testApp::draw(){
    
    if(sd != 1){
        if(pos.x<ofGetWidth()/2){
            ofTriangle(0, ofGetHeight(), 0, 0, pos.x, pos.y);
        }else{
            ofTriangle(ofGetWidth(), ofGetHeight(), ofGetWidth(), 0, pos.x, pos.y);
        }

    }else if(sd == 1){
        ofTriangle(ofGetWidth(),pos.x*sd, ofGetHeight(), ofGetWidth(),pos.x*sd, 0, pos.x,pos.x*sd, pos.y);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    if(key=='1'){
        sd = 1;
    }
    if(key=='2'){
        sd = 2;
    }
    if(key=='3'){
        sd = 3;
    }

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