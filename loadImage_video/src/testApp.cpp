#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255, 255, 255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    fly.loadImage("fly.jpg");
    fly2.loadImage("fly2.png");

    
    ofSetFrameRate(50);
    

    //--------------------------- get the total pixels of video
    totalPixels = GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT *3;
    videoIn.setUseTexture(false);
    videoIn.initGrabber(GRABBED_VID_WIDTH ,GRABBED_VID_HEIGHT);


}

//--------------------------------------------------------------
void testApp::update(){
    videoIn.grabFrame();
    if (videoIn.isFrameNew()){
        int totalPixels = GRABBED_VID_WIDTH*GRABBED_VID_HEIGHT*3;
        unsigned char * tempPixels = videoIn.getPixels();
        for (int i = 0; i < totalPixels; i+=3)
        {
            unsigned char r = abs(tempPixels[i] - dataPixels[i]);
            unsigned char g = abs(tempPixels[i+1] - dataPixels[i+1]);
            unsigned char b = abs(tempPixels[i+2] - dataPixels[i+2]);
            
            diff = r+g+b;
            cout<<diff<<endl;
        }
        memcpy(dataPixels, tempPixels, totalPixels);
        text.loadData(drawingPixels, GRABBED_VID_WIDTH,GRABBED_VID_HEIGHT,GL_RGB);
    }

}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
    fly.draw(ofGetWidth()/2,ofGetHeight()/2);
    
    float diff2 = ofMap(diff, 0, 350, 50, 200);
    fly2.draw(ofGetWidth()/2,ofGetHeight()/2,diff2);
    

    ofDisableAlphaBlending();

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