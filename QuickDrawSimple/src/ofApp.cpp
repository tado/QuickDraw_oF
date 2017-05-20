#include "ofApp.h"
#include <fstream>

void ofApp::setup(){
    ofBackground(255);
    ofSetColor(0);
    ofNoFill();
    ofSetBackgroundAuto(false);

    string inputFile = "bicycle.ndjson";
    ifstream input(ofToDataPath(inputFile), ifstream::in);
    
    ofxJSONElement jsonElement;
    Json::Reader reader;
    string currentLine;
    
    //load JSON data line by line and push back JsonElement into vector
    bool success = true;
    while(success) {
        getline(input, currentLine);
        success = reader.parse(currentLine, jsonElement);
        drawDataJson.push_back(jsonElement);
    }
    cout << "Done : read " << drawDataJson.size() << " drawings!"<< endl;

    objNum = int(ofRandom(drawDataJson.size()));
    strokeNum = 0;
    vertexNum = 0;
}

void ofApp::update(){
}

void ofApp::draw(){
    ofSetLineWidth(2.0);
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2-128, ofGetHeight()/2-128);
    ofBeginShape();
    for (int i = 0; i < vertexNum; i++) {
        int x = drawDataJson[objNum]["drawing"][strokeNum][0][i].asInt();
        int y = drawDataJson[objNum]["drawing"][strokeNum][1][i].asInt();
        ofVertex(x, y);
    }
    ofEndShape();
    ofPopMatrix();
    vertexNum++;
    if (vertexNum > drawDataJson[objNum]["drawing"][strokeNum][0].size()) {
        vertexNum = 0;
        strokeNum++;
        if (strokeNum > drawDataJson[objNum]["drawing"].size()-1) {
            vertexNum = 0;
            strokeNum = 0;
            objNum = int(ofRandom(drawDataJson.size()));
            sleep(1);
            ofBackground(255);
        }
    }
}
