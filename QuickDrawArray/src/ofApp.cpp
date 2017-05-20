#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofxJSONElement jsonElement;
    Json::Reader reader;
    
    ifstream input(ofToDataPath("face.ndjson"), ifstream::in);
    string cur_line;
    bool success;
    
    do {
        getline(input, cur_line);
        success = reader.parse(cur_line, jsonElement, false);
        drawDataJson.push_back(jsonElement);
    } while(success);
    
    cout << "Done : read " << drawDataJson.size() << " drawings!"<< endl;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    int cellSize = 36;
    float scale = 0.1;
    int rowNum = ofGetWidth() / cellSize;
    ofNoFill();
    for (int i = 0; i < 8000; i++) {
        for (int j = 0; j < drawDataJson[i]["drawing"].size(); j++) {
            ofPushMatrix();
            ofTranslate(i % rowNum * cellSize, i / rowNum * cellSize);
            ofBeginShape();
            for (int k = 0; k < drawDataJson[i]["drawing"][j][0].size(); k++) {
                int x = drawDataJson[i]["drawing"][j][0][k].asInt();
                int y = drawDataJson[i]["drawing"][j][1][k].asInt();
                ofVertex(x * scale, y * scale);
            }
            ofEndShape();
            ofPopMatrix();
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
