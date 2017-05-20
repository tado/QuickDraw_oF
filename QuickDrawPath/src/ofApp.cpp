#include "ofApp.h"
#include <fstream>
#include <iostream>

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofSetBackgroundAuto(false);
    
    string inputFile = "face.ndjson";
    ifstream input(ofToDataPath(inputFile), ifstream::in);
    
    ofxJSONElement jsonElement;
    Json::Reader reader;
    string currentLine;
    
    //Load JSON data for each lines and push back into vector
    bool success = true;
    while(success) {
        getline(input, currentLine);
        success = reader.parse(currentLine, jsonElement);
        drawDataJson.push_back(jsonElement);
    }
    cout << "Done : read " << drawDataJson.size() << " drawings!"<< endl;
    
    scale = 0.2;
    objNum = int(ofRandom(drawDataJson.size()));
    strokeNum = 0;
    vertexNum = 0;
    location = ofVec2f(ofRandom(ofGetWidth()) - 128 * scale, ofRandom(ofGetHeight() - 128 * scale));
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(2.0);
    for (int j = 0; j < 4; j++) {
        ofPushMatrix();
        ofTranslate(location);
        ofBeginShape();
        for (int i = 0; i < vertexNum; i++) {
            int x = drawDataJson[objNum]["drawing"][strokeNum][0][i].asInt();
            int y = drawDataJson[objNum]["drawing"][strokeNum][1][i].asInt();
            ofVertex(x * scale, y * scale);
        }
        ofEndShape();
        ofPopMatrix();
        vertexNum++;
        if (vertexNum > drawDataJson[objNum]["drawing"][strokeNum][0].size()) {
            vertexNum = 0;
            strokeNum++;
            if (strokeNum > drawDataJson[objNum]["drawing"].size()-1) {
                location = ofVec2f(ofRandom(ofGetWidth()) - 128 * scale, ofRandom(ofGetHeight() - 128 * scale));
                objNum = int(ofRandom(drawDataJson.size()));
                vertexNum = 0;
                strokeNum = 0;
            }
        }
    }
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
