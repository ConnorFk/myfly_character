#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    scooterMovie.loadMovie("scooter.mp4");
    scooterMovie.play();

    
    time=1; 
    pad = ofxMultiTouchPad();
}

//--------------------------------------------------------------
void testApp::update(){
    ofPoint size = ofPoint(ofGetWidth(),ofGetHeight(),0);
    scooterMovie.update();

}

//--------------------------------------------------------------
void testApp::draw(){
    float v;
    ofSetColor(255, 255, 255);
    scooterMovie.draw(640,360,1280,720);
    
    
    ofEnableSmoothing();
    /*
     Use the MTouch datatype for more information on touches
     */
    ofSetColor(255, 128, 0);
    std::vector<MTouch> mTouches = pad.getTouches();
    float scale = 100;
    for (std::vector<MTouch>::iterator touch=mTouches.begin(); touch!=mTouches.end(); ++touch)
    {
        
        
        size = touch->size*scale;
        ofPushMatrix();
        ofTranslate(touch->x*ofGetWidth(), touch->y*ofGetHeight());
        ofRotate(touch->angle);
        ofEllipse(0, 0, size, size*.5);
        ofPopMatrix();
    }
    
    
    /*
     Iterate over all touches as a vector of ofPoints – very simple datatype though...
     */
    ofPushMatrix();
    ofSetColor(255, 255, 255);
    pad.getTouchesAsOfPoints(&touches);
    ofPoint size = ofPoint(ofGetWidth(),ofGetHeight(),0);
    
    ofSetRectMode(OF_RECTMODE_CENTER);
    for (vector<ofPoint>::iterator touch = touches.begin(); touch!=touches.end(); ++touch) {        
        scooterMovie.update();
        cout<<touches[0].x<<endl;
        if(pad.getTouchCount()==1){
            scooterMovie.setPosition(touches[0].x);
            ofSetColor(255,255,255);
            scooterMovie.draw(640,360,1280,720);
        }else if(pad.getTouchCount()==2){
            v = touches[0].x;
            cout<<touches[1].x<<endl;
            scooterMovie.setPosition(touches[1].x);
            ofSetColor(255,255,v*255);
            scooterMovie.draw(640,360,1280,720);
        }
            if ( touch == touches.end() && touches[0].x<time) {
                playing = true;
                if (touches[0].x>1) {
                    playing=false;
                    touches[0].x=0;
                }
            }

             
    }
    ofPopMatrix();
    

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