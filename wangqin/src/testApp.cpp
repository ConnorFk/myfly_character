#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(255, 255, 255);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    
    
    float y=1000;
    
    
    for(int i=0;i<20;i++){
        
        int f= i%2;
        ofSetColor(f*255);
        
        float k=mouseX*PI*1/600;
        y = y/(sqrt(2)*cos(PI/4-k));
        
        
        ofPushMatrix();
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofTranslate(ofGetWidth()/2,ofGetHeight()/2);
        float r = ofMap(mouseX/100*i, 60,100, 0, 360);
        ofRotateZ(r);
        ofRect(0, 0, y*1.34, y*1.34);
        ofPopMatrix();
        cout<<y<<endl;
        cout<<k<<endl;
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