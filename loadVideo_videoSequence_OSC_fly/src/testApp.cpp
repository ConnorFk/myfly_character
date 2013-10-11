#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    pad = ofxMultiTouchPad();
    
    ofBackground(255, 255, 255);
    ofSetFrameRate(100);
    
    scooterMovie.loadMovie("scooter.mp4");
    scooterMovie.play();
    
    videoIn.initGrabber(grabbedVidWidth,grabbedVidHeight);

}

//--------------------------------------------------------------
void testApp::update(){
   
    videoIn.grabFrame();
    int brightest = 0;
    int index = 0;
    if (videoIn.isFrameNew()) { //check to make sure the frame is new
        drawingPixels = videoIn.getPixels();
        int length = grabbedVidWidth*grabbedVidHeight*3;
        for (int i = 0; i < length; i+=3) {
            unsigned char r = drawingPixels[i];
            unsigned char g = drawingPixels[i+1];
            unsigned char b = drawingPixels[i+2];
            if(int(r+g+b) > brightest) {
                brightest = int(r+g+b);
                brightestLoc[0] = (i/3) % grabbedVidWidth;
                brightestLoc[1] = (i/3) / grabbedVidWidth;
                cout << brightestLoc[0] <<endl;
            }
        }
    }
    
    
    scooterMovie.update();
    
    float p = brightestLoc[0]*100;
    mapPosition=ofMap(p, 1000, 30000, 0.3, 0.7);  //Map the noise value to movie time position
    scooterMovie.setPosition(mapPosition);
    
    

}

//--------------------------------------------------------------
void testApp::draw(){
    
    
    //--------------------------------------------------------------MTouch part
    ofEnableSmoothing();
    
    /*
     Use the MTouch datatype for more information on touches
     */
    ofSetColor(255, 128, 0);
    std::vector<MTouch> mTouches = pad.getTouches();
    float scale = 100;
    for (std::vector<MTouch>::iterator touch=mTouches.begin(); touch!=mTouches.end(); ++touch)
    {
        float size = touch->size*scale;
        ofPushMatrix();
        ofTranslate(touch->x*ofGetWidth(), touch->y*ofGetHeight());
        ofRotate(touch->angle);
        ofEllipse(0, 0, size, size*.5);
        ofPopMatrix();
    }
    
    
    /*
     Iterate over all touches as a vector of ofPoints Ð very simple datatype though...
     */
    ofPushMatrix();
    ofSetColor(255, 255, 255);
    pad.getTouchesAsOfPoints(&touches);
    ofPoint size = ofPoint(ofGetWidth(),ofGetHeight(),0);
    ofSetRectMode(OF_RECTMODE_CENTER);
    for (vector<ofPoint>::iterator touch = touches.begin(); touch!=touches.end(); ++touch) {
        ofRect((*touch)*size, 10, 10);
        cout << (*touch)*size <<endl;
    }
    ofPopMatrix();
    
    
    //--------------------------------------------------------------video part
    
    ofSetHexColor(0xffffff);
    videoIn.draw(0,0,1280,720);
    scooterMovie.draw(0,0,1280,720);
    ofSetColor(255,50,240);
    ofEllipse(1280-brightestLoc[0]*4,720-brightestLoc[1]*4, 10, 10);

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