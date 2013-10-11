#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    alpha = 0;
	counter = 0;
    
    ofBackground(255, 255, 255);
    
    ofSetFrameRate(60);
    
    for (int i = 0; i < NUM; i++){
        time[i]= ofRandom(50);
    }
    
    
    
    //--------------------------- Sound Input
	soundStream.listDevices();
	int bufferSize = 256;
	left.assign(bufferSize, 0.0);
	volHistory.assign(400, 0.0);
	bufferCounter	= 0;
	drawCounter		= 0;
	smoothedVol     = 0.0;
	scaledVol		= 0.0;
	soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    //--------------------------- get the total pixels of video
    totalPixels = GRABBED_VID_WIDTH * GRABBED_VID_HEIGHT *3;
    videoIn.setUseTexture(false);
    videoIn.initGrabber(GRABBED_VID_WIDTH ,GRABBED_VID_HEIGHT);
    
    text.allocate(GRABBED_VID_WIDTH+200, GRABBED_VID_HEIGHT+200, GL_RGB);

}

//--------------------------------------------------------------
void testApp::update(){
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 0.1, true);
    cout<< posx << endl;
    cout << scaledVol<<endl;
	volHistory.push_back( scaledVol );
	if( volHistory.size() >= 400 ){
		volHistory.erase(volHistory.begin(), volHistory.begin()+1);
	}
    
    videoIn.grabFrame();
    if (videoIn.isFrameNew()){
        int totalPixels = GRABBED_VID_WIDTH*GRABBED_VID_HEIGHT*3;
        unsigned char * tempPixels = videoIn.getPixels();
        for (int i = 0; i < totalPixels; i+=3)
        {
            unsigned char r = abs(tempPixels[i] - dataPixels[i]);
            unsigned char g = abs(tempPixels[i+1] - dataPixels[i+1]);
            unsigned char b = abs(tempPixels[i+2] - dataPixels[i+2]);
            
            int diff = r+g+b;
            if (diff > 70) {
                drawingPixels[i] = 255; drawingPixels[i+1] = 255;
                drawingPixels[i+2] = 255;
            } else {
                drawingPixels[i] = tempPixels[i];
                drawingPixels[i+1] = tempPixels[i+1];
                drawingPixels[i+2] = tempPixels[i+2];
            }
        }
        memcpy(dataPixels, tempPixels, totalPixels);
        text.loadData(drawingPixels, GRABBED_VID_WIDTH,GRABBED_VID_HEIGHT,GL_RGB);
    }
    
    counter = counter + 0.033f;
    float one = 1.0;
    alpha += 0.01;
    alpha = (alpha > 1.0) ? 1.0 : alpha;


}

//--------------------------------------------------------------
void testApp::draw(){
    ofEnableAlphaBlending();    
    
    for(int i=0; i<NUM; i++){
        time[i]+=scaledVol;
        // mapping the input volumn to the increase of time line (the volumn controls speed of noise timeline)
        
        // get the continous 3 points from the noise function
        posx =ofNoise(time[i])*1024+p;
        posy =ofNoise(time[i]+1000)*768;
        dx =ofNoise(time[i+1])*1024+p;
        dy =ofNoise(time[i+1]+1000)*768;
        dx2 =ofNoise(time[i+2])*1024+p;
        dy2 =ofNoise(time[i+2]+1000)*768;
        
        float posx2,posy2,posx3,posy3,dx3,dy3,dx4,dy4;
        
        // declare the radius of circlr also with the posx varible controlled by sound
        float r = (posx-p)/400;
        // declare the varible controlled by sound and map it to the range of color
        int c=ofMap(scaledVol, 0.002, 0.009, 0.0, 255);
        
        ofSetColor(c,c*sin(c),c*cos(c),50+smoothedVol*1000);
        ofCircle(posx, posy, r);
        ofCircle(ofNoise(time[49])*1024+p, ofNoise(time[49]+1000)*768, r*30);
        
        if(i%2==0){     // 2 cases to draw Triangle or Line
            posx2=posx;
            posy3=posy;
            dx3=dx;
            dy3=dy;
            dx4=dx2;
            dy4=dy2;
        }else{
            posx3=posx;
            posy3=posy;
        }
        ofTriangle(ofNoise(time[49])*1024+p, ofNoise(time[49]+1000)*768, dx3, dy3, dx4, dy4);
        ofSetLineWidth(c/127);
        ofSetColor(255, 255, 255);
        ofLine(ofNoise(time[49])*1024+p, ofNoise(time[49]+1000)*768,posx3,posy3);
        
        ofEnableBlendMode(OF_BLENDMODE_SCREEN);
        
        ofSetHexColor(0xffffff);
        text.draw(5+GRABBED_VID_WIDTH,200,GRABBED_VID_WIDTH+200,GRABBED_VID_HEIGHT+200);
         
        ofDisableBlendMode();
        
    }
    ofDisableAlphaBlending();

}

//--------------------------------------------------------------
void testApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    int numCounted = 0;
    for (int i = 0; i < bufferSize; i++){
        left[i]		= input[i*2]*0.5;
        curVol += left[i] * left[i];
        numCounted+=2;
    }
    
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    bufferCounter++;
    
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){    //press '1' to move left and '2' to right
    
    if(key=='1'){
        t1+=1;
        
    }
    
    if(key=='2'){
        t2+=1;
    }
    p=-5*(t1-t2);

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