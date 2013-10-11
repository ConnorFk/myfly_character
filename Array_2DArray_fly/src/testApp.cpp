#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(255, 255, 255);
    ofSetCircleResolution(100);

}

//--------------------------------------------------------------
void testApp::update(){
       
       
}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();
    ofEnableSmoothing();

    
    for(int k=0; k<18; k++){
        for(int i=0; i<13; i++){
            for(int j=0; j<14; j++){
                if(sd == 1 && sd2 == 1){
                    ofSetColor(ofRandom(100,200),ofRandom(50,200),ofRandom(60,250));
                }else{
                    ofSetColor(0);
                }
                pos.x=i*60;
                pos.y=j*60;
                mouse.x=mouseX;
                mouse.y=mouseY;
                int distance= (pos - mouse*2).length()/500;     // calculate the distance between mouse and each circle
                
                distance=ofClamp(distance, 0, 2); //restricts a value to be within a specified range defined by values min and max
                
                ofSetLineWidth(distance);   // map the line width to distance value
                ofLine(k*60,i*60,(k+1)*60, j*60);
                
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
    sd2 = 1;

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
      sd = 1;

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
      sd = 2;

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