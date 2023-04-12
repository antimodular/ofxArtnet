#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	sendData.allocate(170, 1, GL_RGB);
//    artnet.setup("127.0.0.1",0);
    
    //IP of artnet device
    artnet.setup("10.0.7.190",0);
}

//--------------------------------------------------------------
void ofApp::update(){
    
	sendData.begin();
	ofClear(0);
	ofColor color;
	color.r = (ofNoise(ofGetElapsedTimef() + 0)* 0.5 + 0.5) * 255;
	color.g = ofNoise(ofGetElapsedTimef() + 3000) * 255;
	color.b = ofNoise(ofGetElapsedTimef() + 1000) * 255;
	ofSetColor(color);
//    ofDrawRectangle(0, 0, sendData.getWidth(), 1);
    ofDrawRectangle(0, 0, 1, 1);
	sendData.end();
    
	ofPixels data;
	sendData.readToPixels(data);
    
    for(int i=0; i<data.size(); i++){
        cout<<int(data[i])<<" , ";
    }
    cout<<endl;
    cout<<endl;
    
	artnet.sendArtnet(data);
    // artnet.sendDmx("10.100.124.253", testImage.getPixels().getData(), 1);

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	ofScale(1, 10);
	sendData.draw(0, 0);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
