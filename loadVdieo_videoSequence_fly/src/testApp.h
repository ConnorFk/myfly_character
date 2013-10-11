#pragma once

#define _OF_BRIGHTNESS
#include "ofMain.h"

#define  NUM 210
#define grabbedVidWidth 320 
#define grabbedVidHeight 240


class testApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    unsigned char* drawingPixels;
    int brightestLoc[2];
    ofVideoGrabber videoIn;
    
    ofVideoPlayer   scooterMovie;
    float mapPosition;
};
