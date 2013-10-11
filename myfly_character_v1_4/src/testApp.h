#pragma once

#include "ofMain.h"


#define  NUM 47
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
    
    void audioIn(float * input, int bufferSize, int nChannels);
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int 	bufferCounter;
    int 	drawCounter;
    
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
    
    float time[50];
    
    float posx;
    float posy;
    float dx;
    float dy;
    float dx2;
    float dy2;
    
    float mouseX;
    float mouseY;
    int p;
    int t1;
    int t2;
    
    unsigned char drawingPixels[GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT *3];
    unsigned char dataPixels[GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT *3];
    ofVideoGrabber videoIn;
    ofTexture text;
    int totalPixels;
    
    ofBlendMode blendMode;
    float       alpha;
    float 		counter;
};