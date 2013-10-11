#pragma once

#include "ofMain.h"
#define  GRABBED_VID_WIDTH 320
#define  GRABBED_VID_HEIGHT 240


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
    unsigned char drawingPixels[GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT *3];
    unsigned char dataPixels[GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT *3];
    ofVideoGrabber videoIn;
    ofTexture text;
    int totalPixels;
    
    ofImage fly,fly2;
    int diff;
};